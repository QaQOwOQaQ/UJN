# 第十七章（1） epoll

# 一、select 速度慢的原因：
1. 调用 select 函数后常见的针对所有文件描述符的循环语句
2. 每次调用 select 函数时都需要向该函数传递监视对象信息

每次调用 select 函数后，并不是把所有发生变化的文件描述符集中到一起，而是通过作为监视对象的 fd_set 变量的变化，找出发生变化的文件描述符（通过循环），而且，正因为 fd_set 会变化，因此调用 select 之前应该复制保存原有信息，并在每次调用 select 时传递新的监视对象信息。

看起来好像循环是 select 速度慢的主要原因，但其实不是。循环可以优化，但是我们每次传递监视信息太底层且不能优化。
因为文件描述符是操作系统管理的，每次传递文件描述符都需要借助操作系统。

解决方法也很简单：仅向操作系统传递一次监视信息（避免每次调用都传递一次信息），监视范围或内容发生变化时只通知发生变化的事件（避免循环）。 -- 这就是 epoll

# 二、epoll
## 1. 与 select 的不同点
epoll 和 select 最大的不同点在于，select 不会让操作系统挖一块空间给他用来保存监视信息，因此每次调用 select 都需要重新传递一个文件夫描述和监视信息。
而 epoll 直接给操作系统说：你给我挖一块空间，专门用来保存我的监视信息，这样我每次调用就不需要重新传入监视信息了。（以空间换时间）

另外，我们需要一个新的数据结构(epoll_event)用来保存发生变化的事件来避免循环查找。

## 2. epoll 函数
``` c++
#include <sys/epoll.h>
epoll_create(); // 等价于 select FD_CLR()，这里用来创建 epoll 例程（用来保存文件描述符）
epoll_ctl();    // FD_SET(), FD_DEL();
epoll_wait();   // 
```

## 3. epoll_event
``` c++
struct epoll_event
{
    __uint32_t events;  // （2） 监视的事件
    epoll_data_t data;
};
typedef union epoll_data {
    void *ptr;
    int fd;             // （1） 监视的对象
    __uint32_t u32;
    __uint64_t u64;
} epoll_data_t;
```
（1）和（2）是我们主要的关注点。
声明足够大的 epoll_event 结构体数组候，传递给 epoll_wait 函数时，发生变化的文件描述符信息将被填入数组。因此，无需像 select 函数那样针对所有文件描述符进行循环。

event 有两个用途：
1. 就是前面说的保存发生变化的事件，event_epoll
2. 作为对象添加/修改的事件 epoll_ctl，event_epoll *

## 4. epoll 事件
EPOLLIN：需要读取数据的情况
EPOLLOUT：输出缓冲为空，可以立即发送数据的情况
EPOLLPRI：收到 OOB 数据的情况
EPOLLRDHUP：断开连接或半关闭的情况，这在边缘触发方式下非常有用
EPOLLERR：发生错误的情况
EPOLLET：以边缘触发的方式得到事件通知
EPOLLONESHOT：发生一次事件后，相应文件描述符不再收到事件通知。因此需要向 epoll_ctl 函数的第二个参数传递 EPOLL_CTL_MOD ，再次设置事件。



## 5. epoll 的流程
1. epoll_create 创建一个 epoll 例程，可以不传入参数
2. 为接受发生变化的 events 分配动态内存
3. 利用 epoll_ctl 操纵事件
4. 利用 epoll_wait 获取变化的文件描述符
5. 调用 close 销毁 epoll 例程
