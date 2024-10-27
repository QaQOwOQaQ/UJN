# C++ Memory Management

## 0x00 prelogue

### 1. source

候捷 C++ 内存管理课程 笔记

[DL Malloc](https://gee.cs.oswego.edu/)

[A Memory Allocator](https://gee.cs.oswego.edu/dl/html/malloc.html)

### 2. english

macro：宏

### 3. quote

0x01 万丈高楼平地起

0x02 西北有高楼，上与浮云齐（为什么孔雀东南飞，因为西北有高楼）



## 0x01 primitives

### 1. 分配内存的层级

![img](https://s3.bmp.ovh/imgs/2023/03/08/401ce1768fecfa41.png)

malloc 并不是 c++ 的一部分，它属于更低阶的 c 中的 c-runtime-library 的一部分。

调用层次太低阶会导致移植性变差，所以最好不要在程序中使用底层调用函数。

### 2.c++ primitivies

![c++](https://s3.bmp.ovh/imgs/2023/03/08/b8ef04e0d7761b29.png)

测试：

``` c++
// ::operator new
void *pp = ::operator new(sizeof(int));
// int *p = new(pp) int(4);
// cout << *p << endl;
::operator delete(pp);  // 必须加括号，因为是个函数
// allocator
int *pa = allocator<int>().allocate(5);
for(int i = 0; i < 5; i ++ )
    *(pa + i) = i + 10;
for(int i = 0; i < 5; i ++ )
    cout << pa[i] << ' ';
cout << endl;
allocator<int>().deallocate(pa, 5);
```

### 3. new expression

不能直接调用构造函数，非要调用的话，可以通过 `placement new` 来调用

``` C++
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <memory>
#include <numeric>
#include <algorithm>
#include <limits>   // not limits.h !! 

#define V2

using namespace std;

typedef struct node_t {
    int val;
    int len;
    node_t() = default;
    node_t(int _val, int _len) : val(_val), len(_len) {}
} Node;

int main()
{
    // now, we want Node *pn = new Node(1,2);
    // compiler will conver this sentense in followings 

    Node *pn = nullptr;

    // like this way 1
#ifdef V1
    try {
        void *mem = operator new(sizeof(Node));
        pn = static_cast<Node*>(mem);
        // pn->Node::Node(1,2);    // 注意只有编译器能调用构造函数，因此本行编译不通过
        operator delete(mem);
    }
    catch(std::bad_alloc &c) {  // pass by ref
        cout << c.what() << endl;
    }
#endif 
    // like this way 2
#ifdef V2
    try {
        long long cnt = numeric_limits<long long>::max();
        void *mem = operator new(cnt * sizeof(Node));
        pn = new(mem) Node(1,2);
        cout << pn->val << ' ' << pn->len << endl;
    }
    catch(std::bad_alloc &c) {  // pass by ref
        cout << c.what() << endl;
    }
#endif 
    return 0;
}
```

### 4. delete expression

可以直接调用析构函数。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef struct node_t {
    int val;
    int len;
    node_t() = default;
    node_t(int _val, int _len) : val(_val), len(_len) {}
    ~node_t() { cout << "dtor" << endl; }
} Node;

void testMyType()
{
    Node *newNode = new Node(1,2);
    cout << newNode->val << ' ' << newNode->len << endl;
    // now we want to delete newNode
    // delete newNode;
    // like this way in compile:
    newNode->~Node();     // after dtor, newNode convert to a no-type pointer
    operator delete(newNode);   // free memory
    // operator delete call free()
    
    // And you can found, we can call dtor directly
    // but we cant call ctor directly
    // And we not use newNode->Node::~Node(); to delete
    // but if we want to ctor(if we can do)
    // we must use like ptr->Node::Node(x,y); 
    // because ptr is not a Node type object current
    // so Node() it not the member function for ptr
}

void testBuiltInString()
{
    string *sptr = new string("hello,world!");
    cout << *sptr << endl;
    // sptr->~basic_string<char>();    
    // [Warning]
    // In old version, you cant write like followings
    // becuase string is a typedef of basic_string<char>
    // but now, it is valid....
    sptr->~string();
    delete sptr;
}

int main()
{
    testMyType();
    puts("-----------------------");
    testBuiltInString();
    
    return 0;
}
```

### 5. array new/delete

`array new` 在设计时，都会在分配的空间中添加一个 `cookie`用来保存一些额外信息，最重要的信息之一就是数组的长度。

`array new` 和 `operator new` 需要配套使用的一个底层原因是，operator new 和 array new 分配出来的内存结构可能是不同的，例如，`array new` 分配出来的一块内存可能包含一个长度信息，而 `operator new` 则不需要。

另外，在析构函数没有意义（对象内没有动态分配的资源…）的情况下，可能可以使用 `operator delete` 来释放 `array new`，注意，是可能。因为 `operator delete` 会释放 `array new` 分配在堆上的所有内存，内存不会少释放，但是只会调用一次析构函数，因为析构函数没有意义（没有实际作用），所以说，调用一次与调用多次的效果都是一样的。当然，只是有可能，正如上面说的，他们的内存结构可能是不同的。

所以说，千万不要尝试通过 delete 释放 new[]，千万不要！

### 6. placement new

Placement new 允许我们将 objects 构建与 allocated memory 中。

没有所谓的 placement delete，因为 placement new 根本就没有分配 memory。

当然，你可以称呼 placement new 对应的 operator delete 为 placement delete。因为我们需要为 placement new 重载一个对应的 operator delete。

同 operator new 一样，编译期在内部也会对 placement new 进行转换：



测试：

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef struct node_t {
    int val;
    int len;
    node_t() = default;
    node_t(int _val, int _len) : val(_val), len(_len) {}
    ~node_t() { cout << "dtor:" << this << endl; }
} Node;

void testPlacementNew()
{
    char s[] = "hello,world!";
    void *buf = ::operator new(strlen(s) + 1);
    char *str = new(buf) char;
    strcpy(str, "Hello,World");
    cout << str << endl;
    ::operator delete(buf); // match operator new
}

void testPlacementNew2()
{
    char *buf = new char[sizeof(Node) * 3];
    void *nullp;
    Node *p = new(nullp) Node(1, 2);    // wrong!
    cout << p->val << ' ' << p->len << endl;
    delete[] buf;   // match array new
    /* --------  */
    /* placement new 语句就想当下面的四条语句，发现其实和operator new是一样的
       这是因为 placement new 其实就是调用的 operator new，是不是是其一个重载版本
       这个重载版本第二个参数接受一个指针，在这个指针分配的内存上构造对象
       因此说，我们要保证这个指针不为空或者未定义。。
    Node *p;
    void *mem = operator new(sizeof(Node), buf);
    p = static_cast<Node*>(mem);
    p->Node::Node(1, 2);
    */
}



int main()
{
    testPlacementNew();
    puts("-----------------");
    testPlacementNew2();
    return 0;
}
```

### 7. 分配内存的途径（流程）

![memory](https://s3.bmp.ovh/imgs/2023/03/08/e0d5986e17ce2219.png)



### 8. 重载

我们可以重载 class member operator new()，并且重载多个版本，前提是每一个版本都有独特的参数列。重载 new() 必须其第一参数是 **size_t**，其余参数以 new 所指定的 **placement arguments** 作为初值。出现于 new(..) 小括号内的便是 **placement arguements**。此类形式都可以称为**“placement new”**。

例如：`Type *p = new(arg1, arg2, ... argn) Type;`

其中的 `arg1, arg2, ... argn` 就是 placement arguments。

----

我们可以重载 class member operator delete()，写出多个版本，但他们绝不会被 delete 调用。**只有当 new 所调用的 ctor 抛出 exception 才会调用这些重载版的 oeprator delete()。**它只可能这样被调用，主要用于清理未能称完全创建成功的 object 所占用的 memory。

即使 operator delete 未能一一对应与 operator new，也不会出现报错，你的意思是，放弃 ctor 抛出的任何异常，

#### 8.1 重载全局函数

重载全局 operator new 和 全局 operator delete，注意重载全局 new 和 delete 是很危险的！

下面是某一版本的 operator new 和 operator delete 的实现：

![deleteAndnew](https://s3.bmp.ovh/imgs/2023/03/08/a5000dbfa22f85f9.png)

测试：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef struct node_t {
    int val;
    int len;
    node_t() = default;
    node_t(int _val, int _len) : val(_val), len(_len) {}
    // ~node_t() { cout << "dtor:" << this << endl; }
} Node;

void *myAlloc(size_t size)
{
    return malloc(size);    
}

void myFree(void *ptr)
{
    free(ptr);
}

inline void* operator new(size_t size)
{
    cout << "operator new" << endl;
    return myAlloc(size);
}

inline void* operator new[](size_t size)
{
    cout << "operator new[]" << endl;
    return myAlloc(size);
}

inline void operator delete(void *ptr, size_t)
{
    cout << "operator delete with size" << endl;
    myFree(ptr);
}

inline void operator delete(void *ptr)
{
    cout << "operator delete" << endl;
    myFree(ptr);
}

inline void operator delete[](void *ptr)
{
    cout << "operator delete[]" << endl;
    myFree(ptr);
}

inline void operator delete[](void *ptr, size_t)
{
    cout << "operator delete[] with size" << endl;
    myFree(ptr);
}

void test()
{
    int *p = new int(10);
    // 调用operator delete(void*, size_t)
    // 而不是 operator delete(void*)
    // 很疑惑。。
    delete p; 
}
void test2()
{   
    int *q = new int[5]{
        1, 2, 3, 4, 5
    };
    delete[] q;
}
void test3()
{
    // 也是调用 operator delete with size_t
    Node *fp = new Node(2,1);
    delete fp;
}
void test4()
{
    Node *fparr = new Node[5];
    delete[] fparr;
}

int main()
{
    test();
    puts("---------------------");
    test2();
    puts("---------------------");
    test3();
    puts("---------------------");
    test4();
    return 0;
}
```

经过测试之后发现，operator new 调用的是带有 size_t 参数的那个 operator delete，这是为什么呢？⚠️[TODO]

#### 8.2 重载 class 中的函数

这是更推荐的重载行为。注意在重载 class 中的 new 和 delete时，要将他们设置为 static，因为一般在调用 new 和 delete 时，对象还没有产生。

测试：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void* operator new(size_t size, char ch, size_t extra)
{
    cout << "global operator new" << endl;
    cout << "size: " << size << endl;
    cout << "char: " << ch << endl;
    cout << "extra: " << extra << endl;
    return malloc(size + extra);
}

class Node {
public:
    int val;
    Node(int _val = 0) : val(_val) {}
    ~Node() { cout << "dtor: " << this << endl; }
public:
    static void* operator new(size_t size)
    {
        cout << "operator new(size_t): " << size << endl;
        return malloc(size);
    }
    static void* operator new(size_t size, char ch)
    {
        cout << "operator new(size_t, char): " << size << ',';
        cout << "char: " << ch << endl;
        return malloc(size);
    }
    static void* operator new[](size_t size)
    {
        cout << "operator new[]: " << size << endl;  
        return malloc(size);
    }
    // 此 operator new 没有对应的 operator delete
    // 并且它回调了全局的 operator new
    void* operator new(size_t size, size_t extra)
    {
        return ::operator new(size, 'A', extra);
    }
public:
    static void operator delete(void *ptr)
    {
        cout << "operator delete" << endl;
        free(ptr);
    }
    static void operator delete(void *ptr, size_t size)
    {
        cout << "operator delee with size_t: " << size << endl;
        free(ptr);
    }
    static void operator delete(void *ptr, char ch)
    {
        cout << "operator delete with char" << ',';
        cout << "char: " << ch << endl;
        free(ptr);
    }
    static void operator delete[](void *ptr)
    {
        cout << "operator delete[]" << endl;
        free(ptr);
    }
};


void test1()
{
    Node *p = new Node;
    delete p;
}

void test2()
{
    // Node的大小是4，但是array new分配出来是12
    // 也就是说，多分配了8个字节
    // 因此，sizeof(p) = 8 + 4 * sizeof(Node)
    Node *p = new Node[10];
    delete[] p;
}

void test3()
{
    Node *p = new('A') Node;
    delete p;   // 不会调用带 char 的operator delete
}

void test4()
{
    size_t extra = 2;
    Node *p = new(2 * sizeof(Node)) Node;
    // p一共分配了3个Node的空间，但即使我们使用了多余三个，可能结果也是正确的
    // 注意！内存越界问题是未定义行为，什么叫未定义行为？
    // 你测试起来是正确的，别人测试起来是正确的，但在最重要的客户手中却失败了！
    
    extra = 10;
    for(size_t i = 0; i < extra; i ++ ) (*(p + i)).val = i + 10;
    for(size_t i = 0; i < extra; i ++ ) cout << p[i].val << ' ';
    cout << endl;
    delete p;
}

int main()
{
    // test1();
    // puts("------------------------------");
    // test2();
    // puts("------------------------------");
    // test3();
    // puts("------------------------------");
    test4();
    return 0;
}
```

### 9. allocator 

#### 9.1 allocator 1.0

**shortcoming:**

1. 复用性差：operator new/delete 的重载放在了 class 实现中，如果我们想在另一个类中添加分配器，就需要再写一次

2. 额外空间大：原本我们希望通过内存池设计，减少cookie的内存，但是我们却在class中添加了一个指针，原本只有一个 int 占 4 字节。现在添加了一个指针变成了 16 字节，足足扩大了 4 倍，当然，在我们的 class 原本体积就很大时，例如 100 字节，那么 8 字节的指针大小其实是可以忽略的。但是我们应该有更好的办法解决 next 指针的问题。

``` c++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstring>
#include <stdlib.h>

#define TEST

using namespace std;

class Foo {
public:
    Foo(int _val = 1024) : val(_val), next(nullptr) {}
    Foo(int _val, Foo *_next) : val(_val), next(_next) {}
    static void* operator new(size_t size);
    static void operator delete(void *ptr, size_t);
    static void grabage_collection();    // 清理空闲链表
public:
    static Foo* freeStore;               // 空闲链表
    static const int FooChunk = 24;      // 每次分配多少个Foo
private:
    static void allocate_new_memory(size_t size);
#ifdef TEST
public:
#endif 
    int val;
    Foo *next;  // 串连空闲链表
};

// 定义static成员时，不需要再加上static
Foo* Foo::freeStore = 0;
inline void Foo::allocate_new_memory(size_t size)
{
    if(freeStore)   return ;
#ifdef TEST
    cout << "Call allocate_new_memory!" << endl;
#endif 
    size_t chunk = FooChunk * size; 
    Foo *p = nullptr;
    p = freeStore = (Foo*)malloc(chunk);
#ifdef TEST
    int count = 0;
#endif
    for(p = freeStore; p != &freeStore[FooChunk - 1]; ++ p)
    {
#ifdef TEST
        cout << "[" << ++ count << "]" << " p: " << p << "; p + 1: " << p + 1 << endl;
#endif 
        p->next = p + 1;
    }
    p->next = 0;
}

inline void Foo::grabage_collection() // cant run！
{
    if(freeStore == nullptr)    return ;
    cout << "can free" << endl;
    void *ptr = (void*)freeStore;
    free(ptr);
}

inline void* Foo::operator new(size_t size)
{
    Foo *p = nullptr;
    if(freeStore == nullptr)
        allocate_new_memory(size);
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}

void Foo::operator delete(void *p, size_t)
{
    static_cast<Foo*>(p)->next = freeStore;
    freeStore = static_cast<Foo*>(p);
}

void test1()
{
    cout << "size: " << sizeof(Foo) << endl;
    static int n = 1024;
    Foo *p[n];
    for(int i = 0; i < n; i ++ )
    {
        p[i] = new Foo(i + 1);
        cout << "[" << i << "] now addr: " << p[i] << endl;
    }
    for(int i = 0; i < n; i ++ )
    {
        delete p[i];
    }

    Foo *tra = Foo::freeStore;
    int count = 0;
    while(tra != nullptr)
    {
        cout << "[" << ++count << "] " << tra->val << endl;
        tra = tra->next;
    }
}

void test2()
{
    Foo *p[10];
    for(int i = 0; i < 10; i ++ )
    {
        p[i] = ::new Foo();
        cout << p[i] << endl;  
    }
}

int main()
{
    test1();
    puts("Test end ...");
    return 0;
}
```

#### 9.2 allocator 2.0

在上一个版本中，我们提到了，我们在 class 当中，我们添加了一个成员变量 `*next*`，这是必要的，因为我们需要将那些放在空闲链表中的内存块串成一个链表。但是，当我们使用某个内存块之后，它的 `next` 指针就没有用了，因为此时它已经不存在与空闲链表中，所以说，我们可以通过 `union`，将我们的数据 `val` 和 `*next*` 放到同一个地址空间，这样就可以解决 `*next*` 带来的额外内存消耗。

一般的，我们称这种设计中的 `*next*` 指针为： **embeded pointer（嵌入式指针）**

Code:

``` C++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <assert.h>

#define TEST

using namespace std;

class Foo {
public:
    static void *operator new(size_t size);
    static void operator delete(void *ptr, size_t);
    static Foo* freeStore;
    static const size_t chunkSize = 24;

public:
    Foo(int _val = 0) : val(_val) {}
    ~Foo();
    int get() const { return val; }
private:
    static void allocateNewMemory(size_t size);
#ifdef TEST
public:
    // 节省内存
    union {
        int val;
        Foo *next;
    };
#endif 
};

Foo *Foo::freeStore = nullptr;

inline void Foo::allocateNewMemory(size_t size)
{
    size_t chunk = chunkSize * size;
    // 不要直接在函数中 new/malloc
    void *mem = malloc(chunk);
    assert(mem);
    Foo *p = nullptr;
    p = freeStore = static_cast<Foo*>(mem);
    for(size_t i = 0; i < chunkSize - 1; i ++ )
        p[i].next = p + (i + 1);
    p[chunkSize - 1].next = nullptr;
}

inline void *Foo::operator new(size_t size)
{
    // 内存分配有误，交给全局 operator new 处理
    if(size != sizeof(Foo))
    {
        cout << "size[" << size << "] not match" << endl; 
        return ::operator new(size);
    }
    Foo *p = nullptr;
    if(freeStore == nullptr)
        allocateNewMemory(size);
    assert(freeStore);
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}
inline void Foo::operator delete(void *ptr, size_t size)
{
    // 可以删除nullptr
    if(ptr == nullptr)  return ;
    if(size != sizeof(Foo))
        return ::operator delete(ptr);
    // 删除只是重新添加到空闲链表
    static_cast<Foo*>(ptr)->next = freeStore;
    freeStore = static_cast<Foo*>(ptr);
}

Foo::~Foo()
{
    static int dtorCount = 0;
    cout << "[" << dtorCount << "] " << "dtor: " << val << endl;
}

void test()
{
    static int n = 32;
    Foo* f[n];
 
    for(int i = 0; i < n; i ++ )
    {
        f[i] = new Foo(i + 10);
        // 间隔只有8，而不是16了！
        // 另外，不同的内存大块之间是不连续的
        // 我们每次只分配24个内存小块
        // 所以说每24个小块之间可能不连续
        cout << "Ctor[" << i << "] " << f[i] << ", val= " << f[i]->get() <<  endl;
    }
    for(int i = 0; i < n; i ++ )
        delete(f[i]);
    int freeCount = 0;
    Foo *p = Foo::freeStore;
    while(p)
    {
        cout << "Del[" << ++freeCount << "] " << p << ", val= " << p->get() << endl;
        p = p->next;
        if(freeCount >= 32)  
        {
            break ;
        }
    }
}

int main()
{
    puts("Test end....");
    test();
    return 0;
}
```



#### 9.3 allocator 3.0

在 2.0 版本中，我们解决了 `*next*` 指针的额外内存消耗问题，但是还有一个问题我们还没有解决，那就是复用性差的问题，对于每一个 class，如果想要使用我们的分配器，就要重载一遍 operator new/delete，这不仅会导致代码的大量重复，导致代码膨胀，维护难等问题，还完全不符合面向对象的设计思想，我们是在 OOP 中写程序！

解决方案也很简单，就是将 operator new/delete 的重载部分拿出来，单独放在一个 class allocator 当中，然后让需要使用的 class 包含 allocator，然后调用接口即可！

taik is cheap，show me your code：

> 在 `void* MyAllocator::allocate(size_t size)` 中我应该是写出了一个比较经典的 bug 了。😅😅😅😅

``` c++
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <assert.h>

#define TEST

using namespace std;

class MyAllocator {
public:
    void* allocate(size_t size);
    void deallocate(void *ptr, size_t);
private:
    struct obj {
        struct obj *next; // embeded pointer(嵌入式指针)
    };
#ifdef TEST
public:
#endif 
    obj* freeStore = nullptr;
    const size_t CHUNK = 5;
};

class Foo {
public:
    // Foo() = default;
    Foo(int _cnt = 1024, double _price = 10.25) 
    : count(_cnt), price(_price) {}
    ~Foo() { cout << "[Dtor] " << this << endl; }
    int getCount() const { return count; }
    double getPrice() const { return price; }
public:
    static MyAllocator myAlloc;
    static void* operator new(size_t size)
    {   
        if(size != sizeof(Foo))
        {
            cout << "alloc error" << endl;
            return ::operator new(size);
        }
        return myAlloc.allocate(size);  
    }
    static void operator delete(void *ptr, size_t size)
    {
        if(size != sizeof(Foo))
        {
            cout << "delete error" << endl;
            return ::operator delete(ptr, size);   
        }
        return myAlloc.deallocate(ptr, size); 
    }
private:
#ifdef TEST
public:
#endif
    int count;
    double price;
};

MyAllocator Foo::myAlloc;

void* MyAllocator::allocate(size_t size)
{
    obj *p = nullptr;
    if(freeStore == nullptr)
    {
        cout << "call new memory!" << endl;
        size_t chunk = CHUNK * size;
        void *mem = malloc(chunk);
        assert(mem);
        p = freeStore = static_cast<obj*>(mem);
        for(size_t i = 0; i < CHUNK - 1; i ++ )
        {
            // [WARNNING] [BUG]
            // 注意不可能写为下面的形式
            // p[i].next = &p[i + 1];
            // 因为p虽然是一个obj对象，但是我们要把它当做一个Foo对象
            // 所以我们要移动的距离是sizeof(Foo)
            // 但是在上面的形式中，我们移动的距离是sizeof(obj)
            p->next = (obj*)((char*)p + size);
            p = p->next;
        }
        p->next = nullptr;
    }
    p = freeStore;
    freeStore = freeStore->next;
    return p;
}
void MyAllocator::deallocate(void *ptr, size_t)
{
    static_cast<obj*>(ptr)->next = freeStore;
    freeStore = static_cast<obj*>(ptr);
}

void test()
{
    cout << "SIZE: " << sizeof(Foo) << endl;
    static int N = 16;
    Foo *f[N];
    for(int i = 0; i < N; i ++ )
    {
        // f[i] = new Foo(Foo(i, i * 1.1)); 
        f[i] = new Foo;
        cout << "Ctor[" << i << "] " << f[i] << endl;
    }
    for(int i = 0; i < N; i ++ )
    {
        f[i]->count = (i + 1);
        f[i]->price = (i + 1) * 1.1;
    }
    for(int i = 0; i < N; i ++ )
    {
        cout << f[i]->getCount() << ' ' << f[i]->getPrice() << endl; 
    }
    for(int i = 0; i < N; i ++ )
        delete f[i];
    auto p = Foo::myAlloc.freeStore;
    int counter = 0;
    while(p && counter < N)
    {
        cout << "cur: " << p << endl;
        p = p->next;
        counter ++ ;
    }
}

void test2()
{
    for(int i = 0; i < 10; i ++ )
    {
        // Foo *f = new Foo(i, i + 10);
        // cout << "addr: " << f << ' ' << f->getCount() << ' ' << f->getPrice() << endl;
        // delete f;
    }
    // Foo *f = new Foo(1, 1024);
    // cout << "addr: " << f << ' ' << f->getCount() << ' ' << f->getPrice() << endl;
}

int main()
{
    test();
    test2();
    puts("Test end......");
}
```

#### 9.4 allocator 4.0

虽然是 4.0，但是它并没有什么更高级的设计，只不过是将 3.0 中的 class 封装设计改为 macro(宏) 设计。

不建议使用 macro，代码不给出了。



### 10. new handler

new handler 提供给你一个机会阻止可能发生的异常(bad_alloc)，因为如果异常产生，程序可能会直接terminate，new handler 就是 c++平台给你提供的补救措施。

在 《Effective C++》提到过，new_handler 做5件事，但真正有用的可能就两件：

1. 分配更多的内存
2. 调用 exit() 和 abort()

![IMG](https://s3.bmp.ovh/imgs/2023/03/09/6542ab298879ce75.png)

![IMG](https://s3.bmp.ovh/imgs/2023/03/09/6673d1b83363c6dc.png)

### 11. =default,=delete

>  It is not only for constructors and assignments,  but also applies to operator new/new[], operator delete/delete[] and their overloads(for =delete)



## 0x02 std::allocator

chunk：大块

block：小块

`G2.9` 的 std::alloc 并没有“释放”内存，他只是把分配的内存重心放入内存池，严格来说，这不算是内存泄漏，因为内存仍然在自己手上，只不过没有释放罢了。之所以不真正 free，是因为难度较大。这也是 alloc 的一个争议点，因为在多用户，多任务系统中，你独占如此大的memory却不释放，肯定不好。

战备池 Pool：

1. 如果战备池为空，分配新内存
2. 能分配几个就分配几个
   * 一个都不能分配，处理碎片，分配新内存
   * 分配战备池

判断指针 p 是否为 null，看以下两种写法：

1. `if(0 == p) {}`
2. `if(p == 0) {}`

我们通常都是第二种写法，但是第一种写法更好，因为如果我们不小心将 `==` 写成了 `=`，编译器会报错，而在第二种写法中，编译会顺利通过，并带来灾难性的后果且不以排查。

但是在现代 c++ 中，我们有 nullptr，不需要担心了。😊

侯捷老师说在第四章会有解决方案，这个“内存泄漏”问题终于解决了！

----

operator delete(ptr)

operator delete(ptr, size_t)

在 class 中可不可以并存吗？并存会报错？

---

round(x,n) = (x+(n-1)) & ~(n-1)

---

malloc 把 VA 分为 32 个 group，每个 group 又分为 8 个page

所以最多有 32*8=256 个 page

而在 tagRegion 中，有 32 个 tagGroup

每个 TagGroup 有 64 个双向链表，总共 2048 个双向链表

---

4080 = 4096 - 8(黄色的两个0xffffffff) - 8(保留/浪费，因为需要16对齐)

4096 - 8 = 4088 not 16 的倍数，因此需要对齐减去 8

16，32，48, 。。。。>=1024 (16 aligned)

Cookie 保存长度信息，这个长度信息包含cookie本身

---

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

vector<int> vec;
list<int> ls;

static size_t c;
static int sum;

typedef struct node_t {
    long long va;
    char ch;
} Node;

void *operator new(size_t size)
{
    sum += size;
    c ++ ;
    cout << "size: " << size << endl;
    return malloc(size);
}

void operator delete(void *ptr, size_t size)
{
    free(ptr);
}

int main()
{
    // for(int i = 0; i < 3; i ++ )  ls.push_back(1);
    // cout << c << endl;
    // cout << sum << endl;
    // cout << pow(2,18) << endl;
    Node *newNode = new Node;   // 16
    
    cout << 68 + 256 + 32 * 516 << endl;
    cout << 16 * 1024 << endl;
    cout << 32 * 64 << endl;
    cout << 0x130 + 8 << endl;
    return 0;
}
```

---

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unistd.h>

using namespace std;

int main()
{
    void *test = sbrk(0);
    cout << "start heap brk: " << test << endl;
    test = sbrk(0x20ff8000);    // 0x9a0000
    cout << "after sbrk() brk: " << test << endl;   // 0x9a0000
    void *p = malloc(sizeof(0x20ff8000));
    test = sbrk(0);
    cout << "after use, brk: " << test << endl;// 0x21998000
    cout << hex <<  0x20ff8000 + 0x9a0000 << endl;
    /*
    即使移动了brk位置，在实际使用之前，Linux也不会给进程分配内存的。
    必须要等到实际写内存的时候，产生了缺页中断后，Linux系统才会申请一个物理内存页给进程。内核申请物理内存页的函数是get_free_pages()。
    */
    return 0;
}
```

----

通过 header -> group -> free-list  来切分，使得每一块内存都比较小，因此全部回收的可能性就更大

如果每一块内存都是 1MB，那么它的回收就很困难

例如即使 1MB 中有 1023KB 没有使用，我们也不能回收它。

---

group头部的size就可以很方便的告诉我们，是否可以全回收。

每个page内的内存块的合并是积极的。

page全回收之后不会立即释放，当等到再有一个page全回收时，才会释放。

## 0x03 malloc/free

## 0x04 loki::allocator

### 1. Loki SourceCode

> [New Version Source Code](https://loki-lib.sourceforge.net/html/a00671.html)
>
> [别人做的分析](https://www.cnblogs.com/UnGeek/p/4537114.html)

### 2. 旧版本的两个 bug

#### （1） 无限循环

在旧版本的 `VicinityFind` 函数中，如果我们传入的 `p` 不是经由 `chunk` 分配的话，那么在 `for` 中会无限循环。这是因为当 `lo` 和 `hi` 都为 `false` 时，没有判断条件来使得 `for` 退出。

这是更正版的代码，在我们标识出的 `(1)` 和 `(2)` 处，添加了判断，这样当 `lo` 和 `hi` 都为 `false` 时，循环就会退出并返回 `NULL`。

``` c++
Chunk * FixedAllocator::VicinityFind( void * p ) const
{
    if ( chunks_.empty() ) return NULL;
    const std::size_t chunkLength = numBlocks_ * blockSize_;
    Chunk * lo = deallocChunk_;
    Chunk * hi = deallocChunk_ + 1;
    const Chunk * loBound = &chunks_.front();
    const Chunk * hiBound = &chunks_.back() + 1;
    // Special case: deallocChunk_ is the last in the array
    if (hi == hiBound) hi = NULL;
    {
        if (lo)
        {
            if ( lo->HasBlock( p, chunkLength ) ) return lo;
            if ( lo == loBound )
            {
                lo = NULL;
                if ( NULL == hi ) break;	// （1）
            }
            else --lo;
        }
        if (hi)
        {
            if ( hi->HasBlock( p, chunkLength ) ) return hi;
            if ( ++hi == hiBound )
            {
                hi = NULL;
                if ( NULL == lo ) break;	// （2）
            }
        }
    }
    return NULL;
}
```

#### （2） chunk 不会回收 [TODO]

看下面回收操作的代码：

![img](https://s3.bmp.ovh/imgs/2023/03/21/dbe229b367a5733b.png)



其中，绿色框框出的代码块就是处错的代码，而红色框框出的代码块是导致绿色代码块处错的根源。

先看红色的代码块：意思是，我们释放了一块内存之后发现它所在 `chunk` 为空，并且这个 `chunk` 不是最后一个 `chunk`，如果此时最后一个 `chunk` 非空的话，说明有两个空 `chunk`，所以我们需要删除一个，由于 `vector` 从中间删除效率很低，所以我们肯定删除最后一个 `chunk` 了。

``` c++
| A | F1 | A | A1 | F2 |
    -->
| A | F1 | A | A1 |，释放 A1
    -->
| A | F1 | A | F |，A1 变为 F
```

如上图所示，我们当前的空 `chunk` 为 `F1`（F 表示 Free，A 表示Allocate），之前的空 `chunk` 是 `F2`，然后我们删除了 `F2`。

好，假设我们现在不停的释放 `chunk A1`，直到它为空。

此时，`vector<chunk>` 中显然有两个 `Free chunk`（F 和 F1），但是我们的 `DoDeallocate` 函数无法清除其中一个 `Chunk`。

因为此时，``F1` 虽然 `Free`，但它没有位于 `vector` 的尾部。

而我们的回收操作，是基于一个假设的：

> Free Chunk 一定在 vector 的尾部。

此时，假设不成立！

所以说，我们不能依赖于该假设，而是要显示的用一个变量来指示，之前 Free 但没有回收的 Chunk在哪里，这就是改正 BUG 之后的新版本的做法。



## 0x05 other::allocator













