# C++ Concurrency In Action

## reference

[Book 开源处(感觉翻译很烂)](https://www.bookstack.cn/read/Cpp_Concurrency_In_Action/README.md#C++%20Concurrency%20In%20Action)

关于异常：

> **出现异常并不意味着程序本身出了问题，而是程序外部的输入无法让正常业务继续执行，这时应该执行的是异常业务，而异常就是这两种业务转接的桥梁——它提供一种机制，使得程序员在遵守一定规则之下，这个异常业务能够正确完成。**
>
> 异常安全的三个级别：noexcept,  basic, strong
>
> [ref](https://01io.tech/error-handling-cpp-exception-safety/)
>
> [ref](https://learn.microsoft.com/zh-cn/cpp/cpp/how-to-design-for-exception-safety?view=msvc-170)

## P0 English

spin：自旋转

unary predicate：一元谓词s

binary predicate：二元谓词

predicate：谓词

snapshot：快照

nice-to-have：可有可无

parallelism: 并行

serialization：串形

RAII: Resource Acqusition Is Initialization，资源获取即初始化

Abstraction penalty：抽象代价

daemon thread: 守护线程

invariants:不变量

race condition：条件竞争

grammar：语法

semantics：语义

malicious_function：恶意函数

hierarchical: 分层的

granularity: 粒度

idiom：惯用法

nest: 嵌套

recursive：互斥

synchronization：同步

condition variable：条件变量

future：期望

spurious wakeup：伪唤醒

asynchronization：异步

pivot：枢纽

chrono：时间

## P1 Hello, concurrency

**contest switch**

> save cpu state and instruction pointer, calculate which task should we switched, and load new cpu state. then, cpu will load the instruction and data in cache

**hardware concurrency**

> truly concurrency

**the way of concurrency**

> 1. Multiprocessing concurrency: need to IPC, so more complex and more slowly, but it has good isolation and more safety
>
> 2. Multithreading concurrency: need to solve concurrency problem carefully

**Warning: **this book base on multiply thread concurrency

**why need to concurrency:** only one for code **ioslation** and other for **prefomance**

**test code:**

``` C++
#include <thread>

void hello() 
{
    cout << "Hello, Concurrency!" << endl;
}

int main()
{
    thread t(hello);
    t.join();
    return 0;
}
```





## P2 Thread management

### 2.1 preface

#### 2.1.1 generalize

> 1. create and run a new thread
> 2. join or detain thread
> 3. unique identify of thread

#### 2.1.2 start thread

thread run when you create a object of `std::thread`

`std::thread` can create a object by `function object`, like this example:

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

void hello() 
{
    cout << "Hello, Concurrency!" << endl;
}

class background_task
{
public:
    void operator()(void) const
    {
        // do something
        cout << "Hello, I am a new thread!" << endl;
        // do something else
        cout << "Good bye~" << endl;
    }
};

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    background_task f;
    thread t(f);
    t.join();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

But, if you want to pass a tempate object to `std::thread`, in this way:`thread my_t(background_task());`

You will found this run with error: `my_t is a declaration of funtion`

This is because C++’s [most vexing parse](https://en.wikipedia.org/wiki/Most_vexing_parse), in that declaration, my_t will be parsed in a funtion but a object, you can solve this by following way:

1. use of an extra parenthesis: `thread t(( background_task() ));`
2. use C++11 initialization: `thread t{ background_task() };`
3. use C++11 lambda: 

``` c++
thread t([]{
    cout << "Hello, this is a thread!" << endl;
    cout << "byt~" << endl;
});
```

If you doesn’t decide join or detain your thread, then it will call dtor(`std::terminate()`).

#### 2.1.2 join thread

If you detach a thread like this way:

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*======================*/

struct func
{
    int &i;
    func(int &_i) : i(_i) {}
    void operator()()
    {
        for(unsigned j = 0; j < 1024 * 1024; j ++ )
        {
            cout << j << " - " << i << "-Hello,World!" << endl;
        }
    }
};

void oops()
{
    int local_state = 1024;
    func my_func(local_state);
    my_func();
    thread my_thread(my_func);
    my_thread.detach(); // wrong!
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    oops();
    /*======================*/
    PRINT_END;  
    return 0;
}


```

In `std::thread my_thread`, we pass by value of `my_func` and access local object in `func::operator()` , if funtion `oops` exit before thread `my_thread` exit, then `my_thread` will access local value which is destoryed, and the behaviour when it happened is UB. 



> so it is important to choose a valid way to wait you thread.
>
> and a programming habit is **do not create a thread which can access local object**



A easy and rude way to wait a thread until exit is `join`

if you call `join`, the resoures about thread will clean automatilly, and you cant call `join` double times and more.

you can call `joinable()` to get if you can join, it return false if you haved joined 

#### 2.1.3 join in special condition

Look the next code:

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

struct func;

/*======================*/

class thread_guard
{
public:
    explicit thread_guard(thread &_t) : t(_t) {}
    ~thread_guard() 
    {
        cout << "~ thread_guard" << endl;
        if(t.joinable())
        {
            t.join();
        }
        cout << "~ end" << endl;
    }
    thread_guard(thread_guard const &) = delete;
    thread_guard& operator=(thread_guard const &) = delete;
private:
    thread &t;
};

void do_something()
{
    cout << "function f() do something here.." << endl;
    throw(string("No reason exception"));
}

void f()
{
    int local_state = 1024;
    func my_func(local_state);
    thread t(my_func);
    do_something();
    // if do_something() throw exception
    // then t.join will be skiped and t would call terminate
    t.join();
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    try
    {
        f();
    }
    catch(string &e)
    {
        cout << "catch in main: " << e << endl;
    }
    /*======================*/
    PRINT_END;  
    return 0;
}


```

In function `f()`, if `do_something()` throw exception, and not catched, then `f()` wiil exit and skiped `join()`

A solution is followings:

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

struct func;

/*======================*/

void do_something()
{
    cout << "function f() do something here.." << endl;
    throw(string("No reason exception"));
}

void f()
{
    int local_state = 1024;
    func my_func(local_state);
    thread t(my_func);
    
    try
    {
        do_something();
    }
    catch(string &e) // (1)
    {
        cout << "catch in f: " << e << endl;
        t.join();
        throw;
    }
    t.join();
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    try
    {
        f();
    }
    catch(string &e)
    {
        cout << "catch in main: " << e << endl;
    }
    /*======================*/
    PRINT_END;  
    return 0;
}
```



But, a better way is in RAII

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

struct func;

/*======================*/

class thread_guard
{
public:
    thread_guard(thread& _t) : t(_t) {}
    ~thread_guard()
    {
        cout << "~thread_guard" << endl;
        if(t.joinable())
        {
            t.join();
        }
        cout << "~thread_guard end" << endl;
    }
    thread_guard(const thread& _t)=delete;
    thread_guard& operator=(const thread& _t) = delete;
private:    
    thread &t;
};

void do_something()
{
    cout << "function f() do something here.." << endl;
    throw(string("No reason exception"));
}

void f()
{
    int local_state = 1024;
    func my_func(local_state);
    thread t(my_func);
    thread_guard g(t);
    do_something();
    // the next will skiped if do_something() throw exception
    t.join();
    cout << "f() end" << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    try
    {
        f();
    }
    catch(string &e)
    {
        cout << "catch in main: " << e << endl;
    }
    /*======================*/
    PRINT_END;  
    return 0;
}
```

In this way, although `do_something()` will throw exception and skip `join`, the object `g` will call `dtor` to `join` the thread he managed

#### 2.1.4 detach thread





### 2.2 pass value

Whaterver the parameters type you set(reference or value), thread will **copy** always! Just copy all arguments in the memory space itself.

In the following code, function `f()` receive a int pass by value and a string pass by reference

And because we detach the thread `t`, so we would can't receiver it’s output.

> 在下面的代码中，函数 f 打印的 s 可能会乱码，这是因为函数 buf 实际上是一个指针变量，它指向局部变量。
>
> 并且它的类型是 `const char *`，当我们把它传递给 `string` 时，会执行一个隐式类型转换。
>
> 但是，我们无法确保隐式类型转换与 thread 传递参数时进行 copy 的执行顺序问题， 也就是说，有可能传递给 string 的事转换前的变量（buf 只想的指针）

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*======================*/

void f(int i, string const &s)
{
    cout << "int: " << i << endl;
    cout << "string: " << s << endl; // string s will chaos
}

void func()
{
    int value = 1024;
    char buf[1024];
    sprintf(buf, "value = %i", value);
    thread t(f, value, buf);
    t.detach();
    cout << "func end" << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    func();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

So, the solution is easy, explicit call type convention

`thread t(f, value, string(buf));`

----

But, sometimes, we actually want to pass by refernece, the solution is use `std::ref`

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*======================*/

void f(int &i)
{
    cout << "thread: " << &i << endl;
}

void func()
{
    int value = 1024;
    cout << "func: " << &value << endl;
    thread t(f, ref(value));
    t.join();
    cout << "func end" << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    func();
    /*======================*/
    PRINT_END;  
    return 0;
}
```



Also, you can pass class funtion and it’s this object

``` c++
#include <iostream>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*======================*/

struct X
{
    int val;
    void do_work()
    {
        cout << "val: " << val << endl;
    }
};

void func()
{
    X x;
    x.val = 10;
    // pass pointer 
    thread t(&X::do_work, &x);
    t.join();
    cout << "func end" << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    func();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

---

But, for some type, the operator assignment or operator copy is deleted, like `unique_ptr<>`, so should `move` but copy.

``` c++
#include <iostream>
#include <memory>
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*======================*/

void f(unique_ptr<int> q)
{
    cout << "value: " << *q << endl;
}

void func()
{
    unique_ptr<int> q(new int(1024));
    thread t(f, move(q));
    t.join();
    cout << "func() end" << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    func();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

It would CE If you not use `std::move`.

> Thread cant copt too.



### 2.3 transfer possessiveness

#### 2.3.1 preface

你不能通过赋新值操作来“丢弃”一个线程，即：你不能将一个线程 move 到一个已经分配了任务的线程。

你也不可以将一个线程 copy 到另一个线程，但是你可以将一个线程 move 到另一个空线程。

对于下面的形式（1）是合法的，因为 `thread(f)` 是一个临时对象 – 移动操作会隐式的调用，如果是一个 `具名对象`， 就需要显示的调用 `move`，如 (2) 所示。

``` c++
void f();
thread t;
t = thread(f); // (1)
thread t2 = move(f); // (2)
```

但是对于 (3) 所示就会 CE：

``` c++
thread t;
t = thread(f);
thread t2 = move(t);
t = thread(f);
t2 = move(t);   // (3) t2 已经被分配
t2.join();
```



#### 2.3.2 scoped_thread

``` c++
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

class thread_guard;
struct func;

/*===========================*/

class scoped_thread
{
public:
    explicit scoped_thread(std::thread _t) 
        : t(std::move(_t)) 
    {
        if(!t.joinable())
            throw std::logic_error("No thread!");
    }
    ~scoped_thread()
    {
        t.join();
    }
    scoped_thread(const scoped_thread&) = delete;
    scoped_thread& operator=(const scoped_thread&) = delete;
private:
    thread t;   // 不能是引用
};

void Test()
{
    int local_value = 1024;
    // 下面药多加一对括号，否则会被认定为函数的声明
    // 通过 move，我们就无需创建具名对象来创建 thread
    scoped_thread t((std::thread(func(local_value))));
    cout << "func() end" << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    Test();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

> 疑问？
>
> 为啥不把 ctor 里的 t 设置为右值引用呢？



#### 2.3.3 jpthread

``` C++
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

class thread_guard;
class scoped_thread;
struct func;

/*===========================*/

class joining_thread
{
public:
    joining_thread() noexcept = default; // ??
    template<typename Callable, typename ...Args>
    explicit joining_thread(Callable &&func, Args&& ...args)
        :t(std::forward<Callable>(func), std::forward<Args>(args) ...) // ???
        {}
    
    joining_thread(joining_thread &&other) noexcept
        : t(std::move(other.t))
        {}
    
    joining_thread(thread _t) noexcept
        : t(std::move(_t))
        {}

    joining_thread& operator=(joining_thread &&other) noexcept 
    {
        if(joinable())
        {
            join();
        }
        t = std::move(other.t);
        return *this;
    }

    // 为啥不是 thread &&t
    joining_thread& operator=(thread t) noexcept 
    {
        if(joinable())
        {
            join();
        }
        t = std::move(t);
        return *this;
    }


    ~joining_thread() noexcept
    {
        if(joinable())
            join();
    }

    void swap(joining_thread &other) noexcept
    {
        t.swap(other.t);
    }

    std::thread::id get_id() const noexcept
    {
        return t.get_id();
    }

    bool joinable() const noexcept 
    {
        return t.joinable();
    }
    
    void join()
    {
        return t.join();
    }

    void detach()
    {
        t.detach();
    }

    const std::thread& as_thread() const noexcept 
    {
        return t;
    }

    std::thread& as_thread() noexcept 
    {
        // 将 const thread& 的 const 属性去掉
        // 去掉 const 属性必须用 const_cast
        return const_cast<thread&>(
            // 将 &this 转换为 const 类型
            // 加上 const 属性用 static_cast
            static_cast<const joining_thread&>(*this).as_thread()
        );
    }

private:
    std::thread t;
};


void Test()
{
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    Test();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

> 疑问？
>
> 为啥不把 ctor 中的 `thread t` 改为 `thread &&t` 呢？





### 2.4 determin count of thread

`thread::hardware_concurrency()` ：返回并发线程的数量。

并行版的 `std::accumulate`

> 因为数据范围并不大，因此得出的时间消耗意义不大！

``` c++
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*===========================*/
/*      std::accumulate      */
/*    concurrency version    */
/*===========================*/

// just the warpped function of std::accumulate
template<typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        result = std::accumulate(first, last, result);
    }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    using cul_t = const unsigned long;
    using ul_t = unsigned long;

    cul_t length = std::distance(first, last);
    
    // special check
    if(!length)
        return init;

    cul_t min_pre_thread = 25; // 一个线程至少处理 25 个任务
    // 最大线程数为：任务总数 / 每个线程处理的任务数量，上取整
    cul_t max_threads = (length + min_pre_thread - 1) / min_pre_thread;
    
    cul_t hardware_thread = std::thread::hardware_concurrency();
    
    // 因为上下文切换的成本也很高，因此和系统真正的并发量取 min
    cul_t num_threads = std::min(hardware_thread != 0 ? hardware_thread : 2, max_threads);
    // 每个线程处理一个任务块
    cul_t block_size = length / num_threads;

    std::vector<T> results(num_threads); // result[num_threads-1] uesed to save finally result
    std::vector<std::thread> threads(num_threads - 1);

    // 分块 
    Iterator block_start = first;
    for(ul_t i = 0; i < num_threads - 1; ++ i )
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(
            accumulate_block<Iterator, T>(),
            block_start, block_end, std::ref(results[i])
        );
        block_start = block_end;
    }
    
    // 最终可能不满一个整块，即可能不能切好分为一个块
    accumulate_block<Iterator, T>()(
        block_start, last, results[num_threads - 1]
    );
    
    // 统计最终结果
    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
    return std::accumulate(results.begin(), results.end(), init);
}


int main()
{   
    PRINT_BEGIN;
    /*======================*/
    
    using ull = unsigned long long;
    vector<ull> num;
    ull sum;
    clock_t cur;
    const ull MAX_REP = 100;
    for(ull i = 0; i < MAX_REP; i ++ )
        num.push_back(i);

    // test std::accumulate
    cur = clock();
    sum = accumulate(num.begin(), num.end(), (ull)0);
    printf("time = %.4lf\n", (clock()-cur) * 1.0 / CLOCKS_PER_SEC);
    cout << "sum: " << sum << endl;
    
    // test concurrency accumulate
    cur = clock();
    sum = parallel_accumulate(num.begin(), num.end(), (ull)0);
    printf("time = %.4lf\n", (clock()-cur) * 1.0 / CLOCKS_PER_SEC);
    cout << "sum: " << sum << endl;
    /*======================*/
    PRINT_END;  
    return 0;
}
```







### 2.5 thread id

`thread::get_id()`：如果线程没有执行，会打印：`thread::id of a non-executing thread`

`this_thread::get_id()` ： 返回当前线程的 id

线程标识符可以用来比较，排序，哈希等。

通过线程标识符可以实现不同的线程执行不同的任务。

`get_id()` 的输出是依赖于实现的，但是C++ 标准规定相同 ID 的线程必须有相同的输出。



``` c++
#include <thread> // C++ Concurrency Library for thread's management

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*======================*/

thread::id master_thread_id;

void fun(int id)
{
    if(this_thread::get_id() == master_thread_id)
    {
        cout << "I am master" << endl;
    }
    else
    {
        cout << "I am slaver" << "[" << id << "]" << endl;
    }
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    vector<thread> threads;
    // create master
    thread master(fun, 0);
    master_thread_id = master.get_id();
    threads.push_back(move(master));    // must add move!
    // create slaver
    for(int i = 0; i < 8; i ++ )    threads.push_back(thread(fun, i + 1));
    // join
    for_each(threads.begin(), threads.end(), mem_fn(&thread::join));
    /*======================*/
    PRINT_END;  
    return 0;
}
```



## P3 data share 

### 3.1 problems

#### 3.1.1 race condition

条件竞争分为恶性条件竞争和良性条件竞争，良性条件竞争不会对系统有什么影响。

避免恶性条件竞争的方法：

1. 对数据结构采用某种保护机制，例如：mutex
2. 无锁数据结构
3. 事务

#### 3.1.2 use mutex to avoid RC

C++ 为我们提供了互斥量用来避免恶性条件竞争，我们可以通过实例化 `std::mutex` 创建互斥量，并通过 `lock()` 和 `unlock()` 进行上锁和解锁，但并不推荐你这么做，认为人总会犯错 😭

所以，类似智能指针，C++ 标准库为互斥量提供了一个 RAII 语法的模板类 `std::lock_guard`，其会在构造的时候自动上锁，并在析构的时候自动解锁。

他们都在 `<mutex>` 头文件当中。

示例程序：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*===========================*/

list<int> L; // shared data
mutex m;

void add_to_list(int value)
{
    lock_guard<mutex> guard(m);
    L.push_back(value);
}

bool list_contains(int value_to_find)
{
    lock_guard<mutex> guard(m);
    return find(L.begin(), L.end(), value_to_find) != L.end();
}

void Test()
{
    for(int i = 0; i < 5; i ++ )    L.push_back(i);
    cout << list_contains(3) << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    Test();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

但互斥量也不总是安全的，例如我们在一个类中返回了被保护数据的指针或引用时，会破坏对数据的保护，并且不会被互斥锁限制。

因此，对接口的设计需要相当谨慎，要确保互斥量能锁住任何对保护数据的访问，并且“不留后门”。

例如，在下面的程序当中，我们通过引用把被保护数据传递到互斥锁作用于之外，从而造成一个潜在的陷阱：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*===========================*/

class some_data 
{
    int a;
    string b;
public:
    void do_something()
    {
        cout << "You are a fool man😄...\n";
    }
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;
public:
    template<typename Function>
    void process_data(Function func)
    {
        lock_guard<mutex> l(m);
        func(data); // 传递“保护”数据给用户函数
    }
};

some_data *unprotected;

void malicious_function(some_data& protected_data)
{
    unprotected = &protected_data;
}

data_wrapper x;

void Foo()
{
    x.process_data(malicious_function);
    // 现在，我么将一个被保护的数据拿出来了，并且可以随意处理
    unprotected->do_something();
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    Foo();
    /*======================*/
    PRINT_END;  
    return 0;
}
```



### 3.2 mutex

#### 3.2.1 RC between interface

使用互斥量对数据进行保护并不能万事大吉。

例一：删除双链表中的一个节点

> 当我们要删除双链表中的节点 `P` 时，仅仅对 P 添加互斥量是不行的，还需要对 `P->next`, `P->prev` 同时添加互斥锁。

例二：堆栈

``` c++
stack<int> s;
void func()
{
    if(!s.empty()) // (1)
    {
        const int value = s.top(); // (2)
        s.pop();             // (3)
        do_something(value); 
    }
}
```

在上面的代码中，当堆栈非空时，我们希望从中取出栈顶素，再调用 `pop()`，但其实 (1) 和 (2) 之间是有竞争条件的，也就是说，可能存在一个线程在 (1) 与 (2) 之间也掉用了 `pop()`。

另一个潜在的竞争条件发正在 (2) 和 (3) 之间，可能有两个线程先后执行了 `top()`，但没有执行 `pop()`，此时两个线程处理后 `value` 的值可能是相同的，这种错误很难定位，因为程序没有出错，出错的是你的逻辑。

> 这就需要接口设计上有较大的改动，提议之一就是使用同一互斥量来保护 top()和 pop()。Tom Cargill[1]指出当一个对象的拷贝构造函数在栈中抛出一个异常，这样的处理方式就会有问题。在 Herb Sutter[2]看来，这个问题可以从“异常安全”的角度完美解决，不过潜在的条件竞争，可能会组成一些新的组合。



一个很有意思的事情是，我们可能不得不面临例二中的竞争条件。在堆栈的 pop 操作中（有返回值），如果我们直接把容器元素 ”移动“ 到目标位置，可能会因为 `bad_alloc` 异常，也就是内存不足而导致数据没有拷贝出去，并且栈中的数据也杯破坏了。

因此，设计人员通常把这个操作操作分为两部分：

1. top()
2. pop()

由此来确保数据不会在内存不足时出错，但我们之前讨论过了，在 1 和 2 之间，有竞争条件。

但幸好，我们还有其它选项，尽管他们也不是完美的。

**solution1：将变量的引用作为参数，传入 pop() 函数中取得想要的”弹出值“**

``` c++
std::stack<std::vector<int>> stk;
/*------------------------*/
std::vector<int> result;
stk.pop(result);
```

> 这种方法有明显的缺点：
>
> 1. 需要构造出一个栈中类型的实例用于接受目标值，这会导致空间和空间的额外开销等
> 2. 要求类型必须支持赋值操作，很多类型即使支持移动构造和拷贝构造，可能也不支持赋值

**solution2：无异常抛出的拷贝构造函数或移动构造函数**

**solution3：返回指向弹出值的指针**

**solution4：“选项1 + 选项2”或 “选项1 + 选项3”**



**Example： thread safe stack**

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

#define PRINT_BEGIN test_begin()
#define PRINT_END   test_end()

void test_end();
void test_begin();

/*===========================*/

struct empty_stack : exception
{
    const char * what() const noexcept
    {
        return "[Error] empty stack!"; // 不要添加格式控制符
    }
};

template<typename T>
class threadsaft_stack
{
public:
    threadsaft_stack() : data(std::stack<T>()) {}
    threadsaft_stack(const threadsaft_stack &other)
    {
        // 在函数体而不是成员初始化列表中copy可以确保数据的正确性
        std::lock_guard<std::mutex> lock(other.m);
        data = other.m;
    }

    // 不提供太多接口
    threadsaft_stack& operator=(const threadsaft_stack &) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty())    throw empty_stack();    // 检查是否为空

        // 在修改的堆栈前，分配出返回值
        const std::shared_ptr<T> res(std::make_shared<T>(std::make_shared<T>(data.top())));
        data.pop();
        return res;
    }

    void pop(T &value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty())    throw empty_stack();
        // 注意下面调用的都是 stack 的内置函数
        value = data.top();
        data.pop();
    }

    bool empty() const 
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }

private:
    std::stack<T> data;
    std::mutex m;
};

void Foo()
{
    threadsaft_stack<int> s;
    for(int i = 0; i < 100; i ++ )  s.push(i);
    cout << "push done" << endl;
    int x;
    s.pop(x);
    cout << x << endl;
}

int main()
{   
    PRINT_BEGIN;
    /*======================*/
    Foo();
    /*======================*/
    PRINT_END;  
    return 0;
}
```

> 其实本质上就是将原本的两个函数（top 和 pop）实现的操作集成到一个函数（pop）当中，这样就可以通过互斥量完成数据的保护。
>
> 通过一个函数修改我们的参数，很自然的有两种方式，一是返回值，而是传引用。
>
> 在返回值这种方式中，return 一个引用是危险的，这我们前面提到过。直接 return 值的话开销可能很大，因此我们考虑传出一个动态对象，而手动 new/delete 不安全，因此使用智能指针。



#### 3.2.2 deadlock

避免死锁的方法：

1. 指定获得锁的顺序
2. 一次性加全部锁
3. …

C++ 标准库的 `std::lock` 可以一次性锁住多个互斥量并且没有死锁风险。

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

struct bank_account
{
    explicit bank_account(int _balance) : balance(_balance) {}
    int balance;
    std::mutex m;
};

struct less_amount : std::exception
{
    const char* what()
    {
        return "Too little money in your amount ^ ^ !";
    }
};

void transfer(bank_account &from, bank_account &to, int amount)
{
    if(&from == &to)    return ;
    if(from.balance < amount)
    {
        throw(less_amount());
        return ;
    }

    std::lock(from.m, to.m);
    std::lock_guard lock1(from.m, std::adopt_lock);
    std::lock_guard lock2(to.m, std::adopt_lock);

    from.balance -= amount;
    to.balance += amount;
}

void Test()
{
    bank_account my_account(100);
    bank_account your_account(50);
    
    std::thread t1(transfer, std::ref(my_account), std::ref(your_account), 10);
    std::thread t2(transfer, std::ref(your_account), std::ref(my_account), 5);
    std::thread t3(transfer, std::ref(my_account), std::ref(my_account), 100);
    
    t1.join();
    t2.join();
    t3.join();
    
    std::cout << "my_account.balance = " << my_account.balance << "\n"
                "your_account.balance = " << your_account.balance << '\n';
}

int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```

虽然规定一个获得锁的顺序可以避免死锁，但他不是万能的，甚至说，会起到适得其反的效果，例如：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

struct bank_account
{
    explicit bank_account(int _balance) : balance(_balance) {}
    int balance;
    std::mutex m;
};

struct less_amount : std::exception
{
    const char* what()
    {
        return "Too little money in your amount ^ ^ !";
    }
};

void bank_swap(bank_account &from, bank_account &to)
{
    if(&from == &to)    return ;

    // std::lock(from.m, to.m);
    from.m.lock();
    
    // do something
    cout << "I get From, balance: " << from.balance << endl;
    sleep(5);   
    
    to.m.lock();

    std::lock_guard lock1(from.m, std::adopt_lock);
    std::lock_guard lock2(to.m, std::adopt_lock);

    swap(from.balance, to.balance);
}

void Test()
{
    bank_account my_account(100);
    bank_account your_account(50);
    
    std::thread t1(bank_swap, std::ref(my_account), std::ref(your_account));
    std::thread t2(bank_swap, std::ref(your_account), std::ref(my_account));

    t1.join();
    t2.join();
    std::cout << "my_account.balance = " << my_account.balance << "\n"
                "your_account.balance = " << your_account.balance << '\n';
}

int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```

在上面的例子中，我们虽然在 `swap()` 中规定了获得锁的顺序，但是如果我们交换了 `swap()` 的参数顺序，那么结果就很可怕了！

> [std::defer_lock, std::try_to_lock, std::adopt_lock](https://en.cppreference.com/w/cpp/thread/lock_tag)
>
> | `defer_lock_t` | 不获得互斥的所有权               |
> | -------------- | -------------------------------- |
> | try_to_lock_t  | 尝试获得互斥的所有权而不阻塞     |
> | adopt_lock_t   | 假设调用方线程已拥有互斥的所有权 |





**Advise to avoid deadlock：**

1. 避免嵌套锁，尽量只使用一个锁
2. 避免在持有锁时调用用户提供的代码
3. 使用固定顺序获取锁
4. 使用层级锁



#### 3.2.3 hierarchical_mutex

>  [reference](https://mysteriouspreserve.com/blog/2021/09/15/Hierarchical-Mutex/)

层级锁的意义在于：在运行时约定是否进行检查，这个建议需要对应用层进行分层，并且识别在给定层上所有互斥量。

层级锁的核心就是：每个互斥量有一个层级值，线程只能以层级值递减的顺序获取锁，由此实现顺序性。

**Sample complement: **

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

class hierarchical_mutex
{
public:
    explicit hierarchical_mutex(unsigned long value)
        : hierarchichy_value(value), 
          previous_hierarchichy_value(0)
        {}
    
    void lock()
    {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        // 备份层级值
        update_hierarchy_value();
    }

    void unlock()
    {
        // 恢复层级值
        this_thread_hierarchy_value = previous_hierarchichy_value;
        internal_mutex.unlock();
    }

    bool try_lock()
    {
        check_for_hierarchy_violation();
        if(!internal_mutex.try_lock())
            return false;
        update_hierarchy_value();
        return true;
    }


private:
    std::mutex internal_mutex;
    
    // 需要构造的锁的层级值
    unsigned long const hierarchichy_value;

    // this_thread_hierarchy_value 的备份
    // 因为在 unlock 之后需要恢复上一次的值
    unsigned long previous_hierarchichy_value;

    // 当前的层级值，第二个锁的层级值必须小于该值
    static thread_local unsigned long this_thread_hierarchy_value; 

    void check_for_hierarchy_violation()
    {
        // 如果需要构造的锁的层级值大于等于当前锁的层级值，不合法
        if(this_thread_hierarchy_value <= hierarchichy_value)
        {
            throw std::logic_error("mutex hierarchy violated");
        }

    }

    void update_hierarchy_value()
    {
        // 更新当前锁的层级值
        previous_hierarchichy_value = this_thread_hierarchy_value;
        this_thread_hierarchy_value = hierarchichy_value;
    }
};

// 不能加 static
thread_local unsigned long hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX);

hierarchical_mutex m1(1000);
hierarchical_mutex m2(10);

void f2()
{
    cout << "F2" << endl;
    lock_guard<hierarchical_mutex> lock(m1);
}

void f1()
{
    cout << "F1" << endl;
    lock_guard<hierarchical_mutex> lock(m2);
    f2();
}

int main()
{   
    PRINT_BEGIN;
    f1();
    PRINT_END;  
    return 0;
}
```

> 1. 初始化 static 成员时不能加 static，避免与 class 之外的 static 变量混淆
> 2. 为什么将 this_thread_hierarchy_value 设置为 thread_local static ? 只有这样才能实现动态更新层级，当我们更新了 this_thread_hierarchy_value 的值之后，下一个创建的 hierarchical_mutex 对象使用的是更新之后的值。例如：
>
> ``` c++
> #include <iostream>
> #include <cstring>
> #include <algorithm>
> 
> using namespace std;
> 
> struct Foo{
>     static int x;
> };
> 
> int Foo::x(1024);
> 
> int main()
> {
>     Foo f;
>     cout << f.x << endl;    // 1024
>     f.x = 233;
>     cout << f.x<< endl;     // 233
>     Foo g;
>     cout << g.x << endl;    // 233
>     cout << Foo::x << endl; // 233
>     return 0;
> }
> ```



#### 3.2.4 std::uniqie_lock

对 swap 函数的改写：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;


struct bank_account {
    explicit bank_account(int balance) : balance{balance} {}
    int balance;
    std::mutex m;
};
 
void my_swap(bank_account &from, bank_account &to)
{
    if(&from == &to) return; // avoid deadlock in case of self transfer
    
    // 将互斥量传入 unique 表示该互斥量应该保持解锁状态（不应该再被其他线程上锁）
    std::unique_lock<std::mutex> lock_a(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock_b(to.m, std::defer_lock);
    // std::defer_lock 留下未上锁的互斥量
    std::lock(lock_a, lock_b);
    std::swap(from.balance, to.balance);
}
 
void f()
{
    bank_account my_account{100};
    bank_account your_account{50};
 
    std::thread t1{my_swap, std::ref(my_account), std::ref(your_account)};
    std::thread t2{my_swap, std::ref(your_account), std::ref(my_account)};
    std::thread t3{my_swap, std::ref(my_account), std::ref(your_account)};

    t1.join();
    t2.join();
    t3.join();
 
    std::cout << "my_account.balance = " << my_account.balance << "\n"
                 "your_account.balance = " << your_account.balance << '\n';
}

int main()
{   
    PRINT_BEGIN;
    f();
    PRINT_END;  
    return 0;
}
```





#### 3.2.5  Passing of mutex ownership in different domains

`std::unique_lock` 实例没有与自身相关的互斥量，互斥量的所有权可以通过**移动操作**， 在不同的实例间传递。

… 看不懂在干啥 😭

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;


std::unique_lock<std::mutex> get_lock()
{
    extern std::mutex some_mutex;
    std::unique_lock<std::mutex> lock(some_mutex);
    cout << "get_lock()" << endl;
    return lock;
}

void process_data()
{
    std::unique_lock<std::mutex> lock(get_lock());
    cout << "process_data()" << endl;
    cout << "hello!" << endl;
}

int main()
{   
    PRINT_BEGIN;
    thread t(process_data);
    t.join();
    PRINT_END;  
    return 0;
}
```





#### 3.2.5 Lock Granularity

锁的粒度用来描述通过一个锁保护着的数据量大小。一个细粒度锁(a fine-grained lock) 能够保护较小的数据量，一个粗粒度锁(a coarse-grained lock)能保护较多的数据量。

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

class Y
{
// private:
public:
    int some_detail;
    mutable std::mutex m;
    int get_detail() const 
    {
        std::lock_guard<std::mutex> lock_a(m);
        return some_detail;
    }

public:
    Y() = default;
    Y(int _sd) : some_detail(_sd) {}

    friend bool operator==(const Y &lhs, const Y &rhs)
    {
        if(&lhs == &rhs)
            return true;
        const int lhs_value = lhs.get_detail(); // (1)
        cout << "I get lhs value:" << lhs_value << endl;;
        usleep(1);
        // 锁的粒度小，在得到lhs_value之后
        // rhs_value可能不是获取lhs_value瞬间的值
        // 他的值可能被修改
        const int rhs_value = rhs.get_detail();  // (2)
        cout << "I get rhs value!: " << rhs_value << endl;
        return lhs_value == rhs_value;
    }

};

std::thread::id master_id;

Y a[2];

void process(int id)
{
    if(this_thread::get_id() == master_id) 
    {
        for(int i = 0; i < 10; i ++ )
        {
            cout << "[" << i << "]I am master!: " << id << endl;
            cout << (a[0] == a[1] ? "Yes" : "No") << endl;
            usleep(1);
        }
    }
    else 
    {
        for(int i = 0; i < 10; i ++ )
        {
            cout << "[" << i << "]I am slaver: " << id << endl;
            a[id].some_detail = rand() % 10;
            usleep(1);
        }
    }
}

void Test()
{
    srand(time(NULL));
    a[0].some_detail = 1;
    a[1].some_detail = 2;
    thread master(process, -1);
    master_id = master.get_id();
    cout << master.get_id() << endl;
    thread slaver[2];
    slaver[0] = thread(process, 0);
    slaver[1] = thread(process, 1);
    master.join();
    slaver[0].join();
    slaver[1].join();
}

int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```





### 3.3 subsititute of shared data protect

#### 3.3.1 protect initialization process of data

假设我们有一个共享源，构建代价很昂贵，他可能会打开一个数据库连接或分配出很多的资源。

Lazy Initialization 在单线程代码中很常见 —— 没一个操作都需要对源进行检查，了解数据是否被初始化，然后在其使用前决定，数据是否需要初始化：

``` c++
class some_resources;
std::shared_ptr<some_resources> resources_ptr;
void Foo()
{
    if(!resources_ptr)
    {
        // lazy initialization
        resources_ptr.reset(new some_resources);
    }
    resources_ptr->do_something();
}
```

在多线程中，一种大粒度锁方法：

``` c++
class some_resources;
std::shared_ptr<some_resources> resources_ptr;
std::mutex resource_mutex;
void Foo()
{
    std::unique_lock<std::mutex> lock(resource_mutex);
    if(!resources_ptr)
    {
        resources_ptr.reset(new some_resources);
    }
    resources_ptr->do_something();
}
```

声名狼藉的“双重检查锁模式”:

``` c++
std::shared_ptr<some_resources> resources_ptr;
std::mutex resource_mutex;
void Foo()
{
    if(!resources_ptr)	// 第一次检查
    {
        // 在 if 与加锁之间，resources_ptr 可能被修改了
        std::lock_guard<std::mutex> lock(resource_mutex);
        if(!resources_ptr) // 第二次检查
        {
            resources_ptr.reset(new some_resources); // (1)
        }
    }
    resources_ptr->do_something(); // (2)
}
```

这个模式声名狼藉的原因在于，存在潜在的条件竞争。

> [具体的可以参考这里](https://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf)

论文太长，我粗略的看了一下，我们知道，new 是分为两步的：

1. operator new(size_of_object)
2. ctor
3. assign

文章给出代码如下所示：

``` c++
Singleton *Singleton::instance() {
    if (pInstance == 0) {
        Lock lock;
        if (pInstance == 0) {
            pInstance =               // Step 3
            operator new(sizeof(Singleton)); // Step 1
            new (pInstance) Singleton;    // Step 2
        }
    }
    return pInstance;
}
```

文章的意思应该是，在 ctor 之前，对象还没被构建，此时指向它的指针为空，即使 ctor 完成了，我们还需要将其地址赋值给指向它的指针，而在ctor与assign之间，指针依然为空。

指针为空就意味着，第二次检查不一定是有效的，也即，仍然可能有多个线程进入 (1) 从而破坏数据，并且行为是未定义的！

----

为了解决这种条件竞争，C++ 标准库提供了 `std::once_flag` 和 `std::call_once` ，并且使用 `std::call_one` 比使用互斥量消耗的资源更少。

> `std::call_once` : 顾名思义，可以准确执行一次 callable object，其通过 `std::once_flag` 来判断是否被执行过，如果多次调用，会抛出异常。
>
> call_one 分为:
>
> 1. active call：第一次调用
> 2. passive call：后序调用
> 3. exceptional call：抛出异常的调用，不会修改 once_flag

例如：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

std::once_flag flag1, flag2;

void simple_do_once()
{
    std::call_once(flag1, [](){
        std::cout << "Simple example: call one\n";
    });
}

void may_throw_function(bool do_throw)
{
    if(do_throw)
    {
        std::cout << "throw: call once will retry\n";
        throw std::exception();
    }
    std::cout << "Do no throw: call once will not attempt retry\n";
}

void do_once(bool do_throw)
{
    try
    {
        std::call_once(flag2, may_throw_function, do_throw);
    }
    catch(...) 
    {
        cout << "get exception\n";
    }
}

void Foo()
{
    std::thread st1(simple_do_once);
    std::thread st2(simple_do_once);
    std::thread st3(simple_do_once);
    std::thread st4(simple_do_once);
    st1.join();
    st2.join();
    st3.join();
    st4.join();
    /**/
    std::thread t1(do_once, true);
    std::thread t2(do_once, true);
    std::thread t3(do_once, false);
    std::thread t4(do_once, true);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

int main()
{   
    PRINT_BEGIN;
    Foo();
    PRINT_END;  
    return 0;
}
```

由此，可以将上面的例子修改为：

``` c++
std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;  // 1
void init_resource()
{
	resource_ptr.reset(new some_resource);
}
void foo() 
{
	std::call_once(resource_flag,init_resource); // 可以完整的进行一次初始化
	resource_ptr->do_something();
}
```



一个例子：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>

using namespace std;

struct X
{
    std::once_flag flag;
    void do_once()
    {
        cout << "do once" << endl;
    }
    void f1()
    {   
        cout << "f1" << endl;
        std::call_once(flag, &X::do_once, this);
    }
    void f2()
    {
        cout << "f2" << endl;
        std::call_once(flag, &X::do_once, this);
    }
};

void Foo()
{
    X x;
    x.f1();
    x.f2();
}

int main()
{   
    PRINT_BEGIN;
    Foo();
    PRINT_END;  
    return 0;
}
```

输出结果为: 

``` 
f1
do once
f2
```

---

局部 static 变量的线程安全的初始化方式（`std::call_once` 的替代方案）

``` c++
class my_class;
my_class& get_my_class_instance()
{
    static my_class instance;
    return instance;
}
```

初始化和定义完全在一个线程中发生，并且没有其他线程可在初始化完成前对其进行处理。

其实这个就是例子设计模式(**Singleton**)的思路，让 static 变量在函数内部完成初始化，从而使得调用该对象时，该对象一定被初始化。

但是为什么呢？

其实主要是因为**“C++只能保证在同一个文件中声明的static变量的初始化顺序与其变量声明的顺序一致。但是不能保证不同的文件中的static变量的初始化顺序。”**

然后对于单例模式而言，不同的单例对象之间进行调用也是常见的场景。比如我有一个单例，存储了程序启动时加载的配置文件的内容。另外有一个单例，掌管着一个全局的日志管理器。在日志管理初始化的时候，要通过配置文件的单例对象来获取到某个配置项，实现日志打印。

这时候两个单例在不同文件中各自实现，很有可能在日志管理器的单例使用配置文件单例的时候，配置文件的单例对象是没有被初始化的。这个未初始化可能产生的风险指的是C++变量的未初始化，而不是说配置文件未加载的之类业务逻辑上的未初始化导致的问题。

而`Meyers' Singleton`写法中，单例对象是次访问的时候（也就是次调用`getInstance()`函数的时候）才初始化的，但也是恰恰因为如此，因而能保证如果没有初始化，在该函数调用的时候，是能完成初始化的。所以先`getInstance()`再访问 这种形式的单例 其关键并不是在于这个形式。而是在于其内容，局部static变量能保证通过函数来获取static变量的时候，该函数返回的对象是肯定完成了初始化的！

另外，该写法需要 C++11 的支持，因为在 C++11 之后，static 变量的初始化是线程安全的。

> [「详细信息参考这里—reference」](https://z.itpub.net/article/detail/DC3250F681713244F01A546413CC2828)

#### 3.3.2 protect data struct which updatelessly

对于更新比较少，读取频繁的数据结构，使用 `std::mutex` 显得有些反应过激了，因为在没有修改时，它将削弱并发读取数据的可能性，因此，这里需要一种不同的互斥量 – 读写锁：一个“写”线程独立访问，多个 “读” 线程并发访问。

C++ 标准库暂时没有提供“读者-写者锁”，但是 Boost 库提供了支持 `boost::shared_lock` (读写锁)，通常用于读操作比较频繁的，而写操作比较少的情况。

读写锁比起mutex具有更高的适用性，具有更高的并行性，可以有多个线程同时占用读模式的读写锁，但是只能有一个线程占用写模式的读写锁，读写锁的基本规则可以总结为**“write first，read shared，cross mutex(交叉互斥)”**，具体表现为读写锁的三种状态：

1. 当读写锁是写加锁状态时，在这个锁被解锁之前，所有试图对这个锁加锁的线程都会被阻塞。（交叉互斥）
2. 当读写锁在读加锁状态时，所有试图以读模式对它进行加锁的线程都可以得到访问权，但是以写模式对它进行加锁的线程将会被阻塞。（读共享，交叉互斥）
3. 当读写锁在读模式的锁状态时，如果有另外的线程试图以写模式加锁，读写锁通常会阻塞随后的读模式锁的请求，这样可以避免读模式锁长期占用，而等待的写模式锁请求则长期阻塞。（写优先）

注：其实在读者-写者问题中，有读者优先和写者优先两种模式，只是在 **shared_mutex which in boost library default complement in writing first**，这其实也是有道理的，**because we always want to read the least data**，这就得保证写者优先。

例子：模拟 dns 缓存的修改和查询

``` c++
#include <boost/thread/shared_mutex.hpp>

using namespace std;

class dns_entry
{
    string domain;
    string ip_addr;
    /*....*/
};

class dns_cache 
{
private:
    std::map<std::string, dns_entry> entries;   // 缓存 dns 数据
    mutable boost::shared_mutex entry_mutex;    // 对数据进行保护

public:
    // from domin name to IP addr
    dns_entry find_entry(const std::string &domain) const 
    {
        boost::shared_lock<boost::shared_mutex> lk(entry_mutex); // 加读锁
        auto it = entries.find(domain);
        return (it == entries.end()) ? dns_entry() : it->second;
    }

    void update_or_addr_entry(const std::string &domain, const dns_entry &dns_details)
    {
        std::lock_guard<boost::shared_mutex> lock(entry_mutex); // 加写锁
        // or add unique_lock<boost::shared_mutex>
        entries[domain] = dns_details;
    }

};
```



#### 3.3.3 nested lock

`std::recursive_mutex`



## P4 synchronization 

单单将数据保护起来并不能满足我们的需求。通常情况下，我们还想对单独的线程进行同步。例如，某个线程作为另一个线程的输入。

通过条件变量(**condition variables**)和期望(**futures**)实现线程之间的同步。



### 4.1 wait event or condition

#### 4.1.1 introduce

情景：我们需要等待一个事件。

最笨的方法是一直加锁，然后时间来临之后，处理事件，解锁。但是这种方法是很低效的，因为等待事件时我们持有锁但什么也不做。

进步的方法是下面这种（`std::this_thread::sleep_for()`），每隔一段时间就进行一次检查，但是这种方法的问题是，很难确定中间间隔的时间，太短或者太长了都不好！

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex, std::mutex_guard

#include <myheader.h>
#include <boost/thread/shared_mutex.hpp>

using namespace std;

bool flag;
std::mutex m;

void wait_for_flag()
{
    std::unique_lock<std::mutex> lk(m);
    while(!flag)
    {
        lk.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));    // 100ms
        lk.unlock();
    }
}

int main()
{   
    PRINT_BEGIN;
    wait_for_flag();
    PRINT_END;  
    return 0;
}
```

最好的办法就是使用条件变量，当时间发生时，广播“条件达成”的信息，由此出发等待该事件的线程。



#### 4.1.2 condition variable

C++标准库对条件变量有两套实现：`std::condition_variable`和`std::condition_variable_any`。这两个实现都包含在`<condition_variable>`头文件的声明中。两者都需要与一个互斥量一起才能工作(互斥量是为了同步)；前者仅限于与`std::mutex`一起工作，而后者可以和任何满足最低标准的互斥量一起工作，从而加上了*_any*的后缀。因为`std::condition_variable_any`更加通用，这就可能从体积、性能，以及系统资源的使用方面产生额外的开销，所以`std::condition_variable`一般作为首选的类型，当对灵活性有硬性要求时，我们才会去考虑`std::condition_variable_any`。

下面是使用 `std::condition_variable` 处理等待数据

``` c++
class data_chunk {/*...*/};
bool more_data_to_prepare();
const data_chunk& prepare_data(); 
bool is_last_chunk(const data_chunk&);
void process(data_chunk&);

std::mutex mut;
std::queue<data_chunk> data_queue;
std::condition_variable data_cond;

void data_preparation_thread()
{
    while(more_data_to_prepare())
    {
        const data_chunk data = prepare_data();
        std::lock_guard<std::mutex> lock(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
}

void data_preocessing_thread()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, []{ // (1) 在这上锁 类似 try_lock
            return !data_queue.empty();
        });
        data_chunk data = data_queue.front();
        data_queue.pop();
        lock.unlock();	// (2) 记得解锁
        process(data);
        if(is_last_chunk(data))
            break;
    }
}
```

在 (1) 中，如果条件不满足(`lambda` 返回 `false`)，`wait()` 函数将解锁互斥量，并将这个线程置于阻塞或等待状态。

当在 `data_preparation_thread` 中调用 `notify_one` 通知条件变量之后，处理数据的线程从睡眠状态中苏醒，重新获得互斥锁，并且对条件再次检查，当条件不满足时，线程将对互斥量解锁，并且重新开始等待，当条件满足时，从 `wait()` 返回并继续持有锁。

> 注意在唤醒之后需要再次检查条件，因为可能还有其他线程也被唤醒，此时会有竞争。这就是所谓的**伪唤醒(spurious wakeup)**，

这也是为甚么要使用 `std::unique_lock` 而不是 `std::lock_guard` 的原因 —— 等待中的线程必须在等待期间解锁互斥量，并在这之后对互斥量再次上锁，而 `std::lock_guard` 没有这么灵活。

> 其实这也说明了 `std::unique_lock` 的主要用途 —— 和 `std::condition_variable` 配合使用，做到多次 `lock()` 和 `unlock()`。



#### 4.1.3 thread safety queue

`std::queue` 接口

``` c++

template<class T, class Container = std::deque<T>>
class queue
{
public:

    explicit queue(const Container&);
    explicit queue(Container&& = Container());

    template <class Alloc> explicit queue(const Alloc&);
    template <class Alloc> queue(const Container&, const Alloc&);
    template <class Alloc> queue(Container&&, const Alloc&);
    template <class Alloc> queue(queue&&, const Alloc&);

    void swap(queue &q);

    bool empty() const ;
    size_t size() const ;

    T& front();
    const T& front() const ;
    T& back();
    const T& back() const ;

    void push(const T& x);
    void push(T&& x);
    
    void pop();
    template<class... Args> void emplace(Args&&... args);
};
```

线程安全的队列

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any

#include <myheader.h>

using namespace std;

template<typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut; // 互斥量必须是可变的
    std::queue<T> data_queue;
    std::condition_variable data_cond;

public:
    threadsafe_queue() = default;

    threadsafe_queue(const threadsafe_queue& other)
    {
        lock_guard<std::mutex> my_lock(mut);    // 为什么不对自己上锁呢？
        std::lock_guard<std::mutex> lock(other.mut);
        data_queue = other.data_queue;
    }

    threadsafe_queue(threadsafe_queue&& other) // 自己写的，可能有误？
    {
        lock_guard<std::mutex> my_lock(mut);    // 为什么不对自己上锁呢？
        std::lock_guard<std::mutex> lock(other.mut);
        data_queue = move(other.data_queue);
    }
    
    threadsafe_queue& operator=(const threadsafe_queue&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }
    
    bool try_pop(T &value) // 通过传引用获得 front 并 pop
    {
        // 防止 front-pop 接口之间存在的竞争条件
        std::lock_guard<std::mutex> lock(mut);
        if(data_queue.empty())
            return false;
        value = data_queue.front(); // get value
        data_queue.pop();
        return true;
    }

    std::shared_ptr<T> try_pop() 
    {
        std::lock_guard<std::mutex> lock(mut);
        if(data_queue.empty())
            return std::shared_ptr<T>();    // NULL
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    void wait_and_pop(T &value)
    {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, [this]{
            return !data_queue.empty();
        });
        value = data_queue.front();
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, [this]{
            return !data_queue.empty();
        });
        std::shared_ptr<T> res = (std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    bool empty() const 
    {
        std::lock_guard<std::mutex> lock(mut);
        return data_queue.empty();
    }

    size_t size() const 
    {
        std::lock_guard<std::mutex> lock(mut);
        return data_queue.size();
    }
};

int main()
{   
    PRINT_BEGIN;

    PRINT_END;  
    return 0;
}
```

同之前提到的一样，当我们执行 `front()-pop()` 时，会有接口之间的条件竞争，因此我们需要将这两个函数放到同一个函数中。



### 4.2 future 

#### 4.2.1 introdece

C++ 标准库模型将这种一次性事件成为**期望(future)**。当事件发生时，这个“期望”就不能被重置。

在C++标准库中，有两种“期望”，使用两种类型模板实现，声明在头文件中: 唯一*期望*(unique futures)(`std::future<>`)和*共享期望*(shared futures)(`std::shared_future<>`)。这是仿照`std::unique_ptr`和`std::shared_ptr`。`std::future`的实例只能与一个指定事件相关联，而`std::shared_future`的实例就能关联多个事件。后者的实现中，所有实例会在同时变为就绪状态，并且他们可以访问与事件相关的任何数据。这种数据关联与模板有关，比如`std::unique_ptr` 和`std::shared_ptr`的模板参数就是相关联的数据类型。在与数据无关的地方，可以使用`std::future<void>`与`std::shared_future<void>`的特化模板。虽然，我希望用于线程间的通讯，但是“期望”对象本身并不提供同步访问。当多个线程需要访问一个独立“期望”对象时，他们必须使用互斥量或类似同步机制对访问进行保护，如在第3章提到的那样。不过，在你将要阅读到的4.2.5节中，多个线程会对一个`std::shared_future<>`实例的副本进行访问，而不需要期望同步，即使他们是同一个异步结果。

最基本的一次性事件，就是一个后台运行出的计算结果。在第2章中，你已经了解了`std::thread` 执行的任务不能有返回值，并且我能保证，这个问题将在使用“期望”后解决——现在就来看看是怎么解决的。



#### 4.2.2 background task with return value — async

假设，你现在有一个需要长时间的运算，你需要能计算出一个有效的值，但是你现在并不迫切需要这个值。因为 `std::thread` 并不提供接受返回值的机制，这里就需要 `std::async` 函数模板（也就是在 `<future>` 中声明）

当不着急得到任务的结果时，你可以使用 `std::async` 启动一个**异步**任务，与 `std::thread` 对象等待的方式不同，`std::async` 会返回一个 `std::future` 对象，这个对象持有最终计算出来的结果，你只需要调用这个对象的 `get()` 成员函数；并且会阻塞线程直到“期望”状态未就绪为止。例如：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future>

#include <myheader.h>

using namespace std;

int find_the_answer_to_ltuae()
{
    int value = 1024;
    /* do something */
    return value;
}

int main()
{   
    PRINT_BEGIN;
    std::future<int> the_answer = std::async(find_the_answer_to_ltuae);
    /* do something */
    std::cout << "The answer is " << the_answer.get() << std::endl;
    PRINT_END;  
    return 0;
}
```

与 `std::thread` 方式一样，`std::async` 允许通过添加额外的调用参数，想函数传递额外的参数。

例如，第一个参数是指向成员函数的指针，第二个参数是提供这个函数成员类的具体对象。

和 `std::thread` 一样，当参数是右值时，拷贝操作将使用移动的方式转移原始数据。

我们还可以在调用之前向 `std::async` 传递一个额外参数，这个参数的类型是 `std::launch`，它提供了两种策略可供选择：

* `std::launch::async` ：在调用 `std::async` 之后就开始创建线程
* `std::launch::deferred` ： 延迟加载方式创建线程。调用 `std::async` 不创建线程，直到调用了 `future` 的 `get()` 或者 `wait()` 时才创建线程。（**lazy calculate**）

默认策略是 `std::launch::async | std::launch::deferred`

例如：

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

struct X
{
    void foo(int i, const std::string& s)
    {
        i ++ ;
        cout << "[" << s << "] id: " << std::this_thread::get_id() << endl;
    }
    std::string bar(const std::string& s)
    {
        cout << "[" << s << "] id: " << std::this_thread::get_id() << endl;
        return s;
    }
} x;

// f1 和 f2 可能在 main 结束之后才执行

// 通过指向 x 的指针调用 foo
auto f1 = std::async(&X::foo, &x, 42, "f1");
// 通过 x 的拷贝调用 bar
auto f2 = std::async(&X::bar, x, "f2");

/*=============================================*/

struct Y
{
    std::string operator()(const std::string s)
    {
        // std::cout << d << std::endl;
        cout << "[" << s << "] id: " << std::this_thread::get_id() << endl;
        return s;
    }
} y;

// 通过 y 的移动构造函数调用 operator()
auto f3 = std::async(Y(), "f3");
// 通过 y 的引用调用 operator()
auto f4 = std::async(std::ref(y), "f4");

/*=============================================*/
class move_only
{
public:
    move_only() = default;
    move_only(move_only&&) = default;
    move_only(const move_only&) = delete;
    move_only& operator=(move_only&&) = default;
    move_only& operator=(const move_only&) = delete;
    void operator()(const std::string s) {
        cout << "[" << s << "] id: " << std::this_thread::get_id() << endl;
        std::cout << "Move only!" << std::endl;
    }
};

auto f5 = std::async(move_only(), "f5");

/*=============================================*/

// 在新线程上执行
auto f6 = std::async(std::launch::async, Y(), "f6");
// 在 wait() 或 get() 调用时执行
auto f7 = std::async(std::launch::deferred, &X::bar, std::ref(x), "f7");
// 实现选择执行方式
void f(const std::string s)
{
    cout << "[" << s << "] id: " << std::this_thread::get_id() << endl;
}
auto f8 = std::async(std::launch::deferred | std::launch::async, f, "f8");

int main()
{   
    PRINT_BEGIN;
    // f7.wait();
    cout << "main: " << hex << std::this_thread::get_id() << endl;
    // f8.get();
    PRINT_END;  
    return 0;
}
```

`std::future` 有三种状态：

* `future_status::deferred`：异步操作还未完成
* `future_status::ready` ：异步操作已经完成
* `future_status::timeout` ：异步操作超时，主要用于 `std::future<T>.wait_for()`

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

void process()
{
    cout << "step1" << endl;
    sleep(3);
    cout << "step2" << endl;
    sleep(3);
    cout << "step3" << endl;
    sleep(3);
}

int main()
{   
    PRINT_BEGIN;
    std::future_status status;
    auto f = std::async(std::launch::deferred ,process);
    do {
        status = f.wait_for(std::chrono::seconds(1));
        if(status == std::future_status::deferred) {
            cout << "deferred" << endl;
            // f.wait();
        }
        else if(status == std::future_status::timeout) {
            cout << "timeout" << endl;
        }
        else if(status == std::future_status::ready) {
            cout << "ready" << endl;
        }
    } while(status != std::future_status::ready);
    PRINT_END;  
    return 0;
}

```

> [reference](https://segmentfault.com/a/1190000039083151)



#### 4.2.3 task and future

`std::packaged_task<>` 会将 `future` 与函数或可调用对象进行绑定。当调用 `package_task<>` 时，就会调用相关函数或可调用对象，当 `future` 状态未就绪时，会存储返回值。

`std::packaged_task<>` 的模板参数是一个函数签名。我们传入对象的签名可以与模板参数中指定的签名不一致，但是必须能隐式转换到目标类型。

例如，一种便特化的 `packaged_task` 的意义如下：

``` c++
template<>
class packaged_task<std::string(std::vector<char*>, int)>
{
public:
    template<typename Callable>
    explicit packaged_task(Callable &&f);
    std::future<std::string> get_future();
    void operator()(std::vector<char*>, int);
};
```

`std::packaged_task` 是一个可调用对象，可以封装在 `std::function` 对象中，从而作为汉城函数传递到 `std::thread` 对象中，或作为可调用物对象传递到另一个函数中或直接调用。

例子1：

``` c++
#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>
std::mutex m;
std::deque<std::packaged_task<void()> > tasks;
bool gui_shutdown_message_received();
void get_and_process_gui_message();
void gui_thread()  // 1
{
  while(!gui_shutdown_message_received())  // 2
  {
    get_and_process_gui_message();  // 3
    std::packaged_task<void()> task;
    {
      std::lock_guard<std::mutex> lk(m);
      if(tasks.empty())  // 4
        continue;
      task=std::move(tasks.front());  // 5
      tasks.pop_front();
    }
    task();  // 6
  }
}
std::thread gui_bg_thread(gui_thread);
template<typename Func>
std::future<void> post_task_for_gui_thread(Func f)
{
  std::packaged_task<void()> task(f);  // 7
  std::future<void> res=task.get_future();  // 8
  std::lock_guard<std::mutex> lk(m);  // 9
  tasks.push_back(std::move(task));  // 10
  return res;
}
```

c++ reference 上的例子 2：

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

int my_add(int x, int y) { return x + y; }
 
void task_lambda()
{
    std::packaged_task<int(int, int)> task([](int a, int b){
        return a + b;
    });
    std::future<int> res = task.get_future();
    task(2, 9);
    cout << "task_lambda: " << res.get() << endl;
}

void task_bind()
{
    // 注意下面packaged_task的函数签名对应的参数要与bind对应 
    std::packaged_task<int()> task(std::bind(my_add, 2, 11));
    std::future<int> res = task.get_future();
    task();
    cout << "task_bind: " << res.get() << endl;
}

void task_thread()
{
    std::packaged_task<int(int, int)> task(my_add);
    std::future<int> res = task.get_future();
    // move 到线程当中
    std::thread task_td(std::move(task), 2, 9);
    task_td.join();
    cout << "task_thread: " << res.get() << endl;
}

int main()
{   
    PRINT_BEGIN;
    task_lambda();
    task_lambda();
    task_thread();
    PRINT_END;  
    return 0;
}
```

解释一下：`std::future<int> result = task.get_future();` 这条语句并不会导致 `task` 封装的可调用对象的执行，它仅仅是将 `task` 的返回值存储到 `result` 这个对象当中。

> 参考： 
>
> [Zhihu](https://zhuanlan.zhihu.com/p/611029683)
>
> [Cpp-reference](https://zh.cppreference.com/w/cpp/thread/packaged_task)

#### 4.2.4 std::promises

cppreference 例1:

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

void accumulate(std::vector<int>::iterator first, std::vector<int>::iterator last, 
                std::promise<int> accumulate_promise)
{
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);
}

void do_work(std::promise<void> barrier)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    barrier.set_value(); // 注释掉改行不会阻塞
}

int main()
{   
    PRINT_BEGIN;
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    std::promise<int> accumulate_promise;
    std::future<int> accumulate_future = accumulate_promise.get_future();
    // 加上 :: ，防止识别为 std::accumulate
    std::thread work_thread(::accumulate, numbers.begin(), numbers.end(), std::move(accumulate_promise));
    
    // future::get() 将等待直至该 future 拥有合法结果并取得它
    // 无需在 get() 前调用 wait()

    cout << "Result: " << accumulate_future.get() << endl;
    work_thread.join();

    // 用 primise<void> 在线程间对状态发信号
    std::promise<void> barrier;
    std::future<void> barrier_future = barrier.get_future();
    std::thread new_work_thread(do_work, std::move(barrier));
    barrier_future.wait();
    new_work_thread.join();

    PRINT_END;  
    return 0;
}
```

例2: 线程等待另一个线程的数据

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

void Test()
{
    std::promise<int> promise = std::promise<int>();
    
    auto t1 = std::thread([&promise]{
        cout << "thread running\n";
        // do something ~
        std::this_thread::sleep_for(chrono::seconds(2)); 

        // write data and invoke the threads which are waiting for that
        promise.set_value(42);	// 注释掉改行会阻塞
        cout << "thread end\n";
    });

    // block until get value
    cout << promise.get_future().get() << endl;
    
    t1.join();
}
int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```

> **[TODO]**
>
> 在这里我发现了一个神奇的事情，如果是按照上面的形式（例2）即，lambda 表达式的形式创建线程，如果不 set_value() 的话，future::wait() 会一直等待，而使用显式的函数则不会（例1），为什么呢？



> 参考：
>
> [JianShu](https://www.jianshu.com/p/6300e02d0625#)
>
> [Cpp-reference](https://en.cppreference.com/w/cpp/thread/promise)

#### 4.2.5 exception and future

如果我们抛出一个异常，那么这个异常会存储到 `future` 中，然后 `future` 的状态设置为 `ready`，之后调用 `get()` 会抛出已存储的异常。

> 注意！标准并未规定重新抛出的这个异常是原对象还是一份拷贝，这取决于山西i安



``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

double my_sqrt(double x)
{
    if(x < 0)
    {
        cout << "out of range ^ ^\n";
        throw std::out_of_range("x < 0");
    }
    return sqrt(x);
}

void Test()
{
    // 将 promise 与 future 绑定起来
    std::promise<double> promise;
    std::future<double> future = promise.get_future();
    try
    {
        cout << "pls input a number: ";
        double x;       
        cin >> x;
        promise.set_value(my_sqrt(x));
    }
    catch(const exception &e)
    {
        // promise.set_exception(current_exception());
        promise.set_exception(std::make_exception_ptr(logic_error("sqrt() error ^ ^")));
    }
    cout << future.get() << endl;
}

int main()
{   
    PRINT_BEGIN;
    Test();
    return 0;
}
```





#### 4.2.6 waiting of multiple thread

如果并行代码没办法让多个线程等待同一个事件， `std::shared_future `可以帮你解决这个问题。因为`future`是只 **move** 的，所以其所有权可以在不同的实例中互相传递，但只有一个实例可以获得特定的同步结果，而 `std::shared_future`实例是可 **copy** 的，所以多个对象可以引用同一关联期望值的结果。

例: std::shared_future

`std::shared_future` 顾名思义，就是多个线程共享一个 `std::shared_future`。可用在一个线程传递数据给多个线程的时候，多个线程在自身的线程空间内通过 `std::shared_future` 共享一个 `future`，这是线程安全的。

``` C++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

int main()
{   
    PRINT_BEGIN;
    using namespace std::literals;
    auto promise = std::promise<int>();

    auto t1 = std::thread([&promise]{
        cout << "thread 1 running\n";
        std::this_thread::sleep_for(std::chrono::seconds(4));
        // 写入数据，这回唤醒那些正在等待数据的线程
        promise.set_value(42);
        cout << "thread 1 end\n"; 
    });

    auto shared_future = std::shared_future<int>(promise.get_future());

    auto t2 = std::thread([shared_future]{
        cout << "thread 2 running\n";
        // 获取数据，如果数据还没准备好就会阻塞
        // 这里使用 std::printf 而不是 std::cout 是为了保证输出在同一行
        std::printf("thread: 2 %d\n", shared_future.get());
        cout << "thread 2 end\n";
    });
    std::printf("Test: %d\n", shared_future.get());
    t1.join();
    t2.join();
    PRINT_END;  
    return 0;
}
```

> `std::shared_future::get` 可以无限次调用，而 `std::future::get` 仅能调用一次。
>
> `std::shared_future::get` 返回的一定是引用（模板参数是 `void` 的除外）

在每一个`std::shared_future`的独立对象上成员函数调用返回的结果还是不同步的，所以为了在多个线程访问一个独立对象时，避免数据竞争，必须使用锁来对访问进行保护。优先使用的办法：为了替代只有一个拷贝对象的情况，可以让每个线程都拥有自己对应的拷贝对象。这样，当每个线程都通过自己拥有的`std::shared_future`对象获取结果，那么多个线程访问共享同步结果就是安全的。

``` c++
#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async

#include <myheader.h>

using namespace std;

int main()
{   
    PRINT_BEGIN;
    using namespace std::literals;
    // 注意 promise 只能 set 一次
    auto promise = std::promise<int>();
    auto shared_future = std::shared_future<int>(promise.get_future());
    
    auto f = [&promise, shared_future](int x){
        cout << "thread " << x << " running\n";
        if(x)
            cout << "value: " << shared_future.get() << endl;
        else 
            promise.set_value(x);
        cout << "thread " << x << " end\n";
    };

    vector<thread> threads;
    for(int i = 0; i < 10; i ++ )
    {
        auto t = std::thread(f, i);
        threads.push_back(move(t));
    }

    std::printf("Test: %d\n", shared_future.get());
    for(auto &t : threads)  t.join();
    PRINT_END;  
    return 0;
}
```



### 4.3 time limited wait

#### 4.3.1 introduce

Sometimes, it is needed to limited the wating time of the wait thread.

There are two ways to signated if timeout:

1. time duration(relative): you are expected to signated a duration of time like: 30s
2. time point(absolute): you are expected to signated a concrete  time like: `[UTC] 17:40:15.034583458`, `2011-11-30` 

The variable which used for relative time  suffixed by `_for`, and other used for absolute time suffixed by `_until`

Before observe the usage of timeout funtion, let’s check the way to signated the time in C++

#### 4.3.2 clock

`#include <chrono>`

对于 C++ 来说，时钟就是时间信息源。并且，时钟是一个 `class`，提供了四种不同的信息：

1. 当前时间：`std::chrono::system_clock::now()` 会返回系统的当前时间，它属于 `time point`.
2. 时间类型
3. 时钟节拍：`std::chrono::high_resolution_clock` 可能是标准库中提供的具有最小节拍周期（因此具有最高的精度）的时钟。
4. 稳定时钟：`std::chrono::steady_clock`



#### 4.3.3 ratio

先介绍一下 `std::ratio`，他定义在 `<ratio>` 头文件当中。

``` c++
template<intmax_t N, intmax_t D = 1>
class ratio {
public:
    typedef ratio<num, den> type;
    static constexpr intmax_t num;  // 分子
    static constexpr intmax_t den;  // 分母
};
```

具体的可以参考 [cppreference](https://zh.cppreference.com/w/cpp/header/ratio)

``` c++
#include <myheader.h>
#include <ratio> // !

using namespace std;

int main()
{   
    PRINT_BEGIN;
    using two_third = std::ratio<2, 3>;
    using one_six   = std::ratio<1, 6>;
    
    using sum = std::ratio_add<two_third, one_six>;
    // exppect print 5/6
    std::cout << "2/3 + 1/6 = " << sum::num << '/' << sum::den << endl;
    PRINT_END;  
    return 0;
}
```

#### 4.3.4 literal

在 C++14 中的 `namespace std::chrono_literals` 中预定义了许多后缀操作符用来表示时长中的常用单位来简化代码。同样，还用用于表示字符串的 `namespace std::string_literals` 等。

例如：

``` c++
#include <myheader.h>

using namespace std;

void Test1()
{
    // d 和 y 是 C++20 提供的
    using namespace string_literals;
    auto one_day = 24h;
    auto half_an_hour = 30min;
    auto half_a_minuter = 30s;
    // 不常用的还有 ms（微秒）, us（微秒）, nm（纳秒）, 
    // 1s = 1e3ms(毫秒) = 1e6us(微秒) = 1e9ns(纳秒) = 1e12ps(皮秒)

    // auto 的类型是：
    std::chrono::milliseconds ms = 1s;
    cout << ms.count() << "ms" << endl;
}

void Test2()
{
    using namespace chrono_literals;
    string s = "hello"s; // suffix by x
}

int main()
{   
    PRINT_BEGIN;
    Test1();
    Test2();
    PRINT_END;  
    return 0;
}
```

#### 4.3.5 time duration

``` C++
template<class Rep, class Period = std::ratio<1>>
class duration;
// Rep: 表示计数的算数类型
// Period：表示计次周期的 std::ratio(即每秒的次数)
```

通俗来讲，`Period` 指定的是 `duration` 的单位，默认是 `1s`,例如，如果 `Period` 指定的是 `ratio<3600,1>` ，那么单位就相当于 `h`，那么 `10` 个 `duration` 就是 `10h`
`Rep` 参数指定了传入的时间单位的类型，可以为 `float`, `int`, `int64` 等，如果为 `float` 则可以表示传入时间单位的“一部分”，比如传入 `1.2` 表示 `1.2` 倍个时间单位。

例如：

``` c++
#include <myheader.h>

using namespace std;

void Test()
{
    using std::chrono::duration;
    using std::chrono::duration_cast;
    using std::ratio;
 
    duration<long long, ratio<1, 1>> tick_s{15}; // 15s
    duration<long long, ratio<1, 1000>> tick_ms{15}; // 1500ms
    duration<long long, ratio<60>> tick_min{15}; // 15min
    duration<float, ratio<3600>> tick_h{1.5}; // 1.5h
    
    // count()方法可以返回我们设置的数值
    cout << tick_h.count() << "h" << endl; 
    cout << tick_min.count() <<  "min" << endl;
    
    // duration_cast 
    auto min = duration_cast<std::chrono::minutes>(tick_h);
    cout << "1.5h = " << min.count() << "min" << endl;

    // 也可以隐式类型转换
    cout << "15min = " << chrono::seconds(tick_min).count() << "s" << endl;

    // 也可以自定义转换类型
    using _day = duration<double, ratio<24 * 3600>>;
    auto hour = duration<long long, ratio<3600>>{8};
    cout << "8h = " << duration_cast<_day>(hour).count() << "day" << endl;

    // duration 还可以支持算数运算和比较运算
    // 这里就不展示了
}

int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```





例如：等待 `future` 状态变为就绪需要 35ms

``` c++
#include <myheader.h>

using namespace std;

int task()
{
    std::this_thread::sleep_for(40ms);
    return 1024;
}

void Test()
{
    std::future<int> f = std::async(task);
    if(f.wait_for(std::chrono::milliseconds(35ms)) == std::future_status::ready)
        cout << "ready" << endl;
    else 
        cout << "deferred" << endl;
}

int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```



#### 4.3.4 time point

``` c++
template<class Clock, class Duration = typename Clock::duration>
class time_point;
// time_point 表示时间中的一个点
// Clock 表示时钟的类型
// Duration 存储一个自 Clock 的纪元起开始的时间间隔
// Unix 的纪元为 1970/1/1/00/00/00（epoch）
```

例如：

``` c++
#include <myheader.h>

using namespace std;

void slow_motion()
{
    static int a[] {1,2,3,4,5,6,7,8,9,10,11,12};
    do{} // 生成 12! 个排列
    while (next_permutation(a, a + 12));
}

int main()
{   
    PRINT_BEGIN;

    using namespace std::literals;
    using namespace std::chrono;

    /* Test 1 */
    const time_point<system_clock> now = system_clock::now();
    const time_t t_c = system_clock::to_time_t(now - 24h);
    cout << "24 hour ago, the time was " << put_time(std::localtime(&t_c), "%F %T.\n") << endl;

    /* Test 2 */
    const time_point<steady_clock> start = steady_clock::now();
    slow_motion();
    const auto end = steady_clock::now();
    cout << "Slow calculation took "
         << duration_cast<milliseconds>(end - start).count() << "us = "
         << (end - start) / 1ms << "ms = "
         << (end - start) / 1s << "s.\n";

    PRINT_END;  
    return 0;
}
```

例2: 等待条件变量满足条件 —— 有超时功能

``` c++
#include <myheader.h>

using namespace std;

using namespace chrono_literals;
std::condition_variable cv;
bool done;
std::mutex m;

void wait_loop()
{
    cout << "wait_loop running\n";
    
    this_thread::sleep_for(100ms);
    cout << "wait loop sleep done.\n";

    const auto timeout = // now + xms
        std::chrono::steady_clock::now() 
        + std::chrono::milliseconds(1000);   
    std::unique_lock<std::mutex> lock(m);
    while(!done)
    {
        if(cv.wait_until(lock, timeout) == std::cv_status::timeout)
        {
            cout << "timeout.\n";
            break;
        }
        // do something or done = true
        // done = true;
    }
    cout << "wait_loop end\n";
}

void signal()
{
    cout << "thread running.\n";

    this_thread::sleep_for(1000ms);
    cout << "thread sleep done.\n";

    cv.notify_one();
    cout << "thread end.\n";
}

int main()
{   
    thread tl(wait_loop);
    thread t(signal);
    tl.join();
    t.join();
    if(done)    cout << "done.\n" << endl;
    PRINT_END;  
    return 0;
}
```



#### 4.3.5 use timeout

使用超时机制的函数

| 类型/命名空间                                                | 函数                                              | 返回值                                                 |
| ------------------------------------------------------------ | ------------------------------------------------- | ------------------------------------------------------ |
| std::this_thread[namespace]                                  | sleep_for(duration)                               | N/A                                                    |
| sleep_until(time_point)                                      |                                                   |                                                        |
| std::condition_variable 或 std::condition_variable_any       | wait_for(lock, duration)                          | std::cv_status::time_out 或 std::cv_status::no_timeout |
| wait_until(lock, time_point)                                 |                                                   |                                                        |
|                                                              | wait_for(lock, duration, predicate)               | bool —— 当唤醒时，返回谓词的结果                       |
| wait_until(lock, duration, predicate)                        |                                                   |                                                        |
| std::timed_mutex 或 std::recursive_timed_mutex               | try_lock_for(duration)                            | bool —— 获取锁时返回true，否则返回fasle                |
| try_lock_until(time_point)                                   |                                                   |                                                        |
| std::unique_lock<TimedLockable>                              | unique_lock(lockable, duration)                   | N/A —— 对新构建的对象调用owns_lock();                  |
| unique_lock(lockable, time_point)                            | 当获取锁时返回true，否则返回false                 |                                                        |
|                                                              | try_lock_for(duration)                            | bool —— 当获取锁时返回true，否则返回false              |
| try_lock_until(time_point)                                   |                                                   |                                                        |
| std::future<ValueType>或std::shared_future<ValueType>        | wait_for(duration)                                | 当等待超时，返回std::future_status::timeout            |
| wait_until(time_point)                                       | 当“期望”准备就绪时，返回std::future_status::ready |                                                        |
| 当“期望”持有一个为启动的延迟函数，返回std::future_status::deferred |                                                   |                                                        |

现在，我们讨论的机制有：**condition variable**、“**future**”、“**promise**”还有 **packaged_task**。是时候从更高的角度去看待这些机制，怎么样使用这些机制，简化线程的同步操作。






### 4.4 simplify code

同步工具在本章成为“构建块”。

比起在多个线程间共享数据，每个任务最好拥有自己的数据，并且其他线程可以通过使用 `future` 获取运行结果。

#### 4.4.1 funtional programming by future 

> **functional programming(FP)** is a programming way which the function_return_value only depend on the arguments and you will get the same result always if you pass the same arguments

串形版针对 `list` 的 `qsort`：

``` c++
#include <myheader.h>

using namespace std;

template<typename T>

std::list<T> sequential_quick_sort(std::list<T> input)
{
    if(input.empty())
    {
        return input;
    }
    std::list<T> result;

    // std::list::splice 实现将元素从一个list转移到另一个list
    // 并且仅仅通过 pointer move 实现，而不 copy or move elements

    // splice(const_iterator pos, list &other, const_iterator it)
    // 从 other 转移 it 所指向的元素到 [*this](calleer) 当中，元素被插入到 pos 所指向的元素之前
    // 即，将 input 的第一个元素转移到 reesult 的 begin 之前
    result.splice(result.begin(), input, input.begin());
    // 选取一个“中间元素”
    const T& pivot = *result.begin();   // pivot: 枢纽

    // paration 返回第一个不满足条件的元素的迭代器，正好是开区间
    // 方便 [) 的设计
    // 根据“中间元素”划分为左右去见
    auto divide_point = std::partition(input.begin(), input.end(),
        [&](const T& t){return t < pivot;} // 以 t<pivot 划分元素，input左侧都是小于pivot，右侧大于pivot
    );

    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

    // recursion
    // 分别对左右区间的元素递归sort
    auto new_lower(sequential_quick_sort(std::move(lower_part)));
    auto new_higher(sequential_quick_sort(std::move(input)));

    // left, middle(privot), right
    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower);
    return result;
}

int main()
{   
    PRINT_BEGIN;
    list<int> l{1, 4, 3, 5, 4, 6, 6, 7, 7, 4, 4, 5};
    l = sequential_quick_sort(l);
    for(auto &val : l)
        cout << val << ' ';
    cout << endl;
    PRINT_END;  
    return 0;
}
```

qsort —— FP pattern with thread strongthen（并行版本）

``` C++
#include <myheader.h>

using namespace std;

template<typename T>
auto parallel_quick_sort(std::list<T> input) -> auto
{
    if(input.empty())
        return input;
    
    std::list<T> result;
    
    result.splice(result.begin(), input, input.begin());
    const T& pivot = *result.begin();
    
    auto divide_point = std::partition(input.begin(), input.end(), 
        [&](const T& t){
            return t < pivot;
    });

    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, 
        input.begin(), divide_point);

    // 创建一个新的线程进行排序
    std::future<std::list<T>> new_lower(
        std::async(&parallel_quick_sort<T>, std::move(lower_part))
    );
    // 在当前线程中执行，无需一个新的线程
    auto new_higher = (
        parallel_quick_sort(std::move(input))
    );

    result.splice(result.end(), new_higher);;
    result.splice(result.begin(), new_lower.get());

    return result;
}

int main()
{   
    PRINT_BEGIN;
    list<int> l{1, 4, 3, 5, 4, 6, 6, 7, 7, 4, 4, 5};
    l = parallel_quick_sort(l);
    for(auto &val : l)
        cout << val << ' ';
    cout << endl;
    PRINT_END;  
    return 0;
}
```

在上面的代码中，每调用一次 `parallel_quich_sort`，我们便创建一个新的线程，由于递归执行的缘故，线程的创建是指数级别的，也就是说，如果递归执行 10 次，那么就会创建 1024 个线程！但创建太多线程显然是不好的，因此 `async()` 会自动执行某些操作，避免创建太多线程。这也符合 `async()` 的策略（既可立马创建新线程，也可以以延迟加载的方式创建线程）。

其实，如果 `async()` 以延迟加载的方式执行，也就是直到在 `std::async()` 返回的 `future` 对象调用 `get()` 或者 `wait()` 时才执行。

然鹅，当调用 `get/wait` 时，函数会同步执行，即调用者会阻塞直到函数运行结束，如果 `get/wait` 没有被调用，函数就绝对不会执行。

> [ref here](https://segmentfault.com/a/1190000039083151)

比起使用`std::async()`，你可以写一个spawn_task()函数对`std::packaged_task`和`std::thread`做简单的包装，如下面代码所示；你需要为函数结果创建一个`std::packaged_task`对象， 可以从这个对象中获取“期望”，或在线程中执行它，返回“期望”。

其本身并不提供太多的好处(并且事实上会造成大规模的超额任务)，但是它会为转型成一个更复杂的实现铺平道路，将会实现向一个队列添加任务，而后使用线程池的方式来运行它们。我们将在第9章再讨论线程池。使用`std::async`更适合于当你知道你在干什么，并且要完全控制在线程池中构建或执行过任务的线程。

``` c++
template<typename F, typename A>
std::future<std::result_of<F(A&&)>::type> spawn_task(F &&f, A &&a)
{
    typedef std::result_of<F(A&&)>::type result_type;
    std::packaged_task<result_type(A&&)> task(std::move(f));
    std::future<result_type> res(task.get_future());
    std::thread t(std::move(task), std::move(a));
    t.detach();
    return res;
}
```

#### 4.4.2 synchronization by message passing 

>  **MPI：**Message Passing Interface，消息传递接口
>
> **CSP：**Communicating Sequentiasl Processer，通讯顺序进程



<font color=blue>???????  THIS SECTION AND NEXT SECTION TODO</font>



TODO …

### 4.5 summary

同步操作对于使用并发编写一款多线程应用来说，是很重要的一部分：如果没有同步，线程基本上就是独立的，也可写成单独的应用，因其任务之间的相关性，它们可作为一个群体直接执行。

本章，我们讨论了各式各样的同步操作，从基本的**条件变量，到“期望”、“承诺”，再到打包任务**。

我们也讨论了替代同步的解决方案：**函数化模式编程，完全独立执行的函数，不会受到外部环境的影响；还有，消息传递模式，以消息子系统为中介，向线程异步的发送消息。**



## P5 memory model and atomatic operation



## P6 data struct with mutex

本章主要内容：

* 设计并发数据结构
* 如何设计
* 实现数据结构

设计并发数据结构时，可以使用多线程中的构建块，比如：`condition_variable` 和 `mutex`。当然也要保证并发块在并发环境下的线程安全。

### 6.1 the significance of concurrency design

设计并发数据结构是为了让多线程并发访问，并且线程可对数据结构做相同或不同的操作。

多线程环境下，无数据丢失和损坏，苏哟偶的数据都维持原样，且无竞争条件的数据结构，称之为“线程安全”的数据结构。

实际上，我们要通过设计线程安全的数据结构为线程提供并发访问数据结构的机会。因为就本质来说，互斥量为了保护数据，会显示阻止线程对数据的并发访问。

#### 6.1.1 guideline of desiging the concurrency DB

设计并发数据结构时，需要两方面的考量：

1. 确保访问安全
2. 真正并发访问

第三章已经对如何保证数据安全做过简单的描述：

* 确保无线程能够看到“不变量”变化时的状态
* 小心会引起条件竞争的接口，提供完整操作的函数，而非操作步骤（top-pop）
* 注意数据结构的行为是否会产生异常，从而确保“不变量”的状态
* 将死锁的概率降到最低。限制锁的范围，避免嵌套锁等

**还需要考虑数据结构对于使用者有什么限制**，当线程通过特殊的函数对数据结构进行访问时，其他的线程还有哪些函数能安全调用?

这是一个很重要的问题，普通的构造函数和析构函数需要独立访问数据结构，所以用户使用时，就不能在构造函数完成前或析构函数完成后对数据结构进行访问。当数据结构支持赋值操作swap()或拷贝构造时，作为 数据结构的设计者，即使线程操纵数据结构中有大量的函数，也需要保证这些操作在并发下是安全的(或确保 这些操作能够独立访问)，以保证并发访问时不会出错。

第二个方面是确保真正的并发，需要考虑一下问题：

1. 操作在锁的范围中进行，是否允许在锁外执行？
2. 数据结构中不同的互斥能否保护不同的区域？
3. 所有操作都需要同级互斥量的保护吗？
4. 能否对数据结构进行简单的修改，增加并发访问的概率？

这些问题都源于一个指导思想:**如何让序列化访问最小化，让真实并发最大化?😊？？😭**

允许线程并发读取的数据结构并不少见，但修改必须是单线程的，这种结构类似于 `std::shared_mutex` 。同样，这种数据结构也很常见—— 支持多线程的不同操作时，也能串行执行相同的操作。

最简单的线程安全结构通常会对数据使用互斥量或锁。虽然，这么做还有问题，不过这样做相对简单，并且能保证只有一个线程在同一时间对数据结构进行独立访问。为了更轻松的设计线程安全的数据结构，接下来了解一下基于锁的数据结构。



### 6.2 DS based on mutex



基于锁的并发数据结构确保访问线程持有锁的时间最短；对于只有一个互斥量的数据结构，需要锁之外的操作不能访问数据；使用多个互斥量保护数据结构不同的区域时要避免死锁。

#### 6.2.1 threadsafe stack

在 push() 操作中，无论如何都无法避免新数据的创建，除非你直接 move 原来的数据（右值引用 + move），但是直接 move 原来的数据有一个问题，那就是如果内存不足，move 一半异常了，那么原来的数据就会被破坏，因此，使用传值的方式拷贝初始数据，在 move 到容器中，更为稳妥。

这里的 “异常 - 安全” 好恶心😭

另外，这里的代码是可能发生死锁的;

用户要对栈负责，当栈未对一个数据进行拷贝或分配时，用户就不能想当然的将其添加到栈中。

所有成员函数都使用 std::lock_guard<> 保护数据，所以栈成员函数才是“线程安全”的。当然，构造与析构函数不是“线程安全”的，但构造与析构只有一次。调用不完全构造对象或是已销毁对象的成员函数，无论在哪种编程方式下都不可取。所以，用户就要保证在栈对象完成构造前，其他线程无法对其进行访问。并且，要保证在栈对象销毁后，停止所有线程的访问操作。

串形化的线程会隐性的限制程序性能。例如我们需要 pop 一个元素，那么当栈为空时我们只能等待，但这种等待时无意义的，我们希望它不这么闲着等，而是去做一些其他事，因此，这需要用户编写等待和提示的代码（例如：条件变量）。下面的队列就是如此。

#### 6.2.2 threadsafe queue – mutex && condition_variable

``` C++
template<typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;

public:
    threadsafe_queue() {}
    void push(T data)
    {
        std::lock_guard<std::mutex> mut;
        data_queue.push(std::move(data));
        data_cond.notify_one(); // 不为空，通知等待的线程
    }
    void wait_and_pop(T &value)
    {
        // 因为wait可能假唤醒，因此这里需要多次lock&&unlock
        // 因此unique_lock用来搭配condition_variable是更好的选择
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, [this]{
            return !data_queue.empty();
        });
        value = std::move(data_queue.top());
        data_queue.pop();
    }
    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, [this]{
            return !data_queue.empty();
        });
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }
    /* [TOOD]
    * 感觉这里可以把两个pop中判断queue是否为空的部分拿出来
    * 放到一个单独的函数里面，这样岂不是更好？
    */
   bool try_pop(T &value)
   {    
        std::lock_guard<std::mutex> lock(mut);
        if(data_queue.empty())  return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
   }
   std::shared_ptr<T> try_pop()
   {
        std::lock_guard<std::mutex> lock(mut);
        if(data_queue.empty())  
            return nullptr; 
        std::shared_ptr<T> res(make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
   }
   bool empty() const 
   {
        std::lock_guard<std::mutex> lock(mut);
        return data_queue.empty();
   }
};
```

这里的代码在有一个问题，就是当 push() 执行 notice_one() 之后，如果唤醒的那个线程发生了异常死了，例如构造新的 shared_ptr 对象时发生异常，那么所有线程都将永眠，因为此时没有其它条件能将他们唤醒，解放方案有如下几种：

1. notice_all()，但是这么做的开销太大了，因为往往只有一个线程最终唤醒，而其他线程仍然需要沉睡
2. 当唤醒的线程异常时，调用 notice_one() 去唤醒另一个线程
3. 将`std::shared_ptr<>`的初始化过程移到push()中，并且存储`std::shared_ptr<>`实例，而非直接使用数据的值。将`std::shared_ptr<>`拷贝到内部`std::queue<>`中，就不会抛出异常了，这样wait_and_pop()又是安全的了。

下面是使用第三种方案修改后的代码：

``` C++
#include <myheader.h>

using namespace std;

template<typename T>
class threadsafe_queue
{
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;

public:
    threadsafe_queue() {}
    void push(T new_value)
    {
        // 这样即使发生了异常也不会导致所有线程沉睡
        // 因为构造对象并不涉及对共享对象的访问
        // 因此它实际上不需要加锁
        std::shared_ptr<T> data(
            std::make_shared<T>(std::move(new_value))
        );
        // 分配完才加锁，减少锁持有的时间，提高并发能力
        std::lock_guard<std::mutex> lock(mut);
        data_queue.push(data);
        data_cond.notify_one(); // 不为空，通知等待的线程
    }
    void wait_and_pop(T &value)
    {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, [this]{
            return !data_queue.empty();
        });
        value = std::move(*data_queue.top());
        data_queue.pop();
    }
    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lock(mut);
        data_cond.wait(lock, [this]{
            return !data_queue.empty();
        });
        std::shared_ptr<T> res = data_queue.front(); // 改为赋值而不是创建
        data_queue.pop();
        return res;
    }
    /* [TOOD]
    * 感觉这里可以把两个pop中判断queue是否为空的部分拿出来
    * 放到一个单独的函数里面，这样岂不是更好？
    */
   bool try_pop(T &value)
   {    
        std::lock_guard<std::mutex> lock(mut);
        if(data_queue.empty())  return false;
        value = std::move(*data_queue.front());
        data_queue.pop();
        return true;
   }
   std::shared_ptr<T> try_pop()
   {
        std::lock_guard<std::mutex> lock(mut);
        if(data_queue.empty())  
            return nullptr; 
        std::shared_ptr<T> res = data_queue.front();
        data_queue.pop();
        return res;
   }
   bool empty() const 
   {
        std::lock_guard<std::mutex> lock(mut);
        return data_queue.empty();
   }
};

int main()
{   
    PRINT_BEGIN;
    PRINT_END;  
    return 0;
}
```



#### 6.2.3 threadsaft queue -  small granularity && condition_variable

下面是一个单线程环境下简单队列的实现，它是一个有头尾节点的单链表，当链表为空时，头尾指针为空。

> 头节点 != 头指针

``` c++
template<typename T>
class Queue
{
private:
    struct node 
    {
        T data;
        std::unique_ptr<node> next; //  使用智能指针
        node(T _data) : data(move(_data)) {}
    };
    std::unique_ptr<node> head;
    node *tail; // 因为这里的tail并不从堆上分配内存，他只是指向一个地址，因此不需要使用智能指针代替
public:
    Queue() {}
    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;
    
    // 返回节点并删除
    std::shared_ptr<T> try_pop()
    {
        if(!head)
            return nullptr;
        /* 这里的const是顶层const，指定res不能再指向别的东西了，但是数据仍然可以修改
        * 你可能疑惑，既然res不能修改，但是接受返回值的变量不一定有这个限制的，他是可以修改的，没错，可以修改，但要记住了，shared_ptr 是有引用计数的，你修改了指向，其实就相当于在修改引用计数（创建了一个新指针），这并不会修改原来的指针，顶多导致她引用计数为0从而被销毁了。
        */
        
        // 分别取得头节点的数据和next指针
        const std::shared_ptr<T> res(
            std::make_shared<T>(std::move(head->data))
        );
        const std::unique_ptr<node> old_head = std::move(head);
        // 头指针指向下一个节点
        head = std::move(old_head->next);
        return res;
    }
    
    void push(T new_value)
    {
        // 1. 创建新节点
        std::unique_ptr<node> p(new node(std::move(new_value)));
        const node* new_tail = p.get();
        // 2. 让尾节点的next指向新节点
        if(tail)
            tail->next = std::move(p);
        else 
            head = std::move(p);
        // 3. 更新尾节为当前节点
        tail = new_tail;
    }
};
```

这段代码在单线程下没问题，但是在多线程下问题就太多了！

因为在给定的实现中有两个数据项(head①和tail②)；即使，使用两个互斥量，来保护头指针和尾指针，也会出现问题。

显而易见的问题就是push()可以同时修改头指针⑤和尾指针⑥，所以push()函数会同时获取两个互斥量。虽然会将两个互斥量都上锁，但这还不是太糟糕的问题。糟糕的问题是push()和pop()都能访问next指针指向的节点：push()可更新tail->next④，而后try_pop()读取head->next③。当队列中只有一个元素时，head==tail，所以head->next和tail->next是同一个对象，并且这个对象需要保护。不过，“在同一个对象在未被head和tail同时访问时，push()和try_pop()锁住的是同一个锁”，就不对了。所以，你就没有比之间实现更好的选择了。这里会“柳暗花明又一村”吗？

可以通过**分离数据**实现并发。

通过“预分配虚拟节点（无数据）”，确保这个节点永远在队列的最后，用来分离头尾指针能访问的节点。

``` c++
#include <myheader.h>

using namespace std;

template<typename T>
class Queue
{
private:
    struct node 
    {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next; //  使用智能指针
    };

private:
    std::unique_ptr<node> head;
    node *tail; 

public:
    Queue() // 预分配一个虚拟节点
    : head(new node), tail(head.get()) 
    {}
    /*
    initialization: 
        [head(taial)] -> NULL 
    push value a
        [head] -> [a(tail)] -> NULL
    push value b
        [head] -> [a] -> [b(tail)] -> NULL
    pop value
        [head] -> [a(tail)] -> NULL
    这样，除了队列为空状态下 head->next == tail->next == NULL
    任何时候他们不会为同一个元素，而队列为空时，不会同时发生 push 和 pop
    */
    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;
    
    std::shared_ptr<T> try_pop()
    {
        if(head.get() == tail) // head与tail指向同一元素，队列为空
            return nullptr;
        
        // 队列不为空，先 front() 再 pop()
        const std::shared_ptr<T> res(head->data); // shared_ptr 不需要 move
        const std::unique_ptr<node> old_head = std::move(head);
        head = std::move(old_head->next);
        return res;
    }

    void push(T new_value)
    {
        // 因为 tail 是我们预分配的节点，因此直接修改 tail 的 dat 即可
        std::shared_ptr<T> new_data(
            std::make_shared<T>(std::move(new_value))
        ); 
        tail->data = new_data;

        // 我们已经把上次预分配的使用了，因此需要重新预分配并作为尾节点
        std::unique_ptr<node> p(new node); 
        const node* new_tail = p.get();
        tail->next = std::move(p);
        tail = new_tail;    
    }
};

int main()
{   
    PRINT_BEGIN;
    PRINT_END;  
    return 0;
}
```

经过修改之后，push 便只需要访问 tail，而原来还需要访问 head，try_pop 需要访问 head 和 tail，但是 head 只在开始时用了一下，所以存在的时间很短。

不过，最重大的提升在于，try_pop 和 push 不能对同一节点进行操作，也就不需要互斥了。因此，现在只需要一个互斥量来保护 head 和 tail 就行了。

那么，该如何加锁呢？

``` c++
template<typename T>
class threadsaft_queue
{
private:
    struct node 
    {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
    };
    std::mutex head_mutex, tail_mutex;
    std::unique_ptr<node> head;
    node *tail;

    node* get_tail()
    {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        return tail;
    }

    std::unique_ptr<node> pop_head()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get() == get_tail()) // 队列为空
        {
            return nullptr;
        }
        std::unique_ptr<node> old_head = std::move(head_mutex);
        // move 掉 next 也是个好事，用户想得到的应该只是数据而不是 next 指针
        head = std::move(old_head->next);
        return old_head;
    }

public:
    threadsaft_queue(): head(new node), tail(head.get()) {}
    threadsaft_queue(const threadsaft_queue&) = delete;
    threadsaft_queue& operator=(const threadsaft_queue&) = delete;
    
    std::shared_ptr<T> try_pop()
    {
        std::unique_ptr<node> old_head = pop_head();
        return old_head ? old_head->data : std::shared_ptr<T>();
    }

    void push(T new_value)
    {
        std::shared_ptr<T> new_data(
            std::make_shared<T>(std::move(new_value))
        );
        std::unique_ptr<node> p(new node);
        const node *new_tail = p.get();

        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        tail->data = new_data;
        tail->next = std::move(p);
        tail = new_tail;
    }
};
```

> 多线程环境下，节点及数据的分配时“并发安全”的。



下面是可上锁和等待的线程安全队列

``` C++
#include <myheader.h>

using namespace std;

template<typename T>
class threadsaft_queue
{
private:
    struct node 
    {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
    };

private:
    std::mutex head_mutex, tail_mutex;
    std::condition_variable data_cond;
    std::unique_ptr<node> head;
    node *tail;

private:
    node* get_tail();
    
    std::unique_ptr<node> pop_head();
    
    std::unique_lock<std::mutex> wait_for_data();
    std::unique_ptr<node> wait_pop_head();
    std::unique_ptr<node> wait_pop_head(T &value);
    
    std::unique_ptr<node> try_pop_head();
    std::unique_ptr<node> try_pop_head(T& value);


public:
    std::shared_ptr<T> try_pop();
    bool try_pop(T &value);
    std::shared_ptr<T> wait_and_pop();
    void wait_and_pop(T &value);
    void push(T new_value);
    bool empty();
};


/*====================*
*       function      *
*=====================*/

template<typename T>
std::shared_ptr<T> threadsaft_queue<T>::try_pop()
{
    std::unique_ptr<node> old_head = try_pop_head();
    return old_head ? old_head->data : std::shared_ptr<T>();
}

template<typename T>
bool threadsaft_queue<T>::try_pop(T &value)
{
    std::unique_ptr<node> old_head = try_pop_head();
    return old_head;
}

template<typename T>
std::shared_ptr<T> threadsaft_queue<T>::wait_and_pop()
{
    const std::unique_ptr<node> old_head = wait_pop_head();
    return old_head->data;
}

template<typename T>
void threadsaft_queue<T>::wait_and_pop(T &new_value)
{
    const std::unique_ptr<node> old_head = wait_and_pop(new_value);
}

template<typename T>
void threadsaft_queue<T>::push(T new_value)
{
    std::shared_ptr<T> new_data(
        std::make_shared<T>(std::move(new_value))
    );
    std::unique_ptr<node> p(new node);
    { 
        // use {} to unlock early 
        const node *new_tail = p.get();
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        tail->data = new_data;
        tail->next = std::move(p);
        tail = new_tail;
    }
    data_cond.notify_one();
}

template<typename T>
bool threadsaft_queue<T>::empty()
{
    std::lock_guard<std::mutex> head_lock(head_mutex);
    return (head.get() == get_tail());
}

/*====================*
*   helper function   *
*=====================*/

template<typename T>
typename threadsaft_queue<T>::node* 
threadsaft_queue<T>::get_tail()
{
    std::lock_guard<std::mutex> tail_lock(tail_mutex);
    return tail;
}

// execute within head mutex
template<typename T>
std::unique_ptr<typename threadsaft_queue<T>::node> 
threadsaft_queue<T>::pop_head()
{
    std::unique_ptr<node> old_head = std::move(head);
    head = std::move(old_head->next);
    return old_head;
}

template<typename T>
std::unique_lock<std::mutex> 
threadsaft_queue<T>::wait_for_data()
{
    std::unique_lock<std::mutex> head_lock(head_mutex);
    // 因为获取了 head_lock，所以下面调用 head.get() 并发安全
    data_cond.wait(head_lock, [&]{
        return head.get() != get_tail();
    });
    return std::move(head_lock);
}

template<typename T>
std::unique_ptr<typename threadsaft_queue<T>::node> 
threadsaft_queue<T>::wait_pop_head()
{
    // 1. [wait] until queue is not empty
    std::unique_lock<std::mutex> head_lock(wait_for_data());
    // 2. [pop] head
    return pop_head();
}

template<typename T>
std::unique_ptr<typename threadsaft_queue<T>::node> 
threadsaft_queue<T>::wait_pop_head(T &value)
{
    // 1. [wait] until queue is not empty
    std::unique_lock<std::mutex> head_lock(wait_for_data());
    // get data
    value = std::move(*head->data);
    // 2. [pop] head
    return pop_head();
}

template<typename T>
std::unique_ptr<typename threadsaft_queue<T>::node> 
threadsaft_queue<T>::try_pop_head()
{
    std::lock_guard<std::mutex> head_lock(head_mutex);
    if(head.get() == get_tail())
        return std::unique_ptr<node>();
    return pop_head();
}

template<typename T>
std::unique_ptr<typename threadsaft_queue<T>::node> 
threadsaft_queue<T>::try_pop_head(T& value)
{
    std::lock_guard<std::mutex> head_lock(head_mutex);
    if(head.get() == get_tail())
        return std::unique_ptr<node>();
    value = std::move(*head->data);
    return pop_head();
}
    

int main()
{   
    PRINT_BEGIN;
    PRINT_END;  
    return 0;
}
```



### 6.3 design more complex DS

栈和队列的设计太 easy 啦（然而我也招架不住😭），下面来点大的。😠😠😠

#### 6.3.1 threadsafe dictionary

和栈和队列一样，标准容器的接口不适合多线程进行并发访问，因为这些接口都存在固有的条件竞争，所以这些接口需要砍掉或者重新修订。

并发访问时，`std::map<>` 最大的问题在于 —— 迭代器。例如当迭代器引用的元素被其它线程删除时，迭代器就会失效，但我们不知道。

查询表（字典）基本操作：

1. （增）添加 key-value
2. （删）删除 key-value
3. （改）修改指定 key 所对应的 value
4. （查）查询指定 key 所对应的 value
5. so on…

如果你坚持之前的线程安全指导意见，例如：**不要返回一个引用**，并且用一个简单的互斥锁对每一个成员函数进行上锁，以确保每一个函数线程安全。最有可能的条件竞争在于，当一对“键值-数据”加入时；当两个线程都添加一个数据，那么肯定一个先一个后。一种方式是合并“添加”和“修改”操作为一个成员函数，就像清单3.13对域名系统缓存所做的那样。

区别多线程环境下一下容器的并发能力：

1. 二叉树，比如：红黑树
2. 有序数组
3. 哈希表

其中哈希表并发性能最好，因为哈希表可以设计为同 bucket+list(或有序数组)，而每一个 bucket 可以独立加锁，bucket 与 bucket 之间独立

下面是基于哈希表，使用读写锁，线程安全的，字典：

``` C++
#include <myheader.h>

using namespace std;

// [TODO] separate bucket_t from threadsafe_lookup_table
template<typename Key, typename Value, typename Hash = std::hash<Key>>
class threadsafe_lookup_table 
{
private:
    class bucket_t
    {
    private:
        /* [BUG]
            if you don't add this, in the function of get_map()
            you cant access the number of data typed bucket_data
            .... 
        */
        friend class threadsafe_lookup_table;

    private:
        typedef std::pair<Key,Value>                 bucket_value;
        typedef std::list<bucket_value>              bucket_data;
        typedef typename bucket_data::iterator       bucket_iterator;
        /* [BUG]
            author use iterator, but it is go CE
            we should use const_iterator
            ... ?
        */
        typedef typename bucket_data::const_iterator bucket_const_iterator;

        bucket_data data;
        mutable std::shared_mutex mutex;
        
        // helper function
        bucket_const_iterator find_entry_for(const Key &key) const 
        {
            /* [BUG]
                
            */
            return std::find_if(data.begin(), data.end(), 
                [&](const bucket_value &items){
                    return items.first == key;
            });
        }
        
    public:
        // Advise: do not return by reference
        // this function return the value which mapped to the key
        // if ther is no item match, then return default value
        // and the default value is designated by the caller
        Value value_for(const Key &key, const Value &default_value) const 
        {
            std::shared_lock<std::shared_mutex> lock(mutex); // read lock
            bucket_const_iterator found_entry = find_entry_for(key);
            return (found_entry == data.end()) ? 
                default_value : found_entry->second;
        }

        // update if this key is existed otherwise add this K-V
        void add_or_update_mapping(const Key &key, const Value &value)
        {
            std::unique_lock<std::shared_mutex> lock(mutex); // write lock
            bucket_const_iterator found_entry = find_entry_for(key);
            if(found_entry == data.end())
                data.push_back(bucket_value(key, value));
            else 
            {
                /* [BUG]
                    because we use the const_iterator(lower const for the data which pointed on)
                    so we cant't modify the data
                    otherwise ust the type convertion
                */
                auto &data = const_cast<bucket_value&>(*found_entry);
                data.second = value;
            }
        }

        void reomove_mapping(const Key &key)
        {
            std::unique_lock<std::shared_mutex> lock(mutex); // write lock
            bucket_const_iterator found_entry = find_entry_for(key);
            if(found_entry != data.end())
                data.erase(found_entry);
        }
    };

    std::vector<std::unique_ptr<bucket_t>> buckets;
    Hash hasher;
    
    bucket_t& get_bucket(const Key &key) const 
    {
        const std::size_t bucket_index = hasher(key) % buckets.size();
        // buckets[idx] is a object of unique_ptr 
        // so use operator* to get the object which ptr pointed on
        return *buckets[bucket_index];
    }

public:
    typedef Key   key_type;
    typedef Value mapped_type;    
    typedef Hash  hash_type;
    typedef pair<Key, Value> value_type;

    threadsafe_lookup_table(
        // the _num_bucket should be a prime so that it will have the best performance
        unsigned _num_buckets = 19, const Hash &_hasher = Hash()
    ) : buckets(_num_buckets), hasher(_hasher) 
    {
        for(unsigned i = 0; i < _num_buckets; i ++ )
        {
            buckets[i].reset(new bucket_t);
        }
    }

    threadsafe_lookup_table(const threadsafe_lookup_table&) = delete;
    threadsafe_lookup_table& operator=(const threadsafe_lookup_table&) = delete;
    
    /*        DO NOT NEED MUTEX
    *  because the count of buckets can't changed
    *  so it is needn't to lock in the following functions 
    *  -- when they call get_bucket() 
    */

    // caller, should designated the default value
    Value value_for(const Key &key, const Value &default_value = Value()) const 
    {
        return get_bucket(key).value_for(key, default_value);
    }

    void add_or_update_mapping(const Key &key, const Value &value)
    {
        get_bucket(key).add_or_update_mapping(key, value);
    }

    void remove_mapping(const Key &key)
    {
        get_bucket(key).reomove_mapping(key);
    }

    // snapshot, return the backup in std::map
    // because we need to lock all buckets
    // if we add unique_lock, it would much wasty
    // so a bettery way is to use shared_mutex(read-lock)
    // so that other threads can also read meanwhile when we have locked a bucket
    // and then, we want to get the current state
    // so we should lock all buckets at one time
    // it is bad to lock and copy bucket one by one
    // because eg. when we lock A, and B will be modified
    // so the state is not consistency
    std::map<Key,Value> get_map() const 
    {
        std::vector<std::unique_lock<std::shared_mutex>> locks;
        for(unsigned i = 0; i < buckets.size(); i ++ )
        {
            locks.push_back(
                std::unique_lock<std::shared_mutex>(buckets[i]->mutex)
            );
        }   
        std::map<Key,Value> res;
        for(unsigned i = 0; i < buckets.size(); i ++ )
        {
            for(auto &map_item : buckets[i]->data)
            {
                res.insert(map_item);
            }
        }
        return res;
    }
};

template<typename Key, typename Value, typename Hash = std::hash<Key>>
using _map = threadsafe_lookup_table<Key, Value>;

void Test()
{
    _map<int,string> table;
    table.add_or_update_mapping(1, "jyyyx");
    cout << table.value_for(1) << endl;
    table.add_or_update_mapping(2, "hello");
    cout << table.value_for(2) << endl;
    table.add_or_update_mapping(1, "sbg");
    cout << table.value_for(1) << endl;
    for(int i = 0; i < 10; i ++ )
    {
        table.add_or_update_mapping(i, "jyyyx: " + to_string(i));
    }
    auto mp = table.get_map();
    for(auto &x : mp)
        cout << x.first << ' ' << x.second << endl;
}

int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```

> ⚠️⚠️⚠️    **[BUG]**    ⚠️⚠️⚠️

在上面的代码中出现了很恶心的 bug（也可能是我太蠢了）， 导致我排查了好长好长时间，其实错误原因很简单。

在成员函数中，如果我们添加了 const 函数修饰符，那么如果我们返回一个迭代器的话，其实返回的是 const_iterator 而不是 iterator，const_iterator 有底层修饰，不能修改指向的对象。

例如下面的代码会报错：

``` c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>

using namespace std;

typedef pair<int, int> PII;
typedef list<PII> L;
typedef typename L::iterator       L_iterator;
typedef typename L::const_iterator L_const_iterator;

class Foo {
public:
    L l;
    L_iterator get(int x) const // (1)
    {   
        return std::find_if(l.begin(), l.end(), [&](const PII &it){
            return it.first == x;
        });
    }   
    int get_val(int x) 
    {
        L_iterator entry = get(x);
        return entry->second;
    }
};

void test()
{
    Foo f;
    L &l = f.l; 
    for(int i = 0; i < 10; i ++ )   l.push_back({i, i + 10});
    L_iterator it = f.get(2);
    cout << it->second << endl;
    it->second = 1000;
    cout << f.get_val(2) << endl;   
}

int main(){test();}
```

报错信息主要内容如下：

``` c++
return std::find_if(l.begin(), l.end(), [&](const PII &it){
      |                ~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
      |                            |
      |                            std::_List_const_iterator<std::pair<int, int> >
   20 |             return it.first == x;
      |             ~~~~~~~~~~~~~~~~~~~~~
   21 |         });
      |         ~~
```

很明显的发现，编译器提示我们，我们的返回值是一个 `list::const_iterator` 类型，而不是 `list::iterator`。

那你可能会说，如果我们不希望返回 const_ierator 的话，把 (1) 处的 const 去掉不久行了？

那你就得好好看了，下面的错误更隐蔽和恶心，去掉 (1) 处的 const 之后，

``` c++
a.cpp: In member function 'int Foo::get_val(int) const':
a.cpp:25:33: error: passing 'const Foo' as 'this' argument discards qualifiers [-fpermissive]
   25 |         L_iterator entry = get(x);
      |                                 ^
a.cpp:17:16: note:   in call to 'L_iterator Foo::get(int)'
   17 |     L_iterator get(int x) // (1)
      |                ^~~
```

上面的报错信息不认真看，理解着看的话，有可能不知道他说的是什么意思！其实这种错误在 《Effective C++》 系列都是强调过的！由此可见，光理论，不实践，掌握的知识不牢固，容易忘！

其实人话来说，就是 get_val() 是一个 const 成员函数，所以，在这个函数中， **this 指针是 this *const(底层 const)**，想必如果你很敏感的话，那么你应该知道错在哪了！我们把一个 this *const 传入到一个非 const 的成员函数 get() 当中，那么在 get() 当中就可能修改我们的 this，从而间接的破坏了 get_val() 的 const 属性！

> 实际上，上面的 bug 正是 《effective STL》的一条 item:
>
> “const_iterator fist!”

那么，作者为什么会写出如此不严谨的代码呢？是选，有意思的一点是，如果不进行测试，上面的代码是没有问题的！那么，到底是作者写这本时的 C++ 和编译器的版本问题，还是作者偷懒没有进行测试呢？大概是前者吧！😊

> [最终在这篇博客找到了 bug 的解决方案，感恩！](https://blog.csdn.net/wangdamingll/article/details/107086966)



最后，给出使用 iterator 的版本，只需要把所有 const 成员函数修饰去掉就行了。

> 解决问题的方法就是不让问题产生 😭

``` c++
#include <myheader.h>

using namespace std;
template<typename Key,typename Value,typename Hash=std::hash<Key> >
class threadsafe_lookup_table
{
private:
  class bucket_type
  {
  private:
    typedef std::pair<Key,Value> bucket_value;
    typedef std::list<bucket_value> bucket_data;
    typedef typename bucket_data::iterator bucket_iterator;
    typedef typename bucket_data::const_iterator bucket_const_iterator;
    
    bucket_data data;
    mutable shared_mutex mutex;  // 1
    bucket_iterator find_entry_for(Key const& key) 
    {
      return std::find_if(data.begin(),data.end(),
      [&](bucket_value const& item)
      {return item.first==key;});
    }
  public:
    Value value_for(Key const& key,Value const& default_value) 
    {
      shared_lock<shared_mutex> lock(mutex);  // 3
      bucket_iterator const found_entry=find_entry_for(key);
      return (found_entry==data.end())?
        default_value:found_entry->second;
    }
    void add_or_update_mapping(Key const& key,Value const& value)
    {
      std::unique_lock<shared_mutex> lock(mutex);  // 4
      bucket_iterator const found_entry=find_entry_for(key);
      if(found_entry==data.end())
      {
        data.push_back(bucket_value(key,value));
      }
      else
      {
        found_entry->second=value;
      }
    }
    void remove_mapping(Key const& key)
    {
      std::unique_lock<shared_mutex> lock(mutex);  // 5
      bucket_iterator const found_entry=find_entry_for(key);
      if(found_entry!=data.end())
      {
        data.erase(found_entry);
      }
    }
  };
  std::vector<std::unique_ptr<bucket_type> > buckets;  // 6
  Hash hasher;
  bucket_type& get_bucket(Key const& key)   // 7
  {
    std::size_t const bucket_index=hasher(key)%buckets.size();
    return *buckets[bucket_index];
  }
public:
  typedef Key key_type;
  typedef Value mapped_type;
  typedef Hash hash_type;
  threadsafe_lookup_table(
    unsigned num_buckets=19,Hash const& hasher_=Hash()):
    buckets(num_buckets),hasher(hasher_)
  {
    for(unsigned i=0;i<num_buckets;++i)
    {
      buckets[i].reset(new bucket_type);
    }
  }
  threadsafe_lookup_table(threadsafe_lookup_table const& other)=delete;
  threadsafe_lookup_table& operator=(
    threadsafe_lookup_table const& other)=delete;
  Value value_for(Key const& key,
                  Value const& default_value=Value()) 
  {
    return get_bucket(key).value_for(key,default_value);  // 8
  }
  void add_or_update_mapping(Key const& key,Value const& value)
  {
    return get_bucket(key).add_or_update_mapping(key,value);  // 9
  }
  void remove_mapping(Key const& key)
  {
    return get_bucket(key).remove_mapping(key);  // 10
  }
};

void Test()
{
    threadsafe_lookup_table<int,string> table;
    table.add_or_update_mapping(1, "jyyyx");
    cout << table.value_for(1) << endl;
    table.add_or_update_mapping(2, "hello");
    cout << table.value_for(2) << endl;
    table.add_or_update_mapping(1, "sbg");
    cout << table.value_for(1) << endl;
}
int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```



#### 6.3.2 threadsafe list

同上面谈到的，容器中的迭代器在并发时会产生麻烦，除非让迭代器持有锁，但这是个很槽糕的做法。因此这意味着迭代器受限于锁，而不是容器。

替代方案是使用迭代函数，例如：将 for_each 作为容器本身的一部分。这就能让容器对迭代的部分进行负责和锁定。

。。。

链表应该提供的操作：（增删改查）

- 向列表添加一个元素
- 当某个条件满足时，就从链表中删除某个元素
- 当某个条件满足时，从链表中查找某个元素
- 当某个条件满足时，更新链表中的某个元素
- （more）将当前容器中链表中的每个元素，复制到另一个容器中
- （more）插入元素到某个指定的位置

使用细粒度锁最初的想法，是为了**让链表每个节点都拥有一个互斥量**。当链表很长时，那么就会有很多的互斥量!这样的好处是对于链表中每一个独立的部分，都能实现真实的并发：其真正感兴趣的是对持有的节点群进行上锁，并且在移动到下一个节点的时，对当前节点进行释放。下面的清单中将展示这样的一个链表实现。

``` c++
#include <myheader.h>

using namespace std;

// a list with head-node
template<typename T>
class threadsafe_list
{
private:
    struct node 
    {
        std::mutex m;
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
        node() : next() {} // default NULL
        node(const T &value) : data(std::make_shared<T>(value)) {}
    };
    node head; // default head node

public:
    threadsafe_list() = default;
    ~threadsafe_list()
    {
        remove_if([](const node&){return true;});
    }

    threadsafe_list(const threadsafe_list&) = delete;
    threadsafe_list& operator=(const threadsafe_list&) = delete;
    
    void push_front(const T &value)
    {
        // the construction of new node neeedn't to lock
        std::unique_ptr<node> new_node(new node(value));
        // lock head
        std::lock_guard<std::mutex> lock(head.m);
        new_node->next = std::move(head.next);
        head.next = std::move(new_node);
    }

    template<typename Function>
    void for_each(Function f)
    {
        // the node of head is a fixed and virtual node
        // it means no one can change it, so there is no "race condition"
        // -- when multiple threads execute the follow sentense
        node *current = &head; 
        // because we need do unlock by self, so unique_lock does
        std::unique_lock<std::mutex> lock(head.m); 
        while(node *next = current->next.get()) // declare a local variable 
                            // -- next in the while's check ????
        {
            // lock the next first and unlock the past succession
            // there is a beautiful name for this process: hand to hand lock ^_^
            std::unique_lock<std::mutex> next_lock(next->m);
            lock.unlock();
            // because head is a virtual node(no data)
            // we should call funtion start at head->next
            f(*next->data);
            current = next;
            lock = std::move(next_lock);
        }
    }

    // expect for unary Predicate
    template<typename Predicate>
    std::shared_ptr<T> find_first_if(Predicate p)
    {
        node *current = &head;
        std::unique_lock<std::mutex> lock(head.m);
        while(node *next = current->next.get())
        {
            std::unique_lock<std::mutex> next_lock(next->m);
            lock.unlock();
            if(p(*next->data))
            {
                return next->data;
            }
            current = next;
            lock = std::move(next_lock);
        }
        return std::shared_ptr<T>();
    }

    template<typename Predicate>
    void remove_if(Predicate p)
    {
        node *current = &head;
        std::unique_lock<std::mutex> lock(head.m);
        while(node *next = current->next.get())
        {
            std::unique_lock<std::mutex> next_lock(next->m);
            if(p(*next->data))
            {
                // usage of smart_ptr and move() can avoid to execute big copy
                std::unique_ptr<node> old_next = std::move(current->next);
                current->next = std::move(next->next);
                next_lock.unlock();
                // needn't to move current to next node
                // because the new next node will satisfiy Predicate, too
            }
            else 
            {
                lock.unlock();
                current = next;
                lock = std::move(next_lock);
            }
        }
    }
};

void Test()
{
    threadsafe_list<int> L;
    for(int i = 0; i < 10; i ++ )   
        L.push_front(i % 5);
    L.for_each([](const int &x){cout << x << ' ';});
    cout << endl;
    L.remove_if([](const int &x){return x == 4;});
    L.for_each([](const int &x){cout << x << ' ';});
    cout << endl;
    auto it = L.find_first_if([](const int x){return x == 1;});
    *it = 1024;
    L.for_each([](const int &x){cout << x << ' ';});
    cout << endl;
    it = L.find_first_if([](const int x){return x == 1;});
    *it = 666;
    L.for_each([](const int &x){cout << x << ' ';});
    cout << endl;
    L.remove_if([](const int &x){return x == 1;});
    L.for_each([](const int &x){cout << x << ' ';});
    cout << endl;
    
}

int main()
{   
    PRINT_BEGIN;
    Test();
    PRINT_END;  
    return 0;
}
```

> 学到了个新东西

可以在 while 的条件判断里面声名一个局部变量，并且可以在 while body 里面使用，但是有个限制，就是只能使用默认比价方式（0，nullptr），如果你想使用特殊的比较方式，例如：`while((int y = x + 1) != 3)`，那么局部变量 y 的作用域实际上是 `(int y = x + 1)` 这个括号里面，除了括号就死了，因此在 while body 里面也就无法使用，这时候，就得在 while 外面声明这个变量了。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int x = 1;
    while(int y = x + 1)
    {
        cout << y << endl;
        x ++ ;
        if(y > 10)  break;
    }
    return 0;
}
```





## P7 data struct without mutex

<font color=blue> TODO</font>











## P8 concurrency design

<font color=blue> TODO</font>

文章主要内容包括：

* 线程间划分数据的技术
* 影响并发代码性能的因素
* 性能因素是如何影响数据结构的设计
* 多线程代码中的异常安全
* 可拓展性
* 并行算法的实现

### 8.1 divide work among threads

 最直白的，对于一个线程，是让他充当一个“全能”线程来完成所有工作，还是充当一个“专业”线程完成一件事情，还是两者混合。等等。诸如此类的选择至关重要。



#### 8.1.1 prepare divide

思想很简单，就是在创建线程之前，把多个任务分为一组，一个线程处理一组任务。

但是这样做仍然有一个不太好的地方，如代码2.8 所示，最后一步仍然是串行的：

``` c++
accumulate_block<Iterator,T>()
(block_start,last,results[num_threads-1]); 
```

不过，accumulate 实际上是一个递减操作（即任务的个数是逐渐减少的），因此当线程数量大于一个线程上最小处理项时，可以对函数递归调用，这样就可以最大化并行的程度。

> 原本递归是等一个子函数执行完，再执行另一个子函数。但是通过线程，我们可以同时递归执行多个子函数，自函数再递归执行多个自函数，每个子函数占用一个线程。
>
> 可以发现，这对线程数量的要求比较高！



#### 8.1.2 recursion divide

快速排序就用到了递归！

下面是 list 的快速排序算法的实现：

``` c++
// TODO
```



#### 8.1.3 work divide

多线程下有两个危险需要分离。

1. 第一个是对错误的担忧（主要表现为线程间共享着很多的数据）
2. 第二个是不同的线程需要相互等待。

这两种情况都是因为线程间很密切的交互。如果这种情况发生，就需要看一下为什么发生这么多交互。当所有交互都有相同的问题，就应该使用但线程来解决，并将引用同一源的线程提取出来。或者当有两个线程需要频繁的交流，在没有其它线程时，就可以将这两个线程合为一个线程。

当任务会应用到相同的任务序列，去处理独立的数据项时，就可以使用 pipeline 系统进行并发。

使用这种方式划分工作，可以为流水线中的每一阶段操作创建一个独立线程。

### 8.2 performance of concurrency

> [关于cpu的核和芯](https://blog.csdn.net/weixin_34074740/article/details/92960920)
>
> 原生多核，封装多芯
>
> 作者说，四核两芯的cpu可以有16个线程，是因为超线程吗？



#### 8.2.1 cpu count

为了拓展线程的数量，且与硬件所支持的并发线程数一致，C++ 标准库提供了 `std::thread::hardware_concurrency()`，使用这个函数可以知道在给定硬件上可以拓展的线程数量。

> 我的 MacBook M1 Air 才是 8



使用的线程个数不是越多越好，太多线程进行切换会导致 oversubscription(超额请求)

#### 8.2.2 race data and cache ping-pong

当多个线程在不同的处理器上时，对数据的读取通常不会有问题，因为数据会拷贝到每个线程的缓存中，并让多个处理器同时处理。然鹅，当有线程对数据进行修改，并且需要同步到其它核心的缓存时，需要浪费一定的时间。这样的修改可能会让其它处理情停下来，等待硬件内存更新缓存的数据。并且，根据 cpu 指令，这是一个特别慢的操作。

> **high contention**：处理器之间经常需要等待数据的更改
>
> **low contention**：处理器之间很少需要相互等待
>
> **cache ping-pong**：在多个处理器的缓存之间来回传递的数据

避免 cache ping-pong 的方法就是减少两个线程对同一个内存为止的竞争

#### 8.2.3 false sharing

cache line sharing

其实就是减少缓存的刷新次数，降低数据伪共享缓存的概率。

#### ….

### 8.3 design data struct for multiple thread environment

当为多线程设计数据结构时，需要考虑：contention, false sharing, data proximity(数据临近)，这些对性能都有重大影响。











































## P9 advance thread management





## P10 parallel algorithm





## P11 test and debug in multiple thread environment

**[TODO]**

## A Myheader

``` C++
/* 
@copyright jyyyx
    __
.__(.)< (qaq ~~~)
\____)
~~~~~~~~~~~~~~~~~-->
When I write this, only god and me konw what the program mean
Now, only god konws QAQ

*/

#ifndef MY_HEADER_GUARD
#define MY_HEADER_GUARD

#include <thread> // C++ Concurrency Library for thread's management
#include <mutex> // std::mutex & std::mutex_guard
#include <condition_variable> // condition_variable & condition_variable_any
#include <future> // future & async
#include <shared_mutex> // std::shared_mutex

#include <iostream>

#include <string>
#include <cstring>
#include <algorithm>    // for_each
#include <ratio>    // class ratio

#include <memory> // unique_ptr
#include <exception>

#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <type_traits> // result_of
#include <numeric> // accumulate
#include <functional>   // mem_fn
#include <utility>
#include <chrono>   // std::chrono, time point, time duration
#include <exception>    // copy_exception renamed to make_exception_ptr
#include <iomanip>   // put_time

#include <cmath>

#include <stdint.h>
#include <unistd.h>
#include <time.h>

#include <climits>
#include <ctime>

/*================ header ================*/

#define PRINT_BEGIN std::cout << "|------ begin ------|" << std::endl;
#define PRINT_END   std::cout << "|------- end -------|" << std::endl;


std::mutex some_mutex;


#endif 
```



## B std::atomic

### 0. reference

[ref1](https://juejin.cn/post/7086226046931959838) 

[ref2](https://www.cnblogs.com/haippy/p/3284540.html)

[ref3](https://subingwen.cn/cpp/atomic/)

### 1. introduce

`#include <atomic>`

原子类型(`std::atoimic<T>`)是封装了一个值的类型，它的访问保证不会导致数据的竞争，并且可以用于在不同的线程之间同步内存访问。

原子类型主要用于避免加锁解锁时的程序开销，从而提高性能。(互斥量加锁一般针对的是一个代码段，而原子操作针对的一般是一个变量)。

原子类型是“指令”层面上的支持，因此它的性能相比锁和消息传递会好很多。

std::atomic 内部使用了 CAS(compare and swap) 自旋锁：

``` c++
int CompareAndSwap(int *ptr, int expceted, int new) {
    int actual = *ptr;
    if(actual == expected) *ptr = new;
    return *actual;
}
/*===================================*/
void lock(lock_t *lock) {
    while(CompareAndSwap(&lock->flag, 0, 1) == 1) 
        	; // spin
}
```



### 2. std::atomic_flag

`std::atomic_flag`是原子布尔类型，它保证是免锁（lock-free）的。只支持两种操作：`test-andset` 和 `clear`

``` c++
#include <myheader.h>

using namespace std;

// 必须使用 ATOMIC_FLAG_INIT 初始化，否则值是 UB
// 即，既不是 set 也不是 clear
// 该宏将使得 atomic_flag 处于 clear 状态
std::atomic_flag alock = ATOMIC_FLAG_INIT;

void f(int n)
{
    for(int i = 0; i < 2; i ++ )
    {
        while(alock.test_and_set(std::memory_order_acquire)) // 获得锁
            ;
        std::cout << "Output from thread " << n << "\n";
        alock.clear(std::memory_order_release);  // 释放锁
    }
}

int main()
{   
    PRINT_BEGIN;
    std::vector<std::thread> v;
    for(int i = 0; i < 10; i ++ )
        v.emplace_back(f, i); // 通过 emplace 传入线程和参数
    for(auto &it : v)   
        it.join();
    PRINT_END;  
    return 0;
}
```



自旋锁

> 自旋锁是**计算机科学用于多线程同步的一种锁**，线程反复检查锁变量是否可用。 由于线程在这一过程中保持执行，因此是一种**忙等待**。 一旦获取了自旋锁，线程会一直保持该锁，直至显式释放自旋锁。 自旋锁避免了进程上下文的调度开销，因此对于线程只会阻塞很短时间的场合是有效的。



C++ 是系统级别的编程语言，标准委员会的目标是不需要比C++还要底层的高级语言。C++ 应该向程序员提供足够的灵活性，无障碍的去做他们想要做的事情。需要时，也可以“接触硬件”。原子类型和原子操作就可以**“接触硬件”**，并提供底层同步操作，通常会将指令数缩减到 1～2 个CPU指令。

<font color = blue> TODO ⌛️⌛️⌛️ </font>

一个简单的示例：

``` c++
#include <iostream>
#include <thread_pool_cpp.h>

using namespace std;

#define MAX_COUNT 10000

struct Counter 
{
    mutex m;
    // int value;
    atomic<int> value;
    Counter(int _value = 0) : value(_value) {}
    void produce()
    {
        for(int i = 0; i < MAX_COUNT; i ++ )
        {
            value ++ ;
            // cout << "increment number: " << value 
            //     << ", threadID: " << hex << this_thread::get_id() << "\n";
            // this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
    void consume()
    {
        for(int i = 0; i < MAX_COUNT; i ++ )
        {
            value -- ;
            // cout << "decrement number: " << value 
            //     << ", threadID: " << hex << this_thread::get_id() << "\n";
            // this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
};

void Test()
{
    Counter c(0);
    auto increment = bind(&Counter::produce, &c);
    auto decrement = bind(&Counter::consume, &c);
    thread t1(increment);
    thread t3(decrement);
    thread t4(decrement);
    thread t2(increment);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << c.value << endl;
;}

int main()
{
    PRINT_BEGIN;
    Test();
    PRINT_END;
    return 0;
}
```















# C:thread_pool

## 站在巨人的肩膀上

> [document](https://subingwen.cn/categories/Linux/)
>
> [multiple thread](https://www.bilibili.com/video/BV1sv41177e4/?p=19)    [document](https://subingwen.cn/linux/threadpool/#1-%E7%BA%BF%E7%A8%8B%E6%B1%A0%E5%8E%9F%E7%90%86)
>
> 
>
> [thread pool in C](https://www.bilibili.com/video/BV1jV411J795/?spm_id_from=333.999.0.0&vd_source=38033fe3a1f136728a1d6f8acf710b51)
>
> 
>
> 

## 一、 多线程

### 1. 概念

> 可以通过sleep稍微控制线程的执行顺序。。。

一个线程就是一个“任务”，当我们创建一个线程时，它就开始执行这个任务。

### 2. 创建线程

我们创建的线程一般称为子线程，为啥不是主线程呢？因为主线程一般是默认存在的！当我们在一个进程中创建线程时，主进程会变成主线程。

因此，当主线程退出时，也就意味着主进程结束了，也就意味着分配的虚拟内存空间要释放，因此其余线程也要销毁。

但是，我们可以通过调用相关API，使得主线程退出后，子线程也可以正常运行。

`pthread_create();`

### 3. 线程退出

在上面提到，如果主线程退出，子线程没执行完也会结束。我们也提到，只需要使用（线程退出函数）就可以让当前线程“马上退出”，并且不会影响其他线程的正常运行。

如果所有线程都使用了线程退出函数，那么当所有线程执行结束之后，系统资源（虚拟地址空间）会被操作系统回收。

`pthread_exit();`

当线程退出时，还可以通过该函数传出一些数据（其实是这些数据的地址）。 注意不能传出栈中的数据。

可以通过下面三种方式：

1. heap
2. 全局/static
3. 接受主线程（调用线程）中的数据，并传出接受的数据。

子线程是不能访问主线程的栈空间的，但是主线程可以主动传入。

### 4. 线程回收

主线程回收子线程资源。

回收什么资源呢？

我们知道，线程独占stack等，当线程结束时，stack资源会自动释放，heap，data和text等共享资源由操作系统自动回收。

主线程回收的主要是“内核资源”。这件事子线程自己干不了。

`pthread_join(tid, **retval);`

为什么第二个参数接受一个二级指针呢？

因为我们如果要接受`pthread_exit();` 返回的数据，就要使用一个指针（``void*``）接受。因为 `pthread_exit` 返回的数据类型就是 `void*`。

如果我们要修改一个指针（注意不是指针指向的数据），就要传入一个指针的地址，所以我们就要用指向指针的指针。

注意 join 是一个阻塞函数。

### 5. 线程分离

detach：分离

默认情况下，主线程和子线程是有联系的，即，主线程需要释放子线程拥有的资源。

调用这个函数之后，指定的子线程和主线程分离。当子线程推出的时候，其占用的内核资源就被系统的其他进程接管并回收了。（这意味着 `pthread_join()` 无法回收子线程资源）

可能你会问，我们已经有了 `join` 了啊，他已经可以完成线程内核资源回收的任务了，为什么还有有 `detach` 呢，这是因为 `join` 是阻塞性函数，也就是说，当子线程不 `exit` 时，主线程就会一直处于阻塞状态。

`detach` 就是给主线程减负的，当子线程结束时，其资源不需要主线程来回收。

但是当主线程结束时，子线程仍然会结束，即使子线程处于 `detach` 状态。如果我们希望主线程结束时不影响子线程的执行，应该调用 `exit` 函数。 

## 二、线程同步

### 1. 为什么要同步

``` c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX (25)
int sum;    

void* add(void *arg)
{
    char ch = *(char*)arg;
    for(int i = 0; i < MAX; i ++ )
    {
        int old = sum;
        old ++ ;
        // do something to make thread run currency worse
        usleep(5);
        sum = old;
        printf("[%c]sum = %d\n", ch, sum);
    }
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t p1, p2;
    char c1 = 'A', c2 = 'B';
    pthread_create(&p1, NULL, add, (void*)&c1);
    pthread_create(&p2, NULL, add, (void*)&c2);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("End, sum = %d\n", sum);
    pthread_exit(NULL);
    return 0;
}
```

上面代码希望通过两个线程实现对 sum 的累加，并希望结果为50，但是却不是。

### 2. 互斥锁

如其名，互斥锁只能被一个线程使用。

通过互斥锁，让线程线性执行，这样就不会有并发问题。

锁的个数取决于临界资源而不是线程个数。

另外，可以发现使用互斥锁的函数都是用的mutex指针，这就说明我们的mutex不能分配在 局部内存。

``` c
// create mutex
pthread_mutex_t mutex;
// init
int pthread_mutex_init(pthread_mutex_t *restrict mutex,const pthread_mutexattr_t *restrict attr);
// destory
int pthread_mutex_destory(pthread_mutex_t *mutex);
// lock，已经lock会阻塞
int pthread_mutex_lock(pthread_mutex_t *mutex);
// 已经lock会失败
int pthread_mutex_trylock(pthread_mutex_t *mutex);
```

key :strict

> 用来修饰指针，只有这个关键字修饰的指针才能访问指向的内存地址，其他指针都是不行的（类型匹配也不行）。
>
> **TODO:** 但是我测试不行？？

``` C++
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void add(int *restrict p)
{
     ++ *p;
    int *q = (int*)p;
    ++ *q;
}

int main()
{
    int x = 1;
    add(&x);
    printf("%d\n", x);


    return 0;
}
```

### 3. 读写锁

读写锁是互斥锁的升级版。在做读操作的时候可以提高程序的执行效率，如果所有的线程都是读操作，那么都是并行的。而使用互斥锁，读操作是串行的。

其与互斥锁的区别主要在于读操作可以并行，因此，当线程涉及到大量读操作，读写锁的效率比互斥锁高。

读写锁虽然有读锁和写锁，但他是「一把锁」。

写锁的优先级比读锁高。

API:

``` c++
// declare
pthread_rwlock_t rwlock;
// init
int pthread_rwlock_init(pthread_rwlock_t *restrict rolock, const pthread_rwlockattr_t *restrict attr);
// destory
int pthread_destory(pthread_rwlock_t *rwlock);
// read lock，如果已经加了写锁，线程阻塞
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
// try read lock，如果已经写了写锁，失败返回，不会阻塞
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
// write lock，只要加了锁（读/写）就会失败，阻塞
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
// try write lock
int pthread_rwlock_tryrwlock(pthread_rwlock_t *rwlock);
// unlock
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
```

Example：下面是，5个线程执行读操作，3个线程执行写操作。

``` c++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>

#define MAX (20)
#define READ_COUNT  (5)
#define WRITE_COUNT (3)

int sum;    
pthread_rwlock_t rwlock;

void* func_read(void *arg)
{
    for(int i = 0; i < MAX; i ++ )
    {
        pthread_rwlock_rdlock(&rwlock);
        printf("Thread read, id = %lu, sum = %d\n", pthread_self(), sum);
        pthread_rwlock_unlock(&rwlock);
        usleep(rand() % 5);
    }
    return NULL;
}

void* func_write(void *arg)
{
    for(int i = 0; i < MAX; i ++ )
    {
        pthread_rwlock_wrlock(&rwlock);
        int cur = sum;
        cur ++ ;   
        sum = cur;
        printf("Thread write, id = %lu, sum = %d\n", pthread_self(), sum);
        pthread_rwlock_unlock(&rwlock);
    }
}

int main()
{
    pthread_rwlock_init(&rwlock, NULL);
    pthread_t rd[READ_COUNT], wr[READ_COUNT];

    for(int i = 0; i < READ_COUNT; i ++ )
    {
        rd[i] = pthread_create(&rd[i], NULL, func_read, NULL);
    }
    for(int i = 0; i < WRITE_COUNT; i ++ )
    {
        wr[i] = pthread_create(&wr[i], NULL, func_write, NULL);
    }
    for(int i = 0; i < READ_COUNT; i ++ )
    {
        pthread_join(rd[i], NULL);
    }    
    for(int i = 0; i < WRITE_COUNT; i ++ )
    {
        pthread_join(wr[i], NULL);
    }
    // expect sum = 60
    printf("Father thread id = %ld\n, sum = %d", pthread_self(), sum);
    pthread_exit(NULL);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
```

运行之后，我们可以发现，所有打印出来的 sum 是升序的，这说明我们的读写锁没有问题，另外，我们可以发现，有大量读操作在最后才执行，这是因为前面说的，当一个读操作和一个写操作同时访问同一个临界资源时，写操作的优先级更高。

### 4. 条件变量

严格意义上来说，条件变量的主要作用不是处理线程同步，**而是进行线程的阻塞。**

如果多线程下只使用条件变量无法完成线程的同步，必须要配合互斥锁来使用。

那既然有了互斥锁，为什么还要用条件变量呢？主要是为了处理「生产者和消费者模型」。（常规的临界资源只有一份，只允许一个线程访问，而有时候临界资源可能有多份，可以分给多个线程，这就是条件变量的用处）

APIs

``` c++
// declare
pthread_cond_t cond;
// create
int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict atrt);
// destroy
int pthread_cond_destroy(pthread_cond_t *cond);
// wait，会阻塞
int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex); // 可以发现，这里使用了一个互斥锁;其中，互斥锁是用来同步的，条件变量是用来阻塞线程的。
// time wait，将线程阻塞一段时间
int pthread_cond_timewait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime); // 阻塞时间为 sec + nsec。
// signal specific one，至少有一个被解除阻塞
int pthread_cond_signal(pthread_cont_t *cond);
// signal all，唤醒阻塞在条件变量伤的线程，被阻塞的线程全部解除阻塞
int pthread_cond_broadcast(pthread_cond_t *cond); 	// 将所有线程唤醒之后，只有wait成功的线程才会执行，剩下的wait失败的线程会继续阻塞。
```

为什么 pthread_cond_wait() 的参数有一个 mutex？

> 首先，我们需要知道 wait 做了什么？
>
> 1. 释放自己占据的 mutex（作为参数传入）
> 2. 阻塞，等待被别的线程唤醒
> 3. 被唤醒后，再次获取 mutex（作为参数传入）
>
> 现在明白了吧，一般来说，我们执行 cond_wait 的时候，都是已经 mutex_lock 的，如果我们不 unlock 的话，其他线程就无法进入临界区，也就无法 cond_signal，那么被阻塞的线程也就不会被唤醒。也就发生了死锁。

example1：生产者消费者模型 - 链表

``` C++
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define COUNT (5)

typedef struct node_t {
    int val;
    struct node_t *next;
} Node;

pthread_mutex_t mutex;
pthread_cond_t cond;
Node *head;

void* produce(void *arg)
{
    unsigned long id = (unsigned long)arg;
    while(1)
    {
        // 链表不可能满，除非malloc错误
        pthread_mutex_lock(&mutex);
        int val = rand() % 1000;
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->next = NULL;
        newNode->val = val;
        if(newNode == NULL)
        {
            printf("[Producer] id = %ld, malloc Wrong\n", id);
        }
        newNode->next = head;
        head = newNode;
        printf("[Producer%d] id = %lu, val = %d\n", id, pthread_self(), val);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);
        // pthread_cond_broadcast(&mutex);
        sleep(rand() % 3);
    }
    return NULL;
}

void* consume(void *arg)
{
    unsigned long id = (unsigned long)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(head == NULL)
        {
            // 阻塞消费者进程，并释放它的锁，否则，它既占据着mutex，又占据cond，就会死锁
            pthread_cond_wait(&cond, &mutex);   
        }
        Node *cur = head;
        head = head->next;
        printf("[Consumer%d] id = %lu, val = %d\n", id, pthread_self(), cur->val);
        free(cur);
        pthread_mutex_unlock(&mutex);
        sleep(rand() % 3);
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    pthread_t t1[COUNT], t2[COUNT];
    for(int i = 0; i < 5; i ++ )
    {
        pthread_create(&t1[i], NULL, produce, (void*)i);
        pthread_create(&t2[i], NULL, consume, (void*)i);
    }
    for(int i = 0; i < 5; i ++ )
    {
        pthread_join(t1[i], NULL);
        pthread_join(t2[i], NULL);
    }
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    return 0;
}
```

> 在这个生产者消费者模型中，我们使用链表储存产品，因为理论上可以存储无限个产品，所以只需要使用一个条件变量判断产品队列是否为空。
>
> 如果使用数组，即产品是有限的，那么我们还需要一个新的条件变量来判断产品是否满了。
>
> 注意我们不能同时使用同一个条件变量判断是否为满和是否为空。

example2：生产者消费者模型 - 数组

``` c++
1
```

### 5. 信号量

同条件变量一样，信号量主要用于阻塞线程，不能完全保证线程安全，如果要保证线程安全，需要信号量和互斥锁一起使用。

另外，需要注意信号量的wait和条件变量的wait是不同的，这从参数列表就可以发现，信号量的wait参数列表中并没有 mutex 参数，因此，当线程阻塞时，他不会释放获取的 mutex 资源，因此，我们必须通过手工的方式控制信号量和锁的获取顺序：先获取信号量，再获取锁，以避免死锁。

`<semaphore.h>`

``` c++
// declare
sem_t sem;
// create
int sem_init(sem_t *sem, int pshared, unsigned int value);
	// pshared
		// 0: 线程同步
		// !0:进程同步
	// value:初始化当前信号量拥有的资源数，如果资源数为0，线程就会被阻塞了。
// destroy
int sem_destroy(se_t *sem);
// wait，if value==0，阻塞
int sem_wait(sem_t *sem);
// trywait，不会阻塞，直接失败
int sem_trywait(sem_t *sem);
// timewait，资源数为0时，阻塞线程，在阻塞 abs_timeout 对应的时间之后，解除阻塞线程
int sem_timedwait(sem_t *sem, const struct timespec, *abs_timeout);
// post
int sem_post(sem_t *sem);
// get shared value
int sem_getvalue(sem_t *sem, int *sval);
	// 第二个参数返回 shared-value，返回值是用来错误检查的
```

example：生产者和消费者模型

### 6. timespec

``` c++
struct timespec {
    time_t tv_sec;	// 秒
    long tv_nsec;	// 纳秒
};
// -------
time mytim = time(NULL);
struct timespec tmsp;
tmsp.tv.nsec = 0;
tmsp.tv_sec = time(NULL) + 100;	// 线程阻塞100秒s
```

## 三、线程池

### 1. 原理

为什么要有线程池

> 同内存池的设计需求一样，线程池也是用来避免线程的大量创建和销毁所带来的巨大开销。

线程池的组成部分

1. 任务队列：线程就是用来处理任务的，但是可能任务的个数要远大于线程的个数，因此无法一次性处理完所有的任务，因此我们就需要用一个 data struct（一般为数组 or 链表） 将任务存起来。
2. 工作的线程：处理任务队列的任务的消费者，通常有多个。
3. 管理者线程：不处理任务队列的任务，负责管理工作的线程（增加或者销毁线程），只有一个。

任务队列的存在也意味着，线程池就差不多是一个生产者消费者模型。线程池负责为负消费者线程和任务队列，而使用者负责维护生产者线程（通过线程池提供的 API 接口）。

任务队列存储的是任务，而任务通常是一个个（回调）函数，因此任务队列需要存储函数的地址。



``` c++
工作线程是一直不停的干活，管理线程是间隔检测的。
如何“销毁”线程？让他们自杀
没干活的线程在哪呢？通过worker函数可以发现，没工作的线程都阻塞在了条件变量里面，那么我们可以唤醒所有线程。
```

### 2. 虚假唤醒

<font color=blue>TODO</font>

# C++:thread_pool



















































