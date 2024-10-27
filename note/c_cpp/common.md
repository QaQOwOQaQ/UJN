# Design Patterns[TODO]

## 0x01. 依赖转置原则

### ref1

例如人吃巧克力：

``` C++
public interface IChocolates{}

public class Oreo implements IChocolates {}

public class Dove implements IChocolates {}

public interface Person { void eat( IChocolates chocolates ); }
```



上面的例子中人对巧克力产生了依赖，那人吃的行为依赖其实跟巧克力没有关系，在巧克力出现之前就已经存在了，因此吃的动作依赖的接口应该是人本身内部的概念，这个接口的归属权应该属于人，概念应该为可食用的（edible）。因此人对巧克力的依赖关系应该倒置为巧克力对可食用接口的依赖。这样倒置之后对人来说具有了更好的扩展性，不仅可以吃各种不同的巧克力，还可以吃饼干，米饭，鱼肉等等其它任何可吃的东西。

``` C++
public interface IChocolates extends IEdible{}

public class Oreo implements IChocolates {}

public class Dove implements IChocolates {}

public interface Person { void eat( IEdible edible ); }
```

### ref2

[REF](https://blog.csdn.net/li1358159/article/details/123306664)



### ref3

[REF](https://blog.csdn.net/u012346890/article/details/111034907?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-111034907-blog-123306664.pc_relevant_aa2&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-111034907-blog-123306664.pc_relevant_aa2&utm_relevant_index=1)

在例子中，如果我们让上层 dirver 依赖于底层的细节 car，那么就完全错误了。

我们应该让 diver 依赖于抽象的 CAR，让具体的 car 继承自抽象的 CAR。 



## 0x02 装饰模式

### ref1

[原文链接](https://blog.csdn.net/qq_40594696/article/details/107611074)

1.什么是装饰模式

装饰模式是一种用于替代继承的技术。它无需定义子类却可以给对象动态增加职责，使用对象之间的关联关系取代类之间的继承关系。

举个栗子：一张照片，不改变照片本身，给它增加一个相框，使他增加防潮的功能，这就是装饰模式。

装饰模式是一种对象结构型模式，他以对客户透明的方式动态的给一个对象附加上更多的责任，可以在不需要创建更多子类的情况下让对象的功能得以扩展。

 

2.装饰模式的结构

（1）**Component（抽象构件）：**它是具体构件和抽象装饰类的共同父类，声明了在具体构建中实现的业务方法，它的引入可以使客户端以一致的方式处理未被装饰的对象以及装饰之后的对象，实现客户端的透明操作。

（2）**ConcreteComponent（具体构件）：**它是抽象构件的子类，用于定义具体的构建对象，实现了在抽象构建中声明的方法，装饰类可以给它增加额外的职责。

（3）**Decorator（抽象装饰类）：**他也是抽象构件的子类，用于给具体构件增加职责，但是具体职责在其子类中实现。它维护一个指向抽象构件对象的引用，通过该引用可以调用装饰之前构件对象的方法，并通过其子类扩展该方法，以达到装饰的目的。

（4）**ConcreteDecorator（具体装饰类）：**它是抽象装饰类的子类，负责向构件添加新的职责。每一个具体装饰类都定义了一些新的行为，他可以调用在抽象装饰类中定义的方法，并可以增加新的方法用于扩充对象的行为。

### ref2

[refreence](https://blog.csdn.net/zhshulin/article/details/38665187)

####### [更好的 ref – c++ 实例](https://blog.csdn.net/NEXUS666/article/details/115672452)

## 0x03 代理模式

[引用计数](https://blog.csdn.net/starlee/article/details/1647412)

[引用计数](https://blog.csdn.net/u012344185/article/details/114497309)

[jk时间 – 好文](https://time.geekbang.org/column/article/169263)



## 0x04 工厂模式

现实生活中，工厂是负责生产产品的；同样在设计模式中，简单工厂模式我们可以理解为**负责生产对象**的一个类，称为“工厂类”。

## 0X05 原型模式

原型模式定义了一个 virtual 拷贝构造函数，C++ 有吗？ C++ 没有虚拷贝构造

[ref1](cloud.tencent.com/developer/article/1686487)

[ref2](https://zhuanlan.zhihu.com/p/365222623)

[ref3](cnblogs.com/jylz/p/10648439.html)



# STL[TODO]

## prelogue

### 0x01 导读 

候捷 STL 与 范型编程学习笔记。

### 0x02 英语

identity：同一，本身

### 0x03 problem

[1](https://blog.csdn.net/nirendao/article/details/115815599?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0-115815599-blog-110736211.pc_relevant_3mothn_strategy_and_data_recovery&spm=1001.2101.3001.4242.1&utm_relevant_index=3)

[2](https://blog.csdn.net/luolaihua2018/article/details/110736211)

[3](https://blog.csdn.net/u013317445/article/details/89680330)

[4](https://www.jianshu.com/p/6b526aa481b1)

## 一、container

大家风范：用前置++，–实现后置++，–

仿函数：函数对象

关联：有key和value

array就是把数组包装成一个class

deque：dai ke

set, map:红黑树.c++并未规定必须使用红黑树，只不过红黑树效率高，因此各大制定标准库的公司都使用红黑树。

set的key就是value，value就是key。



哈希表由一个个桶（bucket）组成，每个桶都是一个链表（link）。现在哈希表大多采用分离链表发（yxc：拉链法）实现。



头文件有保护机制，多次引入没问题



vector空间两倍增长(成长)

（2）vector 有一个机制是这样的，如果新加入一个元素，比如通过push_back()，但是size 大于了capacity，那么vector 就会重新找一块更大的地方再把数据放进去。重新分配的过程：**申请一块新的内存 > 拷贝数据 > 释放原内存**。

 2、vector扩容怎么拷贝？

经常问的一个问题，vector怎么扩容？最简单的回答就是先申请内存，再拷贝，最后销毁原来的内存，然后是1.5倍还是2倍，解释一下。

但是！我看到有人问，怎么拷贝？？？what？？？

没想到吧，看书还是看漏了。

拷贝用的是uninitialized_copy，如果拷贝的是POD（标量型别，也就是trivial）调用的是copy（自己去看STL 的copy实现），如果是non-POD使用for循环遍历，调用construct，一个一个的构造，针对char*和wchar_t*，uninitialized_copy直接用memmove来执行复制行为，更加快。

版权声明：本文为CSDN博主「m0_60126088」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/m0_60126088/article/details/119616254

虽然标准库提供了sort函数，但是一些函数也提供了自己的sort，当容器存在自己的sort的时候，优先使用容器自己的，它自己的肯定更好，不然它提供这个函数干嘛。

forward_list 和 list 提供了自己的 sort

forward_list使用头插法。因此只能在链表头插入元素。



[deque容器底层实现](http://c.biancheng.net/view/6908.html)



queue 和 stack 由于元素进出的顺序是死的（固定的），因此他们没有迭代器，如果有迭代器的话，我们就有可能通过迭代器改变元素进出的顺序，这是不合理的。

set，map底层是红黑树（自平衡二叉查找树）



multimap不可以用下标做 iterator

hashtable 的 bucket 比 元素个数还有要多是合理的，因为元素中间会空出很多 bucket。事实上，bucket的个数肯定比元素个数多，否则的话 bucket 就要重新扩充变为原来的（大约）两倍。（经验法则，避免 bucket 的长度太长）（以空间换时间）

map的底部就是一个 pair

map，set 会丢掉重复元素

从测试结果我们可以看出，使用insert()插入元素的方式并不能覆盖掉相同key的值；而使用[]方式则可以覆盖掉之前的值。为什么会出现这样的结果呢？

原因分析
我们可以通过源码来找原因，在map的源码中，insert方法是这样定义的：

``` C++
pair<iterator,bool> insert(const value_type& __x) 
    { return _M_t.insert_unique(__x); }
```

他调用_M_t.insert_unique(_x)方法，该方法会首先遍历整个集合，判断是否存在相同的key，如果存在则直接返回，放弃插入操作。如果不存在才进行插入。
而[]方式是通过重载[]操作符来实现的，它直接进行插入或覆盖



>  今天调试程序，弄得有点纠结。无意间，和一帮同事讨论起一个问题：进程结束操作系统会回收new的内存吗？在自己的印象中，一直固执地认为，在使用C++操作分配对象内存后，如果程序员自己不用相应的delete操作回收的话，这块从堆内存是一直存在。在讨论中，有同事提醒说，在进程结束后，new操作的内存会被回收。但也只是结论，也说不出具体理由。
>
>     没关系，何不google一下，一查下去，答案已是清晰：
>
>     “内存泄漏不是系统无法回收那片内存，而是你自己的应用程序无法使用那片内存。当你程序结束时，你所有分配的内存自动都被系统回收，不存在泄漏问题。但是在你程序的生命期内，如果你分配的内存都不回收，你将很快没内存使用。”再用自己的一句话来概括的话就是：操作系统本身就有内存管理的职责，一般而言，用malloc、new操作分配的内存，在进程结束后，操作系统是会自己的回收的。但某些系统态的资源，用特殊的系统API申请的内存就不一定了，比如：linux中的shmget申请的共享内存，就与进程结束无关了。
>
>      经过这一番查找，不禁自己为自己汗颜了一把，之前还以为自己对内存管理理解较深，现在才明白：在没有认真深入地钻研过操作系统内核原理之前，所有对内存管理的理解还是浮在表面上的。这次讨论也分外地提醒自己，自己知识的盲区还有许多，还要不断的踏踏实实地努力学习啊！
>
>  ------------------------------------------------
>
>  版权声明：本文为CSDN博主「stanjiang2010」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
>  原文链接：https://blog.csdn.net/stanjiang2010/article/details/5386647



不建议使用分配器。

oop企图将data和method关联在一起

gp企图将data和method分离开



[容器内存分配](https://blog.csdn.net/y1196645376/article/details/52938474)

```C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>

using namespace std;

void test1();
void test2();
void test3();
void test4();

class test 
{
    public:
        typedef pair<int,int> PII;
        PII p;
};

template<typename T>
class complex
{
    public:
        complex(T _val) : val(_val) {}
        T val;
        template<typename U>
        friend complex<U> cal(complex<U> a, complex<U> b);
};

template<typename T>
complex<T> cal(complex<T> a, complex <T> b)
{
    complex<T> c(a.val + b.val);
    return c;
    // return complex(a.val + b.val);
}


int main()
{
    test3();
    return 0;
}

/*====================================================*/

void test3()
{
    test::PII p = {1,2};
    cout << p.first << ' ' << p.second << endl;
    complex<int> a(1);
    complex<int> b(2);
    cout << a.val << ' ' << b.val << endl;
    complex<int> c = cal(a, b);
    cout << c.val << endl;
}

void test1()
{
    vector<int> vec;
    cout << vec.capacity() << endl;
    cout << &vec << endl;
    vec.push_back(1);   // add -> cap:1
    cout << vec.capacity() << endl;
    cout << &vec << endl;
    vec.push_back(1);   // add -> cap:2
    cout << vec.capacity() << endl;
    cout << &(vec[1]) << endl;
    vec.push_back(1);   // add -> cap:4
    cout << vec.capacity() << endl;
    cout << &(vec[1]) << endl;
    vec.push_back(1);
    vec.push_back(1);   // add -> cap:8
    cout << vec.capacity() << endl;
    cout << &(vec[1]) << endl;
    for(int i = 0; i < 1000000; i ++ )   vec.push_back(i);
    cout << &vec << endl;
}

void test2()
{
    map<int,int> m;
    m.insert({1,1});
    cout << m[1] << endl;
    m.insert({1,2});
    cout << m[1] << endl;
    cout << m.size() << endl;
    m[2] = 3;
    cout << m.size() << endl;
    m[1] = 3;
    cout << m[1] << endl;
}
```



## 二、alloactor 



容器的幕后英雄。

所有的分配和释放动作最后都会跑到 malloc 和 free 去。

分配器的 allocate 和 deallocate 最终都是使用 malloc 和 free

直接使用分配器在释放内存的时候，还需要指出需要释放的内存大小。

因此并不建议直接使用分配器分配内存。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void* operator new(size_t size, string s)
{
    cout << "s: " << s << endl;
    return malloc(size);
}

int main()
{
    int *x = new("hello") int;
    auto a = allocator<int>();   
    int *p = a.allocate(512, 0);
    a.deallocate(p, 512);
    return 0;
}
```





## 三、list





不允许 x++ ++

允许 ++ ++ x

所有的容器区间都是前闭后开

在链表中为了保证这个要求，必须要设置一个虚节点（为空）





## 四、vector

内存的扩充一般不会是原地扩充，它会在另一个地方找内存。

``` c++
vector<int> vec;
cout << sizeof(vec) << endl; // 24 = 3 * 8(point)
```

public 继承表示一种 is-a 的关系



## 五、array

array 内部的数据就是一个真的数组，它没有tors

## 六、deque

号称自己拥有连续空间^^

连续是假象，分段是事实。

deque（dei ke）其实是分段连续的。deque的数据由许多个段组成，段与段之间不连续，每个段内连续。

``` C++
#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> q;
    for(int i = 0; i < 10000; i ++ )    q.push_back(i);
    for(int i = 0; i < 10000 - 1; i ++ )
    {
        int *x = &q[i + 1], *y = &q[i];
        if(y - x != -1)  
            cout << y - x << ' ' << &q[i] << ' ' << &q[i + 1] << endl;
    }
    return 0;
}
// 测试结果
-5 0x19d4e6c 0x19d4e80
-5 0x19d507c 0x19d5090
-5 0x19d528c 0x19d52a0
-5 0x19d549c 0x19d54b0
-45 0x19d56ac 0x19d5760
```

deque 的底部实现是一个 vector（称为 map ？？ ），vector 的每个元素是一个指针，每个指针指向一个缓冲区 buffer。



其迭代器是一个类

1. first：当前所在 buffer 的起点
2. last：当前所在 buffer 的重点
3. node：处于（deque控制中心） 的那个段
4. cur：处于当前 buffer 的位置

first 和 last 相当于两个哨兵[first，last) 前闭后开

迭代器在移动的过程中，每次移动都需要判断是否移动到了当前段的末尾，来决定是否需要调到下一个段。（效率低！每次都需要判断一下）



和 vector 一样，deque 也是 2 倍增长的，因此它也有 capacity，事实上标准库并未规定容器的增长细节，但是大多数实现都使用了 2 倍增长。

``` C++
#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int main()
{
    deque<int> q;
    vector<int> vec;
    clock_t start;
    //
    start = clock();
    for(int i = 0; i < N; i ++ )    q.push_back(i);
    cout << (clock() - start) << endl;
    //
    start = clock();
    for(int i = 0; i < N; i ++ )    vec.push_back(i);
    cout << (clock() - start) << endl;
    //
    start = clock();
    int sum = 0;
    for(int i = 0; i < N; i ++ )    sum = q[i];
    cout << (clock() - start) << endl;
    //
    start = clock();
    for(int i = 0; i < N; i ++ )    sum = vec[i];
    cout << (clock() - start) << endl;
    //
    return 0;
}
```



``` C++
15584
16521
79156
3326
```

deque 在拓展的时候 copy 方式是 copy 到新空间的中间位置，以方便前面和后面的扩充。



## 八、queue

`queue<int,  vector<int>> q;` 可以通过编译

但是当我们使用 `q.pop();` 编译器报错

这说明编译器对模板不会进行一个全面的、完整的检测

只有当你用到时才会进行检测



## 九、stack





## 十、Red-Black tree

关联式容器甚至可以看做一个小型数据库

关联式容器的两个重要的底层数据结构：红黑树和哈希表

红黑树就是一颗高度平衡的二叉搜索树

红黑树提供遍历操作和迭代器

编译器会将 size = 0 的class 的size 设为 1

同 link，rb_tree 也设置了一个空节点实现前闭后开区间。

红黑树有【元素自动排序】特性

value[key,date]

``` C++
#include <bits/stdc++.h>

using namespace std;

void test1()
{
    set<int, greater<int>> s; 
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for(auto &x : s)    cout << x << endl;
    set<int>::value_type x = 23.2332;
    set<int>::key_type y = 2.3232;
    cout << x << ' ' << y << endl; 
}
 
 void test2()
 {
    map<int,int>::value_type p = {1,2};
    map<int,int>::value_type::first_type px = 1;
    map<int,int>::value_type::second_type py = 2;
    map<char,char>::key_type c1 = 65;
    map<char,char>::mapped_type c2 = 97;
    
    cout << p.first << ' ' << p.second << endl;
    cout << px << ' ' << py << endl;
    cout << c1 << ' ' << c2 << endl;
 }
 
int main()
{  
    test1();
    test2();
    return 0;
}
```



## 十一、hashtable

hashtable 中有很多经验值

经验法则：如果某个 bucket 的元素个数比 bucket 的个数还要多，就要两倍扩充 bucket 并重新放入元素（rehashing）。





## 十二、 STL 六大部件

容器替我们处理了内存分配上的问题，我们只管往容器里面添加删除元素，至于数据在内存上是怎样分配的，容器替我们解决了。

容器本身并不能处理内存，它是通过分配器来实现内存的分配与回收的。

算法通过迭代器操作容器。

1. 容器
2. 分配器
3. 算法
4. 迭代器
5. 仿函数
6. 适配器



## 十三、新添加待处理

ctor 有必要添加

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Base {
public:
    // Base() {
        
    // }
    Base(int val) {
        cout << "Base" << endl;
    }
    
};

class Derived : public Base {
public:
    Derived(int val) {
        cout << "Derived" << endl;
    }
};

int main()
{
    Derived a(1);   // wrong
    return 0;
}
```

-----

Explicitly specializer:全特化



----

模版别名。

typedef 不可以使用参数

define 虽然可以指定参数，但是必须用（）包围起来，而我们希望使用 <> 包围起来。

``` c++ 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define v(T) vector<T>

using namespace std;

template<typename T>
using vec = vector<pair<T,T>>;

int main()
{
    v(int) a; // 很奇怪
    vec<pair<double,double>> v;
    return 0;
}
```

----



``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

template<typename Container>
void test(Container c)
{
    // 从容器中取出迭代器
    // 每个迭代器都有一个 value_type
    // 通过 value_type 就可以得到容器元素的类型
    typedef typename iterator_traits<typename Container::iterator>::value_type Valtype;
    
    for(int i = 0; i < 10; i ++ )
        c.insert(c.end(), i);
    for(auto &x : c)    cout << x << ' ';
    cout << endl;
}

template<typename T,
            template<typename U>
            typename Container
        >
class C {
private:
    Container<T> c;
public:
    C() {
        for(int i = 0; i < 10; i ++ )
        c.insert(c.end(), i);
        for(auto &x : c)    cout << x << ' ';
        cout << endl;
    }
};

int main()
{
    test(vector<int>());
    C<int, vector> c;
    // C<int, list> c;
    // C<int, queue> c;
    // C<int, map> c;
    // C<int, set> c;
    // C<int, stack> c;
    
    return 0;
}
```

[模板模板参数](https://zhuanlan.zhihu.com/p/409436201)

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename T>
class Foo {
public:
    T a, b;
    Foo() {
        a = 1, b = 2;
        cout << "Ctor for Foo::" << endl;
    }
    ~Foo() {
        cout << "Dtor for Foo::" << endl;
    }
};

template<typename T,
            template<typename U>
            class Container
        >
class C {
private:
    Foo<T> c;
public:
    C() {
        cout << "Ctor for C" << endl;    
    }
    void show() {
        cout << "begin\n";
        cout << c.a << ' ' << c.b << endl;
        cout << "end\n";
    }
};

template<typename T,
            template<typename U>
            class Container
        >
void f(Container<T> c) {
}
        
        

int main()
{
    // f(Foo<int>());
    C<int, Foo> c;
    c.show();
    return 0;
}
```





----

stl

traits：特征，特性

萃取机。

你丢给他某个东西，它可以萃取出这个东西的某些特征。

associated type:

> category
>
> Value_type
>
> Difference_type
>
> pointer
>
> reference

中间件 for：

> class iterator
>
> Native pointer
>
> const native pointer

算法所需要的信息：主要是迭代器的是怎么移动的（方向，大小）

虽然虽然可以直接向迭代器询问，迭代器也可以直接回答，但是如果迭代器不是一个 class，即迭代器如果是一个 native point 的话，他就没有 associate type（5个type），也就无法回答。这时候我们需要一个中间层（trait）来回答算法的询问。

```
iterator_traits<iterator>::type;
```

Bidirectional:双向

----

typeid

```
#include <typeinfo>
typeid(type).name();
```

给 typeid 传入一个 type（typeid(type)），他就会生成一个对象，这个对象有 name() 方法。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <typeinfo>

using namespace std;

void out_tag(random_access_iterator_tag) {
    cout << "random_access_iterator" << endl;
}

void out_tag(bidirectional_iterator_tag) {
    cout << "bidrectional_iterator_tag" << endl;
}

void out_tag(forward_iterator_tag) {
    cout << "forward_iterator_tag" << endl;
}


template<typename Itr>
void out(Itr iter) {
    typename iterator_traits<Itr>::iterator_category category_obj;
    out_tag(category_obj);
    typedef typename iterator_traits<Itr>::iterator_category category_type;
    out_tag(category_type());
    cout << "typeid: " << typeid(category_obj).name() << endl << endl;
    cout << "typeid: " << typeid(category_type()).name() << endl << endl;
}

int main()
{
    out(vector<int>::iterator());
    out(set<int>::iterator());
    out(multiset<int>::iterator());
    out(unordered_set<int>::iterator());
    
    
    return 0;
}
```

----



``` C++ 
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Base {
};

class Derived : public Base{
};

void f(Base b) {
    cout << "you call f()" << endl;
}

void g(Base *b) {
    cout << "you call g(*)" << endl;
}

int main()
{
    Derived d;
    f(d);
    Base *b = new Derived();
    g(b);
    Derived *pd = new Derived();
    g(pd);
    
    return 0;
}
/* 继承表示 is-a 关系
因此可以把子类放到父类里面(子类 is-a 父类)*/
```



---

11 个算法

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

class Myclass {
public:
    int val;
    Myclass() { cout << "Myclass" << endl; val = 0; }
    ~Myclass() { cout << "Dtor for Myclass" << endl; }
    bool operator()(int a, int b) {
        return a < b; 
    }
};

struct Mystruct {
    bool operator()(int a, int b) {
        return a < b;
    }  
}Mstruct;

bool cmp(int a, int b) {
    return a < b;
}

int main()
{
    vector<int> a{1};
    sort(a.begin(), a.end(), Myclass()); // 生成一个临时对象，在 main 函数结束之前便结束
    sort(a.begin(), a.end(), Mstruct);
    sort(a.begin(), a.end(), minus<int>());
    sort(a.begin(), a.end(), cmp);
    
    cout << "main-end" << endl;
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/* 1. accumulate 累计(不是累加，因为还可以指定其他运算方式)
** 指定运算操作时，如果我们传入的是一个函数，那么直接传递函数名即可，
    因为此时相当于我们传入了一个函数指针，函数指针可以类似于函数直接调用。
    例如：void (*ptr)() = &func;
          ptr(); // <==> func();
    但如果我们传入的是一个重载了 () 的函数对象
    我们就必须穿入一个对象，因为只有 class 被实例化为一个 object，
    才能调用它自己的成员函数。
    例如： struct Myclass {
                int operator(int x, int y) { return x + y; }
            }myobj;
            class Myclass { 
                int operator(int x, int y) { return x + y; }
            };
            直接传入 myobj 或者 myclass() 即可，
    如果成员函数是一个模版，还需要指定 <type>
    例如：标准库的 minus
            此时我们传入 minus<int>(); // 传入一个临时对象
*/

/*  2. for_each()
**  例如：
        void func(int x){ cout << x << ' '; }
        vector<int> a{1, 2, 3};   
        for_each(a.begin(), a.end(), func); // 1 2 3
*/

/*  3. replace, replace_if, replace_copy
        count, count_if
    ``` c++
    vector<int> a{1, 4, 3, 4, 5};
    replace(a.begin(), a.end(), 4, 10);
    for(auto &x : a)    cout << x << ' ';   
    cout << endl;   // 1 10 3 10 5 
    replace_if(a.begin(), a.end(), bind2nd(less<int>(), 10), 0);
    for(auto &x : a)    cout << x << ' ';   
    cout << endl;   // 0 10 0 10 0 
    vector<int> b(a.size()); // 必须为 b 分配空间，copy 不会分配空间
    replace_copy(a.begin(), a.end(), b.begin(), 0, 1);
    for(auto &x : b)    cout << x << ' ';   
    cout << endl;   // 1 10 1 10 1 
    vector<int> c; // 或者使用 back_inserter
    replace_copy(a.begin(), a.end(), back_inserter(c), 0, 1);
    for(auto &x : c)    cout << x << ' ';   
    cout << endl;   // 1 10 1 10 1 
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/* 1. accumulate 累计(不是累加，因为还可以指定其他运算方式)
** 指定运算操作时，如果我们传入的是一个函数，那么直接传递函数名即可，
    因为此时相当于我们传入了一个函数指针，函数指针可以类似于函数直接调用。
    例如：void (*ptr)() = &func;
          ptr(); // <==> func();
    但如果我们传入的是一个重载了 () 的函数对象
    我们就必须穿入一个对象，因为只有 class 被实例化为一个 object，
    才能调用它自己的成员函数。
    例如： struct Myclass {
                int operator(int x, int y) { return x + y; }
            }myobj;
            class Myclass { 
                int operator(int x, int y) { return x + y; }
            };
            直接传入 myobj 或者 myclass() 即可，
    如果成员函数是一个模版，还需要指定 <type>
    例如：标准库的 minus
            此时我们传入 minus<int>(); // 传入一个临时对象
*/

/*  2. for_each()
**  例如：
        void func(int x){ cout << x << ' '; }
        vector<int> a{1, 2, 3};   
        for_each(a.begin(), a.end(), func); // 1 2 3
*/

/*  3. replace, replace_if, replace_copy
        count, count_if
     c++
    vector<int> a{1, 4, 3, 4, 5};
    replace(a.begin(), a.end(), 4, 10);
    for(auto &x : a)    cout << x << ' ';   
    cout << endl;   // 1 10 3 10 5 
    replace_if(a.begin(), a.end(), bind2nd(less<int>(), 10), 0);
    for(auto &x : a)    cout << x << ' ';   
    cout << endl;   // 0 10 0 10 0 
    vector<int> b(a.size()); // 必须为 b 分配空间，copy 不会分配空间
    replace_copy(a.begin(), a.end(), b.begin(), 0, 1);
    for(auto &x : b)    cout << x << ' ';   
    cout << endl;   // 1 10 1 10 1 
    vector<int> c; // 或者使用 back_inserter
    replace_copy(a.begin(), a.end(), back_inserter(c), 0, 1);
    for(auto &x : c)    cout << x << ' ';   
    cout << endl;   // 1 10 1 10 1 

    如果函数名后面跟着 _if 表示你要传入一个“条件”
    如果函数名后面跟着 _copy 表示你要传入一个 iterator 用来放置 copy 的元素
        并且作用结果不会作用到原迭代器身上，只是 copy 到新迭代器
*/

/*  4. find & find_if -- 线性时间复杂度 */

/*  5. sort
**   不要拿我们写的 cmp 用于 sort list 和 forward_list
      因为他们的地址不是连续的。而我们写的 cmp 是连续的
*/

/*  6. binary_search
**   二分查找的前提是有序
     binary_search() 调用了 lower_bound()
     然后对 lower_bound 找到的位置进行比较
        first = lower_bound(first, val);
        return (first != last) && (val >= *first);
        // 我感觉后面的 val>=*first 不太必要的，因为如果你 first != last 的话
            // 就说明你肯定找到了，既然找到了，那就应该是合理的！
                // 很奇怪，不知道为啥
     关于 lower/upper_bound
     候捷的解释：
        lower_bound 查找的是 在不改变原数据顺序的前提下
            插入元素可以放入的 最低点
        upper_bound 查找的是 在不改变原数据顺序的前提下
            插入元素可以放入的 最高点
     网络上一般的解释为：
        lower 查找 <=
        upper 查找 >
     其实一样，只不过说法不同
*/


int main()
{
    vector<int> a{1,2,2,2,3};
    auto begin = lower_bound(a.begin(), a.end(),1);
    auto end = upper_bound(a.begin(), a.end(),1);
    cout << *begin << ' ' << *end << endl;
    return 0;
}
```

----

adapter

1. 容器适配器
2. 迭代器适配器
3. 仿函数适配器

一个对象 A 想拥有对象 B  的功能，有两种方式：

1. inherit，继承
2. composition，复合

adapter 是复合

typedef:

binary_function

1. first_arguement_type
2. second_arguement_type
3. result_type

unary_function

1. Argument_type
2. Result_type



`typename + ()` 产生临时对象

借用函数模版的实参推导来完成类模板的实参。

>如果我们直接写类模板的实参 `<>`，我们可能不太好写出类型，我们可以添加一层中间层（函数模板），让函数模板来完成实参类型的推导，然后将类型传给类模板。



``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

void test1() {
    vector<int> a{1,10,2,1,2,5,1,2,3};
    typename less<int>::second_argument_type x = 1 << 31;
    typename less<int>::first_argument_type y = 1 << 31;
    typename less<int>::result_type z = 1 << 31;
    cout << x << ' ' << y << ' ' << z << endl;
}

int main()
{
    auto p = bind2nd(less<int>(), 10);
    binder2nd<less<int>> b2;  // wrong，已经弃用
    return 0;
}
```

Argument 并无参数的意思，之所以被拿来做(参数、变量)的意思是历史原因。



----

bind

取代了 bind2nd, binder2nd, bind1st, binder1st

没写构造函数也可以用 `{}` 初始化



placeholoders

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

void test1() {
    vector<int> a{1,10,2,1,2,5,1,2,3};
    typename less<int>::second_argument_type x = 1 << 31;
    typename less<int>::first_argument_type y = 1 << 31;
    typename less<int>::result_type z = 1 << 31;
    cout << x << ' ' << y << ' ' << z << endl;
}

void test2() {
    auto p = bind2nd(less<int>(), 10);
    // binder2nd<less<int>> b2;  // wrong，已经弃用
}

double my_divide(double a, double b) {
    return a / b;
}

void test3() {
    // _1, _2。。 在 std::placeholders 里面
    // auto f1 = bind(my_divide, std::placeholders::_1, std::placeholders::_2);
    // cout << f1(10, 2) << endl;   // 5
    
    // auto f2 = bind(my_divide, std::placeholders::_2, std::placeholders::_1);
    // cout << f2(10, 2) << endl;   // 0.5
    
    // auto f3 = bind(my_divide, 10, std::placeholders::_1);   // 这里 10 被绑定到第一个参数
    // cout << f3(200) << endl;  // 10 / 200
   
    // auto f5 = bind(my_divide, std::placeholders::_1, 10);
    // cout << f5(100) << endl;    // 10
   
   
    /*  --  */
    /* 占位符_n会选择 [我们传入的] 第n个参数 */
    auto f4 = bind(my_divide, 10, std::placeholders::_2);   // 这里 10 被绑定到第一个参数
    cout << f4(3,2) << endl;   // 3.33，选择我们传入的第二个参数2
   
    auto f6 = bind(my_divide, std::placeholders::_2, 10);
    cout << f6(3,5) << endl;    // 5 / 10，选择我们传入的第二个参数5
}

int main()
{
    test3();
    return 0;
}
```
