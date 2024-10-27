# TLPI

## 0x00 preface

TLPI：The Linux/UNIX Programming Interface

[课后题参考答案](https://linanwx.gitbooks.io/linux-unix/content/)

[官网](https://man7.org/tlpi/code/online/all_files_by_chapter.html)

## 0x07 memory alloc

### 1. brk 和 sbrk 的探究

sbrk 基于 brk 实现，它们都会**“deferred alloc”**和**“PAGE align”**。

我猜测，sbrk 的形式如下：

``` C++
int brk(void *date_end_segment);

void *sbrk(intptr_t increment)
{
    // get_brk() 是我猜测的函数，总要有一种手段获取 brk 的位置
    void *old_brk = get_brk();	
    void *new_brk = (uint64_t)old_brk + increment;
    int flag = brk(ptr);
    return flag == -1 ? NULL : old_brk;
}
```

注意，虽然说，sbrk 和 brk 会 align 到 PAGE(4096)，但是返回给我们的 brk 仍然是我们想要的。

也就是说，它虽然多分配了，但是不告诉你，和 malloc 一样😊。

假如当前 brk 是 4096，如果我们 sbrk(8)，那么 brk 会向上 alloc 到 4096*2，但是返回给我们的是 4096 + 8。简单测试如下：

``` c++
/* 一下测试基于内存检测工具 gcc -fsanitize=address
    真的是利器！
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#define PAGE_SIZE (4096)

uint64_t get_brk()
{
    int *p = sbrk(0);
    return (uint64_t)p;
}

void print_brk()
{
    printf("brk = 0x%lx\n", get_brk());
}

int main()
{
    print_brk();
    sbrk(0x10);
    print_brk();
    return 0;
}
// brk = 0xaaaaee7e1000
// brk = 0xaaaaee7e1010
```

### 2. 测试 

测试程序1：测试 brk 和 sbrk 分配内存时的 **PAGE align**

``` c++
/* 一下测试基于内存检测工具 gcc -fsanitize=address
    真的是利器！
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

int val;

uint64_t get_brk()
{
    int *p = sbrk(0);
    return (uint64_t)p;
}

void print_brk()
{
    printf("brk = 0x%lx\n", get_brk());
}

void print_ptr_int(int **p)
{
    printf("0x%p = 0x%x\n", *p, **p);
}

void print_ptr_char(char **p)
{
    printf("0x%p = %c\n", *p, **p);
}

int main()
{
    printf("PAGE_SIZE = %d\n", getpagesize());

    uint64_t pos = get_brk();   // brk 结尾处
    print_brk();    
    int *p = pos + 10; 
    brk(p);     
    // 等价于 sbrk(10*sizeof(int));
    // brk 分配 10 * sizeof(int) 到 p 结束的位置
    // 但是因为 brk 会 page 对齐
    // 因此，实际分配了 PAGE_SIZE(4096)
    // 因此，brk的位置应该为 pos+PAGE_SIZE
    *p = 1024;
    print_ptr_int(&p);
    int *lastp = pos + 4096 - 4;
    // pos+4096 是 brk 的结束位置，要减去 sizeof(int)    
    *lastp = 0xaabbccdd;
    print_ptr_int(&lastp);
    // 我们可以再测试一下，pos+4096 是最小不可用单位
    char *c1 = pos + 4096 - 1;  // 最后一个可用字节
    *c1 = 'A';
    print_ptr_char(&c1); // 可以运行！
    // 现在可以测试一下最小不可用字节 
    char *c2 = pos + 4096;
    *c2 = '*';
    print_ptr_char(&c2); // 检测工具会报错，因为我们内存越界了！
    
    return 0;
}
```



测试程序2：测试 brk 回收内存

``` c++
/* 一下测试基于内存检测工具 gcc -fsanitize=address
    真的是利器！
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#define PAGE_SIZE (4096)

uint64_t get_brk()
{
    int *p = sbrk(0);
    return (uint64_t)p;
}

void print_brk(char *s)
{
    printf("%sbrk = 0x%lx\n", s, get_brk());
}

void print_ptr_int(int **p)
{
    printf("0x%p = 0x%x\n", *p, **p);
}

void print_ptr_char(char **p)
{
    printf("0x%p = %c\n", *p, **p);
}

int main()
{
    print_brk("Init: ");
    sbrk(2 * PAGE_SIZE);    // 分配两个 PAGE
    print_brk("Alloc: ");
    void *old = get_brk() - 10 * sizeof(int);
    printf("old addr: 0x%p\n", old);
    int flag = brk(old);
    if(flag != -1)
    {
        printf("brk() successful!\n");
    }
    print_brk("After des: ");
    int *p = get_brk() - 4; // 最后4个可用字节
    printf("0x%p\n", p);
    *p = 0xaabbccdd;
    print_ptr_int(&p);  // 可以运行
    p ++ ;
    // 按理说，下面的代码运行失败！
    char *ch = old;
    *ch = 'A';
    print_ptr_char(&ch);
    // wow，出乎我们的意料哦，竟然可以正常运行！  
    return 0;
}
```

测试程序3：测试 sbrk 回收内存

``` c++
/* 一下测试基于内存检测工具 gcc -fsanitize=address
    真的是利器！
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#define PAGE_SIZE (4096)

uint64_t get_brk()
{
    int *p = sbrk(0);
    return (uint64_t)p;
}

void print_brk(char *s)
{
    printf("%sbrk = 0x%lx\n", s, get_brk());
}

void print_ptr_int(int **p)
{
    printf("0x%p = 0x%x\n", *p, **p);
}

void print_ptr_char(char **p)
{
    printf("0x%p = %c\n", *p, **p);
}

int main()
{
    print_brk("Init: ");
    sbrk(2 * PAGE_SIZE);    // 分配两个 PAGE
    print_brk("Alloc: ");
    void* old = sbrk(-10 * sizeof(int));     // 减少 brk
    if(old == NULL)
    {
        printf("sbrk() error!");
        exit(0);
    }
    print_brk("After dec: ");

    int *p = get_brk() - 4; // 最后4个可用字节
    *p = 0xaabbccdd;
    print_ptr_int(&p);  // 可以运行
    
    // 按理说，下面的代码应该 SF
    // wow，出乎我们的意料哦，竟然可以正常运行！
    // 前提是 i<10。i不能取11，12.。。。
    for(int i = 0, j = 1; i < 10; i ++ , j <<= 1) 
    {
        p = p + 1;
        *p = j;
        print_ptr_int(&p);  
    }
    printf("now end addr of p: %p\n", p + 1);
   
    return 0;
}
```



### 3.  疑问

通过上面的测试 2 和测试 3 我们可以发现，对于已经回收的内存，我们仍然可以使用，并且不会报错。。。？

但是，如果我们回收的内存比较大，它就会真的回收了。

我想，这是因为。brk 为了性能，对于较小的内存块，它不会回收？？但是在下面的例子中，我们分配了10个int，然后又全部回收，会报错。

``` c++
/* 一下测试基于内存检测工具 gcc -fsanitize=address
    真的是利器！
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>

#define PAGE_SIZE (4096)

uint64_t get_brk()
{
    int *p = sbrk(0);
    return (uint64_t)p;
}

void print_brk(char *s)
{
    printf("%sbrk = 0x%lx\n", s, get_brk());
}

void print_ptr_int(int **p)
{
    printf("0x%p = 0x%x\n", *p, **p);
}

void print_ptr_char(char **p)
{
    printf("0x%p = %c\n", *p, **p);
}

int main()
{
    print_brk("Init: ");
    sbrk(10 * sizeof(int));    // 分配两个 PAGE(2K)
    print_brk("Alloc: ");
    void* old = sbrk(-(10 * sizeof(int)));     // 减少 128KB
    if(old == (void*)-1)
    {
        printf("sbrk() error!");
        exit(0);
    }
    print_brk("After dec: ");
    int *p = get_brk() - 4; // 最后4个可用字节
    *p = 0xaabbccdd; 
    print_ptr_int(&p);  // 可以运行
    // 按理说，下面的代码应该 SF
    // wow，出乎我们的意料哦，竟然可以正常运行！
    // 前提是 i<10。i不能取11，12.。。。
    for(int i = 0, j = 1; i < 5; i ++ , j <<= 1) 
    {
        p = p + 1;
        *p = j;
        print_ptr_int(&p);  
    }
    printf("now end addr of p: %p\n", p + 1);
   
    return 0;
}
// 128K = 0x20000
//  10 0000 0000 0000 0000
```

可见，如果我们回收了我们全部分配的，那么是会真的回收的。

### 4. bss 和 heap

> 注意，**bss 和 heap 是不相邻的，它们有一个随机的间隔**，并且同一个程序 bss 的结束地址编译期就固定，而 heap 的起始地址在每次运行的时候都会改变。程序开始运行时 heap 的大小是 0，所以起始地址和结束地址是一样的。可以通过 brk(n) 来设置起点，设置为当前的 heap 地址减去一个偏移，只要这个偏移不超出随机间隔的空间。
>
> ```c
> #include <stdio.h>
> #include <stdlib.h>
> #include <unistd.h>
> 
> int bss_end;
> #define SIZE 0x2000
> 
> void heapLocation(){
>     void * tret = sbrk(0);
>     if (tret != (void *)-1)
>         printf ("heap start: %p ", tret);
>     int r = brk((char*)tret-SIZE);
>     printf("brk(%p):%d %p\n", (char*)tret-SIZE, r, sbrk(0));
> }
> int main(void)
> {
>     printf("bss end: %p\n", (char *)(&bss_end) + 4);
>     heapLocation();
>     void *m = malloc(SIZE);
>     heapLocation();
> }
> ```



### 5. malloc vs. calloc

在 `ubuntu20.04, gcc version 11.3.0 (Ubuntu 11.3.0-1ubuntu1~22.04) 下`测试，calloc 确实比 malloc 要满，大约两倍到三倍。但这应该也与实现有关，在有些实现上，calloc和malloc可能也一样快。

那么，既然 calloc 性能上没有那么差劲，还有初始化为 0 的保护，为什么几乎都是用 malloc 而不是 calloc 呢？并且，鲜为人知的是，calloc 可以避免整形溢出，因为他没有乘法。

> [ref](https://www.v2ex.com/t/572612)
>
> [ref2](https://stackoverflow.com/questions/1538420/difference-between-malloc-and-calloc)
>
> 大致意思就是，C 语言的大原则是程序员知道自己在干什么，在这个前提下，也就**没必要**初始化了。
>
> 因此，calloc 的性能没有那么差，但是也没有必要浪费这些性能。

另外，calloc 并不比 malloc+memset 要快多上，理论上，它们应该是一样快的。

``` C++
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int s = clock();
    for(int i = 0; i < 1e6; i ++ )
    {
        int *p = malloc(3 * 1024);
        // free(p);
    }
    double t = (clock() - s) * 1.0 / CLOCKS_PER_SEC;
    printf("malloc: %.5f\n", t);
    s = 0;
    for(int i = 0; i < 1e6; i ++ )
    {
        int *p = calloc(3, 1024);
        // free(p);
    }
    t = (clock() - s) * 1.0 / CLOCKS_PER_SEC;
    printf("calloc: %.5f\n", t);
    return 0;
}
// malloc: 1.86035
// calloc: 3.81964
```





### 6. 内存对齐

> 

### 7. mtrace() 分析内存泄漏



### 8. [TODO]

> [[1]](http://monchickey.com/post/2022/04/07/c-memory-api/)
>
> [[2]](https://www.cnblogs.com/linuxnewbie/p/3884611.html)
>
> [[3]](https://zhuanlan.zhihu.com/p/57863097)
>
> [[4]](https://www.kandaoni.com/news/22271.html)
>
> 