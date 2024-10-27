





# Essential C++

## 0x00 附录

### 1. 站在巨人的肩膀上

[Oracle C++用户指南](https://docs.oracle.com/cd/E19205-01/820-1214/index.html)

### 2. 英语 

parameter：参数列表

classes hierarchy：类层次体系

string literal：字符串常量

character literal：字符常量

dereferencing：(指针)解引用，提领

placehold：占位符

function prototype：函数原型

debugger：调试器

scopre：作用域

predicate：谓词

unary：一元

partition：分区

populate：填充 

###  3. 基于对象的编程风格

基于对象（Object Based）：使用了“对象“的概念，把状态和行为封装在一个对象的内部。

面向对象（Object Oriented）：使用了“对象”的概念，同时还有“继承”和“多态”的概念。

所以，**面向对象**基本上是**基于对象**的一个子集。同时由于面向对象很重视“继承”和“多态”，所以也可以认为面向对象更多是“**面向类**”的。

候捷：基于对象中，类之间的关系比较弱，而面向对象中，类之间的关系很密切。

## 0xf2 函数与头文件

### 1. 随机数

如果希望使用(伪)随机数，可以通过 C 标准库的 srand() 和 rand() 函数实现。srand() 用来初始化随机数种子(seed)，一般使用时间来初始化：`srand(time(NULL));` 。而 rand() 则返回一个 int 范围内的随机数。这两个函数的声明位于头文件 `<cstdlib>` 中。

### 2. exit()

exit() 的声明在 `<cstdlib>` 头文件中。 

### 3. 最值

在头文件 `<limits>` 中的 **class** numeric_limits 中，由很多返回最值的函数。例如：

``` c++
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int a = numeric_limits<int>::max();
    int b = numeric_limits<int>::min();
    double c = numeric_limits<double>::max();
    double d = numeric_limits<double>::min();
    double e = numeric_limits<char>::max();
    double f = numeric_limits<char>::min();
    
    cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << endl;
    
    return 0;
}
```

### 4. string

string 居然还有 empty() 函数

## 0x01 C++ 编程基础

简要介绍了一些 C++ 的基础知识。

### 1.1 类

class 机制，赋予了我们增加 **“程序内之类型抽象化层次”** 的能力。

> 例如，如果我们要表示一个立方体的特征（体积特征和颜色特征），在最原始最基本的情况下，我们可以用三个浮点数来表示长宽高，一个整数表示颜色。以这么低级的方式来编程，势必让我们的思考不断在 “立方体的抽象类型” 和 “相应于立方体的三个浮点数和一个整数” 之间反复来回。
>
> class 机制，赋予了我们增加 **“程序内之类型抽象化层次”** 的能力。我们可以定义一个 Volumn class 用来表示体积特征，定义一个 Color class 用来表示颜色特征，最后，用一个 Rectangle class 来包含这两个 class。这样，虽然我们同样使用三个浮点数和一个整数，但是我们的思考不在直接面对七个浮点数，而是转为对 Rectangle class 的思考。
>
> **我们要记住，数据类型虽然为我们的编程任务提供了基石，但它们并非程序的重心所在。**

一般来说，class 的定义分为两部分，分别写在不同的文件中。其一是所谓 “头文件”，用来声明该 class 的各种操作行为。另一个文件，程序代码文件，则包含了这些操作行为的实现内容。既，**“机制与策略分离的思想”**

**delete 是语言关键字。** 这也正是 string class 采用 erase() 而非 delete() 来表示 “删去一个字符” 的原因。

### 1.2 输入和输出

数据的输入和输出，并非 C++ 语言本身定义的一部分（次精神同 C 语言），而是由 C++ 的一套面向对象的类层次体系（classes hierarchy）提供支持，并作为 C++ 标准库的一员。

**无论是标准输入输出，还是文件的输入输出，都是通过对象进行的。**

例如标准输入对象（cin），标准输出对象（cout）和标准错误输出对象（cerr）。我们的内容都是对对象执行读入和写入操作的。

标准错误输出和标准输出一样，都将输出结果定向到用户的终端。两者的唯一差别是：cerr 的输出结果并无缓冲区 —- 它会立即显示到用户的终端。（使用 iostream library 提供的操作符 ‘endl’ 可以输出并刷新缓冲区）。

C++ 中用于实现数据输入输出的流类及其继承关系。 

![img](https://s1.328888.xyz/2022/10/09/gk6tw.png)



> istream：常用于接收从键盘输入的数据；
> 		ostream：常用于将数据输出到屏幕上；
> 		ifstream：用于读取文件中的数据；
> 		ofstream：用于向文件中写入数据；
> 		iostream：继承自 istream 和 ostream 类，因为该类的功能兼两者于一身，既能用于输入，也能用于输出；
> 		fstream：兼 ifstream 和 ofstream 类功能于一身，既能读取文件中的数据，又能向文件中写入数据。



因此，如果我们需要使用文件来进行输入输出，我们首先需要实例化相应的文件输入输出对象。然后将标准输入输出对象换成文件输入输出对象即可。

文件的读写：

1. 为了打开一个可供输出的文件，我们定义一个 ofstream 对象，并将文件名传入：`ofstream outfile("a.txt");` 。便创建并构造函数初始化了一个 ofstream 对象 outfile。
2. 为了打开一个可供输入的文件，我们定义一个 ifstream 对象，并将文件名传入：`ifstream infile("a.txt");` 。便创建并构造函数初始化了一个 ifstream 对象 infile。
3. 如果想同时读写一个文件，我们得定义一个 fstream 对象，并将文件名和模式信息传入：`fstream iofile("a.txt", ios_base::app || ios_base::in);` 。其中 ios_base 定义了流打开模式信息。详细信息参考[官方文档](https://www.apiref.com/cpp-zh/cpp/io/ios_base.html)



### 1.3 数据与运算符

<< output 运算符

\<\< input 运算符

. dot 成员选择运算符

-> arrow 成员选择运算符

字符常量分为两类：

1. 第一类是大打印字符。
2. 第二类是不可打印字符，例如换行符(‘\n’)或制表符(‘\t’)。由于不可打印字符并无直接的表示法（这表示我们无法使用单一而可显示的字符来独立表示），所以必须以两个字符所组成的字符序列来表示。

数据类型决定了对象所能持有的数值范围，同时也决定了对象应该占用多少内存空间。

相较于 C 语言只能采用 =（assignment 运算符）来初始化，C ++ 为什么要额外增加构造函数语法来初始化对象呢？这主要是因为 C++ 增加了 class 的机制，例如 complex class，它的初始化需要两个值（一个实部一个虚部），而 assignment 运算符无法完成这个任务。于是增加构造函数来处理“多值初始化”

我们知道，windows下的路径表示使用 ‘\\’，而 linux 下的路径表示使用 ‘/’，由于 ‘\\’ 是转义字符，所以说用字符串保存 windows 下的路径的时候，要使用两个 ‘\\’。例如：

`string path = F:\\essential\\prigram\\chapter1\\demo1.cpp;`

数组的大小是一个**常量表达式**，它必须在编译时确定（常量可以在编译时确定），而普通变量只能在运行时确定。

### 1.4 错误

在 C++ 中，如果你没有在 main() 的末尾写下 return 语句，会自动加上，

off-by-one错误。

> **差一错误**（英语：**Off-by-one error**，缩写**OBOE**）是在计数时由于边界条件判断失误导致结果多了一或少了一的错误，通常指[计算机编程](https://zh.m.wikipedia.org/wiki/计算机编程)中[循环](https://zh.m.wikipedia.org/wiki/程序循环)多了一次或者少了一次的程序错误，属于[逻辑错误](https://zh.m.wikipedia.org/wiki/逻辑错误_(程序设计))的一种。比如，程序员在循环中进行比较的时候，本该使用“小于等于”，但却使用了“小于”，或者是程序员没有考虑到一个序列是从0而不是1开始（许多程序语言的数组下标都是这样）。在[数学](https://zh.m.wikipedia.org/wiki/数学)领域，此错误也时有发生。

### 1.5 模版

在模版中，数据类型作为一个参数存在，在对数据类型赋值时，要用尖括号（<>）包围。

### 1.6 指针

指针可以为程序提供一层间接性。从而为程序提供弹性（在第二章和第三章将深切体会）。

`p->a` 等价于 `(*p).a` ，arrow 成员选择运算符主要是为了我们方便使用指针而提供的。

在 C++ 动态分配时也可以使用构造函数（将 a 初始化为 3）:`int *a = new int(3);`

C++ 没有为没有提供任何语法让我们得以从 heap 分配数组的同时为其元素设定初值（C 语言可以使用 malloc）。

`int *a = new int[3];`

释放为数组分配的空间（[ ]必须放在变量名的前面，delete的后面）：`delete []a;`

### 1.7 命名空间

把命名空间和操作系统的文件管理下不同文件夹下文件名的管理练习起来，就很容易理解了。

[菜鸟教程](https://www.runoob.com/cplusplus/cpp-namespaces.html)

[微软文档](https://learn.microsoft.com/zh-cn/cpp/cpp/namespaces-cpp?view=msvc-170)

练习：

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

namespace xjy {
    void func() {
        cout << "namespace xjy!" << endl;
    }
}

namespace cs {
    void func() {
        cout << "namespace cs!" << endl;
    }
}

namespace xjy {
    void refunc() {
        xjy::func();
        cout << "rexjy" << endl;
    }
}

namespace rexjy {
    using namespace xjy;
    void refunc() {
        func();
        xjy::refunc(); 
        // 如果我们using引入的命名空间和当前命名空间存在相同的函数
        // 并且我们还没有使用namespace::加以区分的话
        // 默认使用自己命名空间下的函数
    }
}


void func() {
    cout << "std" << endl;
}


int main()
{
//     func();
//     xjy::func();
//     xjy::refunc();
    rexjy::refunc();   
    return 0;
}
```



## 0x02 面向过程的编程风格

在原书中，通过一步步的优化，将一个简单的低级的函数优化为一个复杂的高级的函数。

### 2.1 如何编写函数

在规模较大的程序当中，将一部分的代码封装成函数独立出来又很多好处：

1. 用函数调用操作取代编写相同的程序代码，可以使代码更容易读懂。
2. 可以在不同的程序中调用这些函数。
3. 可以更容易地将工作分配给协作开发团队。

函数参数扮演者占位符的角色。

函数必须先声明，然后才能被调用。函数的声明让编译器得以检查后续出现的使用方式是否正确 —- 是否有足够的参数，参数类型是否正确，等等。函数证明不必提供函数题，但必须指明返回类型，函数名以及参数列表。此即所谓的**函数原型**。

函数声明中可以忽略参数名，但是不推荐这样做。因为参数名可以为我们提供很多有用的信息。在编写文档的时候，为函数的声明提供参数名也是必要的（不然别人看了你的文档中的某个函数就会一头雾水）。

如果函数的最后一条语句不是 return，那么最后一条语句之后便是该函数的**隐式退出点**。当然，前提是函数的返回类型是 void 你才可以这么做。



### 2.2 调用函数

#### 2.2.1 传引用

by reference（传引用，传址）:所有的引用占用同一个地址（被引用元素的地址）。

C++ 不允许我们改变 reference 所代表的对象，它们必须**从一而终**。reference也必须只想一个对象。

面对 reference 的所有操作和面对 “reference所代表的对象” 所进行的操作一般无二。

例如：

``` C++
#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 4;
    int &p1 = a;
    int &p2 = a; 
    cout << a << ' ' << p1 << ' ' << p2 << endl;
    cout << &a << ' ' << &p1 << ' ' << &p2 << endl;
    p1 = 2;
    cout << a << ' ' << p1 << ' ' << p2 << endl;
    a = 3;
    cout << a << ' ' << p1 << ' ' << p2 << endl;
    // &p1 = b; // 编译错误
    //int &p3; //Error: 'p3' declared as reference but not initialized
    return 0;
}
```

```
1 1 1
0x7fffc7134da8 0x7fffc7134da8 0x7fffc7134da8
2 2 2
3 3 3
```



当我们以 by reference 方式将对象作为函数参数传入时，对象本身并不会复制出另一份 —— 复制的是对象的地址。函数中对该对象进行的任何操作，都是相当于对传入的对象进行**间接操作**。

以 by reference 的方式传入对象有两个理由：

1. 得以直接对所传入的对象进行修改。
2. 降低复制大型对象的额外负担以提高程序效率。在这种情况下，我们可能并不想修改对象，为了保证程序的安全性，我们需要将参数同时声明为 const 类型来必然修改对象的操作。

在传递参数时，使用 reference 或 point 的区别大致是用法不同罢了，reference 更简单？但是这两种方式传入的参数区别就很大了！point 可能是个空指针，因此当我们 deference 的时候，一定要先确定其值不为空。至于 reference，则必定会代表某个对象，所以不需要做额外的检查。

如果我们想要在函数中返回一个 vector 对象，无论是 point 还是 reference 都是不正确的，因为函数中的 vector 对象是分配在程序堆栈（program stack）上的，在函数结束时就会被释放（实际上是从 stack 中 pop掉了）。但是我们可以在函数中以传值方式返回该 vector 对象，因此返回的乃时对象的副本，它在函数之外依然存在。如下 func1()：

``` C++
#include <iostream>
#include <vector>
using namespace std;
vector<int> func1()
{
    vector<int> a(3, 1);
    return a;
}
int
int main()
{
    vector<int> a = func();
    for(auto &x : a)    cout << x << ' ';
    return 0;
}
```

> 对于数组我们没法以 by value 的方式返回，因为数组的本质就是一个指针（by point）。
>
> 大多数 C++ 编译器对于 “以 by value 方式返回的 class object” ，都会通过优化程序，加上额外的 reference 参数。

#### 2.2.2 冒泡排序

所谓冒泡排序，就是将大的数据或者小的数据冒泡到数据的顶部（我们假设下标为 0 的位置为顶部）。

``` c++
void bubble_sort(vector<int> vec) // 升序排序
{
    int n = vec.size();
    for(int i = 0; i < n; i ++ )
        for(int j = i + 1; j < n; j ++ )
            if(vec[i] > vec[j])
                swap(vec[i], vec[j]);
}
/*
	再该函数中，每次for:i，就可以确定下标为i的位置经过排序后的值。它的思路是那未经排序时该位置的值和所有未确定位置([i+1,j])的值进行比较，如果比未确定位置的值大就交换，最后就可以找到一个最小值然后放在该位置。
	整个过程就好像把所有数值小的元素冒泡到数组顶部一样。
*/
```



#### 2.2.3 作为开关的参数

​								**——- 为参数提供默认值**

在 C++ 中，我们可以为参数提供默认值，所有提供了默认值的参数都必须放在参数列表的末尾。

我们可以利用这个语法，将函数的参数作为一个开关。

例如上面我们编写的冒泡排序。如果我们想要打印排序的流程，即在函数中插入一些 printf() 函数，我们总不能为了这个功能而额外添加一个函数吧，毕竟这个功能可能很少用到。我们也不能在原函数直接添加 printf() 函数吧，当元素很多时，大量的打印信息会造成极大的浪费。

一个方便的且拓展性好的方式是为函数增加一个 “开关” 参数，这个参数作为是否打印信息的 “开关”，默认情况下，这个开关是关闭（设定一个初始值）的，我们甚至可以 “忽略这个参数”，即视这个参数不存在。只有当我们需要打印信息时，传入一个我们设定好的开关参数，函数就会打印我们想要的信息。如下：

```c++
void bubble_sort(vector<int> vec, bool flag = false) // 升序排序
{
    int n = vec.size();
    for(int i = 0; i < n; i ++ )
        for(int j = i + 1; j < n; j ++ )
        {
            if(flag == true)	
            {
                // do something
            }
            if(vec[i] > vec[j])
                swap(vec[i], vec[j]);
        }
}
```

> 我们甚至可以将 bool 类型替换为 int 类型来为这个参数增加更多的功能。

不过为函数参数提供默认值会给我们带来一个问题，那就是这个默认值是在函数声明时提供，**但不能同时在声明和定义处提供**，还是都提供呢？

> **为什么不能在声明和定义处都提供呢？**
>
> 声明是用户可以看到的部分，**客户非常信任**地使用这个特性，希望得到一定的结果，但是你在实现里使用了不同的[缺省值](https://so.csdn.net/so/search?q=缺省值&spm=1001.2101.3001.7020)，那么将是灾难性的。因此编译器禁止声明和定义时同时定义缺省参数值。
>
> **结论：在声明处提供默认值更好！**
>
> 若声明时没有定义缺省参数值，那么在定义成员函数时可以定义缺省参数值。但这种情况通常**用户是看不见的**，因此应避免。
>
> **核心：用户就是上帝！**

在我看来，为参数提供默认值更像是一种**机制**，而你是否使用这个对象（你可以不为这个对象提供参数值，看起来就是好像没有使用这个对象一样），或者是否使用这个默认值更像是一种**策略**。（结合上面冒泡排序的例子理解）



### 2.3 使用局部静态对象

**为了节省函数之间的通信而将对象定义于 file scope，永远都是一种冒险**。通常，file scope 对象会打乱不同函数之间的**独立性**，使他们难以理解。

> 能不定义全局对象，就不要定义全局对象。

一种好的方式是声明静态对象。



### 2.4 声明 inline 函数

将函数声明为 inline，表示**要求**编译器在每个函数函数调用点上，将函数的内容展开。面对一个 inline 函数调用操作，编译器可将该函数的调用操作该为以一份该函数的副本代替。

将函数指定为 inline，只是对编译器提出的一种 **“要求”** 或者说 **“建议”**，也就是说 inline 并不是一种强制性操作。编译器是否执行这项请求，需视编译器而定。

inline 函数的定义，通常放在头文件中。由于编译器必须在它被调用的时候加以展开，所以这个时候其定义必须时有效的。（也就是声明和定义必须在同一个文件当中）

> 实测 inline 函数不会再初始化后展开。

[参考](https://www.cnblogs.com/my_life/articles/4089184.html)



### 2.5 重载函数

编译器无法根据类型来区分两个具有相同名称的函数，因为返回类型无法给我们一个足以区分不同重载函数的语境。（你 TM 知道我想返回什么类型？）



### 2.6 模版函数

函数模版是一种 **“机制”**，让我们得以将单一函数的内容与希望显示的各种类型绑定（bind）起来。

function template 将参数列表中指定的全部（或部分）参数的类型信息抽离了出来。

function template 以关键字 template 开场，其后紧接着成对尖括号（< >）包围起来的一个或多个标识符。这些标识符表示我们希望 **“推迟决定”** 的数据类型。这些标识符事实上扮演着占位符的角色，用来放置函数参数列表及函数题中的某些实际数据类型。

例如：

```c++
#include <iostream>

using namespace std;

template <typename Ta, typename Tb>
Ta MAX(Ta a, Tb b)
{
    return max(a, b);
}

int main()
{
    int a = 1, b = 2;
    double c = 2.43, d = 4.34;
    cout << MAX(a, b) << endl << MAX(c, d) << endl;
}
```



当我们以某种类型调用模版函数时，编译器会将类型与我们模版中的定义绑定（bind）起来，然后生成一份函数实例（参数类型确定）。

> 同 inline 函数，这应该是在编译时做的操作。



### 2.7 函数指针数组

直接举例子：

``` C++
#include <iostream>

using namespace std;

int func1(int x) { return x;     }
int func2(int x) { return x * x; }
int func3(int x) { return x * 2; }

// typedef个一个type，type的实例是一个返回值类型为int
// 有一个int类型参数的函数值怎
typedef int (*handler)(int); 


// 定义一个函数指针数组
handler cal[3] = {
    &func1, &func2, &func3
};

int main()
{
    int val = 4;
    for(int i = 0; i < 3; i ++ )
        cout << cal[i](val) << endl;
}
```

在定义函数指针数组的时候，最好将函数指针 typedef 成一个单独的类型，这样方便我们编写代码。否则，看看下面的形式：

```c++
int (*cal[3])(int) = {
    &func1, &func2, &func3
};
```

还好理解吗？更复杂一点的呢？（例如返回值类型为指针 or 指向指针的指针。。。）

一定要区分**函数指针** 和 **指针函数**

> `int (*cal)(int, int);`	– 函数指针，是一个指针，指针指向一个函数
>
> `int *cal(int,int);`		– 指针函数，是一个函数，函数的返回值类型为一个指针
>
> 差异的根源在于同是单目运算符的优先级从右向左。



### 2.8 设定头文件

头文件的拓展名习惯上是 `.h` 。标准库例外，它没有拓展名。

程序的定义可以有多份，但是声明只能有一份。（机制只能有一个，但是基于机制的策略可以有很多种）。但是有个例外：inline 函数的定义。为了能够拓展 inline 函数的内容，在每个调用点上，编译器都取得其定义。这意味着我们必须将 inline 函数的定义放在头文件中，而不是把它放在各个不同的程序代码文件中。还有个例外就是 const object。和 inline 一样，const 也是 “一次定义” 规则下的例外。**const object 的定义只要一出文件之外便不可见**。这意味着我们可以在多个程序代码文件中加以定义，不会导致任何错误。

> 关于 const object 的定义一出文件之外便不可见是 C ++ 独有的性质， C并不具备这个性质。
>
> **原因：c++中 const 具有内部链接性，c 中 const默认外部链接性。**
>
> 我们可以测试一下，有两个文件：
>
> 1.c/1.cpp
>
> ```c++
> #include <stdio.h>
> const int val = 2038;
> void func();
> int main()
> {
>  func();
>  printf("1.c val = %d\n", val);
> }
> ```
>
> 2.c/2.cpp
>
> ``` c++
> #include <stdio.h>
> const int val = 222;
> void func()
> {
>  printf("2.c val = %d\n", val);
> }
> ```
>
> 当我们以 `.c` 的后缀编译这两个文件的时候，编译器会给出重定义错误，但如果我们以 `.cpp` 的后缀编译这两个文件，就可以正常执行。

一个关于 C++ 中的 const 变量定义在源文件还是头文件的建议：

>作者：雨落惊风
>链接：https://www.zhihu.com/question/21622061/answer/2373761045
>来源：知乎
>著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
>
>
>
>以下仅适用于c++中（c中有区别，原因：c++中const具有内部链接性，c中const默认外部链接性）
>
>const/constexpr定义放在头文件中，
>
>```cpp
>优点：编译器在进行分离编译时，由于在每个文件中都可以看到const的定义，
> 从而可以进行编译优化
>缺点：如果编译优化并未发生，
>   1. 由于const的内部链接性，每个文件都保存了一份const的副本，
>        编译后，内存占用可能过大。
>     2. 当对const有变更需求时，每个包含头文件的.cpp文件都需要重新编译，
>        编译时间可能很长。
>```
>
>const定义放在源文件中，并在.h头文件中包含对其声明，使用const的.cpp文件包含头文件
>
>```cpp
>优点：1. extern const作为共享变量，仅仅在定义的.cpp文件被实例化1次，
>        使用const的.cpp文件只是包含头文件，
>        链接器负责链接到const定义。所以，内存空间占用相对变小。
>     2. 由于分离编译，当有需求变更const变量时，仅需要重新编译
>        定义const的.cpp源文件即可，其他使用const的.cpp文件，由链接器
>        代劳链接到重新编译好的const上，无需对使用const的文件重新编译(g++ -c)。
>        所以，编译时间相对变少。
>缺点：当头文件被预处理器展开后，由于其中只有const变量的声明，编译器在
>     分离编译时无法获取const的定义值，所以存在无法进行编译优化的问题，
>     比如替换const为对应值（做不到啊，const值是啥！）
>```
>
>所以，
>
>如果你在意你程序内存的大小以及出版本时的编译速度（不用加班，oho），你就将const定义放在源文件中，const声明放在头文件中；
>
>```text
>xxx.cpp
>extern const int noWantJiaBan = ...
>
>xxx.h
>extern const int noWantJiaBan;
>
>xxx.cpp
>#include "xxx.h"
>```
>
>如果你在意编译优化，那么const定义就放直接放在头文件中.
>
>```text
>xxx.h
>const int optimizable = ...
>
>xxx.cpp
>#include "xxx.h" 
>```

在 file scope 定义的对象，如果可能被多个文件访问，就应该声明于头文件中。因为如果我们没有在程序中声明某个对象，便无法加以访问。

关于头文件由 <> 或者 “” 包围的说明

> 更有技术含量的回答是：
>
> 如果此文件被认定为标准的成项目的或项目专属的头文件，我们便以尖括号将文件名括住；当编译器搜索此文件时，会先在某些默认的磁盘目录中寻找。
>
> 如果此头文件由成对的双引号括住，此文件便被认为是一个用户提供的头文件；搜索此文件时，会由要包含此文件的文件的所在磁盘目录开始找起。





## 0x03 范型编程风格

### 1. STL

STL：standard template library

组成：

1. container：
   1. 顺序容器：vector, list, deque, ..
   2. 关联容器：map, set, ..
   3. 容器适配器：stack, queue, ..
2. generic algorithm：



顺序容器

> 顺序容器内元素的地址并不一定连续，但是它的元素位置一定连续。
>
> vector 和 deque 支持随机索引。
>
> list 和 deque 支持双向插入。



插入（insert）

> push_back 和 push_pop 是特殊的插入操作。
>
> insert 的四种变形：
>
> 1. 



范型算法系通过 function template 技术，达到 “与操作对象的类型相互独立” 的目的。而**实现 “与容器无关” 的诀窍，就是不要直接在容器身上进行操作。** 而是借由一对 iterator（first 和 last），表示我们要进行迭代的元素范围。

> 对于 iterator last，我们一般将其设置为容器的**终点位置（最后一个元素的下一个位置）**，而不是最后一个元素的位置。并称其为 “哨兵”。



### 2. 编写你的模板函数 - find

通过模版来屏蔽元素类型

如何屏蔽容器类型：如果我们使用指针来查找元素的话，那么我们传入某个容器的指针。如果我们能够把指针抽象，无论是哪个容器的指针，我们都能把他们看作普通的 “指针”，这样我们就实现了屏蔽容器的类型。

> vector != array
>
> 虽然可以用 array 给 vector 初始化，但是 vector 和 array 仍然是两个概念。





**< — 暂停更新，实在是太费时间，接下来只记录一些书上没有明确说明的nearing – >**



### 3. 根据 const 重载

可以根据一个函数是否是 const 的重载，这里的 const 修饰的是函数而不是返回类型。

``` c++
class test
{
    public:
        const int get()  
        { 
            return 1;
        }
        int get()
        {
            return 1;
        }
};
// compile error
```

``` c++
class test
{
    public:
		int get() const
        { 
            return 1;
        }
        int get()
        {
            return 1;
        }
};
// accept
```



### 4. static in C/Cpp

static 在 C 中一般作为静态全局/局部变量和静态函数存在。

静态函数：

1. 静态函数的作用域为当前的源文件（屏蔽功能），而局部函数的作用域为整个工程。

2. 静态函数会被一直放在一个一直使用的存储区，直到退出应用程序实列，避免了调用函数时的压栈和出栈，速度快很多。

在 C++ 的 class 中，static 拓展出了 static member function 和 static member variable



### 5. cerr && cout

std::cerr是标准错误输出流，不需要缓存，直接显示在显示器上，而且只能显示到显示器上，即std::cerr流不能转向。

std::cout需要缓冲区（目的是为了减少屏幕刷新次数，一次全部显示），std::cout流可以转向，例如可将cout流流向文件操作中去。

1.区别
cout对应于标准输出流，默认情况下是显示器。这是一个被缓冲的输出，可以被重定向。
cerr对应标准错误流，用于显示错误消息。默认情况下被关联到标准输出流，但它不被缓冲，也就说错误消息可以直接发送到显示器，而无需等到缓冲区或者新的换行符时，才被显示。一般情况下不被重定向。

2.为什么要用cerr
比如，你的程序遇到调用栈用完了的威胁（无限，没有出口的递归）。
你说，你到什么地方借内存，存放你的错误信息？
所以有了cerr。其目的，就是在你最需要它的紧急情况下，还能得到输出功能的支持。 缓冲区的目的，就是减少刷屏的次数——比如，你的程序输出圣经中的一篇文章。不带缓冲的话，就会每写一个字母，就输出一个字母，然后刷屏。有了缓冲，你将看到若干句子“同时”就出现在了屏幕上（由内存翻新到显存，然后刷新屏幕）。

> by xjy
>
> 因此说 cerr 更像是一种需要在紧急情况下做输出的东西，他并不会终止程序的运行。



### 6. enum 的作用域

enum 内元素的作用域是全局的，例如：

``` c++
enum E1 {
    a, b
};
enum E2 {
    a, b
};
/* compile error
error: 'a' conflicts with a previous declaration
error: 'b' conflicts with a previous declaration
*/
```

如果我们确实需要在不同的 enum 内声明重名的枚举量，C++ 11 位我们提供了一种新的枚举类型（enum class），其枚举的作用域为类。

这样编译就不会出错，但是使用的时候要加上枚举名来限定枚举量。例如：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

enum class e1{
    d,a,b,c
};

enum class e2{
    b,c,e,a
};

int main()
{
    e1 var1 = e1::a;
    e2 var2 = e2::a;
    
    // 必须强制类型转换
    cout << (int)var1 << endl;
    cout << (int)var2 << endl;
    
    
    return 0;
}
```

> 关于更详细的 enum 和 enum class 的比较 和 enum class 的介绍：[[reference]](https://blog.csdn.net/weixin_42817477/article/details/109029172?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-109029172-blog-78535754.pc_relevant_recovery_v2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-109029172-blog-78535754.pc_relevant_recovery_v2&utm_relevant_index=3)



### 7. 将临时对象作为参数传给引用

试看下面的代码：

``` C++
#include <iostream>
void g(int &x)
{
    std::cout << "getx: " << x << std::endl;
}
void f(const int &x)
{
    std::cout << "getx: " << x << std::endl;
}
int main()
{
    int a = 1, b = 2;
    g(a+b);
    //f(a+b);
    return 0;
}

```



上面的两个调用之前，a+b 的值会存在一个临时变量中，当把这个临时变量传给函数 g 时，由于 g 的声明中，参数是 int&，不是常量引用，所以产生以下编译错误：

```shell
a.cpp:8:7: error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    8 |     g(3);
```

意思就是我们不能将一个作为左值 int 引用和一个 int 绑定。

而在 f(a+b) 中，由于 f 定义的参数是 const int&，编译通过。  问题是为什么临时变量作为引用参数传递时，必须是常量引用呢？很多人对此的解释**是临时变量是常量，不允许赋或者改动**，所以当作为非常量引用传递时，编译器就会报错。这个解释在关于理解临时变量不能作为非 const 引用参数这个问题上是可以的，但不够准确。事实上，临时变量是可以被作为左值(LValue)并被赋值的，请看下面的代码：

```c++
#include <iostream>
using namespace std;

class test
{
    friend test operator+(const test &p1, const test &p2);
    friend ostream& operator<<(ostream &os, const test &p);
    public:
        test() {}
        test(int _x) : x(_x) {}
    private:
        int x;
};

test operator+(const test &p1, const test &p2)
{
    test p3;
    p3.x = p1.x + p2.x;
    cout << "you get here!" << endl;
    return p3;
}

ostream& operator<<(ostream &os, const test &p)
{
    os << p.x;
    return os;
}

int main()
{
    test a(2), b(3), c(4);
    cout << ((a + b) = c) << endl;  // 临时对象作为左值
    
    // int x = 1, y = 2, z = 3;
    // cout << ((x + y) = z) << endl; // 编译不通过
    
    return 0;
}
```



上面的程序编译通过，而且运行结果是：

``` C++
you get here!
4
```



临时变量确实被赋值，而且成功了。

> 至于为什么能成功，作者并没有说，但是从我们在 operator+ 重载函数插入的 cout 语句以及输出可以看出，应该是在 a+b 时调用了该函数，然后生成了一个 “对象”，该对象可以作为左值。
>
> 而在 main 函数的最后两条语句，(x+y)=z 编译就不通过，大概是因为 x+y 生成的不算是一个 “对象”，而只是一个单纯的值罢了。

所以，临时变量不能作为非 const 引用参数，不是因为他是常量，而是因为 c++ 编译器的一个关于语义的限制。如果一个参数是以非 const 引用传入，c++ 编译器就有理由认为程序员会在函数中修改这个值，并且这个被修改的引用在函数返回后要发挥作用。

但如果你把一个临时变量当作非 const 引用参数传进来，由于临时变量的特殊性，程序员并不能操作临时变量，而且临时变量随时可能被释放掉，所以，一般说来，修改一个临时变量是毫无意义的，据此，c++ 编译器加入了临时变量不能作为非const 引用的这个语义限制，意在限制这个非常规用法的潜在错误。

还不明白？OK，我们说直白一点，如果你把临时变量作为非 const 引用参数传递，一方面，在函数申明中，使用非常量型的引用告诉编译器你需要得到函数对某个对象的修改结果，可是你自己又不给变量起名字，直接丢弃了函数的修改结果，编译器只能说：“大哥，你这是干啥呢，告诉我把结果给你，等我把结果给你了，你又直接给扔了，你这不是在玩我呢吗？”所以编译器一怒之下就不让过了。这下大家明白了吧？



> 所以说，临时对象只能作为右值的理解是片面的。
>
> 一个对象必然有左值和右值，系统是否提供给用户使用则是另外一码事



## 0x04 基于对象的编程风格

 ### 1. operand ->\*  &&  .\*

[rerference - 微软](https://learn.microsoft.com/zh-cn/cpp/cpp/pointer-to-member-operators-dot-star-and-star?view=msvc-170)

[rerference - 菜鸟教程](https://www.runoob.com/w3cnote/cpp-func-pointer.html)

`->* 和 .*`：指向成员的指针运算符

> 当我们的成员函数或者成员变量被记录为指针时，不能再通过 `. 或者 ->` 直接调用该成员，需要使用指向成员的指针运算符。

例如：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class BaseClass
{
public:
    void func1()
    {
        cout << "helloBase" << endl; 
    }
};

void (BaseClass::*Bptr)() = &BaseClass::func1;

class Derived : public BaseClass
{
public:
    void func2()
    {
        cout << "HelloDerived" << endl;
    }
};

void (Derived::*Dptr)() = &Derived::func2;

int main()
{
    BaseClass b;
    BaseClass *pb = new BaseClass;
    (b.*Bptr)();
    (pb->*Bptr)();
    
    Derived d;
    Derived *pd = new Derived;
    (d.*Dptr)();
    (pd->*Dptr)();
    
    //
    // (pb->*Dptr)();
    (pd->*Bptr)();
    // (b.*Dptr)();
    (d.*Bptr)();
    
    
    return 0;
}
```

 



## 0x05 面向对象的编程风格

[析构函数与虚函数](https://www.cnblogs.com/yuanch2019/p/11625460.html)

 

局部对象在生命周期结束之后会自动调用 dtor，但是分配在 heap 上的对象在函数结束之后也不会调用 dtor，必须 delete 才会调用。

子类包含父类继承的成员，但是子类不能直接初始化这些成员，需要调用父类的构造函数，让每个类自己控制自己成员的初始化过程。

只要调用基类的构造函数和析构函数，就一定会调用父类的构造函数和析构函数。

如果类 A 有个虚函数，那么类 B 继承类 A，类 C 继承类 B，那么 B 也可以重载这个虚函数。并且父类 A 的指针也可以指向子类 C。

子类可以不实现父类的纯虚函数。存在纯虚函数的类不能被实例化。



# 侯捷 OOP

## preface

### reference

[侯捷资源github](https://github.com/coder0818/-C-)

[资料](https://github.com/coder0818/-C-/tree/master/C++-newC++11&14-HouJie)

### prologue

一、二：object based

三：some addition

四、：object oritened

### English

oop：object oriented programming，面向对象编程

layout：布局

torment：折磨，煎熬

overload：重载

override：覆写，覆盖

scopre：作用域

interlude：插叙

inheritance：继承

composition：复合

delegation：委托

composite：复合

prototype：原型

explicit：明白的，明去的，清楚的

signatrue：签名

parenthses：小括号， ()

barces：大括号，{}

alias：别名，化名

### Tips

模版会造成代码的膨胀，但这是必要的，并不是缺点。

编译器会对 function template 进行 实参推导（argument dedution）。即选择类型。

### [ref1](https://blog.csdn.net/qq_42247231/article/details/105109709)

今天我们来谈一谈面试 C++ 工程师时经常被谈到的一个问题：为什么析构函数必须是虚函数？为什么默认的析构函数不是虚函数？

首先，我们看一下百度百科对虚函数是怎么定义的:

在某基类中声明为 virtual并在一个或多个派生类中被重新定义的成员函数，用法格式为：virtual 函数返回类型 函数名 ( 参数表 ) { 函数体 }；实现多态性，通过指向派生类的基类指针或引用，访问派生类中同名覆盖成员函数。

好了，现在我们大概知道什么是虚函数，虚函数就是类中使用关键 virtual修饰的成员函数，其目的是为了实现多态性。

那么什么是多态性呢？

所谓多态性，顾名思义就是“多个性态”。更具体一点的就是，用一个名字定义多个函数，这些函数执行不同但相似的工作。最简单的多态性的实现方式就是函数重载和模板，这两种属于静态多态性。还有一种是动态多态性，其实现方式就是我们今天要说的虚函数。

回归正题。

一、为什么析构函数必须是虚函数？

当然了，这么说其实是不太严谨的，因为我完全可以将析构函数定义成非虚函数。这个我们后面再说。

首先我们需要知道析构函数的作用是什么。析构函数是进行类的清理工作，具体来说就是释放构造函数开辟的内存空间和资源，当然我们完全可以在析构函数中进行任何我们想要的操作，比如下面我们给出的示例代码，就在析构函数中打印提示信息。

前面我们在介绍虚函数的时候就说到，为实现多态性，可以通过基类的指针或引用访问派生类的成员。也就是说，声明一个基类指针，这个基类指针可以指向派生类对象。

下面我们来看一个例子：

```C++
#include <iostream>

using namespace std;

class Father {
public:
    ~Father() {
        cout << "class Father destroyed" << endl;
    }
};

class Son : public Father {
public:
    ~Son() {
        cout << "class Son destroyed" << endl;
    }
};

int main() {
    Father* p = new Son;
    delete p;

    return 0;
}
```

运行结果：

``` SHELL
运行结果：
class Father destroyed
```


上面的示例程序中，我们定义了两个类，一个基类，一个派生类，派生类公有继承父类。为了描述简单，这两个类只定义了析构函数，并在析构函数中输出提示信息。在主函数中，我们声明了一个基类的指针，并用一个派生类的实例去初始化这个基类指针，随后删除这个指针。我们看到程序运行的结果，只有基类的析构函数被调用。

为什么会这样呢？指针明明指向的是派生类对象，那删除这个指针，为何只有基类的析构函数被调用，而派生类的析构函数却没有调用呢？

我们先把问题留在这里，接下来我们看看，若析构函数被定义成虚函数会怎么样呢？

``` c++
#include <iostream>

using namespace std;

class Father {
public:
    virtual ~Father() {
        cout << "class Father destroyed" << endl;
    }
};

class Son : public Father {
public:
    ~Son() {
        cout << "class Son destroyed" << endl;
    }
};

int main() {
    Father* p = new Son;
    delete p;

    return 0;
}
```

运行结果：

``` shell
class Son destroyed
class Father destroyed
```

当基类的析构函数被定义成虚函数时，我们再来删除这个指针时，先调用派生类的析构函数，再调用基类的析构函数，很明显这才是我们想要的结果。因为指针指向的是一个派生类实例，我们销毁这个实例时，肯定是希望即清理派生类自己的资源，同时又清理从基类继承过来的资源。而当基类的析构函数为非虚函数时，删除一个基类指针指向的派生类实例时，只清理了派生类从基类继承过来的资源，而派生类自己独有的资源却没有被清理，这显然不是我们希望的。

所以说，如果一个类会被其他类继承，那么我们有必要将被继承的类（基类）的析构函数定义成虚函数。这样，释放基类指针指向的派生类实例时，清理工作才能全面进行，才不会发生内存泄漏。

二、为什么默认的析构函数不是虚函数？

那么既然基类的析构函数如此有必要被定义成虚函数，为何类的默认析构函数却是非虚函数呢？

首先一点，语言设计者如此设计，肯定是有道理的。

原来是因为，虚函数不同于普通成员函数，当类中有虚成员函数时，类会自动进行一些额外工作。这些额外的工作包括生成虚函数表和虚表指针，虚表指针指向虚函数表。每个类都有自己的虚函数表，虚函数表的作用就是保存本类中虚函数的地址，我们可以把虚函数表形象地看成一个数组，这个数组的每个元素存放的就是各个虚函数的地址。
这样一来，就会占用额外的内存，当们定义的类不被其他类继承时，这种内存开销无疑是浪费的。

这样一说，问题就不言而喻了。当我们创建一个类时，系统默认我们不会将该类作为基类，所以就将默认的析构函数定义成非虚函数，这样就不会占用额外的内存空间。同时，系统也相信程序开发者在定义一个基类时，会显示地将基类的析构函数定义成虚函数，此时该类才会维护虚函数表和虚表指针。

## <一出手就是大家之范>

## 一、class with no pointer

#### 0x01 Introduce

##### 1. C vs C++

由于 C 语言没有提供足够的关键字，因此 C 语言中能够被函数处理的变量一定是全局变量（局部变量没有意义，它在函数结束之后就释放了）。但这就意味着所有的函数都可以使用这个全局变量。

##### 2. class based or class oriented

只要你写的 class 之间有关系，就可以称为**面向对象**。

Class based: 单一 class

class oriented：多个class，class之间有连续

##### 3. C++ code frame

.h：classes declaration

.h：standard library 

.cpp：one main and others

##### 4. guard declaration of header

头文件防卫式声明：

避免重复 include。

```shell
#ifndef __XXX_GUARD__
#define __XXX_GUARD__
...;
#endif
```

##### 5. layout of header 

``` shell
# <guard>

// 0. forward declarations

// 1. class declarations

// 2. class definition

# </guard>
```

##### 6. about a = b

对于类似 `a = b;` 类型的语句，你应该说： 

`b assigned to a `，而不是： 

`a 等于 b`

#### 0x02 Construtor

##### 1. access level

class 中一般根据访问级别划分为两大段：public, private。（当然你也可以划分为多个public，private….）

数据部分一般划分为 private，因为我们的数据需要封装起来，不能随便为外界所看到。

函数根据是否需要开放给外界可以划分为 private，也可以划分为 public。

当然，还有另一种 access level：protected。

##### 2. constructor（ctor）

initialization list（初值列，初始列），只有构造函数才有的语法。当我们使用构造函数时，能使用初值列，不要在大括号内初始化。

因为一个数据的设定有两个阶段：初始化（初值列）和赋值（大括号内）。你如果不在初值列不设定数值，而在大括号内设定数值，就会浪费初始化这一步骤。（这是效率的问题，你明明能一步搞定，为啥走两步呢？

当我们为一个构造函数的所有参数都提供默认值时，此时不能再提供默认的没有参数的构造函数。因为前面的构造函数已经实现了默认构造函数的功能。

##### 3. tmp var

局部变量，没有名字。

[参考](https://blog.popkx.com/why-can-c-language-functions-be-return-local-variables-and-local-variables-are-not-released/)

[参考](https://blog.csdn.net/xiaomingZeng/article/details/89319861)

[好文！](https://www.cnblogs.com/lsfv/p/6016764.html)

[临时变量的常量性](https://www.3dwindy.com/article/177572)

 临时变量应该在导致临时变量创建的"完整表达式"求值过程的最后一个步骤被析构

> 如果函数返回值是一个对象，要考虑 return 语句的效率。例如   
> 		return String(s1 + s2);
> 	 	这是临时对象的语法，表示“创建一个临时对象并返回它” 。
>
> 不要以为它与“先创建一个局部对象 temp 并返回它的结果”是等价的，如
> 			String temp(s1 + s2);
> 			return temp;
>
> 实质不然，上述代码将发生三件事。首先，temp 对象被创建，同时完成初始化；然后拷贝构造函数把 temp 拷贝到保存返回值的外部存储单元中；最后，temp 在函数结束时被销毁（调用析构函数） 。
>
> 然而“创建一个临时对象并返回它”的过程是不同的，**编译器直接把临时对象创建并初始化在外部存储单元中**，省去了拷贝和析构的化费，提高了效率。
>
> 类似地，我们不要将 
> return int(x + y); // 创建一个临时变量并返回它
> 写成
> int temp = x + y;
> return temp;
>
> 由于内部数据类型如 int,float,double 的变量不存在构造函数与析构函数， 虽然该 “临时变量的语法”不会提高多少效率，但是程序更加简洁易读。

当返回一个变量的时候，我们只想返回这个变量的值，而不是这个变量。

虽然局部变量和临时变量在函数结束后被销毁，但其值仍存放在寄存器 rax 中。

临时对象在表达式完成之后就会被销毁。但如果将一个临时变量返回给一个引用，它的生命周期会延长。

**编译器直接把临时对象创建并初始化在外部存储单元中**。这句话我们可以这样理解：返回局部变量时，我们返回的是一个对象，而对象需要创建和销毁。返回临时变量时，我们直接返回了一个值，

`typename(...)；`

不可以对临时对象 returnby reference，因为，它们返回的必定是个 local object。

#### 0x03 Const

##### 1. overload by const

``` C++
double imag() const { return im; }
double imag() { im = -1; return im; }
```

##### 2. by value vs. by reference(to const)

上面的（to const）表示可选。

pass/return by value or pass/return by reference(to const)

引用（reference）为 C++ 特有。引用的底部就是一个指针。传引用就是传指针，但是它更漂亮。

注意并不是传指针一定比传引用快，例如我们只是传一个char，一个字节，而指针则需要四个字节。

当我们传指针（引用）只是为了效率，要加上 const。

###### 3. friend

将一个函数设置为 friend 之后，该函数可以拿到该对象的 private 数据成员，虽然有时我们也可以通过开放的函数看到 private 成员。但这样做的一个好处是减少通过函数调用拿到成员的函数调用开销。

**同个 class 的各个 objects 互为 friends**

```c++
class test
{
    public:
        test(int r) : val(r) {}
    	int func(test &x) { return x.val; }
	private:
    	int val;
};
```

> 在上面的例子中，我们在 func 中直接拿到了另一个对象 x 的私有成员。这是合法的。不需要将 func 声明为 friend。

#### 0x04 Operator overload

##### 1. this *

所有的成员函数都带有一个隐藏的成员参数 – *this，谁调用这个函数，谁就是 this，这个参数一般放在参数列表的最左侧。当成员调用成员函数的时候就会把它的地址放到 this 中。

##### 2. return way

传送者无需知道接收者是否以 reference 形式接受。但是在 C 中，传送者必须知道接收者是否以 pointer 形式接受来决定返回数值还是地址。

##### 3. 连串赋值的返回类型

因为赋值运算符（=，+=，-+ …）的优先级顺序自右向左，因为它可能会出现这种形式：

`a += b += c`

`b+=c` 的结果会作为左值交给 `a+=`

此时如果我们重载的 `+=` 返回了一个 void，那事情就严重了。我们应该返回 `b+c` 的类型

对任意 a op b，都是 b 作用 op 于 a 身上，即右侧的对象作用到左侧，C++ 不存在左侧的对象作用在右侧的语法。

当我们重载 output(<<) 运算符的时候，不可以重载为成员函数。

> 如果我们重载为成员函数，那么 class 对象会作为隐式的最左侧的 operand，而 ostream 对象会作为右 operand，此时如果我们调用该函数：
>
> ```c++
> class Complex;
> Complex c(1, 2);
> c << cout;
> ```
>
> 这显然是不合理的，cout 竟然在右侧！

## 二、class with pointer

### 0x01 Big Three 

#### 1 what's three?

 copy structure function 

copy assignment struction

destruction function

#### 2. how copy 

copy struction

`string s1(s2);`

`string s1 = s2`;

copy assignment

`s1 = s2;`

> 当一个对象第一次出现并利用另一个对象赋值的时候，它会调用拷贝构造函数。
>
> 如果对象已经出现，此时再用另一个对象赋值，它会调用拷贝赋值。

如果你没有在类中提供拷贝构造和拷贝赋值函数，编译器会默认使用自己的那一套函数，就是一个 bit 一个 bit 的copy 过去，也就是说，对于指针类型，它只会把指针 copy 过去，这显然是不合理的，但是对于**非指针**，这是可行的。

因此，对于指针，你必须有你自己的 copy structure function and copy assignment function

拷贝构造函数：构造函数的参数对象是它自己

拷贝赋值函数：重载赋值运算符，参数对象是它自己。当我们使用拷贝赋值时，一定要检查是否是自己赋值给自己。这不仅是效率的问题，还关乎程序的正确性。

`delete [] ptr;` 的 [] 理解为**“关门”**很形象啊。

> 总而言之，用同类对象为该对象初始化 or 赋值的操作就是拷贝初始化 or 赋值。
>
> 但是默认拷贝只是单纯拷贝 val，对于指针来说，它的 val 就是 只想对象的 address。
>
> 这可能（绝大数情况下）并非我们想要的，因此我们需要重载拷贝（初始化 and 赋值）。
>
> 就是这么简单。

#### 3. ctor and dtor

构造和析构函数

`complex();` 创建一个临时对象

`complex c1;` 调用默认构造函数创建一个全局/局部对象c1

### 0x02  memory management

#### 1. Local object 

also named **auto object**, because it’s memory will be cleaned up automatically by stack.

#### 2. new and delete

> new：先分配空间，再调用构造函数

当我们执行语句：`complex *p = new colplex(1,2);`的时候，编译器优化为：

``` c++
void *mem = operator new(sizeof(complex)); // 分配内存
pc = static_cast<complex*>(mem); // 类型转换
pc->complex::complex(1,2);	// call dtor
```

其中，operator new 在内部调用的是 C 的 malloc

complex(1,2) 转换为 complex(pc,1,2);



>  delete：先调用 dtor，再释放内存

当我们执行语句 `delete []pc;` 的时候，编译器会优化为：

``` c++
complex::~colplex(ps);	// 析构函数
operator delete(ps);	// 释放内存
```

operator delete 内部调动 free();



> array new && array delete

![IMG](https://s3.bmp.ovh/imgs/2022/10/20/3d23ec94b22a0b36.png)



如果我们使用了 array new 而没有使用 array delete

那么编译器只会调用一次 dtor。

## 三、Interlude

### 0x01 static

#### 1. 静态成员变量

##### 1.1 性质 

静态变量是 一个**类的成员变量**，而不是**类的实例的成员变量**。

静态变量调用的时候可以通过对象调用,也可以通过类直接调用。

>  不能在构造对象的构造函数中初始化静态变量。不然的话你就是把静态变量视为类的实例的一个成员变量，这就与它的定义矛盾了。

> 设计模式中的**单例模式**就是只有一个实例对象，这个实例对象是静态的，并且它的构造函数被放在 private 中。

##### 1.2 内存分配

静态就是在程序编译时就分配存储空间，而不是等到运行时才知道，也就是程序加载之后，它的存储空间就已经分配了。这是因为**我们有时候希望即便类的实例销毁了，但我却希望保存它的某些数据**，那么这个时候，静态成员变量就是一个很好的选择。对于被所有类共享的数据可声明成静态变量，它在程序运行前就已经存在了(所以一定要初始化)，它被放到静态存储区，按照出现次序被初始化。 它被所有该类的对象共享，静态变量可以被改变。

##### 1.3 静态成员变量一定要初始化吗

先上答案：绝绝绝大多数情况下，需要初始化！暂时还不知道不不初始化的情况。

我们知道C++类的[静态成员](https://so.csdn.net/so/search?q=静态成员&spm=1001.2101.3001.7020)变量是需要初始化的，但为什么要初始化呢。

其实这句话“静态成员变量是需要初始化的”是有一定问题的，应该说“静态成员变量需要定义”才是准确的，而不是初始化。

两者的区别在于：**初始化是赋一个初始值并且同时分配内存，而定义是只分配[内存](https://so.csdn.net/so/search?q=内存&spm=1001.2101.3001.7020)。**

静态成员变量在类中仅仅是声明，没有定义，所以要在类的外面定义，实际上是给静态成员变量分配内存。

如果我们没有在类的外部定义静态成员变量，那么我们此时就仅仅只是声明了它，如果我们尝试使用它就会导致编译错误。

当然你也可以不定义它，前提是你不会使用它，但既然你不使用它，你为何声明它，并且声明为静态的，这不是搞笑吗？因此，只要在类中声明了一个静态成员变量，你就有很大的必要在类外部定义它（可以不赋值，此时它应该会被默认初始化为0）。

##### 1.4 为什么 static 成员变量一定要在类外初始化

先上答案：**不一定！**

前面提到，我们要在外部定义（注意不一定是初始化，我们可以不给它赋值）静态成员函数。那么我们可以不可以在类中初始化它呢？ 

因为静态成员属于整个类，而不属于某个对象，如果在类内初始化，会导致每个对象都包含该静态成员，这是矛盾的。

《c++primer》里面说在类外定义和初始化是保证[static](https://so.csdn.net/so/search?q=static&spm=1001.2101.3001.7020) 成员变量**只被定义一次**的好方法。 但为什么 static const int 就可以在类里面初始化呢？ 

想起 C 中一个函数里定义一个 static 变量是为了保证只初始化（分配内存并赋值）一次。

那么，是否可以这样理解: static 数据成员在类外定义和初始化是为了**保证只被定义和初始化一次**,这样编译器就不必考虑类的函数里面第一个对 static 变量的 ’=’ 操作是赋值还是初始化了。 static const int 可以在类里面初始化，是因为它既然是 const 的，那程序就不会再去试图初始化了。

什么东西能在类内初始化 ？
能在类中初始化的成员只有一种，那就是**静态常量成员**。

> 因为静态常量成员是常量，不允许修改，这种情况下是否所有的对象共享同一份数据已经不重要了，因为都是同一常量数据，而且如果不允许直接赋值，那么这个常量就没有意义了，直接就是系统默认的值了。
>
> 另外常量在声明时必须同时初始化，否则编译器报错。

> 在我的测试中，发现即使在类中初始化静态成员变量，它也不会算到类的实例的空间当中。例如：
>
> ```c++
> class test
> {
>  public:
>      int y;
>      const int z = 0;
>      static const int x = 3;
> };
> 
> int main()
> {
>  test a;
>  cout << sizeof(a) << end;
> }
> // 4
> ```
>
> Sizeof(a) 的大小是 4 而不是 8，这谁就说明 static 仍然属于类。

> c++11现在支持在类内初始化 const 常量成员了。`const int count =0;`是可以的。

#### 2. 静态成员函数

##### 2.1 性质

1. 静态函数没有 this 指针。 （它不属于类的实例）

2. 静态函数只能访问类中的静态成员变量。
3. 静态函数不需要类的实例就可以调用。
4. 静态成员函数不属于任何对象，而是属于类的。

##### 2.2 访问权限

调用**静态函数**效率要高，因为不需要找类实例的数据就可以执行（所以自然不需要标记类实例地址的 this 指针了，不需要穿参），同时由于没有隐含的this指针，自然无法访问类的其他变量，而**只能访问静态变量**了。

##### 2.3 static & virtual & const

(1) static 成员函数不能为 virtual：       

` virtual static void fun() { }//错误`

原因：

1. static成员不属于任何类对象或类实例，故即使给此函数加上virutal也是没意义的。

2. 静态成员函数没有this指针。 



(2) static成员函数不能为const函数：

  `static void fun() const { } //编译错误`  

 `const static void fun() {}  //可以的` 

原因：当声明一个非静态成员函数为 const 时，对 this 指针会有影响。对于一个 Test 类中的 const 修饰的成员函数，this 指针相当于 Test const , 而对于非 const 成员函数，this 指针相当于 Test . 而 static 成员函数没有 this 指针，所以使用const 来修饰 static 成员函数没有意义。 volatile 的道理也是如此。

##### 2.4 为啥要引入静态成员函数

> 假如我们需要将对静态成员变量的一系列操作封装起来作为一个成员函数（注意不是静态的），那么如果我们想要调用该函数，就必须实例化一个类的对象。而对象的实例化与销毁是需要开销的，更何况我们只是想操作静态成员变量，仅此而已，为此我们实例化一个对象，这太浪费了。

我们知道在C++中调用类的成员函数，会传递一个this指针，将类的实例化对象的首地址传递给成员函数，函数操作会根据对象首地址计算其成员变量的地址，然后进行操作。然而静态成员变量并不保存在对象的内存布局中，而是保存在数据段中，因而没有必要用到 this 指针。所以需要一种独立于对象之外对对象静态成员变量的访问操作。在早期 C++ 引入静态成员函数之前，你会看到下面这样奇怪的写法：（假设有类 test，静态成员函数 `sfunc()`）

`((test *)0)->sfunc();`

编译器生成的代码是先将 ecx 清零，然后直接调用 `test::sfunc()` 函数。这种写法的优点就在于不用对进行对象实例化操作从而节省了时间和空间。这种写法最早由贝尔实验室的成员 Jonathan Shopiro 提出，他本人也是引入静态成员函数的主要倡导者。

另外，当我们不存在实例并且也不想额外实例化一个对象的时候，静态成员函数为我们提供了操作静态成员变量的方法，这种场景很多。

但注意，它不能操作非静态成员变量，否则当不存在类实例的时候，我们可以调用非静态成员变量，但此时非静态成员变量尚不存在，显然是不合法的。而静态成员变量存储在数据段中，所以它是存在的。

> 还有如下好处：
>
> 1. 与类实例无关。
>
> 2. 把类名当成namespace用。
>
> 3. 控制该函数的访问权限。
>
> 4. 控制类内的static变量。

### 0x02 namespace

#### 1. reference

[里面谈到了全局命名空间](https://codeantenna.com/a/gIRJK7VV7N)

[知乎的讨论](https://blog.51cto.com/aiyc/4998037)

[stack overflow 讨论中文翻译](http://129.226.226.195/post/602.html)

#### 2. using namespace std

为什么不要在**头文件**中引入 `using namespace std;`

>  **本来只需要一棵树，你缺砍了整个森林。**

这句解释太形象了，有时候你只是想要 cout，cin，但你却把整个标准库 using 进来，太不合理了。

你引入的太多，发生冲突的概率也就越大。

另外，注意我们是不要在 头文件（.h）而不是源文件（.cpp）里面。因为头文件需要开放给他人使用，而 .cpp 文件并不需要开放给他人。



> 只是千万不要在头文件里面using而已。
>
> 主要是命名冲突，而且冲突以后，编译器给的错误信息基本是妖魔，牛头不对马嘴，难以追查。有些根本编译就没错误和警告，但是就是运行错误。
>
> 跟萌心们解释这些很麻烦，而且效果也不是很好，所以一般直接硬性规定头文件不准出现任何一个using。



比较好的做法应该是自己用一个命名空间封装std，然后using 自己的那个命名空间。

`x=::a;`  a 是全局global作用域下的，不声明 namespace 就是默认处于全局作用域下。例如：

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

namespace xjy {
    int a = 10;
    void f() {
        cout << "namespace:xjy" << endl;
    }
}

int a = 2020;
void f() {
    cout << "namespce:global" << endl;
}

int main()
{
    cout << ::a << endl;
    cout << xjy::a << endl;
    ::f();
    xjy::f();
    return 0;
}
```

#### 3. Examples

举个例子1：变量冲突

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

namespace name1
{
    int a = 2;
}

namespace name2
{
    int a = 3;
}

using namespace name1;
using namespace name2;

//int a = 10; // (1)

int main()
{
    printf("a = %d", a);
}
```

在命名空间 name1 和 name2 中我们都定义了一个 a，此时如果把他们全部引入到程序当中，此时再使用 a，就会出现编译错误–命名冲突，但如果我们加入 （1）处语句，程序会成功运行并输出 10，这是因为（1）处的 a 处于**全局命名空间**，他会取代 using 的 a，就像我们 using namespace std 之后，我们再写一个函数 max，它会覆盖标准库的 max 函数。



例子2：函数冲突

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

namespace name1
{
    void f()
    {
        std::cout << "name1";
    }
}

namespace name2
{
    void f()
    {
        std::cout << "name2";
    }
}

using namespace name1;
using namespace name2;

int main()
{
    f();
}
```

``` shell
a.cpp: In function 'int main()':
a.cpp:28:7: error: call of overloaded 'f()' is ambiguous
   28 |     f();
      |       ^
a.cpp:9:10: note: candidate: 'void name1::f()'
    9 |     void f()
      |          ^
a.cpp:17:10: note: candidate: 'void name2::f()'
   17 |     void f()
      |          ^
```



例子3：与 std 发生冲突

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int max = 1;
int main()
{
    std::cout << max << std::endl;
}
```

如果我们将 using namespace std 注释掉，程序正确运行并输出 1，但如果不注释掉，max 会命名冲突。

别问我为什么定义一个 max 变量，只要我不引用 std，不就是正确的吗？

但是我引用了你的头文件，而你的头文件中引用了 std，那我就绷不住了 T.T。

### 0x03 [Virtual function table](https://leehao.me/C-%E8%99%9A%E5%87%BD%E6%95%B0%E8%A1%A8%E5%89%96%E6%9E%90/)

虚函数表就是一个 **指针数组**，数组的元素就是指向一个虚函数的指针。

虚函数表内的条目，即虚函数指针的赋值发生在编译器的编译阶段，也就是说在代码的编译阶段，虚表就可以构造出来了。

### 0x04 typename

[Reference](https://blog.csdn.net/iotflh/article/details/114789270)

## 四、Oritened Object

### 0x01 Class Relation

> 面向对象的思想就是 class 和 class 之间有各种各样的联系

#### 1. Composition（has a）

复合表示一种 “has-a” 的关系。即，“我中有你”。

在人类的理解中，一个东西的构造肯定是由内而外的，只有里面构造好了，东西才扎实。同样，C++ 面向对象也要和人类的理解相似。

> 复合关系下的构造和析构。
>
> 假设现在有一个 Container 类包含 Component 类。

**构造由内而外：**

Container 的构造函数首先调用 Component 的 default 构造函数，然后才执行自己。

`Container::Container(...) : Component() { ... };`

**析构由外而内：**

Container 的析构函数首先执行自己，然后才调用 Component 的析构函数。

`Container::~Container(...) { .. ~Component() };`

如果包含了多个 class，执行的顺序编译器会帮我们实现。

> 关于这里的执行顺序问题，在下面 [四 .0X02 .1] 中我们把 component 比作房子中的装饰品，把 container 比作房子。这其实对于这里的理解不太好，因为不都是先建好房子，再装饰房子吗？
>
> 我们可以换一种角度，只有把房子装饰好了，才能说这个房子是完整的，而我们要的是一个完整的房子，不是一个空壳。
>
> 因此说，我们先构造 compoent，再构造 container。

#### 2. Inheritance（is a）

is a，表示 “是一种” 的关系。

C++ 给我们提供了三种继承方式（Java 只有 public 一种继承方式，因此在 Java 中，public 可以不写）。

> 单纯的继承价值并不大，只有与 “虚函数” 搭配时，继承才能发挥它最大的价值。



> 继承关系下的构造与析构。
>
> 假设现在类 Derived 继承自基类（父类） Base。

**构造由内而外：**

Derived 的构造函数首先调用 Base 的 default 构造函数，然后才执行自己。

`Derived::Derived(...) : Base() { ... };`

**析构由外而内：**

Derived 的析构函数首先执行自己，然后才调用 Base 的析构函数。

`Derived::~Derived( ... ) { ...~Base() };`



> Base class 的 dtor 必须是 virtual，否则会出现 undefined behavior。

[参考本文 Appendix 中的 0x04]

文中提到了：

1. 静态多态性 和 动态多态性：函数重载与模版实现静态多态性。虚函数实现动态多态性。
2. 为什么需要将析构函数设置为虚拟函数：避免内存泄漏。
3. 为什么默认的构造函数不是虚函数：避免不必要的内存浪费。



> 为什么析构函数不设置为虚函数会导致内存泄漏？ —— 动态绑定
>
> **virtual function is the basis for dynamic binding** 

 直接的讲，C++中基类采用virtual虚析构函数是为了防止内存泄漏。具体地说，如果派生类中申请了内存空间，并在其析构函数中对这些内存空间进行释放。 **“假设基类中采用的是非虚析构函数，当删除基类指针指向的派生类对象时就不会触发动态绑定，因而只会调用基类的析构函数，而不会调用派生类的析构函数”**。 那么在这种情况下，派生类中申请的空间就得不到释放从而产生内存泄漏。所以，为了防止这种情况的发生，C++中基类的析构函数应采用virtual虚析构函数。

#### 3. Delegation

**composition by reference**

> 也有人把 delegation 和 composition 视为一类，这是术语上的差异，明白其**“精神”**即可，怎么称呼其实无关紧要。delegation 的 “精神” 就是 composition by reference。

> by pointer
>
> The way to pass value is divided into two ways: pass by value and pass by reference. 
>
> We find that there is no pass by pointer. why? Because that is what academia(学术界) calls it. **Although we pass by pointer, we still call it pass by reference.**

通过在 class 中引用其他 class 可以提高程序的弹性，我们的源 class 不需要变化（这意味着我们开放给用户的接口不变），而只需要修改引用的 class 即可。

![img](https://s3.bmp.ovh/imgs/2022/10/20/bcce1dd5388a77e9.png)

Pimpl: pointer to implement 

### 0x02 virtual function



> **virtual function is the basis for dynamic binding**



![img](https://s3.bmp.ovh/imgs/2022/10/20/56c751f20ee7e7c0.png)

this template is not that key template

#### 1. Inheritance and composition

当继承和复合都存在的时候，构造和析构的顺序：

这里有两种情况：

1. **class** inherit 继承**class** fa，**class** inherit 包含 **class** com
2. **class** inhert 继承 **class** fa，**class** fa 包含 **class** com：这种情况比较明显，**class** inherit contain **class** fa, **class** fa contain **class** com

所以我们考虑第一种情况：

构造函数执行顺序：fa -> com -> inherit

析构函数执行顺序：herit->com->fa

> 为什么总是先调用父类的呢？

我们可以这样理解：把子类比作一个房子。

子类继承自父类，父类就相当于 “地基”，而子类中的复合类就相当于 “房子中的装饰”，例如地板，墙壁，装饰品等，我们首先得把地基搭好了，然后才能开始建房子，所以说父类肯定在子类之前。

而我们只有把地基搭好，才能装饰我们的房子吧，所以说，复合类也应该在父类之前。

> 不过无需太关心这个，而且这个一般和编译器相关。

#### 2. Inheritance and delegation

候捷这里举了一个很经典的例子，来说明继承和委托的典型应用：画图。

在一些画图软件中，我们可能有这样的功能选项：系统给定了你一些图形（圆形，三角等），你可以自己设置这些图形的参数（长宽高，半径等）。

想要用类来表达这个功能，我们首先需要将所有的图形抽象出来，作为一个抽象的 **class** shape，那么 **class** 三角，**class** 圆形等都继承自 **class** shape。然后我们可以把我们的数据传送（委托）给具体的子类（**class** 圆形，**class** 三角形），让它替我们完成数据的处理并描绘出具体的图形。 

这就是通过委托和继承我们将一份数据（图形的参数信息）表达为多种不同的形态（三角形 or 圆形 .. ）。 

#### 3. composite

设计模式之 complsite（复合）模式。

#### 4. prototype 模式

设计模式之 prototype（原型） 模式

## <勿在浮沙筑高台>

## 五、object modle

### 0x01 conversion function

格式：`operator TYPE() const { return XX_TYPE; }`

其中 TYPE 就是我们想要转换成的类型，返回值的类型也是 TYPE，注意**不能有参数和返回类型**。

作为一个转换函数当然不需要参数。没有返回类型是因为返回值的类型和 TYPE 必然相同，C++ 编译器说：“你不用写返回类型，因为 TYPE 已经指出返回类型了，而你写还有可能写错”。

后面通常加上 const，你不加也没错，但是你该加就要加，因为类型转换一般不会改变成员变量。

转换函数和内置类型的转换函数一样，都可以隐式调用。

例如：

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Fraction
{
public:
    Fraction(int _num, int _den = 1) : num(_num), den(_den) {}
    
    // 如果是这个 ctor，直接产生解释2
    // explicit Fraction(int _num, int _den = 1) : num(_num), den(_den) {}

    operator double() const  {
        return (double)num / den;
    }
    operator string() const {
        return string(to_string(num) + '/' + to_string(den));
    }
    Fraction operator +(const Fraction &f) {
        return Fraction(num + f.num, den + f.den);
    }
private:
    int num;
    int den;
};

int main()
{
    Fraction f(2, 4);
    double d = 4 + f;
    //double d = f + 4; // ambiguous overload for 'operator+' (operand types are 'Fraction' and 'int')
    cout << d << endl;
        
    // extension
    string s = f;
    cout << s << endl;
    return 0;
}
```

注意转换函数可能会与我们重载的其它运算符发生冲突。在上面的例子中，如果我们以 `double d = f + 4;` 的形式调用就会产生二义性，这是因为 `f + 4` 可以有两种解释形式：

1. 调用 `operator+` 解释 `f+4` 为一个` fraction` 类型（因为在  `fraction` 的构造函数中，我们只需要传入一个参数 `num` 就可以调用构造函数，所以这里的 `4` 调用了构造函数），然后调用转换函数，将 `fraction(f+4)` 转换为 `double` 类型。
2. 调用转换函数将 `f` 解释为 `double`。

> 我们可以通过如下方式调用构造函数：
>
> ```
> Fraction f = 4;
> ```

不过如果我们不适用` f+4` 这种形式就不会出现这种错误（自己骗自己），但是要留意这种二义性错误。

> 应用：
>
> `vector` 的 `[]` 就是通过构造函数实现的

### 0x02 non-explicit-one-argument ctor

one argument 表示该 ctor “至少” 需要一个实参，也就是说可以是多个实参，但是其他都有默认值，我们只需要一个参数就可以调用 ctor。

explicit 是一个 **key word**，它的意思是：明白的，明确的。用它修饰一个函数（例如构造函数），就是在告诉编译器，我就是一个构造函数，不要那我干其他事情，例如用我做类型转换等。

这个 key word 很少用到，并且百分之九十五的情况下看到这个关键字都是在 ctor 的前面，其它在模版里一个很小的地方也会用到。

其实主要就是为了解决 0x01 中的二义性错误，在上面的例子中，之所以产生二义性错误的主要原因是因为我们的语句：`double d = f + 4;` 的 `4` 会调用构造函数，这并不是我们所希望的，我们没有任何显式的表示要让这个 `4` 作为 `Fraction` 类型，而且我们的本意也是说 4 是一个 `double` ，毕竟我们的 `d` 声明的也是一个 `double` 类型。

但是编译器“默默”为我们做了这些事，那么有没有什么办法阻止编译器“替”我们调用构造函数吗？有。

通过为构造函数加上关键字 `explicit`，就可以让 ctor 做他该做的事情（初始化对象），而不是在这里将表达式中的一个变量作为对象并调用构造函数。

这也说明了为啥是 one-argument，因为我们的运算对象通常都是一个变量，你不会一下子 op 两个对象把？`a op (b,c)` 这不太符合直觉。



----



### 0x03 xxx-like classes

#### 1.  pointer-like classes

一个像 pointer 的 class，所谓 **smart pointer**。

为什么把一个 class 设计的像 pointer？因为我们像让它比单纯的指针多做一些事情。

一个智能指针里面一定包含一个真的指针，也就是说智能指针就是对普通指针的封装，并提供了更多的功能，但是它应该实现真的指针的功能（解引用 `*` 和 `->`）。

例如：

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Foo
{
    int data;
    void method()
    {
        cout << "you call Foo::method." << endl;
    }
};

template<typename T>
class shared_ptr
{
public:
    shared_ptr(T *obj) : px(obj) {}
    T& operator *() const 
    {
        return *px;
    }
    T* operator ->() const 
    {
        // otherway, call operator* but create new
        //return &(operator *());   
        return px;
    }
private:
    T* px;
    long *pn;
};

int main()
{
    shared_ptr<Foo> p(new Foo); 
    // 把指向shared_ptr类的指针p当做一个指向Foo对象的指针使用即可
    (*p).data = 1024;
    p->method();
    cout << p->data << endl;
    
    Foo *f = new Foo;
    f->method();
    
    return 0;
}
```

在上面的对 std 中的 shared_ptr 简化模拟中，我们可以发现，shared_ptr 内部包含了一个成员变量 - 指针 px，这体现了智能指针其实就是对普通指针的封装。我们还可以在 shared_ptr 中添加一个额外的功能。（但是我并没有。。懒）

然后可以发现我们重载了 `*` 和 `->` 这两个指针必需的运算符

1.  `*` 的返回类型是一个对象的引用（`&`），这我们可以理解。在上面的例子中，我们的语句 `(*p).data = 1024;` 会被转换为 `(*px).data = 1024;`  很合理。
2.  `->` 的返回类型是一个指针（`*`）。在上面的例子中，我们的语句 `p->method();` 会被转换为 `pxmethod();` what？这非常不合理，我们想要的是：`px->method();`  但是我们的 `->` 不见了！那我们还怎么调用 `method`。别担心，`->` 有一个性质，就是当它被解释后，它会继续执行执行下去，什么意思呢？在这里的重载函数中，我们实际上是把 `->` 解释没了，但其实，它仍然存在。好像有点麻烦，不过你不需要纠结这些，你只要记住 `->` 被解释之后也会继续作用在它原本指向的对象就行了。

小 tips：

> 在重载 `->` 之后，我们返回 `T*`。不要傻乎乎的把 `T*` 直接在源表达式替换：`(*px)->method();`
>
> 在返回的时候，我们要加上 `*`表示这是一个指针，但是在使用 “指针”（注意不是指针所指向的对象）的时候，我们不能加上 `*`，否则就会被解释为指向所指向的对象。
>
> 指针其实就是对象的地址的另一种表达方式，同理，地址也是表示指针指向对象的一种表达方式。不要刻意区分他们。

应用：

> 迭代器。

例如：

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

template<class T>
struct list_node {
    void *prev;
    void *next;
    T data;
};

template<class T, class Ref, class Ptr>
struct list_iterator {
  typedef list_iterator<T, Ref, Ptr> self;
  typedef Ptr pointer;
  typedef Ref reference;
  typedef list_node<T>* link;
  link node;
  
  bool operator ==(const self &x) const { return node == x.node; }
  bool operator !=(const self &x) const { return node != x.node; }
  
  reference operator  *() const { return (*node).data; }
  pointer   operator ->() const { return &(operator *()); }
  
  self& operator ++() { // pre: ++ x
    node = (link)((*node).next);
    return *this;
  }
  self operator ++(int)  { // post: x ++ 
    self tmp = *this;
    ++ (*this);
    return tmp;
  }
  self& operator --() { // pre: -- x
    node = (link)((*node).prev);
    return *this;
  }
  self operator --(int) { // post: x --
    self tmp = *this;
    -- (*this);
    return tmp;
  }
};

using namespace std;

int main()
{
    
    return 0;
}
```



#### 2. function-like classes

一个像 function 的 class，所谓 **仿函数**，**函数对象（function object）**。

例如：

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template<class T>
struct indetity {
    // 重载运算符：()
    // 返回类型是：const T&
    // 参数是：T &x
    // 是一个常量成员函数
    const T& 
    operator ()(const T &x) const {
        return x;
    }
};

template<class Pair>
struct select1st {
    const typename Pair::first_type& 
    operator ()(const Pair& x) const {
        return x.first;
    }
};

template<class Pair>
struct select2st {
    const typename Pair::second_type&
    operator ()(const Pair &x) const {
        return x.second;
    }
};

/*Pair域下的两个类型变量
    Pair::first_type
    Pair::second_type
*/

int main()
{
    select1st<pair<double,int>> s1;
    pair<double,int> p = {1, 2};
    cout << s1(p) << endl;
    return 0;
}
```

标准库中的仿函数的模拟实现：

```C++
#include <iostream>

template<class T>
struct minus {
    T operator ()(const T &x, const T &y) { return x - y; }
};

template<class T>
struct equal_to {
    bool operator ()(const T &x, const T &y) { return x == y; }  
};

template<class T>
struct less {
    bool operator ()(const T &x, const T &y) { return x < y; }
};

template<class T>
struct plus {
    T operator ()(const T &x, const T &y) { return x * y; }
};

template<class T, class eleType>
eleType test(eleType a, eleType b, T func)
{
    return func(a,b);
}

int main()
{
    int a = 2, b = 4;
    // std::cout << plus<int>()(a,b) << std::endl;
    // std::cout << minus<int>()(a,b) << std::endl;
    // std::cout << equal_to<int>()(a,b) << std::endl;
    // std::cout << less<int>()(a,b) << std::endl;
    std::cout << test(a, b, plus<int>()) << std::endl;
    std::cout << test(a, b, minus<int>()) << std::endl;
    std::cout << test(a, b, equal_to<int>()) << std::endl;
    std::cout << test(a, b, less<int>()) << std::endl;
    return 0;
}
```



#### 3. CLASS_NAME obj();

这个写法是一个经典的错误写法。

下面通过一个例子再深刻理解一下。

``` C++
#include <iostream>
using namespace std;

class test {
public:
    test() { cout << "I am ctor" << endl; }
    void func() { cout << "I am func!" << endl; }
};

int print(int x) { cout << "I am " << x << endl; }

int main()
{
}
```

在上面的代码中，我们定义了一个函数 print 和一个类 test，main 函数内容为空，程序可以通过编译。

（1）现在，如果我们想定义一个类的对象 p：

``` C++
test p();
```

程序依然可以通过编译。

（2）接下来，我们希望通过这个对象 p 调用类中的函数 func：

``` C++
test p(); 
p.func();
```

发现程序报错：

``` SHELL
error: request for member 'func' in 'p', which is of non-class type 'test()'
   26 |     p.func();
```

大致意思就是说我们的 p 不是一个 class 类型，所以它不存在成员函数，咦，我们不是定义了一个 class 对象 p 并且编译通过了吗？怎么现在又报错呢？

这是因为 C++ 兼容 C 的缘故，编译器看到 p 后面跟着一个 () ，就会将 `test p();` 解释为声明一个函数，函数名是 p，返回值类型是 class test。这当然没问题。

但是我们现在通过函数名调用 class 的成员函数 func 就不合理了。

> 小插曲：可以在函数的内部声明函数吗？
>
> 这关系到 **C 语言的标准规范**和**具体编译器的实现**问题。
>
> 　从标准规范来看：
>
> 1. C语言**允许函数里声明函数**，但是不建议这么写，因为不利于多文档的组织。
> 2. C语言**禁止函数里定义函数**，但是个别编译器却没遵循标准。
> 3. **C语言的标准**和**编译器的实现**并不是完全统一，为了可移植性，建议一切都按 C 语言标准中推荐的做法来写。
>
> 综上所述，在函数内声明函数是合法的，并且在链接到另外一个文件中的函数时，也可以在函数内部声明。但是这种语法不应该被我们使用，因为它不利于代码的移植性和规范性。
>
> 例如下面两个文件：
>
> ``` C++
> /* declare.cpp*/
> #include <iostream>
> int print(int x)
> {
>     std::cout << "I am " << x << std::endl;
>     return x;
> }
> 
> /* main.cpp */
> #include <iostream>
> using namespace std;
> int main()
> {
>     int print(int x);
>     cout << "MAIN: " << print(1024) << endl;
>     return 0;
> }
> 
> //  g++ declare.cpp main.cpp -o app
> //  输出：
> //  MAIN: I am 1024
> //  1024
> ```
>
> 经过测试发现可以正常执行。

（3）但是在上一节的例子中，我们的语句 `std::cout << test(a, b, plus<int>()) << std::endl;` 可以正确执行。

 `plus<int>()` 的作用是创建一个 “没有名字的” 临时对象，它会调用默认构造函数并且不会解释为函数。

而且如果我们声明语句： `less<int> tmp();` 依然会解释为一个函数。

（4）如何声明一个类的临时对象？

在上面的说明中，之所以编译器会将` less<int> tmp();` 解释为一个函数，其实主要是因为我们指定了“这个东西的名字”！如果我们不指定“名字”，而是直接： `less<int> ();` 那么编译器就会将这句话看做是声明一个 class less 的临时对象。

综上，创建临时对象的语法：`CLASS[<>] ();`

这就是通过 `()` 调用默认构造函数，注意不要与上面的东西混淆了，他们的区别仅仅在于是否有名字，但是解释后的结果却截然相反，一个是函数，一个是对象。

### 0x04 template

#### 1. class template

不多做介绍。

#### 2. function template

函数模版在编译后得到的是一个 “半成品”，它不一定能保证使用。意思就是模版本身编译可以通过，当真正使用时会再编译一次（这次实参的类型已经确定了），这时能不能通过就不确定了（类型不合适之类，或者你得类没有重载相应的运算符）。

#### 4. member template

成员模板。

向上转型（**up-cast**）：在将继承关系画成图的时候，我们通常将父类画在图的上方，子类画在图的下方，子类指向父类。因为子类到父类的转换我们形象的称其为 “向上转型”。

在成员模板中，子类的对象可以传给父类，因为子类从父类继承，它拥有父类的东西，但是父类不一定包含子类的东西，所以说父类的对象不可以传给父类。当我们把一个子类的对象传给父类的时候，我们说发生了 “**up-case**”。

如图：（我们通常用用△来表示继承关系，用◇箭头表示 point 关系，point 关系的 ◇ 在指针一方而不是指向的对象一方，继承关系的△在父类乙方）![IMG](https://s3.bmp.ovh/imgs/2022/10/25/90eda9ffa0c8f118.png)

例子：

``` C++
#include <iostream>

using namespace std;

template <class T1, class T2>
class Pair
{
public:
    typedef T1 first_type;
    typedef T2 second_type;
    
    T1 first;
    T2 second;
    
    Pair() : first(T1()), second(T2()) { cout << "ctor1" << endl; }
    Pair(const T1 &a, const T2 &b) : first(a), second(b) { cout << "ctor2" << endl; }
    
    template<class U1, class U2>
    Pair(const Pair<U1, U2> &p) : first(p.first), second(p.second) { cout<< "ctor3" << endl; }
    
    void print() { cout << "print" << endl; }
};

class Base {};
class Derived : public Base {};

int main()
{
    /* test 1 */
    Pair<char, double> p1 = {'A', 23.32};
    cout << p1.first << ' ' << p1.second<< endl;
    
    // Pair<int, int> p2 = p1;
    Pair<int, int> p2 = Pair<char, double>('A', 23.32);
    cout << p2.first << ' ' << p2.second<< endl;
   
    /* test 2 */
    // 向上转型
    Pair<Base, Base> p3;
    Pair<Derived, Derived> p4;

    Pair<Base, Base> p5 = Pair<Derived, Derived>(); // up-cast
    Pair<Base, Base> p6 = p4;   // up-cast
    // Pair<Derived, Derived> p7 = p3;  // cant up-cast
    
    /* test3 */
    // 声明一个临时对象
    Pair<int,int> ().print();

    return 0;
}
```

你可能会问，为什么可以把子类的传给父类，而父类不可以传给子类？

> s别钻牛角筋。你只需要牢记，面向对象的考虑都是从现实生活考虑的。
>
> 现在假设动物是父类，哺乳类和鸟类分别是子类。（**up-cast**）
>
> 哺乳动物和鸟类是动物，但是动物不一定是鸟类或者哺乳类。
>
> 就是这么简单。

#### 5. specialization

##### 5.1 介绍

模板特化就是将模板中的一部分类型抽离出来，明确的规定好是什么类型。

模板特化的种类：

1. (full) specialization：模版特化（全特化）

2. paritical specialization：模版偏特化（局部特化）

   (1) 个数的偏特化

   (2) 范围的偏特化

3. template template parameter：模版模版参数

语法：就如同我们前面说的那样，模板特化就是在原模板的基础上，将一部分类型从模板中 “抽离” 出来，直接写在类名的后面，然后在模板中删去这个类型即可。但是在偏特化中，即使我们只是抽取了一部分类型，也要把所有类型写在类中。

##### 5. 2 全特化和偏特化

类模板全特化的例子：

``` C++
#include <iostream>

using namespace std;

// 模板
template<class T1, class T2>
class Hash {
public:
    Hash() { cout << "T1 && T2" << endl; }
};

// 模板全特化
template<> // 抽离 class key
class Hash<int, char> { // 加上 <int>
public:
    Hash() { cout << "int && char" << endl; }
};

// (个数)模板偏特化 1
template<class T2>
class Hash<T2, int> {
public:
    Hash() { cout << "T2 && int" << endl; }
};

// (个数)模板偏特化 2
template<class T2>
class Hash<int, T2> {
public:
    Hash() { cout << "int && T2" << endl; }
};

// (范围)模板偏特化 1
template<class T1, class T2>
class Hash<T1*, T2*> {
public:
    Hash() { cout << "T1* && T2*" << endl; }
};

// (范围)模板偏特化 2
template<class T2>
class Hash<int*, T2*> {
public:
    Hash() { cout << "int* && T2*" << endl; }
};

int main()
{
    Hash<int,  char>   h1;    // int && char
    // Hash<int,  int>  h2; // ambiguous
    Hash<char, char>   h3;    // T1 && T2
    Hash<char, int>    h4;    // T2 && int
    Hash<int*, int*>   h5;    // int* && T2*
    Hash<char*, char*> h6;    // T1* && T2*
    return 0;
}
```

当我们将模板的类型固定为具体类型（指定类型的指针也是具体类型）的时候，我们称其为**个数偏特化**，如果固定为一个指针（没有指定类型），称为**范围偏特化**。

可以发现，模板特化与模板可以共存，并且当我们传入的类型可以从特化的模板中匹配时，会**优先考虑特化的模板**，如果有很多个特化的模板可供选择，选择**特化程度最高的**。

另外，当我们声明 h2 的时候会产生二义性，这是因为两个个数偏特化的模板都符合要求，并且优先级相同，编译器不知道调用那个了。同样 h7 也会产生二义性，因为个数偏特化2 和 范围偏特化1 发生了冲突。

由此，我们可以发现模板特化很容易产生冲突啊。

上面的例子都是特化类模板，如果我们特化的是函数模板呢？加入此时同时存在普通函数，特化模板，纯模板，函数调用的优先级是什么呢?

> 普通函数的优先级 > 特化 > 非特化

例如：

``` C++
#include <iostream>
using namespace std;
 
template<typename T1, typename T2>
void func(T1 a, T2 b) {
    cout << "template<T1, T2> func" << endl;
}
 
template<>
void func(int a, int b) {
    cout << "template<int,int> func" << endl;
}

template<typename T2>
void func(int a, T2 b) {
    cout << "template<int,int> func" << endl;
}

void func(int a, int b) {
    cout << "normal func" << endl;
}
 
int main() {
    int a = 3, b = 4;
    char c = 'A';
    double d = 3.14;
    func(a, b); // int,int
    func(a, d); // int, double
    func(c, d); // char, double
 
    return 0;
}
/*normal func
template<int,int> func
template<T1, T2> func*/
```

使用普通函数重载和使用模板特化还是有不同之处，主要表现在如下三个方面：

1. 如果使用普通重载函数，那么不管是否发生实际的函数调用，都会在目标文件中生成该函数的二进制代码。而如果使用模板的特化版本，除非发生函数调用，否则不会在目标文件中包含特化模板函数的二进制代码。这符合函数模板的“**惰性实例化**”准则。
2. 如果使用普通重载函数，那么在分离编译模式下，需要在各个源文件中包含重载函数的申明，否则在某些源文件中就会使用模板函数，而不是重载函数。

3. 模板特化版本还是模板，必须放到头文件里面。普通函数重载得放在.c和.cpp里面。

[为什么不该特化函数模板](https://www.jianshu.com/p/e78d9d3bf535)

##### 5.3 模板模板参数

模板模板参数的含义就是模板的一个参数又是一个模板。

例如：[参考自](https://blog.csdn.net/men_wen/article/details/74033327)

```C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <list>
#include <vector>
#include <map>

using namespace std;

// 模板类 XCls 的一个参数是一个又是一个模板
template<typename T, 
        template<typename U> 
        typename Container
        >
class TT
{
    public:
        Container<T> c;
};

template<typename T>
class Bar
{
    public:
        T t;
};

template<typename T1, typename T2 = int>
class Foo
{
    public:
        T1 t1;
        T2 t2;
};


int main()
{
    TT<string, Bar> mylst1;
    TT<string, Foo> mylst2;
    // 很奇怪
    // TT<string, list>   mylst3;
    // TT<string, map>    mylst4;
    TT<string, set>    mylst5;
    TT<string, vector> mylst6;
    return 0;
}

```



### 0x05 reference VS. pointer

引用：代表

指针：指向

引用的底层实现就是指针

reference 就是一种漂亮的 pointer

[[1]](https://blog.csdn.net/cnmilan/article/details/7464233?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-7464233-blog-78511858.pc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-7464233-blog-78511858.pc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=1)

[[3]](https://zhuanlan.zhihu.com/p/384591552)

[[2]](https://blog.csdn.net/weixin_33868027/article/details/86379309?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-86379309-blog-7464233.pc_relevant_layerdownloadsortv1&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-86379309-blog-7464233.pc_relevant_layerdownloadsortv1&utm_relevant_index=1)

[[4]](https://blog.csdn.net/coutamg/article/details/61924902?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0-61924902-blog-100904422.pc_relevant_layerdownloadsortv1&spm=1001.2101.3001.4242.1&utm_relevant_index=3)

signature签名, const算函数签名，但是引用不算

string 内部是一个指针

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s = "sddsdasa";
    cout << sizeof(s) << endl;
    return 0;
}
```



### 0x06 vptr && vtbl

![img](https://s3.bmp.ovh/imgs/2022/10/25/e00b2a81977cdfb5.png)

虚指针和虚表:放的都是函数指针

在继承中，成员变量直接把内存也继承了过来，而成员函数只是继承了使用权（它不会在生成一份），因此，如果父类有虚函数，子类也一定有（不管你有没有实现）。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class A
{
    public:
        virtual void vfunc1() {}
        virtual void vfunc2() {}
        void func1();
        void func2();
    private:
        int data1;
};

class B : public A
{
    public:
        virtual void vfunc1() {}
        void func2();
    private:
        int data2;
};

class C : public B
{
    public:
        virtual void vfunc1() {}
        void func2();
        int data1;
    private:
        int data3;
};

int main()
{
    A a;
    B b;
    C c;
    cout << sizeof(a) << ' ' << sizeof(b) << ' ' << sizeof(c) << endl;

    return 0;
}
// 我们可以发现 sizeof(a)=16，这是因为虚指针占用8字字节并且对其的原因
```

打印虚函数的地址

``` c++
#include <iostream>

using namespace std;
 
class Base
{
public :
    int base_data;
    Base() { base_data = 1; }
    virtual void func1() { cout << "base_func1" << endl; }
    virtual void func2() { cout << "base_func2" << endl; }
    virtual void func3() { cout << "base_func3" << endl; }
};
 
class Derive : public Base
{
public :
    int derive_data;
    Derive() { derive_data = 2; }
    virtual void func1() { cout << "derive_func1" << endl; }
    virtual void func2() { cout << "derive_func2" << endl; }
};
 
typedef void (*func)();
 
int main()
{
    Base base;
    cout << "&base: " << &base << endl;
    cout << "&base.base_data: " << &base.base_data << endl;
    cout << "----------------------------------------" << endl;
 
    Derive derive;
    cout << "&derive: " << &derive << endl;
    cout << "&derive.base_data: " << &derive.base_data << endl;
    cout << "&derive.derive_data: " << &derive.derive_data << endl;
    cout << "----------------------------------------" << endl;
    
    /* 对象和第一个数据之间的地址差了8，这个8应该存放的时虚指针 */
 
    for(int i=0; i<3; i++)
    {
        // &base : base首地址
        // (unsigned long*)&base : base的首地址，vptr的地址
        // (*(unsigned long*)&base) : vptr的内容，即vtable的地址，指向第一个虚函数的slot的地址
        // (unsigned long*)(*(unsigned long*)&base) : vtable的地址，指向第一个虚函数的slot的地址
        // vtbl : 指向虚函数slot的地址
        // *vtbl : 虚函数的地址
        unsigned long* vtbl = (unsigned long*)(*(unsigned long*)&base) + i;
        cout << "slot address: " << vtbl << endl;
        cout << "func address: " << *vtbl << endl;
        func pfunc = (func)*(vtbl);
        pfunc();
    }
    cout << "----------------------------------------" << endl;
 
    for(int i=0; i<3; i++)
    {
        unsigned long* vtbl = (unsigned long*)(*(unsigned long*)&derive) + i;
        cout << "slot address: " << vtbl << endl;
        cout << "func address: " << *vtbl << endl;
        func pfunc = (func)*(vtbl);
        pfunc();
    }
    cout << "----------------------------------------" << endl;
    
    return 0;
}
```

动态绑定的三个条件：指针调用。向上转型。调用虚函数。



### 0x07 class VS. struct in C++

[C++](http://c.biancheng.net/cplus/) 中保留了C语言的 struct 关键字，并且加以扩充。在C语言中，struct 只能包含成员变量，不能包含成员函数。而在C++中，struct 类似于 class，既可以包含成员变量，又可以包含成员函数。

C++中的 struct 和 class 基本是通用的，唯有几个细节不同：

- 使用 class 时，类中的成员默认都是 private 属性的；而使用 struct 时，结构体中的成员默认都是 public 属性的。
- class 继承默认是 private 继承，而 struct 继承默认是 public 继承。
- class 可以使用模板，而 struct 不能（《[模板、字符串和异常](http://c.biancheng.net/cpp/biancheng/cpp/rumen_14/)》一章会讲解模板）。


C++ 没有抛弃C语言中的 struct 关键字，其意义就在于给C语言程序开发人员有一个归属感，并且能让C++编译器兼容以前用C语言开发出来的项目。

**在编写C++代码时，我强烈建议使用 class 来定义类，而使用 struct 来定义单纯的结构体（无函数），这样做语义更加明确。**

在 C 语言中，结构体内无法声明函数，但是我们增加一层抽象（计算机的问题总是可以通过抽象解决），在结构内声明一个指针，让这个指针指向某个函数。

``` c++
#include <stdio.h>
#include <stdlib.h>

void f()
{
    puts("func::f");
}

int g(int x)
{
    puts("self[x]");
    return x;
}

typedef struct
{
    int data;
    void (*p1)();
    int (*p2)(int);
} node;

int main()
{
   node s = {
      .data = 1,
      .p1 = f,
      .p2 = g
   };

    printf("data: %d\n", s.data);
    s.p1();
    printf("p2: %d\n", s.p2(1024));
   return 0;
}
```



### 0x08 Using

#### 1. management namespace

配合命名空间，对命名空间权限进行管理**

```c++
using namespace std;//释放整个命名空间到当前作用域
using std::cout;    //释放某个变量到当前作用域
```

#### 2. type alias

类型重命名。作用等同typedef，但是逻辑上更直观。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef void (*tptr)();
using uptr = void(*)();

void f() 
{
    cout << "you call f^ ^" << endl;
}

int main()
{
    tptr tp = f;
    uptr up = f;
    tp();
    up();
    
    return 0;
}
```



#### 3. inherit permission

继承体系中，改变部分接口的继承权限。

有这样一种应用场景，比如我们需要私有继承一个基类，然后又想将基类中的某些 public 接口在子类对象实例化后对外开放直接使用。如下即可

[附：私有继承](https://zhuanlan.zhihu.com/p/376368003)

#### 4.TODO: VS. typedef & define



### 0x09 delete & new 

我们在前面已经提到过，调用 new 和 delete 时编译器会转化为调用 operator new 和 operator delete，而 operator new 和 operator delete 的底层调用是 malloc 和 free。也就是对 malloc 和 free 的封装。

我们可以重载 new 和 delete，通过重载 operator new 和 operator delete，实际上就是以我们自己的方式封装 malloc 和 free。

[重载的 delete 为什么不能执行](https://bbs.csdn.net/topics/390822574)

new ：operator new，array new，placement new

重载的 new 的第一个参数的类型必须是 `size_t` 。我们在调用 new 函数的时候，并不需要将 size_t 作为参数传入参数列表，而是在 new 后面紧跟着一个类型，例如： `new int;` 而不是 `new(4);` 或者 `new(int);`

所以说，在我们 placement new 的时候，为 new 的参数列表中传入 n 个参数，那么实际上 new 的参数列表中有 n+1 个参数。

![img](https://s3.bmp.ovh/imgs/2022/10/27/1f9bf40a891a34f9.png)

例子：

``` C++
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void *my_Alloc(size_t size)
{
    // cout << "you call myAlloc" << endl;
    malloc(size);
}

void my_Free(void *ptr)
{
    // cout << "you all myFree" << endl;
    free(ptr);
}

// 重载 new 和 delete，其实就是运算符重载
inline void *operator new(size_t size)
{
    cout << "size: " << size << ' ';
    cout <<"you call global new()\n";
    return my_Alloc(size);
}

inline void *operator new(size_t size, int extra)
{
    cout << "extra: " << extra << endl;
    return my_Alloc(size + extra);
}

inline void operator delete(void *ptr)
{
    cout << "you call global delete delete()\n";
    my_Free(ptr);
}

inline void *operator new[](size_t size)
{
    cout << "size: " << size << ' ';
    cout << "you call global new[]()\n";
    return my_Alloc(size);
}


inline void operator delete[](void *ptr)
{
    cout << "you call global delete[]\n";
    my_Free(ptr);
}

void test(void *ptr)
{
    cout << "you call test" << endl;
}

struct Foo
{
    public:
        Foo() { 
            cout << "Foo::Foo()" << endl; 
        }
        Foo(int x) { 
            cout << "Foo::Foo(int)" << endl;
            throw -1;
        } 
        ~Foo() { // 我们这里写析构函数只是为了测试，实际上Foo类并不需要析构函数
            cout << "Foo::~Foo()" << endl;
        }
                
        static void *operator new(size_t size)
        {
            cout << "size: " << size << ' ';
            cout <<"you call Foo new()\n";
            return my_Alloc(size);
        }
        
        static void operator delete(void *ptr)
        {
            cout << "you call Foo delete delete()\n";
            my_Free(ptr);
        }
        
        static void *operator new[](size_t size)
        {
            cout << "size: " << size << ' ';
            cout << "you call Foo new[]()\n";
            return my_Alloc(size);
        }
        
        
        static void operator delete[](void *ptr)
        {
            cout << "you call Foo delete[]\n";
            my_Free(ptr);
        }
        
        virtual void func() {}  // 虚函数表占 8 字节
        int data;
};

int main()
{
    /*  测试 delete 和 new  */
    int *a = new int;
    double *b = new double;
    test(a);
    test(b);
    delete a;
    delete b;
    cout << "---------------------------" << endl;
    cout << "---------------------------" << endl;
    
    
    /* 测试 delete array 和 new array */
    int *arr = new int[10];
    delete[] arr;
    cout << "---------------------------" << endl;
    cout << "---------------------------" << endl;


    /* 测试在 class 上 new 和 delete */
    Foo singleF;
    cout << "sizeof(Foo) = " << sizeof(singleF) << endl;
    Foo *f = new Foo[5];
    delete[] f;
    Foo *f2 = ::new Foo[5];
    ::delete[] f;
    // Foo *wf = new Foo(1);   // throw exception: terminate called after throwing an instance of 'int'
    cout << "---------------------------" << endl;
    cout << "---------------------------" << endl;
    
    
    /* placement new */
    int *pn = new(1) int; // new只传入一个参数
    delete pn;
    
    return 0;
}
```

## 七、 C++ 2.0

### 0x01. Revolution of C++

#### 1. C++ 的标准演化

```
C++98 (c++ 1.0)
C++03
C++11 (C++ 2.0)
C++14
```

#### 2. C++ 2.0之后更新的小主题

> 其实就是我不想太详细的做笔记了 T.T

1. **header:** 在引入 C头文件的时候不需要加 .c 后缀是在 C++11 引入的。

2. **space in template expression**:  类似于：`vector<vector<int>> v;` 最后的两个 `>` 之间不再需要空格。

   

3. **auto：**不要滥用 auto，编译器的类型推导在 C++ 11 之前就已经存在了，只不过在 C++11 之后才把这个功能提供给我们。

4. 全局函数 `begin()` 和 `end()`，取代 `obj.begin()` 为 `begin(obj)`。

### 0x02. Variadic Templates

7大例子

### 0x03. nullptr and std::nullptr_t

C++11 lets you use nullptr instead of 0 or NULL to specify that a pointer refers to no value(with differs from habing an undefined value). 

用法：`void *p = nullptr;`

nullptr 的一个好处是它显示的指明：我是一个空指针。

而在次之前，我们使用 NULL 来表示空指针，但其实 NULL 只不过是一个值为 0 的宏罢了，它也可以被解释成其他类型，例如整形，浮点型等。

但是 nullptr 只能被解释为指针，这在下图的例子中深有体现：

![IMG](https://s3.bmp.ovh/imgs/2022/10/26/4b9ea5742d3f1eea.png)

``` C++
#include <iostream>
using namespace std;

void f(int x)
{
    cout << "I am int" << endl;
}

void f(void *x)
{
    cout << "I am pointer" << endl;
}

int main()
{
    f(0);       // "I am int"
    // f(NULL); // ambigious
    f(nullptr); // "I am pointer"
    return 0;
}
```



### 0x04 Uniform Initializarion

一致性初始化。

在 C++11 之前，对象的初始化可能发生在：

1. 大括号 {} 之后
2. 小括号 () 之后
3. 赋值运算符之后

这让人很迷惑，到底什么时候用什么样的初始化方式呢？

基于这个原因，C++11 统一使用大括号 {} 来初始化。当然，之前的小括号和赋值也会向前兼容。

**原理：**编译器会把大括号 {} 内的所有参数**打包**到一个数据结构 `initializer_list<>` 中，形成一个**数据包**，并关联到一个 `array<T,n>` 容器中，`T` 是类型，`n` 是参数。当我们调用函数的时候（例如 ctor），`array` 内的所有元素会被编译器逐一分解给函数。但若函数参数是个 `initializer<_list>`，不会自动分解，也就是说，传给函数参数的仍然是数据包 `initializer_list<int>`，而不是单一的一个个 `<int>` 数据。（很合理）

![img](https://s3.bmp.ovh/imgs/2022/10/26/080a6ee4df06aa92.png)



### 0x05 Initializer lists

用于初始化，并且可以默认初始化，在 gcc 平台上还可以做隐式类型转换。(注意在投影片中不可以做隐式类型转换，这应该是编译器平台的问题，不必深究)

![img](https://s3.bmp.ovh/imgs/2022/10/26/b4766877737c31e2.png)



#### 1. Initializaer lists 的底层结构：

#### `initializer_list<>`

![IMG](https://s3.bmp.ovh/imgs/2022/10/26/a00c529e01d71682.png)



Initializer_list<> 和 Variadic Templates 的区别在于前者只能传入统一类型的参数，而后者可以传入不同类型的参数

例如：

``` C++
#include <iostream>

using namespace std;

void print(initializer_list<int> vals)
{
    for(auto p = vals.begin(); p != vals.end(); p ++ )
        cout << *p << endl;
}

int main()
{
    print({1,2,3,4,5});
    return 0;
}
#include <iostream>

using namespace std;

class p
{
    public:
        p(int a, int b)
        {
            cout << "P(int,int), a = " << a << ' ' << "b = " << b << endl;
        }
        p(initializer_list<int> list)
        {
            cout << "P(Initializer_list<int>), val = ";
            for(initializer_list<int>::iterator it = list.begin(); it != list.end(); it ++ )
                cout << *it << ' ';
            cout << endl;
        }
};

int main()
{
    p a(1,2);
    p b{1,2};
    p c{1,2,3};
    p d = {1,2};
    return 0;
}
/*
P(int,int), a = 1 b = 2
P(Initializer_list<int>), val = 1 2 
P(Initializer_list<int>), val = 1 2 3 
P(Initializer_list<int>), val = 1 2 
*/
```

下图中包含了 `initializer_list<int>` 的源码，编译器会调用它的私有的构造函数，将一个容器 `array` 的头和大小传给它（当然，在此之前，编译器已经构造好了一个 `array` 容器）。

> 编译器拥有无上权限，它可以调用你的私有对象！

![IMG](https://s3.bmp.ovh/imgs/2022/10/26/5fba537fae2977b6.png)



如上图，在 `class initializer_list<>` 源代码中，我们可以发现它内部并没有包含元素，所有的元素都在 `array` 中，而它只是包含一个指向 `array` 的指针。

所以说如果我们 copy `initializer_list<int>` ，实际上是一个浅拷贝。

`initializer_list<>` 被广泛应用于容器和算法当中，也就是说这些容器和算法都可以接受任意数量的参数。

#### 2. 关联的容器 array



`array` 就是数组的另一种表现性质，只不过它现在是一个容器，可以利用容器的很多接口，例如迭代器 begin(), end(), 和算法等。

在 array 容器中，如果你传入的长度是 0，它内部会变为 1，毕竟长度为 0 的容器不太合理。。 `len ? len : 1;`



如下图，红圈中的内容需要额外注意：

![img](https://s3.bmp.ovh/imgs/2022/10/26/0fd7a98ee82afd23.png)







### 0x06 explicit



>  构造函数的类型

**构造函数**分为无参构造函数，和有参构造函数。有参构造函数又分为单参数构造函数和多参数构造函数

**C++中存在隐式构造的现象：在某些情况下，会隐式调用单参数的构造函数**

总而言之，大概就是 `A a(10);` 就是显式调用构造函数。而 `A a = 10;` 就是显式的调用构造函数。

但是这种隐式调用有些不太好，因为我们的本意可能不是调用构造函数，所以我们有了 explicit 关键字



>  explicit

在C++中，`explicit`关键字用来修饰类的构造函数，被修饰的构造函数的类，不能发生相应的**隐式类型转换**，只能以显示的方式进行类型转换。因为无参构造函数和多参构造函数本身就是显示调用的。再加上`explicit`关键字也没有什么意义。

在 C++2.0 之前，是  **explicit for ctor one argument**，这个我们前面已经介绍过了，不再多做介绍。

在 C++2.0 之后，有了**explicit for ctors taking more than one argument**，我们发现多了一个 more than，这是因为 C++2.0 提供了一种新的语法：`initializer_list<>` ，这个我们前面也提到过了。所以说，现在我们不仅传入一个单参数会隐式调用  ctor，传入一个数据包也会调用  ctor。



> 参考

[implicit & explicit](https://blog.csdn.net/cpp_learner/article/details/117883912?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-117883912-blog-84141043.pc_relevant_recovery_v2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-117883912-blog-84141043.pc_relevant_recovery_v2&utm_relevant_index=2)

[隐式构造函数](https://blog.csdn.net/weixin_45452278/article/details/126019006)



> 举几个例子：

例1：下面的代码可以正确运行，但如果我们将 p 的构造函数用关键字 explicit 修饰的话，编译器就会报错。 

``` c++
#include <iostream>
using namespace std;

class p
{
    public:    
        p(int a, int b, int c) {
            cout << "P(int,int,int), a = " << a << ' ' << "b = " << b 
                << ", c = " << c << endl;
        }
};

int main()
{
    p a = {1,2,3}; // 隐式类型转换

    return 0;
}
```

例2；下面的代码可以正确运行，但如果我们将 C 的构造函数用关键字 explicit 修饰的话，编译器就会报错。 

``` C++
#include <iostream>
#include <vector>

using namespace std;

class C {
    public:
        C(string _s) : s(_s) {};
        string s;
};

ostream& operator<<(ostream &os, const C c) {
    return cout << c.s;
}

int main()
{
    vector<string> s = {
        "hello", "world", "cpp"
    };
    for(const C &ele : s)   // 隐式类型转换
        cout << ele << endl;
    return 0;
}
/*
hello
world
cpp
*/
```

但如果我们以如下方式进行 for 循环，那么程序依然可以正确执行，这是因为我们使用的不再是隐式类型转换，而是显式类型转换。

``` C++
for(auto &ele : s) {
        cout << C(ele) << endl; // 显式类型转换
    }
```



### 0x07 range-based for statement

**range-based for statement**：即 for 函数

有以下需要注意的点：

1. 和 auto结合使用效果极佳。
2. 关联式容器不可以用 auto 修改元素的值。
3. for 的实质就是迭代器遍历。如下图所示：

![IMG](https://s3.bmp.ovh/imgs/2022/10/26/8268f467b08cd0b7.png)





### 0x08 =default, =delete

一言以蔽之：=default 用来让编译器生成默认函数，=delete 用来删除编译器生成默认函数

c++ 右值引用

参考：

> [big fice](https://blog.csdn.net/tutuxs/article/details/54947395)
>
> [右值引用](http://c.biancheng.net/view/7829.html)
>
> [=default, =delete](https://www.cnblogs.com/Braveliu/p/12247471.html)



### 0x09 Alias Template



### 0x0a decltype



declareType

当我们用了：：的时候，加上 typename 让编译器直到我们要的是一个类型。



![img](file:///C:\Users\24072\AppData\Roaming\Tencent\Users\2407217576\QQ\WinTemp\RichOle\1[{%QORATSLSNBYEQMMPM[7.png)





``` C++
\
    #include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

template<typename T1, typename T2>
auto add(T1 x, T1 y) -> decltype(x + y)
{
    return x + y;
}

int main()
{
    vector<vector<int>> vec;
    decltype(vec)::value_type elem;
    for(int i = 0; i < 3; i ++ )   elem.push_back(10);
    
    map<int,int> mp;
    decltype(mp)::value_type pr = make_pair(2,2);
    cout << pr.first << ' ' << pr.second << endl;
    
    // decltype for  return type
    int a = 1;
    double b = 2.23;
    char c = 'A';
    auto s = a + b;
    cout << s << ' ' << sizeof(s) << endl; 
    auto s2 = a + c;
    cout << s2 << ' ' << sizeof(s2) << endl;
    string str1 = "hello", str2 = ",world!";
    auto s3 = str1 + str2;
    cout << s3 << ' ' << sizeof(s3) << endl;
    
    
    // used to pass the type of a lambda
    set<int, greater<int>> S;
    S.insert(343);
    S.insert(34);
    S.insert(44);
    for(auto &x : S)    cout << x << endl;    
    
    return 0;
}
```

[1](https://blog.csdn.net/hlsdbd1990/article/details/46439577)

[2](https://www.cnblogs.com/huty/p/8517000.html)



### 0x0b lambda

#### 1. 概念

c++ 11 引入 lambda，可以定义内联函数

可以用来作为参数或者函数对象

可以直接写在一个 statements 或者 expression 里面作为匿名函数

```
[]() mutable(opt)  throsSpec(opt) -> retType(opt) {} 
```

其中，有三个 `opt`（可选的），如果这三个都没选，`()` 就可以不加，但是只要有一个存在，就必须有 小括号 `()`

lambda 只能捕获在它之前出现的变量，在它后面出现的它“不认识”

对于 value 传递，它不会感受在它之后发生的变化。

对于 reference 传递，后续的变化会改变到。

是否感知后续的变化应该是 lambda 使能的，也就是说它会根据是否是 by reference 而主动的监听。

lambda 直接传给 set不行，因为 lambda 定义的是一个对象，而模板参数是个类型，因此需要借用 decltype

 lambda 像是一个重载了 () 的函数对象，但是它不同于函数对象。因为它不能定义构造函数。

#### 2. 测试程序1

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

void test1()
{
    // 无意义，定义了一个对象
    [] {
        cout << "hello,world!" << endl;
    }; 
    // 直接调用,但这种写法是脱裤子放屁--多此一举
    [] {
        cout << "hello,world!" << endl;
    }();
    // 把这个对象保存到 out，一般写法
    auto out = [x=1] {
        cout << "hello,world!" << endl;
        cout << x << endl;
    };
    out();
}

void test2()
{
    int id = 100;
    auto f = [id]() mutable {
        cout << id << endl;
        id ++ ;
    };
    id = 42;
    f();    f();    f(); // 1 2 3
    cout << id << endl; // 42
}

void test3()
{
    class Person {
    public:
        int val;
    };
    auto cmp = [&](const Person &x, const Person &y) {
        return x.val > y.val;
    };
    set<Person, decltype(cmp)> s(cmp);
    s.insert({1});
    s.insert({2});
    s.insert({3});
    for(auto &x : s) {
        cout << x.val << endl;
    }
}

void test4()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    auto pos = find_if(v.begin(), v.end(), [](int x){
        return x >= 9;
    }); // 这种形式不是 inline function
    cout << *pos << endl;
}

int main()
{
    test4();
    
    return 0;
}
```



#### 3. 测试程序2

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

template<typename T>
class G
{
    public:
        G() {
            cout << "you get here!" << endl;
        }
        bool operator()(const T &a, const T &b) const { // 不加 const 报错
            return a > b;
        }
};

int main()
{
    auto cmp = [](int a, int b) -> bool {
        return a > b;
    };
    set<int, decltype(cmp)> S1(cmp);  // 不加(cmp)报错
    S1.insert(22);
    S1.insert(11);
    S1.insert(33);
    for(auto &x : S1) cout << x << endl;
    
    cout << "---------------------" << endl;
    
    set<int, G<int>> S;  // ther call default ctor
    S.insert(22);
    S.insert(11);
    S.insert(33);
    for(auto &x : S) cout << x << endl;
    
    return 0;
}
```



## <TODO:下面为新添加项>

## 语法

### 1. type alias

using

1. Using-directives for namespace and using-declaration for namespace members

```
using namespace std;
using std::count;
```

2. using-declaration for class member

```c++
class C {
protected:
    using std::cout;
    using std::cin;
};
```

3. using alias and alias template declaration (since c++ 11)

``` c++
using func = void(*)(int,int);

template<typename T>
struct Container {
    using value_type T;
}

template<class CharT> using mystring = std::basic_string<CharT, std::char_traits<CharT>>
```



### 2. noexcept

exception：异常

``` c++
void func() noexcept(bool condition) {
}
// if bool condition, will not throw exception

```

terminate() default call abort()



### 4. override

Override for virtual

避免你重写 virtual 的时候写错类型之类导致你写了一个新的函数 ^^。

如果你的函数原型与继承来的函数原型不一致，报错。



### 5.final

1. 用来修饰 class 表示该 class 是继承体系的最底层，也即该 class 不可被继承。

``` c++
struct EndClass final {  
};
```

2. 用来修饰虚函数表示该函数不可以被下层的继承对象 override

``` c++
class A{
    virtual void f() final;
}
class B : public A {
    void f();
    // [Error] overriding final function `virtual void A::f()`
};
```



### 6. lambda



### 7. variadic template

谈的是 template

1. function template
2. class template

变化的是 template parameters

1. 参数个数（variable number）– 利用**参数个数逐一递减**的特性，实现递归函数调用，使用 function template 完成
2. 参数类型（different type） – 利用**参数个数逐一递减** 导致 **参数类型也逐一递减** 实现递归继承或者递归复合，以 class template 实现。

关于（省略号） `...` 的位置，怎么记忆呢？。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void print() {} // must have

template<typename T, typename... Types> // left
void print(const T& firstArg, const Types&... args) // left
{
    cout << firstArg << ' ' << sizeof...(args);
    print(args...); // left
}
    
int main()
{
    func(1,2,3,4); // 1 2 3 4
    return 0;
}
```



----

#### Case1

simple test

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void print() {} // must have
template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
    cout << firstArg << ' ';
    print(args...);
}
template<typename... Types>
void print(const Types&... args) { // 可以和上面的共存
                    // 函数的泛化程度更高，因此永远不会被调用
    cout << sizeof...(args);
    cout << "you call here!" << endl;
}
void test1() { 
    print(1,123456789001,'A',4.4,"hello"); // 1 123456789001 A 4.4 hello 
}

int main()
{
    test1();
    return 0;
}
```

#### case2

Simulator print

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void print(const char *s) 
{
    // cout << "str: " << s << endl;
    while(*s) {
        if(*s == '%' && *(++s) != '%') 
        {
            throw runtime_error("invalid format string: missing argument!\n");
        }
        cout << *s++ ;
    }
}

template<typename T, typename... Args>
void print(const char *s, T value, const Args&... args) 
{
    while(*s) 
    {
        if(*s == '%' && *(++s) != '%') 
        {
            cout << value;
            print( ++ s, args...);
            return ;
        }
        cout << *s ++ ;
    }
    throw logic_error("you cant go here!");
}

int main()
{
    print("[%d %s %s %d]", 1024, "hello", "hello", 1024);
    return 0;
}
```





#### case3

simulator max()

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/*  参数类型一样的话，不需要使用 variadic
**  使用 initializer_list<> gingham */

int my_max(initializer_list<int> ls) {
    return *max_element(ls.begin(), ls.end());
}


int t_max(int n) {
    return n;
}
template<typename... Args>
int t_max(int n, const Args&... args) {
    return max(n, t_max(args...));
}

int main()
{
    vector<int> a{1,3,5,2,4,6,100,-2};
    
    // case1
    int x = *max_element(a.begin(), a.end());
    cout << x << endl;
    
    // case2
    cout << my_max({1,3,5,2,4,6,100,-2});
    
    
    // case3
    cout << t_max(1,3,5,2,4,6,100,-2); // 不能加 {}
    
    return 0;
}
```



#### case4

simulator print have format

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <tuple>

using namespace std;


template<int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
    static void print(ostream &os, const tuple<Args...> &t) {
        os << get<IDX>(t) << (IDX+1==MAX ? "" : ","); // get<idx> 是 tuple 的函数
        PRINT_TUPLE<IDX+1, MAX, Args...>::print(os, t);
    }
};


/* 把这段代码放在上一个struct的前面就不对，为啥呢？ */
template<int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
    static void print(ostream &os, const tuple<Args...> &t) {
        // 递归终点，什么都不做
    }
};



template<typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...> &t) {
    os << "[";
    PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os,t);
    os<< "]";
}

int main()
{
    cout << make_tuple(1,2,3,4) << endl; // tuple 就是任意个元素可以组合成一 包
    
    return 0;
}
```





Struct 不能用于模板参数指的是：

``` c++
template<struct T> // Error!
//而不是
template<typename T>
struct s{
};
```



#### case5

递归调用处理的都是参数，使用 function template。

递归继承处理的都是类型，使用 class template。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename... Values> class my_tuple;

template<> class my_tuple<> {};

template<typename Head, typename... Tail> 
class my_tuple<Head, Tail...>  : private my_tuple<Tail...> 
{
    typedef my_tuple<Tail...> inherit;
public:
    my_tuple() {}
    my_tuple(Head v, Tail... vtail) 
        :m_head(v), inherit(vtail...) {} // 只有继承才能使用 inherit()
    
    Head head() { return m_head; }
    inherit& tail() { return *this; };
protected:
    Head m_head;
};

/* */
template<typename... Args> struct Sum;
template<typename First, typename... Rest>
struct Sum<First, Rest...> {};
template<typename Last>
struct Sum<Last> {};
/* */

int main()
{
    my_tuple<int, double, char, string, long long> mt(
            1024, 3.14, 'A', "Hello", 101010101010);
    
    cout << mt.head() << endl;
    cout << mt.tail().head() << endl;
    cout << mt.tail().tail().head() << endl;
    cout << mt.tail().tail().tail().head() << endl;
    cout << mt.tail().tail().tail().tail().head() << endl;
                        
    return 0;
}
```



### 8. decltype

通过使用新关键字 decltype，你可以让编译器找到一个**表达式**的类型。

application of decltype:

1. declare return types
2. use it in metaprogramming(元编程)
3. Pass the type of lambda



``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

/* use case 1
    下面的写法是错的，因为在 decltype(x+y) 的时候
    我们并不知道 a 和 b 是什么（还未出现）  
template<typename T1, typename T2>
decltype(x + y) wrong_add(T1 x, T2 y) {
    return x + y;
}
*/

// 可以借助 lambda 表达式 
template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x + y) {
    return x + y;
}

void test1() {
    int a = 10;
    double b = 3.14;
    long long c = 101918171615;
    char d = 'A';
    cout << add(a, b) << endl;
    cout << a + b << endl;
    cout << b + c << endl;
    cout << a + d << endl;
}

/* use case 2 */
void test2() {
    map<string, int> coll;
    // ......
    decltype(coll)::value_type elem = {"hello", 1};
    cout << elem.first << ' ' << elem.second << endl;
    typedef typename decltype(coll)::iterator iType;
}

/* uese case 3
*/
auto cmp = [](const int a, const int b) {
    return a > b;
};

class my_cmp1 {
public:
    bool operator()(const int a, const int b) const { 
        return a > b;
    }
};

void test3() {
    // 你不仅需要把类型放到 <>
    // 还需要把对象放到 ()
    // set 接口就是这样设计的
    set<int, decltype(cmp)> coll(cmp); // 必须加上 (cmp)
    coll.insert(1);
    coll.insert(8);
    coll.insert(23);
    for(auto &x : coll) {
        cout << x << ' '; 
    }
    cout << endl;
    set<int, my_cmp1> my_set;
    my_set.insert(1);
    my_set.insert(8);
    my_set.insert(23);
    for(auto &x : my_set) {
        cout << x << ' '; 
    }
    cout << endl;
}


int main()
{
    test3();
    return 0;
}
```



## 承上启下 – Rvalue reference

上语法，下标准库

右值引用

左值：可以出现在 = 左侧

右值：只能出现在 = 右侧，没有名称，临时对象是右值

临时对象的拷贝也很占用时间，特别是在像 vector 这种会执行大规模数据迁移的容器。

因此我们要避免 “非必要的拷贝”。

Rvalue references are a new **reference typr** introduced in c++0x that help solve problem of **uncessary coping** and enable **perfect forwarding**

when the right-hand side of an assignment is an **rvalue**, then the left-hand side object can **steal** resources from the right-hand side object rather than performing a separate allocation, thus enabling **move semantics**

函数的地址就是函数起点。

所谓 偷，move 像浅拷贝，它与浅拷贝的区别是，move 之后，原本的指向就指向 null，这样就不会出现悬空指针的情况。

move semantics

通过 move() 可以将一个左值转换为右值。（你要确保这个左值之后不会再被使用，因为 move 之后会调用右值引用，导致原本的数据“没了”）。

![img](https://s3.bmp.ovh/imgs/2022/11/09/32208de44cadebed.png)



Arbitrary argument: 任意参数



### Perfect forward

![img](https://s3.bmp.ovh/imgs/2022/11/09/14f68f254b2d91a6.png)

``` C++
#include <bits/stdc++.h>
using namespace std;

void func(int &a) {
    cout << &a << " & " << a << endl;
}

void func(int &&a) {
    cout << &a << " && " << a << endl;
    a = 10;
}

void gofunc(int &&a) {
    cout << "gofunc: " << a << endl;
    func(a);
}

int main()
{
    // int a = 3;
    // cout << &a << endl;
    // func(a);
    // func(move(a));
    // func(10);
    // cout << &a << endl;
    // cout << a << endl;
    gofunc(2);  // unperfect forward
    return 0;
}
```



Move or normal

``` c++
#include <bits/stdc++.h>
using namespace std;

class String {
    char *_data;
    size_t _len;
    void init_data(const char *s) {
        _data = (char *)malloc(strlen(s) + 1);
        strcpy(_data, s);
        _data[_len] = '\0';
    }
public:
    int idx = 0;
    String(const char *s) {
        _len = strlen(s);
        init_data(s);
    }
    String(const String &s) {
        _len = s._len;
        init_data(s._data);
    }
    String(String &&s) {
        _len = s._len;
        _data = s._data;
        s._data = nullptr;  // important
        s._len = 0;
    }
    String() : _data(nullptr), _len(0) {}
    void print() {
        cout << _data << ' ' << _len << endl;
    }
    ~String() {
        if(_data != nullptr) {
            cout << "~String(): " << idx << endl;
            delete _data;
        }
    }
    void Copy(const String &s) {
        if(this == &s) {
            return ;
        }
        if(_data) {
            delete _data;
        }
        _len = strlen(s._data);
        init_data(s._data);
    }
    void Copy(String &&s) {
        if(this == &s) {
            return ;
        }
        if(_data) {
            delete _data;
        }
        _data = s._data;
        _len = s._len;
        s._data = nullptr;  // important !!!
        s._len = 0;
    }
};

int main()
{
    String s1("hello");     s1.idx = 1;
    String s2(s1);          s2.idx = 2;
    String s3(move(s1));    s3.idx = 3;    // delete s1
    String s4;              s4.idx = 4;
    s4.Copy(move(s2));                     // delete s2
    return 0;
}
```





Move  对性能的影响：

1. 将一个容器的 元素 一个一个拷贝到另一个容器

对于元素以节点形式存在的容器：哈希表，红黑树，链表。move 几乎没有什么影响

但是对于 vector，move 的影响很大，甚至可以优化一倍。

对于 deque，如果始终在一头插入，那么性能上也没有什么影响。但是如果在中间插入元素，影响是巨大的，因为需要移动元素。

2. 将一个 容器 直接拷贝给 另一个容器

move 对性能的提升巨大！想想 vector。move 只需要 偷 三个指针，而普通 copy 需要先分配空间，然后一个一个将所有元素从另一个容器拷贝到该容器。



只要当作右值，就是他的 resources 被 偷了

## 标准库

### 1. array

1. no tors

2. Contain a array

``` C++
typedef int T[100];
T c;    // T <==> int [100]
```



### 2. hashtable

Separate Chaining

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

void test1() {
    // C ++ 自带的哈希函数
    cout << hash<char>()('A') << endl;
    cout << hash<short>()(123) << endl;
    cout << hash<int>()(123) << endl;
    cout << hash<long>()(123L) << endl;
    cout << hash<string>()(string("ABC")) << endl;
    cout << hash<const char *>()("ABC") << endl;
    cout << hash<float>()(3.14) << endl;
    cout << hash<double>()(3.14) << endl;
    void *p = (void *)(new int(100));
    cout << hash<void *>()(p) << endl;
}

int main() 
{
    test1();
    return 0;    
}
```



### 3. tuple

Metaprograming: 对类型做操作，我们一般都是对变量做操作

# old C++ 

## 0x00 what old C++

> 《effective c++》
>
> 《more effective c++》
>
> 《effective stll》

## 0x01 whta’s UB ?

> 不确定性为指的是：
>
> 对我可以正常工作，对你可以正常工作，在开发和QA中可以正常工作，但在最重要的客户面前，却失败了。

## 0x02 为什么流对象无法copy

因为流对象中含有指向IO缓冲区的**指针**，假如流对象可以复制，那么将会有两个指针同时操作缓冲区，如何释放、如何修改都会有冲突同步问题，因此流对象无法复制。

没有意义啊所以接口需要**Make it easy to use right and hard to use wrong.**

> 我觉得根本原因在于，流是系统资源，并且它本身并没有实现拷贝操作。并且，read流也会改变流的状态，而流只有一个。
>
> 即使我们深拷贝了读取流的指针，那么我们如何确保同时使用两个指针操纵流的正确性呢？
>
> 当用一个指针操纵流时，流的状态就会改变，此时再用另一个指针操纵流，此时流的状态就不对了。
>
> 并且，因为流只有一个，还会存在互斥问题等。



## [0x03 初始化器](https://www.cnblogs.com/james-wangx/p/14917406.html)



## 0x04 智能指针

>  [ref1](https://blog.wangzhl.com/posts/self-defined-deleter-in-cpp-smart-pointer/)
>
>  [ref2](https://www.jianshu.com/p/03eea8262c11)



## 0x05 CLASS allocator

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

class Foo {
public:
    int d1, d2;
    Foo(int _d1, int _d2) : d1(_d1), d2(_d2) {
        
    }
    ~Foo() {
        cout << "data:" << d1 << ' ' << d2 << endl;
    }
};

int main()
{
    allocator<Foo> Alloc;
    Foo *p = Alloc.allocate(10);
    for(int i = 0; i < 10; i ++ ) {
        Alloc.construct(p + i, i, i * i);
    }
    for(int i = 0; i < 10; i ++ ) {
        cout << p[i].d1 << ' ' << p[i].d2 << endl;
    }
    for(int i = 0; i < 10; i ++ ) {
        Alloc.destroy(p + i);
    }
    Alloc.deallocate(p, 10);
    return 0;
}
```



## 0x06 why operator = return reference

我觉得主要是应对这种情况：

`(a = b) = c = 10;`

执行之后，b不变，a=10，c=10

如果不是返回引用，那么(a=b)会返回一个临时对象，让一个临时对象等于c不太合理！



## 0x07 为什么不能用浮点数和字符串作为非类型模板参数

注：

1. **浮点数**、**类对象**以及**字符串**是不允许作为非类型模板参数的。
2. 非类型的模板参数必须在**编译期**就能确认结果。

匹配模板特化时，编译器会匹配模板参数，包括非类型参数。

就其本质而言，浮点值并不精确，并且C ++标准未指定它们的实现。因此，很难确定两个浮点非类型参数何时真正匹配：

```
template <float f> 
void foo() {}
void bar () 
{
    foo< (1.0/3.0) > ();
    foo< (7.0/21.0) > ();
}
```

这些表达式不一定产生相同的**“位模式”**，因此不可能保证它们使用相同的特化 - 没有特殊的措辞来涵盖这一点。

[Stack Overflow的讨论](https://cloud.tencent.com/developer/ask/sof/101321)



## 0x08 emplace

[ref](http://blog.guorongfei.com/2016/03/16/cppx-stdlib-empalce/)



## 0x09 forward_list

[ref](http://t.zoukankan.com/lgxZJ-p-6339694.html)

forward_lis没有insetr函数，但是有insert_before

forward_list 是极其注重效率的，因此他没有size函数，因为想要高效的维护size，就需要舍弃空间来保存size的大小。

forward_list之所以是头插法，是因为我们维护了指向头节点的指针，因为只有这样才能实现正向（单向）遍历，如果是尾插法的话，要么每次插入都O(N)的循环找到最后一个节点，要么保存指向尾节点的指针。这两种方法在时间和空间上都不能两全。



## 0x0a 模板

关于模板参数的限制：

1. 当模板参数为非类型参数时，传递的实参必须时一个常量表达式。
2. 如果是指针或者引用的话，其实参必须具有静态的生存期。
3. 不可以是浮点数，字符串或者类对象。浮点数有歧义，类对象不一定能在编译期确定结果（动态类型推导），字符串？？。

## 0x0b 为什么const引用可以绑定右值

是让传引用和传值成为函数本身的细节，调用者本身不用去关心。因为加上了const之后，无论是传值还是引用都不会影响结果，因为const就不能进行修改了。

[参考](https://www.zhihu.com/question/40238995)



## 0x0c shared_ptr实现

[complement](https://www.jb51.net/article/262284.htm)

[complement2](https://cloud.tencent.com/developer/article/1688444)

> 用指针作为计数器的版本

``` c++
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Shared_ptr {
public:
    // template<typename U>    
    // friend void swap(Shared_ptr<U> &lhs, Shared_ptr<U> &rhs);
    
    // 不可以将上面的友元写为下面的形式：
    friend void swap(Shared_ptr<T> &lhs, Shared_ptr<T> &rhs)
    {
        std::swap(lhs.ptr, rhs.ptr);
        std::swap(lhs.use, rhs.use);
        cout << "swap66666" << endl;
    }
    
    
    Shared_ptr(T _val = T()) : ptr(new T(_val)), use(new size_t(1)) {}
    
    Shared_ptr(const Shared_ptr &rhs);
    Shared_ptr& operator=(const Shared_ptr &rhs);
    ~Shared_ptr();
    
    size_t use_count() const {
        return *use;
    }
    
    T& operator*() const {
        return *ptr;
    }
    
    T* operator->() const {
        return &operator*();
    }
    
    
private:
    T *ptr;
    size_t *use;
    
    void doFree();
};

// template<typename T>
// void swap(Shared_ptr<T> &lhs, Shared_ptr<T> &rhs)
// {
//     std::swap(lhs.ptr, rhs.ptr);
//     std::swap(lhs.use, rhs.use);
// }

template<typename T>
inline void Shared_ptr<T>::doFree() {
    delete ptr;
    delete use;
}

template<typename T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr &rhs)
: ptr(rhs.ptr), use(rhs.use)
{
      ++ *use;
}

template<typename T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr &rhs)
{
    // maybe self assignment
    ++ *rhs.use;
    if( -- *use == 0) {
        doFree();
    }
    ptr = rhs.ptr;
    use = rhs.use;
    return *this;
}

template<typename T>
Shared_ptr<T>::~Shared_ptr()
{
    if( -- *use == 0) {
        cout << "free:" << *ptr << endl;
        doFree();
    }
}

int main()
{
    Shared_ptr<int> s(1024);
    cout << s.use_count() << endl;
    Shared_ptr<int> p = s;
    cout << p.use_count() << endl;
    cout << s.use_count() << endl;
    Shared_ptr<int> a1(666);
    Shared_ptr<int> a2 = a1;
    Shared_ptr<int> a3 = a1;
    // -- 
    cout << a1.use_count() << ' ' << a2.use_count() << ' ' << a3.use_count() << endl;
    cout << *p << endl;
    cout << *a1 << endl;
    swap(a1, p);
    cout << a1.use_count() << ' ' << a2.use_count() << ' ' << a3.use_count() << endl;
    cout << p.use_count() << endl;
    cout << *p << endl;
    cout << *a1 << endl;
    return 0;
}
```

## 0x0d 友元作为模板类函数的bug

这个bug发生在上面的 shared_ptr 实现中。

看下面的程序：

``` c++
#include <iostream>

template<typename T>
class Foo {
public:
  Foo(const T& value = T());
  friend Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs);
  friend std::ostream& operator<< (std::ostream& o, const Foo<T>& x);
private:
  T value_;
};

template<typename T>
Foo<T>::Foo(const T& value)
  : value_(value)
{ }

template<typename T>
Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs)
{ 
    return Foo<T>(lhs.value_ + rhs.value_); 
}

template<typename T>
std::ostream& operator<< (std::ostream& o, const Foo<T>& x)
{ 
    return o << x.value_; 
}


int main()
{
  Foo<int> lhs(1);
  Foo<int> rhs(2);
  Foo<int> result = lhs + rhs;
  std::cout << result;
  // ...
}
```

我们试图调用 class Foo 里面的两个友元函数，可是编译报错：

``` c++
a.cpp:7:64: warning: friend declaration 'Foo<T> operator+(const Foo<T>&, const Foo<T>&)' declares a non-template function [-Wnon-template-friend]
    7 |   friend Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs);
      |                                                                ^
a.cpp:7:64: note: (if this is not what you intended, make sure the function template has already been declared and add <> after the function name here)
a.cpp:8:68: warning: friend declaration 'std::ostream& operator<<(std::ostream&, const Foo<T>&)' declares a non-template function [-Wnon-template-friend]
    8 |   friend std::ostream& operator<< (std::ostream& o, const Foo<T>& x);
      |                                                                    ^
/tmp/ccUODpQ0.o: In function `main':
a.cpp:(.text+0x4b): undefined reference to `operator+(Foo<int> const&, Foo<int> const&)'
a.cpp:(.text+0x5f): undefined reference to `operator<<(std::ostream&, Foo<int> const&)'
collect2: error: ld returned 1 exit status
```

大致就是说，我们定义的两个友元函数并不是“模板函数”，起码编译器看不出来这是个模板函数，并且产生“未定义错误”，因为我们对两个友元函数的定义是模板函数，对非模板函数并无定义，而在class 内部却是声明的非模板函数，所以说连接器找不到我们对友元的定义。

解决方法如下：

1. 在报错中，就给我们提供了一种解决方法，就是在 class 定义之前声明这两个模板函数，并且在class内部的声明中，在友元函数名之后加上 `<>`。

``` c++
#include <iostream>

/* 前置声明 */
template<typename T> 
class Foo;  // 模板累
template<typename T> 
Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs); // 模板函数
template<typename T> 
std::ostream& operator<< (std::ostream& o, const Foo<T>& x); // 模板函数
/* 前置声明 */

template<typename T>
class Foo {
public:
  Foo(const T& value = T());
  // 在函数名之后加上 <>
  friend Foo<T> operator+ <>(const Foo<T>& lhs, const Foo<T>& rhs);
  friend std::ostream& operator<< <>(std::ostream& o, const Foo<T>& x);
private:
  T value_;
};

// 定义不变
template<typename T>
Foo<T>::Foo(const T& value)
  : value_(value)
{ }

template<typename T>
Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs)
{ 
    return Foo<T>(lhs.value_ + rhs.value_); 
}

template<typename T>
std::ostream& operator<< (std::ostream& o, const Foo<T>& x)
{ 
    return o << x.value_; 
}

int main()
{
  Foo<int> lhs(1);
  Foo<int> rhs(2);
  Foo<int> result = lhs + rhs;
  std::cout << result;
  // ...
}
```

2. 直接在class内部声明friend函数时加上模板函数声明。(代码短，更推荐)

``` c++
#include <iostream>

template<typename T>
class Foo {
public:
  Foo(const T& value = T());
  // 直接在class内部声明为模板函数
  template<typename U>
  friend Foo<U> operator+ (const Foo<U>& lhs, const Foo<U>& rhs);
  template<typename U>
  friend std::ostream& operator<< (std::ostream& o, const Foo<U>& x);
private:
  T value_;
};

// 定义不变
template<typename T>
Foo<T>::Foo(const T& value)
  : value_(value)
{ }

template<typename T>
Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs)
{ 
    return Foo<T>(lhs.value_ + rhs.value_); 
}

template<typename T>
std::ostream& operator<< (std::ostream& o, const Foo<T>& x)
{ 
    return o << x.value_; 
}


int main()
{
  Foo<int> lhs(1);
  Foo<int> rhs(2);
  Foo<int> result = lhs + rhs;
  std::cout << result;
  // ...
}
```

3. 直接在class内部定义，这样就不会出现找不到定义，因为归根结底是链接错误。

``` c++
#include <iostream>

template<typename T>
class Foo {
public:
    Foo(const T& value = T());
    friend Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs)
    { 
        return Foo<T>(lhs.value_ + rhs.value_); 
    }
    friend std::ostream& operator<< (std::ostream& o, const Foo<T>& x)
    { 
        return o << x.value_; 
    }
private:
  T value_;
};

template<typename T>
Foo<T>::Foo(const T& value)
  : value_(value)
{ }
template<typename T>
Foo<T> operator+ (const Foo<T>& lhs, const Foo<T>& rhs);
template<typename T>
std::ostream& operator<< (std::ostream& o, const Foo<T>& x);

int main()
{
  Foo<int> lhs(1);
  Foo<int> rhs(2);
  Foo<int> result = lhs + rhs;
  std::cout << result;
  // ...
}
```

[上述内容参考自这里 ](https://isocpp.org/wiki/faq/templates#template-friends)

[讨论](https://stackoverflow.com/questions/4039817/friend-declaration-declares-a-non-template-function#comment4336280_4039892)

## 0x0e ctor 中的参数默认值

当ctor的声明和定义分别在class内外时。

1、应该在声明构造函数时指定默认值，而不能只在定义构造函数时指定默认值。

2、 不可以既在声明处指定默认值，又在定义处指定默认值。（避免你定义前后不一致）

总而言之，就是如果要指定默认值的话，只能在声明处指定。



## 0x10 模拟 vector

``` c++

```



## 0x11 switch

switch的参数不能为**实型**，



## 0x12 upcast & downcast

1、隐式转型（向上转型，即将派生类对象赋值给基类）
C++允许向上转型，即将派生类的对象赋值给基类的对象是可以的，其只不过是将派生类中基类的部分直接赋给基类的对象，这称为向上转型（此处的“上”指的是基类），例如：

``` c++
class Base{ };
class Derived : public base{ };
Base* Bptr;
Derived* Dptr;
Bptr = Dptr; //编译正确，允许隐式向上类型转换
Dptr = Bptr；//编译错误，C++不允许隐式的向下转型；
```

~~但是编译正确不代表能够使得程序安全运行。这很好理解，如果你把一个指向Base类对象的指针 赋值 给一个Drived类类型的指针，如果这个指针去访问Drived类中存在而Base类中不存在成员，很明显就不安全了。
所以一个更好的办法是使用dynamic_cast;~~

2、向下转型
正如上面所述，类层次间的向下转型是不能通过隐式转换完成的。此时要向达到这种转换，可以借助static_cast 或者dynamic_cast。

2.1 通过static_cast完成向下转型
例如：

``` c++
class Base{ };
class Derived : public base{ };
Base* B;
Derived* D;
D = static_cast<Drived*>(B); //正确，通过使用static_cast向下转型
```

需要注意的是：static_cast的使用，当且仅当类型之间可隐式转化时，static_cast的转化才是合法的。有一个例外，那就是类层次间的向下转型，static_cast可以完成类层次间的向下转型，当时向下转型无法通过隐式转换完成！

2.2 通过dynamic_cast完成向下转型
和static_cast不同，dynamic_cast涉及运行时的类型检查。如果向下转型是安全的（也就是说，如果基类指针或者引用确实指向一个派生类的对象），这个运算符会传回转型过的指针。如果downcast不安全（即基类指针或者引用没有指向一个派生类的对象），这个运算符会传回空指针。
**ps：要使用dynamic_cast类中必须定义虚函数**

``` c++
class Base{
public：
	virtual void fun(){} 
 };
class Drived : public base{
public:
	int i;
 };
Base *Bptr = new Drived()；//语句0
Derived *Dptr1 = static_cast<Derived *>(Bptr); //语句1；
Derived *Dptr2 = dynamic_cast<Derived *>(Bptr); //语句2；
```

此时语句1和语句2都是安全的，因为此时Bptr确实是指向的派生类，虽然其类型被声明为Base*，但是其实际指向的内容确确实实是Drived对象，所以语句1和2都是安全的，Dptr1和Dptr2可以尽情访问Drived类中的成员，绝对不会出问题。
但是此时如果将语句0改为这样：

`Base *Bptr = new Base()；`

那语句1就不安全了，例如访问Drived类的成员变量i的值时，将得到一个垃圾值。（延后了错误的发现）
语句2使得Dptr2得到的是一个空指针，对空指针进行操作，将发生异常，从而能够尽早的发现错误，这也是为什么说dynamic_cast更安全的原因。

2.3多继承时的向下转型

``` C++
class Base1{
	virtual void f1(){}
}；
class Base2{
	virtual void f2(){}
};
class Derived: public Base1, public Base2{
	void f1(){}
	void f2(){}
};
Base1 *pD = new Derived;
Derived *pD1  = dynamic_cast<Derived*>(pD);  //正确，原因和前面类似
Derived *pD2  = static_cast<Derived*>(pD);  //正确，原因和前面类似
Base2 *pB1  = dynamic_cast<Base2*>(pD);    //语句1
Base2 *pB2  = static_cast<Base2*>(pD);    //语句2
```

此时的语句1,将pD的类型转化为Base2*，即：使得pB1指向Drived对象的Base2子对象，为什么能达到这种转化？因为dynamic_cast是运行时才决定真正的类型，在运行时发现虽然此时pD的类型是Base1*，但是实际指向的是Derived类型的对象，那么就可以通过调整指针，来达到pB1指向Derived 对象的Base2子对象的目的；

但是语句2就不行了，其使用的是static_cast，它不涉及运行时的类型检查，对于它来讲，pD的类型是Base1*，Base1和Base2没有任何关系，那就会出现编译错误了。error: invalid static_cast from type ‘Base1*’ to type ‘Base2*’

总结：对于多种继承，如果pD真的是指向Derived，使用static_cast和dynamic_cast都可以转化为Derived，但是如果要转化为Base1的兄弟类Base2，必须使用dynamic_cast，使用static_cast不能通过编译。

ps：因为Derived和Base1和Base2*之间存在隐式转化，可以将语句2修改为：

`Base2 *pB2 = static_cast<Base2*>(static_cast<Derived*>(pD));`

这样就可以完成转换。

> [Reference](https://blog.csdn.net/baidu_35679960/article/details/80821222)

>总结来说，static_cast 对于 upcast 和 downcast 都能胜任，特别是 upcast。但是对于 downcast来说，可能无法转换，就是说转换未必能够成功，当转换不成功时，static_cast 不会给你提供一些额外信息（置为空指针 or 异常）。
>
>dynamic_cast 就是专门用来 downcast 的，当转换不成功时，他会为你提供额外信息（指针：置为空；引用：异常）。需要注意的就是 dynamic_cast  的对象必须要有需函数。
>
>对于 downcast 和 upcast，转换的对象必须是 pointer 或者 reference，因为只有这两个东西才能 “动态类型转换”。



## 0x13 cin和cout如何判断数据类型

cout的本质是对象，而操作符实际是cout对象的一个成员函数，即cout实际是cout.operator  <<  (类型)
利用C++函数的可重载性，cout可以即可实现各种输入数据的自动匹配。如：cout.operator << (int )，cout.operator  << (double)等等，实际也是如此 。

## 0x14 Virtual Base Class

[stackover flow](https://stackoverflow.com/questions/21558/in-c-what-is-a-virtual-base-class)

[LearnCPP](https://learncppcn.github.io/18-virtual-functions/18.7-virtual-base-classes/)

[内存模型分析](https://blog.nowcoder.net/n/9aef77c96f3b4e8dbdb6094070d69052)

虚基类会产生虚基类表和虚指针。

## 0x15 实参相关的查找与类类型参数

当我们给函数传递一个**类类型**的对象时，除了在常规的作用域查找外还会查找**实参类所属的命名空间**。

查找规则的这个例外允许概念上作为类接口一部分的**非成员函数**无需单独的using声明就能被程序使用。

例如：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

namespace xjy {
    struct Foo {
        int val;
        Foo(int _val = 0) : val(_val) {}
        friend std::ostream& operator<<(std::ostream &os, Foo &f) {
            return os << f.val;
        }
        void g() {
            std::cout << "Baseval: " << val << std::endl;
        }
    };
    std::ostream& operator<<(std::ostream &os, Foo &f);
    void out(Foo &f) {
        std::cout << "val: " << f.val << std::endl;
    }
}

int main()
{
    xjy::Foo f(1024);
    out(f);
    f.g();
    std::cout << f << std::endl;
    return 0;
}
```

## 0x16 继承方式

C++ 中有三种继承方式（不包括虚继承）：

1. public
2. private
3. protected

只需要注意一点：继承方式改变的是父类中的成员在派生类中的访问属性。这只会影响到该派生类的派生类和使用改派生类的用户。

不要认为说，D private 继承 B，D 就不能使用 B 中的 public 和 protected 成员了。无论何种继承方式，派生类都能访问父类中的 public 和 protected 成员。它影响的是使用它的用户，而不是他自己本身。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class B {
public:
    int a = 1;
    void f1() {
        cout << "public" << endl;
    }
protected:
    int b = 2;
    void f2() {
        cout << "protected" << endl;
    }
private:
    int c = 3;
    void f3() {
        cout << "private" << endl;
    }
};

class D : private B {
public:
    void f() {
        cout << a << ' ' << b << endl;
        f1();
        f2();
    }
};

class E : public D {
public: 
    void g() {
        cout << a << ' ' << b << endl;
    } // 编译错误，a和b不可见
};	

int main()
{
    D d;
    d.f();
    return 0;
}
```

## 0x17 typename

1. 作为 `template<typenmae t>`

2. 类型声明符

着重介绍一下 typename 作为类型说明符的情况。

何时需要用到 typename 作为类型说明符呢？

当**[在模板中]**使用内嵌类型时。例如：

``` c++
template<typename C>
void f()
{
    // typename C::value_type *x = new typename C::value_type();    // 正确写法
    C::value_type *x = new C::value_type(); // 错误写法
    delete x;
}
```

上面的代码会编译错误，因为 `x` 未声明！

奇了怪了，我们明明是要定义一个指针`x`，却告诉我们`x`没有声明？搞笑呢。

别急，之所以是这样是因为编译器无法区分**从属名称**，即`C::value_type *x = new C::value_type();`中的`value_type` 是一个类型还是变量。

因为`*`可以是表示乘号或者指针。而无论哪种解释都可以解释为正确的！例如：

`static int value_type = 1024;`，（虽然这么写有点脑残，但是他是合法的！）

而C++在出现这种情况的时候默认认为`::` 后面跟的对象是一个变量。所以说这里`x和value_type`被认为是变量，所以说出现了`x`未声明的错误。

针对从属名称，我们要使用typename标明！但是有两个意外：

1. base class list。
2. member initialization list 中作为base class 的修饰符。

``` c++
struct B {
    typedef struct B_son {
    }Son;
};

struct D :  typename B::Son  { 	// Wrong 1
    D() : typename B::Son() {}  // wrong 2
};
```



> 从属名称
>
> template 中出现的某个名称依赖于某个 template 参数，就称这个名称为“从属名称”。
>
> 如果从属名称在class中呈嵌套状，称其为“嵌套从属名称”。
>
> 简单来说，就是`typename::son_type`中的`son_type`就是个从属名称。



> 虽然建议来说，出现从属名称就应该加上 typename，但是这好像只限定在 template，也就是说，当不存在 template时，不需要加 typename，因为此时不会出现歧义。
>
> 例如 `typename int x = 1;` 是不合法的。
>
> 所以说上面的程序有两个错误：
>
> 1. 在不能加 typename 的地方使用 typename
> 2. 在 template 之外使用 typename；



## 0x18 traits

Traits 是一种技术。也是一种 C++ 程序员共同遵守的协议。

常见的 traits 有：

1. iterator_traits
2. char_traits
3. numeric_limits（不是以traits结尾，但他确实是traits）

``` c++
template <class Iterator>
struct iterator_traits {
    typedef typename Iterator::value_type 			value_type;			// 迭代器所指对象的类型
    typedef typename Iterator::iterator_category 	iterator_category;	// 迭代器的类别
    typedef typename Iterator::difference_type 		difference_type;	// 两个迭代器的之间距离
    typedef typename Iterator::pointer 				pointer				// 指向迭代器所指的对象的指针
    typedef typename Iterator::reference 			reference			// 迭代器所指对象的引用
}
```

> [ref](https://blog.csdn.net/qq_43278899/article/details/128482849?csdn_share_tail=%7B%22type%22%3A%22blog%22%2C%22rType%22%3A%22article%22%2C%22rId%22%3A%22128482849%22%2C%22source%22%3A%22unlogin%22%7D)



## 0x19 类型转换运算符

重载类型转换运算符主要用于隐式类型转换。重载类型转换运算符不需要加上返回类型。但是和重载普通运算符（+，-…）一样，需要加上`operator`。例如：

``` c++
class Foo {
private:
    int val;
public:
    operator int() {
        return val;
    }
    operator Bar() {
        return Bar();
    }
};
```

## 0x1a 特化

模板为什么要特化，因为编译器认为，对于特定的类型，如果你能对某一功能更好的实现，那么就该听你的。

模板分为类模板与函数模板，特化分为全特化与偏特化。全特化就是限定死模板实现的具体类型，偏特化就是如果这个模板有多个类型，那么只限定其中的一部分。

当有多个偏特化满足条件时会编译错误。

C++ 只允许对类模板偏特化，不允许对函数模板偏特化。

至于为什么函数不能偏特化，似乎不是因为语言实现不了，而是因为偏特化的功能可以通过函数的重载完成。

---

区分函数模板的重载和偏特化有什么区别，偏特化需要载函数名后面加上 `<...>`，而函数重载则不需要。例如：

``` c++
// 模板函数
template<typename T1, typename T2>
auto add(const T1 &a, const T2 &b) -> decltype(a + b)
{
    cout << "template" << endl;
    return a + b;
}

// 全特化
template<>
int add<int,int>(const int &a, const int &b)
{
    cout << "int" << endl;
    return a + b;
}

// 偏特化
template<typename T>
int add<int, T>(const int &a, const T &b)
{
    cout << "int" << endl;
    return a + b;
}

// 重载
template<typename T>
int add(const int &a, const T &b)
{
    cout << "int" << endl;
    return a + b;
}
```

可以发现，只要是特化（无论是全特化还是偏特化），都需要载函数名后面加上 `<...>`。

[ref](https://developer.aliyun.com/article/94909)

## 0x1b 在 namespace std 里添加东西

我们不能往里面添加新的东西，只能添加全特化的东西。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Foo {
    int val;
    
    Foo(int _val = 0) : val(_val) {}
    void swap(Foo &other) 
    {
        using std::swap;
        cout << "struct" << endl;
        int t = other.val;
        other.val = val;
        val = t;
    }
};

namespace std {
    template<>
    void swap<Foo>(Foo &a, Foo &b)
    {
        cout << "std" << endl;
        a.swap(b);
    }
}


int main()
{
    Foo a(1), b(2);
    swap(a, b);
    cout << a.val << ' ' << b.val << endl;
    return 0;
}
```



## 0x1c 友元函数必须在class外声明

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename T>
class Foo {
public:
    friend void f() {
        cout << "void" << endl;
    }
private:
    T val;
};

// void f();

int main()
{
    f(); // wrong!

    return 0;
}
```

## 0x1d new && delete

可以delete空指针，但是不能多次delete同一个指针。

``` c++
    int *p = new int(4);
    cout << *p << endl;
    delete p;
    // delete p;   // wrong
    
    int *d = nullptr;
    delete d;   // accept
```

因此说好的编程习惯应该是在delete之后，设为NULL。

## 0x1e static member

Static 成员也会被继承，在继承类中也只有一份。

static成员只有被修饰为const才能在class中直接初始化。

static member 也会受访问属性影响



## 0x20 异常

如果某个地点抛出异常，那么它一定要存在于某个 `try` 执行域内，并且有相匹配的 `catch`，否则这个异常没法处理，并且导致 `terminate`。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <exception>

using namespace std;

void g()
{
    cout << "start g" << endl;
    throw 12;
    cout << "end g" << endl;
    try {
        
    } 
    catch(int x) {
        cout << "int: " << x << endl;
    }
}

void f()
{
    cout << "start f" << endl;
    try {
        cout << "start try" << endl;
        g();
        cout << "end try" << endl;
    }
    catch(double x) {
        cout << "exp: " << x << endl;
    }
    cout << "end f" << endl;
}

int main()
{
    f();
    
    return 0;
}
```

上面的代码会 `terminate`，因为 throw 所在 try 执行域只接受一个 double 异常对象（异常对象不能隐式类型转换），并且函数 `g` 中的 catch 并不会接受 throw，因为 throw 的地方并不在他的 try 内。

----

抛出异常会导致抛出端点所在执行域提前结束（`try`语句包裹起来的也是一个执行域），例如：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <exception>

using namespace std;

void g()
{
    cout << "start g" << endl;
    throw 12;
    cout << "end g" << endl;
}

void f()
{
    cout << "start f" << endl;
    try {
        cout << "start try" << endl;
        g();
        cout << "end try" << endl;
    }
    catch(int x) {
        cout << "exp: " << x << endl;
    }
    cout << "end f" << endl;
}

int main()
{
    f();
    
    return 0;
}
/* 输出
start f
start try
start g
exp: 12
end f
*/
```

> 通过输出结果可以发现，throw 所在的函数 `g()` 和 `g()` 所在的 `try` 执行域都提前结束了。
>
> `g()` 提前结束是因为 `g()` 时 throw 所在执行域，当 throw 时，`g()` 会因为出现异常立即结束，然后返回 `g()` 的调用端去寻找相匹配的 catch，但是在 try 中也不存在 catch，所在 try 也提前结束，然后返回 try 的调用端（`f()`），发现 `f()` 中存在 catch，至此异常的到处理，`f()` 正常结束。

----

在抛出异常时，穿引用会copy一次，传val会copy两次，传pointer不会copy。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct Foo {
    static int copy_idx;
    int val = 1024;
    Foo(const Foo &x) {
        val = ++ Foo::copy_idx;
    }
    Foo() = default;
};

int Foo::copy_idx = 0;

void passReference()
{
    try {
        Foo f;  // val = 1024
        throw f;
    } 
    catch(Foo &f) {
        cout << f.val << endl;  // 1
    }
}

void passVal()
{
    try {
        Foo f;  // val = 1024
        throw f;
    } 
    catch(Foo f) {
        cout << f.val << endl;  // 2
    }
}

void passPointer()
{
    try {
        Foo *f = new Foo();  // val = 1024
        throw f;
    } 
    catch(Foo *f) {
        cout << f->val << endl;  // 1024
        delete f;
        f = nullptr;
    }
    
}

int main()
{
    passPointer();
    return 0;
}
```

----

不要使用 exception specification，C++11 已经舍弃了它（太难用）。

[很好的文章](https://www.cnblogs.com/whyandinside/p/3677589.html)

----

在catch中再次throw，下一次接受throw的位置不是在这个try-catch中了，而是在上一层的try-catch。例如：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct B {
    int val = 1024;
    B(const B &x) {
        cout << "Base copy" << endl;
    }
    virtual void f() {
        cout << "Base f()" << endl;
    }
    B() = default;
};

struct D : B {
    int len = 999;
    D(const D &x) {
        cout << "Derived copy" << endl;
    }
    void f() override {
        cout << "Derived f()" << endl;
    }
    D() = default;
};

void g();

void f()
{
    try {
        g();
    }
    catch(int x)	// call
    {
        cout << "pre" << endl;
    }
}

void g()
{
    try {
        // B *b = new D();
        // B b;
        throw 1;
    }
    catch(int x)	// call
    {
        // b.f();
        cout << x << endl;
        throw ;
    } 
    catch(int x)
    {
        cout << "next" << endl;
        // b.f();
    }
}

int main()
{
    f();	
    return 0;
}
// 1
// pre
```

另外就是再次抛出异常的时候，如果多写了异常对象，会发生copy行为。

注意copy行为有一个问题，那就是执行的copy取决于静态类型。这在继承体系中会发生对象切割行为。例如：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct B {
    int val = 1024;
    B(const B &x) {
        cout << "Base copy" << endl;
    }
    virtual void f() {
        cout << "Base f()" << endl;
    }
    B() = default;
};

struct D : B {
    int len = 999;
    D(const D &x) {
        cout << "Derived copy" << endl;
    }
    void f() override {
        cout << "Derived f()" << endl;
    }
    D() = default;
};

void g();

void f()
{
    try {
        g();
    }
    catch(B &b)
    {
        b.f();  // base
    }
}

void g()
{
    try {
        B *b = new D();
        throw b;
    }
    catch(B *b) // pass pointer 不会copy，因此下面的 f 调用的是派生类的
    {
        b->f(); // Derived
        throw *b;    // base copy,对象切割为base
    } 
}

int main()
{
    f();
    return 0;
}
```

其实就是写为 `throw` 而不是 `throw b`，只要你不是传指针，都会copy。有点奇怪。。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct B {
    int val = 1024;
    B(const B &x) {
        cout << "Base copy" << endl;
    }
    virtual void f() {
        cout << "Base f()" << endl;
    }
    B() = default;
};

struct D : B {
    int len = 999;
    D(const D &x) {
        cout << "Derived copy" << endl;
    }
    void f() override {
        cout << "Derived f()" << endl;
    }
    D() = default;
};

void g();

void f()
{
    try {
        g();
    }
    catch(B *b)
    {
        b->f();  //  // Derived
    }
}

void g()
{
    try {
        B *b = new D();
        throw b;
    }
    catch(B *b)
    {
        b->f(); // Derived
        throw b;   // copy指针，但不copy b
    } 
}

int main()
{
    f();
    return 0;
}
```

## 0x21 new && delete

> [Ref](https://www.cnblogs.com/justinyo/archive/2013/03/11/2954565.html)
>
> Ref effettive c++ `<new and delete>`

当我们在基类重载了new，而不希望派生类使用它时，

``` c++
void * Base::operator new(std::size_t size) throw(std::bad_alloc)
{
    // 如果大小不为基类大小
    if (size != sizeof(Base))
    // 调用标准的 new 操作符
    return ::operator new(size);
    自定义大小为基类大小的分配处理
}
```

这样处理的一个前提是：认为子类的大小一定大于父类。

对于 operator new[] 来说，我们很难通过上面的方式检查到底是父类还是子类调用了操作符。通过 operator new[] 操作符的参数，我们无法得知分配的元素的个数，无法得知分配的每个元素的大小。operator new[] 的参数 size_t 表明的内存分配的大小可能大于需要分配的元素的内存大小之和，因为动态内存分配可能会分配额外的空间来保存数组元素的个数。



## 0x22 三目运算符

例子1

``` C++
int a = 1;
cout << "ABCDE"[a];	 // B
cout << "ABCDE"[!a]; // A
cout << "AB"[a];	 // B
cout << "AB"[!a];	 // A
```

> 很久之前在竞赛中看到的写法，主要用来进行格式化输出。
>
> 例如，最后一个数据后面跟一个换行，其余数据后面跟一个空格：
>
> `cout << " \n"[i == n - 1];`
>
> 乍一看好像挺懵圈的，实际上这个东西非常非常简单，他就是一个再普通不过的 `operator [];` 表达式罢了！
>
> 或许换一种写法更清晰一些：
>
> ``` c++
> char s[] = "hello";
> cout << s[a == 1];
> // <===> cout << "hello"[a == 1];
> ```
>
> 好了，就是这样！
>
> ⚠️注意：这不是什么新型的三目运算符！（尽管我之前一直这么认为。。）或者什么乱七八糟的东西，他就是一个 `operator [];`
>
> 只不过我们可以直接对一个 `postfix-expression` 表达式进行下标运算，而不必非得是数组名，但是有一个限制：`postfix-expression` 表示的值必须是一个指针值，（数组标识符会隐式转化为一个指针），一个字符串字面值是一个`const char*` 。

例子2

``` c++
int x = 0, y = 2, c = 0;
c = x ? : 2;    // 2
x = 1;
c = x ? : 2;    // 1
```

> 这里就不卖关子了，直接说明：
>
> 对于 `expression ? expression : other;`
>
> 我们可以直接写为：`expression ? : other;` 
>
> (? :之间的空格可以省略)
>
> 一种三目运算符的简化写法
>
> ⚠️**但他们并不总是等价的。**
>
> 例如：
>
> ``` c++
> int x = 0, c = 0;
> c = ++ x ? ++ x : -1;
> cout << c << ' ' << x << endl;	// 2 2
> x = 0;
> c = ++ x ?: -1;
> cout << c << ' ' << x << endl;	// 1 1
> ```
>
> 虽然两种写法等价，但是简化版本中，expression 只会执行一次，而非简化版本依然执行两次。



## 0x23 swap

swap 交换 a 和 b 时，a 所携带的信息和 b 所携带的信息也会被交换！

对于 vector 容器来说，这意味着 swap 不仅仅交换元素，还交换了 capacity！

``` c++
 vector<int> a, b;
    for(int i = 0; i < 2; i ++ )    a.push_back(i);
    for(int i = 0; i < 128; i ++ )  b.push_back(i);
    cout << a.size() << ' ' << a.capacity() << endl;    // 2 2
    cout << b.size() << ' ' << b.capacity() << endl;    // 128 128
    swap(a, b);
    cout << a.size() << ' ' << a.capacity() << endl;    // 128 128
    cout << b.size() << ' ' << b.capacity() << endl;    // 2 2
```

通过该性质我们可以得到一个关于 swap 实现 **shrink to fit** 的奇技淫巧 —- 通过 swap+临时变量。

```c++
vector<int> a;
for(int i = 0; i < 1024; i ++ )  a.push_back(i);
cout << a.capacity() << endl;	// 1024
for(int i = 0; i < 1024 - 8; i ++ )  a.pop_back();
cout << a.capacity() << endl;	// 1024
vector<int> (a).swap(a);
cout << a.capacity() << endl;	// 8
vector<int> ().swap(a);
cout << a.capacity() << endl;   // 0
```

注意不是 `vector<int> b(a).swap(a);` 

`vector<int> b(a)` 不是一个临时变量，最显而易见的就是他有名字。

临时变量不一定非得是默认构造的，你也可以拷贝构造。

``` c++
cout << int(3) << endl; // 3
cout << int() << endl;  // 0
```

## 0x24 reserse

以 vector 容器举例，reverse 仅仅用来重新分配内存，而不会调用 ctor，而不调用 ctor 就意味着没有对象产生，因此 size==0。

例如：

```c++
struct Foo {
    int val = 1024;
    Foo() {
        cout << "ctor" << endl;
    }
};

int main()
{
    vector<Foo> f(3);
    cout << "----" << endl;
    vector<Foo> p;
    p.reserve(3);
    cout << p.size() << endl;	// 0
    return 0;
}
//ctor
//ctor
//ctor
//----
```

另外就是 reserve 虽然是用来”重新分配内存“的，但实际上他只能让占用的内存变得更大，而不是变得更少！当我们让 reserve 缩小容器占用内存的时候，他什么也不做！

``` c++
struct Foo {
    int val = 1024;
    Foo() {
        cout << "ctor" << endl;
    }
    ~Foo() {
        cout << "dtor" << endl;
    }
    Foo(const Foo &f) {
        val = f.val;
        cout << "copy" << endl;
    }
};

vector<Foo >f(4);
// call 4times ctor
cout << f.capacity() << ' ' << f.size() << endl; // 4 4
f.reserve(2);   // 什么也不做
for(int i = 0; i < 2; i ++ )
    cout << f[i].val << ' ';
cout << endl; // 1024 1024
cout << f.capacity() << ' ' << f.size() << endl;	// 4 4(不变)
```

```c++
ctor
ctor
ctor
ctor
4 4
1024 1024 
4 4
dtor
dtor
dtor
dtor
```

## 0x25 `vector<bool>`的问题

``` c++
vector<bool> vec(5);
cout << vec[2] << endl; // default -> 0
auto it = vec[2];   // auto -> bool&
it = 1;
cout << vec[2] << endl; // yes, vec[2] -> 1 now
bool b = vec[2];
b = 0;
cout << vec[2] << endl; // 1, b not reference
// bool *p = &vec[2];  // compile error
```

我们发现:

1. 无法取 `vector<bool>` 的地址

2. 在下标返回值的 auto 是引用类型，但是对于其他类型不是，例如：

``` c++
vector<int> v(5);
v[4] = 1024;
cout << v[4] << endl;
auto it = v[4]; // auto -> int but int&
it = 128;
cout << v[4] << endl;   // 0
```



## 0x26 near pointer, far pointer

These are some old concepts used in 16 bit intel architectures in the days of MS DOS, not much useful anymore.

**Near pointer** is used to store 16 bit addresses means within current segment on a 16 bit machine. The limitation is that we can only access 64kb of data at a time.

**A far pointer** is typically 32 bit that can access memory outside current segment. To use this, compiler allocates a segment register to store segment address, then another register to store offset within current segment.

Like far pointer, **huge pointer** is also typically 32 bit and can access outside segment. In case of far pointers, a segment is fixed. In far pointer, the segment part cannot be modified, but in Huge it can be

> DOS(磁盘操作系统)是基于16位CPU的，使用16位寄存器只能访问64K的内存，为了访问更大范围的内存，采用了分段的方法，用两个16位二进制数来记录[逻辑地址](https://so.csdn.net/so/search?q=逻辑地址&spm=1001.2101.3001.7020)，第一个是段值(segment)，第二个是偏移量(offset)。
>
> 一般DOS程序把执行代码放在一段，数据放在另一段。
>
> 16位C编译器的int和pointer默认都是16位，pointer默认只存偏移量(offset)，只能指向同一段，称为近程指针(near pointer)。当程序有多个代码段(存放函数)或数据段(存放变量)，而且指针和所指向的地方不在同一个段时，就需要定义一个32位的远程指针(far pointer)。



## 0x27 erase VS. remove

C++ STL中的remove和erase函数曾经让我迷惑，同样都是删除，两者有什么区别呢？


vector中的remove的作用是将等于value的元素放到vector的尾部，但并不减少vector的size

vector中erase的作用是删除掉某个位置position或一段区域（begin, end)中的元素，减少其size


list容器中的remove 成员函数，原型是void remove (const value_type& val);

他的作用是删除list中值与val相同的节点，释放该节点的资源。

而list容器中的erase成员函数，原型是iterator erase (iterator position);

作用是删除position位置的节点。这也是与remove不同的地方。

考虑到list::erase是与位置有关，故erase还存在API:   iterator erase (iterator first, iterator last);


对于set来说，只有erase API，没有remove API。 erase 的作用是把符合要求的元素都删掉。

(1) void erase (iterator position);
(2) size_type erase (const value_type& val);
(3) void erase (iterator first, iterator last);

综上所述，erase一般是要释放资源，真正删除元素的，

而remove主要用在vector中，用于将不符合要求的元素移到容器尾部，而并不删除不符合要求的元素



## 0x28 istream

`istream_iterator<T>(); // 一个end-of-stream 迭代器` 

``` c++
istream is("data.txt");
list<int> message(istream_iterator<int> is,
                 istream_iterator<int>());
```



## 0x29 empty 和 size

>  [ref](https://zhuanlan.zhihu.com/p/594522964)



## 0x2a function pointer

> [ref](https://zhuanlan.zhihu.com/p/168627944)

首先要明白一点，<font color = blue>函数名绝不等于函数指针</font>。

虽然函数名和函数指针都指向函数在内存的地址，但是函数指针本质上是个指针，对这个指针取地址得到的是这个指针变量的地址，而对函数名取地址，得到的还是函数的入口地址。如果是类成员函数指针，差别更加明显。

----

其次，<font color = blue>初始化函数指针时要加上取地址符号</font>。

之所以我们有时候可以写法下面的初始化语句：

``` c++
void func(int x);
typedef void(*fp)(int);
fp f = func;
```

主要是为了兼容 C 语言的写法，这在 C++ 是不正规的！不正规意味着这不总是正确的，例如在成员函数指针中，我们必须加上`&`。

其行为应该是函数名隐式转换为了一个函数指针。

---

另外，还有一种很少的写法，就是不使用 typedef，直接声明并初始化一个函数指针。

``` c++
void(*fp)(int) = func;
fp(1);
```

但是极为不推荐这么写，特别是函数指针比较复杂并且涉及到数组名时。<font color = blue>当函数指针涉及数组名时，牢记[]必须紧跟在变量名的后面。</font>

声明一个函数指针数组的正确写法：

`void (*f_ptr[10])(); 函数类型为void(void)`

错误写法：

`void (*f_ptr)()[10];`

----

>  类的函数指针

在类中，函数被分为了两类：

1. 成员函数
2. 静态函数

只需要牢记一句话：<font color = blue>静态函数没有 this 指针。</font>

> 类静态成员函数指针

类的静态成员函数没有 this 指针，它的存储方式和普通的函数是一样的，<font color = blue>可以取得的是该函数在内存的实际地址。</font>

它的声明和普通函数指针一样，但是在初始化时需要指明`class::`

``` c++
struct Foo {
    static void func() {
        cout << "f()" << endl;
    }  
};

int main()
{
    typedef void(*pf)();
    pf f = &Foo::func;	// 也可以不加&
    f();
    (*f)();				// 正规的调用方式
}
```

> 类成员函数指针

与静态函数不同，<font color = blue>成员函数在调用时，必须要提供 this 指针</font>。

因为在它被调用之前，自己也不知道哪个对象的此函数被调用，所以通过 `&` 得到的不是实际的内存地址。

只有调用的时候，C++才会结合 this 指针通过固定的偏移量找到函数的真正调用地址。

之所以会这样，是因为C++对象的内存模型决定的！每个类对象的内存中并不包含成员函数，成员函数被单独放在一片内存空间中，所有类对象共享这块内存空间。

[类与对象总结](https://www.cnblogs.com/zjuhaohaoxuexi/p/16655902.html)

为了支持这种调用方式，这里C++给专门提供了特殊的几个操作符：`::*` `.*` `->*`

- 声明：`void (Test::*fptr)()；`，类成员函数指针的声明，就必须加上类名限定，这就声明了一个函数指针变量fptr，他只能指向Test类的成员函数。

- 赋值：`fptr = &Test::function`

- 调用：类的成员函数是无法直接调用的，必须要使用对象或者对象指针调用（这样函数才能通过对象获取到this指针）。

- - `(t.*fptr)();`，t是Test类的一个实例，通过对象调用。
  - `(pt->*fptr)();`，pt是一个指向Test类对象的指针，通过指针调用。



``` c++
struct Foo {
    void f() {
        cout << "f()" << endl;
    }
    void g() {
        cout << "g()" << endl;
    }
};

int main()
{
    typedef void(Foo::*fp)();
    fp f1 = &Foo::f;	// 1
    fp f2 = &Foo::g;	// 2
    Foo obj;
    (obj.*f1)();	// 2
    Foo *objp = new Foo();
    (objp->*f2)();	// 3
    delete objp;    // 4
    return 0;
}
// 在1处，如果不加&，会报错，因为编译器找不到Foo::在哪里，还记得前面说的嘛？只有通过对象调用的时候，才能找到真正的函数的地址，否则得到的是一个假地址，既然地址都不对，那么编译器自然也就无法将其转换为函数指针了
```

---

函数指针不可以隐式转换参数和返回值类型，想要改变只能通过`reinterpert_cast`

reinterpret:重新解释

cast：转型

reinterpret_cast 就有<font color = blue>“重新解释的转型”</font>的意思。

**“reinterpret_cast 运算符并不会改变括号中运算对象的值，而是对该对象从位模式上进行重新解释”**

[ref](https://zhuanlan.zhihu.com/p/33040213)

一言以蔽之，自己心里没点B数，还是不要使用了（捂脸）。



## 0x2b C语言不支持函数重载

这主要是由<font color = blue>名称重整机制</font>决定的。

C语言不存在名称重整机制，但是C++有。

例如有一个函数 `void function(int x, int y);`

在C语言中可能会被解释为：`_function`

在C++中可能被毁解释为 `_function_int_int`



## 0x2c 纯虚函数

纯虚函数可以有实现，但必须在class声明之外。

抽象类可以有成员函数和静态成员函数。



## 0x2d map中[]和insert

当插入一个元素时，map会多一次元素的 ctor, dtor

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

static int idx = 0;

struct Foo {
    Foo(int _val = 0) : val(_val) {
        val = ++ idx;
        cout << "ctor" << endl;
    }  
    Foo(const Foo &f) {
        cout << "copy ctor" << endl;
    }
    ~Foo() {
        cout << "dtor" << endl;
    }
    Foo& operator=(const Foo &f) {
        cout << "assignment copy" << endl;
        return *this;
    }
    int val;
};

struct Cmp {
    bool operator()(const Foo &lhs, const Foo &rhs) const {
        return lhs.val < rhs.val;
    }  
};

Foo f;

void test1()
{
    map<Foo,int, Cmp> m;
    m[1] = 3;
}

void test2()
{
    map<Foo, int, Cmp> m;
    m.insert(make_pair(1, 2));
}

int main()
{
    // test1();
    /*
    ctor
    ctor
    copy ctor
    dtor
    dtor
    dtor    */
    test2();
    /*
    ctor
    ctor
    dtor
    dtor    */
    return 0;
}
```



## 0x2e 在class中初始化vector

``` c++
class Foo {
public:
    Foo() : vec(100) {} // !
    vector<int> vec;
};
int main()
{
    Foo f;
    cout << f.vec.size() << endl;	    // 100
    cout << f.vec.capacity() << endl;	// 100
    cout << f.vec.size() << endl;		// 101
    cout << f.vec.capacity() << endl;	// 200
}
```

当我们直接初始化时，分配的大小就是capacity的大小。这说明capacity并不总是2的指数次幂，并且在扩大时也不会变成2的指数次幂，而是直接变为原来的两倍。





## 0x2f 智能指针

### 1. 缺陷

### 2. weak_ptr



### 3. 常见错误

``` c++
// shared_ptr<int> p1 = make_shared(new int(10));
// shared_ptr<int> p2 = make_shared<int>(new int(10));
shared_ptr<int> p3 = make_shared<int>(int(10));
// shared_ptr<int> p4 = new int(10);
shared_ptr<int> p5(new int(10));
```

在上面的代码中，有几种常见的（我经常犯的）错误：

1. make_shared是模板函数，你需要为它指定类型
2. 使用makes_shared创建时，不需要再 new了，不然你传给它一个参数干什么？不就是替你分配空间的吗？
3. new 必须直接初始化，不能拷贝初始化，因为不存在从原始指针到智能指针的隐式类型转换。



## 0x30 引用的引用的误区

c++不能定义引用的引用，看下面代码：

``` c++
int a = 1;
int &b = a;
int &c = b;
cout << a << ' ' << b << ' ' << c << endl;
c = 100;
cout << a << ' ' << b << ' ' << c << endl;
b = 1000;
cout << a << ' ' << b << ' ' << c << endl;
a = 10000;
cout << a << ' ' << b << ' ' << c << endl;
```

⚠️注意了！c是一个b的引用，而不是一个“引用的引用”，他就是一个普通的引用，别无其他！

所谓“引用的引用”就下面形式：

`int &(&c) = b;`

这才是“引用的引用”。



## 0x31 嵌套类和局部类

嵌套类：在一个类中定义的类

> 定义嵌套类的初衷是建立仅供某个类的成员函数使用的类类型。目的在于**隐藏类名，减少全局的标识符，从而限制用户能否使用该类建立对象。**这样可以提高类的抽象能力，并且强调了两个类(外围类和嵌套类)之间的主从关系。

外围类：拥有嵌套类的类

局部类：在一个函数体内定义的类

>  （1）局部类只能在定义它函数内部使用，在其他地方不能使用。
>
>  （2）局部类的所有成员函数都必须定义在类体内，因此在结构上不是特别灵活。
>
>  （3）在局部类的成员函数中，可以访问上级作用域的所有变量，如函数局部变量、全局变量等。
>
>  （4）局部类中不能定义静态数据成员，因为这种数据成员的初始化无法完成，静态成员数据的定义和初始化必须放在全局作用域。

[ref](https://cloud.tencent.com/developer/article/1177286)



## 0x32 相等和等价混用

相等和等价混用当然是错误的行为❌

等价性出现在关联容器，lower_bound,upper_bound，unique等带有多排序性质的算法中。

当我们在上面情况中处理元素时，要注意等价性和相等行不要混用了，例如：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string convert_to_lower(string s)
{
    for(auto &x : s) x = tolower(x);    
    return s;
}

struct Foo {
    string val;
    Foo(string _val = string()) : val(_val) {}
    bool operator<(const Foo &rhs) const { // 忽略大小写的比较的等价性测试
        string ls = convert_to_lower(this->val);
        string rs = convert_to_lower(rhs.val);
        return ls < rs;
    }
};

int main()
{
    vector<Foo> s;
    s.push_back(Foo("abc"));
    s.push_back(Foo("hello"));
    s.push_back(Foo("ohmygod!"));
    sort(s.begin(), s.end());
    
    Foo f("Abc");   // 注意不能直接传入 "Abc"，因为不存在 Foo 到 string 的隐式类型转换，老生常谈的问题了！不要老是犯错！
    auto pos = lower_bound(s.begin(), s.end(), f);
    if(pos != s.end() && pos->val == f.val) {  // == 相等行测试
        cout << "has found: " << pos->val << endl;
    }
    else {
        cout << "not found" << endl;
    }
    // 上面混用等价性和相等性导致我们明明找到了，却“没找到”
    // 比较好的解决方法时修改相等行测试为等价性测试
    // 或者使用equal_bound，避免相等行测试
    auto p = equal_range(s.begin(), s.end(), f);
    if(p.first == p.second) {
        cout << "not found" << endl;    // 成功找到了
    }
    else {
        cout << "has found: " << p.first->val << endl;
    }
    
    return 0;
}
```



## 0x33 语言类型

**什么是静态（类型）语言&动态（类型）语言，强类型语言&弱类型语言**

>  [ref here](http://c.biancheng.net/view/8803.html)

静态/动态类型语言是指变量的类型如何确定

1. 静态类型语言：创建变量时就指定变量的类型

2. 动态类型语言：不需要指定变量的类型，由编译器自行推断

强/弱类型指的是编程语言如何处理运算过程中的值。当值的类型不符合运算规则时，编程语言究竟是做出一些猜测，临时转换值的类型以帮助人们解决问题，还是停止运行，提醒人们不应该这样做？

类型系统的“强/弱”指的是当编程语言遇到与类型定义不匹配的运算时，尝试猜测或者转换的力度/程序。它不是一条明确的界限，而是一个范围。

- 强类型语言在遇到与类型定义明显矛盾的运算时，一般会当做一种语法错误，而不会尝试对值的类型进行转换。
- 弱类型语言恰好相反，会猜测程序员的意图，并对其中一些值的类型进行转换，以让程序继续执行。



# Tiny C++ Prime

## ref

[about Linux](https://www.cntofu.com/book/46/linux_system/linuxxi_tong_bian_cheng_zhi_cuo_wu_chu_li_ff1a_per.md)

## 英文

curly brace：花括号，curly：弯曲

built-in type：内置类型

comment：注释

形参：parameter

实参：argument

## vim

[快捷键](https://matt33.com/2016/12/06/vim-basic/)

## TODO

p18 class

p43 c++ 关键字，操作符替代名

在解释变量名的时候，遵循自右向左，数组自内而外，const就左原则（自左而右），从靠近变量名的部分开始

[引用的本质](https://blog.csdn.net/feigegegegegegegeg/article/details/52613627)

[不能定义引用的引用](https://www.zhihu.com/question/28023545)

[不能定义指向引用的指针](https://www.cnblogs.com/wuhongbin/p/14048477.html)

const的extern

```
int x = int(5);
```

## 第一章

一个统计输入中每个连续值出现了多少次的函数

``` c++
void wordCount()
{
    int val = 0, cnt = 0;
    if(cin >> val) {    // !
        cnt = 1;
        int curVal;
        while(cin >> curVal) 
        {
            if(curVal == val)   cnt ++ ;
            else 
            {
                cout << val << ' ' << cnt << endl;
                val = curVal;
                cnt = 1;
            }
        }
        cout << val << ' ' << cnt << endl;
    }
}
```

## 第二章

[列表初始化不允许窄化转换，例如double转int](https://developer.aliyun.com/article/758380)

窄化转换：

1. 浮点数转整数
2. 整数转浮点数
3. 高精度浮点数转低精度浮点数
4. 大整数转小整数

注意编译器不一定会对窄化转换报错！



typedef 可以用逗号分割

``` C++ 
#include <iostream>
typedef double *dp, d;  // !
int main()
{
    d x = 3.13;
    dp p = &x;
}
```

关于引用

> 为什么 decltype((i)) 的返回类型是引用
>
> 一言以蔽之：(i) 的类型是 lvalue
>
> [ref](https://segmentfault.com/q/1010000000516149)
>
> 再结合decltype的推到规则

decltype推导四规则

如果e是一个没有带括号的标记符表达式或者类成员访问表达式，那么的decltype（e）就是e所命名的实体的类型。此外，如果e是一个被重载的函数，则会导致编译错误
否则 ，假设e的类型是T，如果e是一个将亡值，那么decltype（e）为T&&
否则，假设e的类型是T，如果e是一个左值，那么decltype（e）为T&
则，假设e的类型是T，则decltype（e）为T

``` c++
int main()
{
    int i = 1;
    decltype((i)) x = i;
    (i) = 10;
    cout << i << endl;
    int (y);
    (y) = 20;
    cout << y << endl;
    return 0;
}
```

为什么在class中不可以用圆括号初始化

> [参考](https://www.zhihu.com/question/37019538)
>
> 总结来说，就是避免语法分析时有歧义

为什么switch只能case整形

>[ref](https://blog.csdn.net/Abrazen_zz/article/details/79250450)
>
>因为switch内部实现是一个跳转表，跳转表就是一个数组，这个数组的大小就是[switch的最大case-最小case+1]，可见这个数组并不一定充分利用，因为中间可能空出很多case。
>
>对于case，我们得到case值，减去最小case，得到的就是在跳转表中的下标。对于一个下标，我们只能通过整形去求。



## 为何C++/Rust都不允许静态函数是虚的？

你的定义不够精确。否则的话你自己就能发现问题。

这个函数是要运行时查找具体的入口地址再调用的
其实应该是这个函数x是要运行时查找所在对象具体的入口地址再调用的。或者说，虚函数表是从所在对象索引的。

而static不存在所在对象。所以怎么找它的虚函数表？别忘了在加入static之前，你需要调用一个静态函数，得这样：

`static_cast<T*>(0)->Func();`
因为Func和对象无关，所以这里搞个0也无所谓。后来有了静态函数，你可以写成：

`T::Func();`
所以，你这下明白了为什么虚函数表不能放静态函数了吧。

你非得要类似功能的话，不用static就行了呗，就把那个函数变成一个成员。那就随便virtual了。

> 总结来说，静态函数是不属于class的实例的，也就是说，静态函数不属于某个具体的对象。但是虚函数是依赖于对象的，因为它要从对象的虚函数表中查找具体的入口（到底是那个函数)



## 三种继承方式

C++ 中支持三种继承方式：公有继承，私有继承，保护继承，C++ 中的默认访问属性为 private

1. 公有继承（public）

基类的 public 和 protected 成员的访问属性在派生类中保持不变，**但基类的 private 成员不可直接访问**。
派生类中的成员函数可以直接访问基类中的 public 和 protected 成员，但不能直接访问基类的 private 成员。
通过派生类的对象只能访问基类的 public 成员。

2. 保护继承（protected）

基类的 public 和 protected 成员都以 protected 身份出现在派生类中，**但基类的 private 成员不可直接访问**。
派生类中的成员函数可以直接访问基类中的 public 和 protected 成员，但不能直接访问基类的 private 成员。
通过派生类的对象不能直接访问基类中的任何成员

3. 私有继承（private）

基类的 public 和 protected 成员都以 private 身份出现在派生类中，**但基类的 private 成员不可直接访问**。
派生类中的成员函数可以直接访问基类中的 public 和 protected 成员，但不能直接访问基类的 private 成员。
通过派生类的对象不能直接访问基类中的任何成员



## 用自定义类型

set

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

// 1. 重载 operator<
class Foo {
private:
    int val;
public:
    Foo(int _val = 0) : val(_val) {}
    bool operator<(const Foo &rhs) const {
        return val > rhs.val;
    }
    int get() const {
        return val;
    }
};

void testFoo() 
{
    set<Foo> s;
    for(int i = 0; i < 5; i ++ ) {
        Foo f(i);
        s.insert(f);
    }
    for(auto &x : s) {
        cout << x.get() << endl;
    }
}

// ---------------------------------------------

// 2. 自定义比较函数
class Bar {
private:
    int val;
public:
    Bar(int _val) : val(_val) {}
    int get() const {
        return val;
    }
};

bool cmpBar(const Bar &l, const Bar &r) {
    return l.get() < r.get();
}

void testBar()
{
    set<Bar, decltype(cmpBar)*> s(cmpBar);
    for(int i = 0; i < 5; i ++ ) {
        Bar b(i + 10);
        s.insert(b);
    }
    for(auto &x : s)    cout << x.get() << endl;
}

int main()
{
    testFoo();
    testBar();   
    return 0;
}
```

起别名

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
#include <map>
#include <ctime>

using namespace std;

class Foo {
private:
    int val;
public:
    Foo(int _val) : val(_val) {}
    int get() const  { return val; }
};

bool cmp(const Foo &l, const Foo &r) 
{
    return l.get() < r.get();
}

int *getPtr(int x) {
    int *p = new int(x);
    return p;
}

int main()
{
    // decltype，注意decltype一个函数得到的是引用而不是指针
    set<Foo, decltype(cmp)*> q0(cmp);
    
    // 函数指针 + decltype
    bool(*p)(const Foo&, const Foo&) = cmp;
    set<Foo, decltype(p)> q1(cmp);  
    
    // using 别名
    using T = bool(*)(const Foo&, const Foo&);
    set<Foo, T> q2(cmp);  
    
    // typedef 别名
    typedef bool(*cmpFoo)(const Foo&, const Foo&);
    set<Foo, cmpFoo> q3(cmp);  
    
    return 0;
}
```

priority_queue，和set几乎一模一样，不同之处在于需要在声明时添加“底层容器”，因为优先队列是一个适配器。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
#include <map>
#include <ctime>

using namespace std;

class Foo {
private:
    int val;
public:
    Foo(int _val) : val(_val) {}
    int get() const  { return val; }
};

bool cmp(const Foo &l, const Foo &r) 
{
    return l.get() < r.get();
}

int *getPtr(int x) {
    int *p = new int(x);
    return p;
}

int main()
{
    // 比set多了一个vector<int> 
    
    // decltype，注意decltype一个函数得到的是引用而不是指针
    priority_queue<Foo, vector<Foo>, decltype(cmp)*> q0(cmp);
    
    // 函数指针 + decltype
    bool(*p)(const Foo&, const Foo&) = cmp;
    priority_queue<Foo, vector<Foo>, decltype(p)> q1(cmp);  
    
    // using 别名
    using T = bool(*)(const Foo&, const Foo&);
    priority_queue<Foo, vector<Foo>, T> q2(cmp);  
    
    // typedef 别名
    typedef bool(*cmpFoo)(const Foo&, const Foo&);
    priority_queue<Foo, vector<Foo>, cmpFoo> q3(cmp);  
    
    
    return 0;
}
```

## 错误处理函数



* perror
* strerror

``` C++
#include <stdio.h>
void perror(const char *s);
```

它先打印s指向的字符串，然後輸出當前errno值所對應的錯誤提示信息，例如當前errno若為12，調用perror("ABC")，會輸出"ABC: Cannot allocate memory"。

``` c++
#include <string.h>
char *strerror(int errnum);
```

它返回errnum的值所對應的錯誤提示信息，例如errnum等於12的話，它就會返回"Cannot allocate memory"。

[参考](https://www.cntofu.com/book/46/linux_system/linuxxi_tong_bian_cheng_zhi_cuo_wu_chu_li_ff1a_per.md)

* errno

[将errno](https://cplusplus.com/errno) 的值解释为错误消息，并将其打印到[stderr](https://cplusplus.com/stderr)（标准错误输出流，通常是控制台），可选择在其前面加上*str*中指定的自定义消息。

[errno](https://cplusplus.com/errno)是一个整型变量，其值描述错误条件或调用库函数产生的诊断信息（C 标准库的任何函数都可以为 errno 设置一个值，即使没有在本参考中明确指定，[即使](https://cplusplus.com/errno)没有发生错误），请参阅[errno](https://cplusplus.com/errno)了解更多信息

## 定义指针要记得初始化

``` c++
int *p;
if(p == nullptr)    cout << "null" << endl;
else    cout << "ptr" << endl;
// 输出为：ptr
```

这是因为p没有初始化，它里面的内容是未知的，因此对 它的行为是未定义的

所以我们应该写为：`int *p = nullptr;`

## 纯虚函数

当一个 class 包含纯虚函数时，它就是一个抽象类，我们不可以为一个抽象类创建实例，但是我们可以为这个虚函数提供**定义**，并且还可以调用它。

[Effective c++ 条款35]

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class B {
public:
    virtual void f() = 0;
};

void B::f()
{
    cout << "B::f()" << endl;
}


class D : public B {
public:
    void f() override {
        B::f();
    };
};


int main()
{
    D d;
    d.f();
    return 0;
}
```



## 函数指针别名

``` c++
int f(int a, int b) {
    return a + b;
}
using prt1 = int(*)(int,int);
typedef int(ptr2*)(int,int);
```

返回值类型不需要加括号



## std::function

由于可调用对象的定义方式比较多，但是函数的调用方式较为类似，因此需要使用一个统一的方式保存可调用对象或者传递可调用对象。于是，`std::function`就诞生了。

std::function是一个**可调用对象包装器**，是一个类模板，可以容纳除了类成员函数指针之外的所有可调用对象，它可以用统一的方式处理函数、函数对象、函数指针，并允许保存和延迟它们的执行。

我们通常把{函数，函数指针，lambda表达式，仿函数}称为可调用对象，function可以持有任何与它的签名式**“兼容”**的可调用对象。所谓兼容，就是说这个可调用对象的参数可以隐式转换为function签名式中的对象。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

typedef function<int(int,int)> func;    // int

double f(double a, double b)    // double
{
    return a * b;
}

struct Foo {
    int operator()(short a, short b) {
        return a - b;
    }  
};

int main()
{
    int a = 2, b = 4;
    func p1 = f;
    func p2 = Foo();

    cout << p1(a, b) << endl;
    cout << p2(a, b) << endl;
    
    return 0;
}
```

function 相当于一个指向函数的泛化指针



# new C++

## 0x00 what is new c++

> 《effective modern c++》
>
> 《》

`1983 年，c++ 取代了 c with class 成为了该程序设计语言的名字。`

## 0x01 Initializer_list 初始化问题

在 **ctor** 中，Initalizer_list的优先级非常高，函数会优先匹配他，如果不可用再匹配别人，并且，貌似可以违反它不可以窄化和转型的规定，例如下面代码（通过编译）

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <initializer_list>

using namespace std;

struct Foo {
    Foo(int a, double b)
    {
        cout << "int, double: ";
        cout << a << ' ' << b << endl;
    }
    
    Foo(initializer_list<int> s)
    {
        cout << "initializer_list<int>: ";
        for(auto it = s.begin(); it != s.end(); it ++ )     cout << *it << ' ';
        cout << endl;
    }
    Foo(char ch, string s) 
    {
        cout << "char, string: ";
        cout << ch << ' ' << s << endl;
    }
};


int main()
{
    int a = 1;
    short b = 2;
    double c = 3.14;
    string s = "hello";
    Foo f1{a, b};	// 窄化
    Foo f2{b, c};	// 类型转换
    Foo f3{c, s};
    Foo f4{b, s};
    
    return 0;
}
```

但是，如果如果 cotr 中 Initalizer_list 并不是作为一个单独的参数出现，而是有多个参数，例如，我们将上面的第二个构造函数改为：

``` c++
Foo(initializer_list<int> s, int c)
    {
        cout << "initializer_list<int>, int: ";
        for(auto it = s.begin(); it != s.end(); it ++ )     cout << *it << ' ';
        cout << endl;
    }
```

并且调用`Foo f5{a, a};` 也不会匹配到它。

但如果我们调用 `Foo f5{{a}, a};` 就会匹配他。

这是因为，只有当 Initializer_list 只有作为构造函数的单独的参数，并且我们通过 {}来调用构造函数，才能使得 Initializer_list 同时和其他函数（也是构造函数）匹配。

否则，我们都必须通过 `{}` 显示指明，我们要调用的是Initializer_list。

这是因为在 c++11 之后，新增了 {} 的初始化方式，而 {} 的参数类型就是 Initializer_list。

所以说，如果我们以 () 的形式调用构造函数，永远不会匹配 Initializer_list，因为类型就不匹配！编译期不会把 () 里面的内容解释为 Initializer_list。

下面的代码编译错误，因为编译期找不到合适的匹配函数。（注意如果Initializer_list里面有多余的参数但是有默认值，也是可行的）

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <initializer_list>

using namespace std;

struct Foo {
    Foo(initializer_list<int> s, int c = 1)
    {
        cout << "initializer_list<int>, int: ";
        for(auto it = s.begin(); it != s.end(); it ++ )     cout << *it << ' ';
        cout << endl;
    }
};


int main()
{
    int a = 1;
    Foo f(1, a);
    return 0;
}
```

> [ref](https://www.cnblogs.com/jerry-fuyi/p/12806284.html)

## 0x02 函数决议和重载决议

函数决议有三个步骤：

1. 名字查找
2. 重载决议
3. 可访问性检查

例如：

``` c++
#include <complex>

class Calc
{
public:
    double Twice(double);
private:
    int   Twice(int i);
    std::complex<float>  Twice(std::complex<float c>);      
};

int main()
{
    Calc c;
    c.Twice(21);  //编译出错，Twice(int) 不可访问
}
```



（1）名字查找：编译器会首先寻找至少包含一个名为Twice的实体作用域，并将其放入候选实体列表。本例中，编译器的名字查找首先是从Calc的作用域中开始，编译器会查看Calc中是否至少存在一个名为Twice的成员，如果没有，就会继续依次在其基类和外围空间中查找，直到找到一个至少具有一个候选函数的作用域。本例中在第一个作用域中找到三个候选函数。

（2）重载决议。编译器在候选的重载函数中选出唯一的最佳匹配。因为c.Twice(21)参数是21默认int，所以最佳匹配是Twice(int)。注：如果编译器在函数匹配中找不到最佳的匹配就会产生二义性，编译报错

（3）可访问性检查。最后编译器会检查函数的可访问性，因为Twice(int)是private，不可访问

> ⚠️：重载决议在可访问性检查的前面！

## 函数决议 [TODO]

> 当存在模板和重载函数同时完美匹配时，重载函数优先。其次是全特化，偏特化，最后是未特化模板。

隐式类型转换级别：[ref](https://c-cpp.com/cpp/language/overload_resolution.html)

1. 完美匹配：不要求转换、左值到右值转换、限定性转换、函数指针转换、 (C++17 起)类类型到相同类的用户定义转换
2. 提升匹配：整型提升、浮点提升
3. 转换匹配：整型转换、浮点转换、浮点整型转换、指针转换、成员指针转换、布尔转换、派生类到其基类的用户定义转换

> 注意这里的提升分为两种：
>
> 1. 实参到形参的提升
> 2. 形参到实参的提升

整形提升的意义

> CPU内整型运算器(ALU)的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度
>
> 因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整型操作数的标准长度
>
> 所以，表达式中各种长度可能小于int长度的整型值，都必须先转换为int或unsigned int，然后才能送入CPU去执行运算
>

C语言中的数值类型转换：整型提升/寻常算术变化/截断/强制类型转换

> [原文地址，防止丢失，copy一份](https://blog.csdn.net/KingCat666/article/details/44755973)
>
> ***\*整型提升：\****
>
> K＆R C中关于整型提升(integral promotion)的定义为：
>
> "A character, a short integer, or an integer bit-field, all either signed or not, or an object of enumeration type, may be used in an expression wherever an integer maybe used. If an int can represent all the values of the original type, then the value is converted to int; otherwise the value is converted to unsigned int. This process is called integral promotion."
>
>
> 上面的定义归纳下来就是以下两个原则：
>
> 1). 只要一个表达式中**用到了整型值**，那么类型为**char、short int**或***\*整型位域\****(这几者带符号或无符号均可)的变量，以及枚举类型的对象，都可以被放在这个整型变量的位置。
>
> 
> 2). 如果1）中的变量的原始类型值域可以被**int**表示，那么原值被转换为**int**；否则的话，转为**unsigned int**。
>
> 以上两者作为一个整体，被成为***\*整型提升\****(Integral promotion)
>
> 整型提升的概念容易与***\*普通算术类型转换\****产生混淆。这两者的区别之一在于后者是在**操作数之间类型不一致的情况下发生**，最终将操作数转换为同一类型。而在算术运算这种情景下，**即使操作数具有相同的类型，仍有可能发生整型提升**。
>
> 例如：
>
> 
>
> ```cpp
> char a, b, c;
> c = a + b;</span>
> ```
>
> 
>
> 在上述过程中，尽管两个运算符"+"和"="的操作数全为char型，但在**中间计算过程中存在着整型提升**：对于表达式a+b ，a、b都是char型，因此被提升至int型后，执行“+”运算，计算结果(int型)再赋值给c(char型)，又执行了***\*隐式的类型转换\****。
>
> 理解了整型提升的概念后，面对下面这个C语言的FAQ，你应该不会产生困惑。
>
> 例：
>
> ```html
> <pre name="code" class="cpp"><span style="font-size:14px;">char a;
> printf(“sizeof(a)=%d”, sizeof(a));</span>
> ```
>
> ```
> 
> ```
>
> 输出： 1
>
> 原因：a不是一个表达式，a是char型，char型占1字节。
>
> 
>
> ```cpp
> <span style="font-size:14px;">printf(“sizeof(‘A’) = %d”, sizeof(‘A’));</span>
> ```
>
> 
>
> 输出： 4
>
> 原因：字符‘A’是int型，不需整型提升，int型占4字节
>
> 
>
> ```cpp
> <span style="font-size:14px;">char a, b;
> printf(“sizeof(a+b)=%d”, sizeof(a+b));</span>
> ```
>
> 
>
> 输出： 4
>
> 原因：a+b是一个算术表达式，a、b均整型提升(int型)，所以占4个字节。
>
> 
>
> 
>
> ```cpp
> <span style="font-size:14px;">char a, b, c;
> printf(“sizeof(c=a+b)=%d”, sizeof(c=a+b));</span>
> ```
>
> 
>
> 输出： 1
>
> 原因：表达式c=a+b中，a和b是算术运算，因此整型提升(int型)，计算结果(int型)再赋值给c(char型)，又执行了隐式的类型转换，所以最终占1字节。
>
> 
>
> 来源： <http://blog.chinaunix.net/uid-23036581-id-2609840.html>
>
> 运算过程中的隐式数据转换如下：
>
>   **double**    ←  float 高
>
> 　　↑
>
> 　 ***\*long\****
>
> 　　↑
>
> 　unsigned
>
> 　　↑
>
> 　  int      ←  char,short 低
>
> 
>
> ***\*参数传递：\****
>
> 另一个可能发生隐式参数转换的地方就是参数传递。
>
>  在K&R C中，由于函数的参数也是表达式，所以也会发生类型提升。
>
> 在ANSI C中，如果使用了适当的函数原型，类型提升便不会发生，否则也会发生。
> 在被调用函数的内部，***\*提升后的参数被裁减为原先声明的大小\****。
>
> 这就是为什么单个的printf()格式字符串%d能适用于几个不同类型，
> short、char或int，而不论实际传递的是上述类型的哪一个。
> 函数从堆栈中（或寄存器中）取出的参数总是***\*int类\****，并在printf或其他被调用函数里按统一的格式处理。
> printf是一个可变参数函数，此时一般的参数提升始终会发生。
>
> 来源： <http://blog.csdn.net/ztz0223/article/details/1870816>
>
> 消除形参与实参之间的整型提升：
>
> ANSI C函数原型的目的是使C语言成为一种更加可靠的语言。建立原型就是为了消除形参和实参之间的类型不匹配。
> 如果使用了函数原型，缺省参数提升就不会发生。如果参数声明为char，则实际传递的也是char。
>
> ***\*截断/赋值中的类型转换:\****
>
> 当赋值运算符两边的运算对象类型不同时，将要发生类型转换， 转换的规则是：把***\*赋值运算符右侧表达式的类型\****转换为**左侧变量的类型**。具体的转换如下：
>
> 　　***\*(1) 浮点型与整型\****
>
> 　　● 将浮点数(单双精度)转换为整数时，将舍弃**浮点数的小数部分**， 只保留**整数部分**。
>
> 　　将整型值赋给浮点型变量，数值不变，只将形式改为浮点形式， 即**小数点后带若干个0**.
>
> 注意：整型转浮点型可能是不准确的：
>
> ```
> 种类-------符号位-------------指数位----------------尾数位---- float-----第31位(占1bit)---第30-23位(占8bit)----第22-0位(占23bit) double--第63位(占1bit)---第62-52位(占11bit)---第51-0位(占52bit) int-------第31位(占1bit)--------------------------第30-0位(占31bit)
> 取值范围主要看指数部分： float的指数部分有8bit(2^8)，由于是有符号型，所以得到对应的指数范围-128~128。 double的指数部分有11bit(2^11)，由于是有符号型，所以得到对应的指数范围-1024~1024。 由于float的指数部分对应的指数范围为-128~128，所以取值范围为： -2^128到2^128，约等于-3.4E38 — +3.4E38 精度(有效数字)主要看尾数位： float的尾数位是23bit，对应7~8位十进制数，所以有效数字有的编译器是7位，也有的是8位，也即一个整数转换为float的话，会表示成科学计数法，由小数（精度）和指数构成，对0,1四舍五入。int可以稳式转换成float和double，float只能强制转换成int，但是可以隐式转换成double，double只能强制转换成float和int。
> ```
>
> 　　在说明问题之前，还很有必要温习一下计算机组成原理时学习到的一些知识，就是二进制补码表示以及浮点数表示。我想把一个十进制转化为二进制的方法已经不用多费唇舌，只不过为了计算方便以及消除正零与负零的问题，现代计算机技术，内存里存的都是***\*二进制的补码形式\****，当然这个也没什么特别的，只不过有某些离散和点，需要特殊定义而已，比如-(2^31)，这个数在int的补码里表示成1000…(31个零)，这个生套补码计算公式并不能得到结果（其实不考虑进位的话还真是这个结果，但是总让人感觉很怪）。再者，浮点数，其实就是把任何二进制数化成以0.1....开头的科学计数法表示而已。
>
> 　　废话说完，这就出现了几个问题，而且是比较有意思的问题。
>
> 
>
> ```html
> <span style="font-size:14px;">int i = Int32.MaxValue;
> float f = i;
> int j = (int)f;
> bool b = i == j;</span>
> ```
>
> 
>
> 　　这里的b，是false。刚才这个操作，如果我们把***\*float\****换成**long**，第一次进行**隐式转换**，第二次进行**强制转换**，结果将会是true。乍一看，float.MaxValue是比int.MaxValue大了不知道多少倍的，然而这个隐式转换中，却造成了数据丢失。int.MaxValue，这个值等于***\*2^31-1\****，写成二进制补码形式就是**01111…(31个1)**，这个数，在表示成float计数的科学计数法的时候，将会写成+0.1111…(23个1)*2^31，对于那31个1，里面的***\*最后\*******\*8\*******\*个\****，被float无情的抛弃了，因此，再将这个float强制转换回int的时候，对应的int的二进制补码表示已经变成了0111…(23个1)00000000，这个数与最初的那个int相差了**255**，所以造成了不相等。
>
> 　　那么提出另一个问题，什么样的int变成float再变回来，和从前的值相等呢？这个问题其实完全出在那23位float的数据位上了。对于一个int，把它写成二进制形式之后，成为了个一32个长度的0、1的排列，对于这个排列，***\*只要第一个\*******\*1与最后一个1之前的间距，不超过23，那么它转换成 float\*******\*再转换回来，两个值就会相等\****。这个问题是与大小无关的，而且这个集合**在****int****这个全集下并不连续**。
>
> 
>
> ```html
> <span style="font-size:14px;">double d = 0.6;
> float f = (float)d;
> double d2 = f;
> bool b = d == d2;</span>
> ```
>
> 
>
> 　　这里的b，也是false。刚才这个操作，如果开始另d等于0.5，结果就将会是true。乍一看，0.6这个数这么短，double和float都肯定能够表示，那么转换过去再转换回来，结果理应相等。其实这是因为我们用十进制思考问题太久了，如果我们0.6化成二进制小数，可以发现得到的结果是***\*0.10011001……(1001循环)\****。这是一个无限循环小数。因此，不管float还是double，它在存储0.6 的时候，都**无法完全保存它精确的值**（计算机不懂分数，呵呵），这样的话由于**float保存23位，而double保存52****位**，就造成了double转化成 float的时候，丢失掉了一定的数据，非再转换回去的时候，那些丢掉的值被补成了0，因此这个后来的double和从前的double值已经不再一样了。
>
> 　　这样就又产生了一个问题，什么样的double转换成float再转换回来，两个的值相等呢？其实这个问题与刚才int的那个问题惊人的相似（废话，都和float打交道，能不相似么），只不过我们还需要考虑double比float多了3位的指数位，太大的数double能表示但float 不行。
>
> 　　还有一个算是数学上的问题，什么样的十进制小数，表示成二进制不是无限小数呢？这个问题可以说完全成为数学范畴内的问题了，但是比较简单，答案也很明显，**对于所有的最后一位以****5****结尾的十进制有限小数，都可以化成二进制的有限小数**（虽然这个小数可能长到没谱）。
>
> 　　最后，一个有意思有问题，刚才说过0.6表示成为二进制小数之后，是0.1001并且以1001为循环节的无限循环小数，那么在我们将它存成浮点数的时候，一定会在某个位置将它截断（比如float的23位和double的52位），那么真正存在内存里的这个二进制数，转化回十进制，到底是比原先的十进制数大呢，还是小呢？答案是It depends。人计算十进制的时候，是四舍五入，计算机再计算二进制小数也挺简单，就是**0舍1****入**。对于float，要**截断成为****23****位**，假如卡在24位上的是1，那么就会**造成进位**，这样的话，存起来的值就比真正的十进制值大了，如果是0，就舍去，那么存起来的值就比真正的十进制值小了。因此，这可以合理的解释一个问题，就是0.6d转换成float再转换回double，它的值是0.60000002384185791，这个值是比0.6大的，原因就是 0.6的二进制科学计数法表示，第24位是1，造成了进位。
>
> 　　到了这里，仍然有一事不解，就是对于浮点数，硬件虽然给予了计算上的支持，但是它与十进制之间的互相转换，到底是如何做到的呢，又是谁做的呢（汇编器还是编译器）。这个东西突出体现在**存在内存里的数明显实际与****0.6****不等**，但是无论哪种语言，都能够在Debug以及输入的时候，将它**正确的显示成** **0.6****提供给用户**（程序员），最好的例子就是double和ToString方法，如果我写double d=0.59999999999999999999999999999，d.ToString()给我的是0.6。诚然，对于double来说，我写的那个N长的数与0.6在内存里存的东西是一样的，但是计算机，又如果实现了将一个实际与0.6不相等的数变回0.6并显示给我的呢？
>
> 
>
> 来源： <http://blog.sina.com.cn/s/blog_5c6f79380101bbrd.html>
>
>  
>
> 　　***\*(2) 单、双精度浮点型\****
>
> 　　● 由于c语言中的浮点值总是用双精度表示的，所以float 型数据只是在尾部加0延长为doub1e型数据参加运算，然后直接赋值。doub1e型数据转换为float型时，通过截尾数来实现，截断前要进行四舍五入操作。
>
> 　　***\*(3) char型与int型\****
>
> 　　● int型数值赋给char型变量时，***\*只保留其最低8位\****，高位部分舍弃。
>
> 　　● chr型数值赋给int型变量时， 一些编译程序不管其值大小都作正数处理，而另一些编译程序在转换时，若char型数据值大于127,就作为负数处理。对于使用者来讲，如果原来char型数据取正值，转换后仍为正值;如果原来char型值可正可负，则转换后也仍然保持原值， 只是数据的内部表示形式有所不同。
>
> 另有说法：
>
> 无符号数截断时，截断后数仍为无符号
>
> 有符号数截断时，***\*自动把截断后的数转换为无符号\****
>
> 　　***\*(4) int型与1ong型\****
>
> 　　● long型数据赋给int型变量时，将低16位值[送给](http://www.chinabyte.com/keyword/送给/)int型变量，而***\*将高16 位截断舍弃\****。(这里假定int型占两个字节)。
>
> 　　将int型数据送给long型变量时，其外部值保持不变，而内部形式有所改变。
>
> 　　***\*(5) 无符号整数\****
>
> 　　● 将一个unsigned型数据赋给一个占据同样长度[存储](http://storage.chinabyte.com/)单元的整型变量时(如：unsigned→int、unsigned long→long,unsigned short→short) ,**原值照赋**，内部的存储方式不变，但外部值却可能改变。
>
> 　　● 将一个非unsigned整型数据赋给长度相同的unsigned型变量时， 内部存储形式不变，**但外部表示时总是无符号的**。
>
> 　　/*例：赋值运算符举例 */
>
> 
>
> ```html
> <span style="font-size:14px;">　　main()
> 　　{ 
>             unsigned a,b;
> 　　    int i,j;
> 　　    a=65535;
> 　　    i=-1;
> 　　    j=a;
> 　　    b=i;
> 　　    printf(“(unsigned)%u→(int)%d ”,a,j);
> 　　    printf(“(int)%d→(unsigned)%u ”,i,b);
> 　　}</span>
> ```
>
> 　　运行结果为：
>
> 　　(unsigned)65535→(int)-1
>
> 　　(int)-1→(unsigned)65535
>
> 　　● 计算机中数据用补码表示，int型量最高位是符号位，为1时表示负值，为0时表示正值。如果一个无符号数的值小于32768则最高位为0,赋给 int型变量后、得到正值。如果无符号数大于等于32768,则最高位为1, 赋给整型变量后就得到一个**负整数值**。反之，**当一个负整数赋给unsigned 型变量时，得到的无符号值是一个大于32768的值**。
>
> 　　● c语言这种赋值时的类型转换形式可能会使人感到不精密和不严格，因为不管表达式的值怎样，系统都自动将其转为赋值运算符左部变量的类型。
>
> 　　● 而转变后数据可能有所不同，在不加注意时就可能带来错误。 这确实是个缺点，也遭到许多人们批评。但不应忘记的是：c面言最初是为了替代汇编语言而设计的，所以类型变换比较随意。当然， 用强制类型转换是一个好习惯，这样，至少从程序上可以看出想干什么。
>
> 
>
> 来源： <http://soft.chinabyte.com/database/282/12430782.shtml>

## 0x03 nullptr

Nullptr 严格来说并不是一个指针类型，他只是可以转换为任意指针类型。nullptr 不可以转换为非指针类型。

因此，将 nullptr 传给 int 是不合法的，double..，char同理。

如果存在多个指针，会有二义性错误，例如：

``` c++
#include <iostream>
using namespace std;
void f(int *) {
    cout << "int*";
}
void f(double *) {
    cout << "double *";
}
int main()
{
    f(nullptr);
    return 0;
}
```

上面的代码会二义性错误。



## 0x04 模板中的嵌套命名

在模板中，注意是必须是在模板中，使用嵌套类型，必须加 typename，这是因为模板实例话的过程中，不知道是将该 `::` 之后的内容解释为变量还是类型。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

template<typename T>
struct Foo {
    typedef T value_type;
    // 不能排出有 sb 将一个变量的名字搞得像一个 type。。。
    static const value_type fake_type = 1024; 
};

template<typename T>
struct Bar {
    void f() {
        // 去掉 typename 报错
        typename Foo<T>::value_type x = 1;
        cout << x << endl;
    }
    void g() {
        cout << Foo<int>::fake_type << endl;
    }
};

int main()
{
    Bar<int> b;
    b.f();
    return 0;
}
```

## 0x05 enum的前置声明

在 `gcc version 11.2.0 (Ubuntu 11.2.0-19ubuntu1)` 测试下，C 语言可以前置声明 enum，且不会报错。

但是书上说不可以。。

而且，C语言貌似不能指定 enum 的底层类型？下面代码在 c 编译不过，在c++正常运行。

``` c++
#include <stdio.h>
#include <stdint.h>

enum Boolean : int{
    A, B
};

int main()
{
    printf("%d", sizeof(A));
    return 0;
}
```

## 0x06 虚函数的返回类型

1.如果父类虚函数返回的是内建数据类型，那么派生类虚函数的返回类型要与父类严格一致，否则报错，没得商量。

对于这样的规则，相信我们都不会觉得有任何争议或者意外；

2.如果父类虚函数返回的是某个父类（可以是另外一个类，比如叫CBase）的指针或引用，那么派生类虚函数的返回类型可以是CBase类的派生类（比如叫CDerive1）的指针或引用。

规则到这里发生了一点变化，C++对于返回的指针或引用类型有个特殊照顾，会检查派生类返回的与基类返回的是否有向下派生的关系，一个非常有意思的设计，一些工厂模式的实现也正是利用了这一语法特性。

那么如果父类和派生类返回的引用或指针没有向下派生的关系，比如说父类返回的是CDerive的指针，而其基类返回的是CBase指针，此时编译器果断报错。

## 0x07 TODO：atomic p103



## 0x08 TOOD: <type_traits>



## 0x09 move 是一种请求

## 0x0a emplace_back 性能之外[TODO]

emplace_back 粗略的形式

``` c++
template<class T, class Allocator = allocator<T>>
class vector {
public:
    template<class... Args>
    void emplace_back(Args&... args);
}
```

我们注意到，emplace_back 的参数是可变模板参数列表，这导致了它与 push_back 巨大的差异，看下面代码：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Foo {
    Foo() = default;
    Foo(int _l, int _r) : l(_l), r(_r) {}
    int l, r;  
};

int main()
{ 
    vector<Foo> v;
    v.emplace_back(1, 2);
    // v.push_back(3, 4);	// 编译错误
    // v.emplace_back({7, 8}); // 编译错误
    v.push_back({5, 6});
    for(auto &x : v) {
        cout << x.l << ' ' << x.r << endl;
    }
    return 0;
}
```

我们定一个 struct Foo，他有两个成员以及一个构造函数和默认构造函数，然后我们定义了一个类型为 Foo 的 vector，如果我们想向 vector 添加一个 Foo 元素。

* 通过 push_back 添加时，必须使用花括号 {}
* 通过 emplace_back 添加时，不需要使用花括号，如果使用还会报错。

现在来解释一下，通过一开始我们给出的 emplace_back 的粗略实现，我们看到，它的可以接受任意参数，当我们传入参数的时候，它会挨个将这些参数放入相应的构造函数当中。而 push_back 不可以，它的实现应该是只能接受一个参数。即下面的形式：（我自己猜测的） ⚠️TODO,真正实现⚠️

```c++
template<class T, class Allocator = allocator<T>>
class vector {
public:
    template<class... Args>
    void push_back(const T& t);
}
```

也就是说，push_back 无法传入多个值，如果非要这么做的话，用花括号括起来，生成一个临时对象。

而 emplace_back 能支持传入多个参数，也与他的优化特性有关，因为它不需要构造临时对象，所以说，只需要值就行了，然后将值直接放到构造函数当中。

但是，正因如此，如果我们给 emplace_back 一个花括号，他会解释为 `initializer_list<>`，在 `effective modern c++`中文版第198页提到：

> 如果我们传入一个 initializer_list（`{1,2,3}`），而形参不是接受这样类型，编译器就会禁止从 `{1,2,3}` 出发推到推导类型。
>
> 这叫做“非推导语境”。
>
> 同时这种情况也是万能引用失效的一种情况。



## 0x0b 引用

非const左值引用只能接受左值，const 左值引用可以接受左值和右值。

非const右值引用只能接受右值，const右值引用只能接受右值。

## 0x0c 区分右值引用和引用的引用

`&` 连在一起就是右值引用，分开就是引用的引用。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int &&p = 1;    // 右值引用
    // int& &q = 1;    // 指向引用的引用
    // int & &r = 2; // 指向引用的引用
    int && s = 2; // 右值引用
    
    return 0;
}
```

## 0x0d 函数指针作为参数

可以像声明一个函数一样声明一个函数指针参数，这应该是语法的一致性问题，声明函数指针不需要加上 `*`，在调用函数指针的时候，也可以不加 `*`。

可以直接将函数名参数函数指针。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int add(int a, int b)
{
    cout << "call add()" << endl;
    return a + b;
}

// int f(int (*doAdd)(int,int), int a, int b)
int f(int doAdd(int,int), int a, int b)
{
    cout << "call f()" << endl;
    return doAdd(a, b);
}

int main()
{
    int res = f(add, 1, 2);
    cout << res << endl;
    return 0;
}
/*
call f()
call add()
3
*/
```

## 0x0e 常数传播和拓展 [TODO]

> [本文参考自 csdn，谁说csdn都是垃圾的，😠](https://blog.csdn.net/u012520854/article/details/125354719)

下面我们来看一段臭名昭著的代码（恶意修改敞const对象😠）

注意下面的是 C 语言书写并且用 gcc 编译：

``` c
#include <stdio.h>
int main()
{
    const int a = 10;
    int *b = (int*)&a;
    *b = 20;
    printf("%d\n", *b);         // 20
    printf("%d %d\n", a, *b);   // 20 20
    printf("%d %d\n", *&a, *b); // 20 20
}
```

入我们所料，const 对象 a 的值被我们通过指针卑鄙的修改为了 20.

再来看同样的代码，在 g++ 编译后的结果：(代码是一摸一样的，只不过换了编译期，因此只贴出结果)

``` c++
// 20
// 10 20 ❓
// 20 20
```

注意看我们用❓标识的地方，此时我们明明通过指针 b 的到了 a 的地址并且修改了 a 的值啊，为什么此时打印出来的 a 仍然是 10 呢？并且我们接下来，几乎是同样的方法 `a = *&a;` 再一次打印 a，结果却是 20 呢？

好吧，这是编译器优化（常量传播）惹的祸。

因为我们将 a 定义成一个 const 类型的对象，在编译的时候，a 就会告诉编译器说：“编译器大哥，我是常量，我是常量！”，于是编译器接受到了这个信息，并采取了一种优化 – <font color = blue>“常量传播”</font>，它会将所有用到 a 的地方，替换为 `0x14`，也就是 a 的值，只不过在编译器那里，是个 16 进制的值。

所以说，如果我们直接打印 a，得到的结果就是它初始化时的值。不信的话，我们再多测试一下：

``` c++
#include <stdio.h>
void f(int val)
{
    printf("function f(): a = %d\n", val);
}
int main()
{
    const int a = 10;
    int *b = (int*)&a;
    *b = 20;
    
    int c1 = a + 20;    // 10 + 20
    int c2 = a - 5;     // 10 - 5
    int c3 = a / 5;     // 10 / 5
    int c4 = a * 2;     // 10 * 2
    printf("%d %d %d %d\n", c1, c2, c3, c4);
    f(a);   // 10
    return 0;
}
```

入我们所料，所有使用 a 的地方都被替换为了 `0x14`。

你可能会问，既然 const 并不是真真正正的常量，它好像只是程序和编译器之间的一种“约定”，既然是约定，肯定是可以打破啊，那为什么编译器非要施行常量传播优化呢？

好吧，我想说，脑子但凡正常的人应该都不会写出通过指针卑鄙的修改 const 的代码，再说了，开头我们提到了，a 告诉编译器自己是一个“常量”了，如今又出尔反尔，“改变”了自己的值，这能怪编译器嘛😠。

但是，在`    printf("%d %d\n", *&a, *b);` 语句中，我们需要取到 a 的地址，再对地址上的值进行解释，这里编译器就无法进行常量传播了，编译器虽然很🐮，但是还没有智能到识别出这种优化。

>  我认为，对 a 取地址，和使用 a 完全是两码事！
>
> 对 a 取地址会得到一个指针，而指针也是个变量啊！
>
> 假设这个隐式指针是 p，无论是什么，他都不是 a 了，既然不是 a，编译器自然也就不会将他替换为 `014`了。

因此，它会老老实实的按照 a 的地址，找到它的值 `00000000000000000000000000001010`，（好吧，这串 01 序列看着有点头痛），编译期会把这串 01 序列按照 int 解释，结果就是 10 了。

我们可以再次测试一下：

``` c++
#include <stdio.h>
void f(const int *val)
{
    printf("function f(): a = %d\n", *val);
}
int main()
{
    const int a = 10;
    int *b = (int*)&a;
    *b = 20;
    
    f(&a);   // 20
    return 0;
}
```

我们将上面测试中的函数 f 改为传入一个指针，这时候，就需要去的 a 的地址，也就会把 a 解释为“正确”的值20了。

----

咦？似乎好像遗漏了一个地方！我们上面的套路都是机遇 g++ 编译器的，而在 gcc 编译器中，a 就是修改后的值，这是为什么啊？

猜测下原因，`const`是C从C++中借鉴的，真的只用于编译器检查，没有具体的优化动作。这就是所说，学只学得表象，未得其精髓😂。

----

**有关常量的编译器优化：**

> <font color = blue>常量传播(常量替换)</font>： 顾名思义，将能够在编译期计算出结果的变量直接替换为常量。
>
> <font color = blue>常量折叠</font>：故名思议，在编译优化时，多个常量进行计算时，而且能够直接计算出结果，那么该常量表达式的值将由常量直接替换。
>
> 例如：
>
> ``` c++
> int a = 1 + 2 + 3;	// a = 6
> cout << a << endl;
> ```

---

真常量``#define`和约定常量`const`。[参考自](https://blog.csdn.net/lc_910927/article/details/21110943)

> \#define定义的常量是真正的常量(保存在常量区)，而const却是由编译器判断实现的常量，是一个假常量。const常量本质上还是一个变量，只不过C++中提出的const机制在编译层面上对const常量提供了写保护，是为了防止意外修改。

----

[对于一个很复杂的常量表达式，编译器会算出结果再编译吗？](https://www.zhihu.com/question/55976094/answer/147302764)		[TOOD]⚠️

## 0x10 [结构化绑定 – c++17 – 不太懂](https://zhxilin.github.io/post/tech_stack/1_programming_language/modern_cpp/cpp17/structured_bindings/)

### 1. 概念

结构化绑定（Structured Bindings）：可以对数组 array，元祖 tuple，结构体 struct 的成员变量进行绑定。类似引用，结构化绑定是一个已存在对象的别名。不同于引用的是，结构化绑定的了类型不必为引用类型。

语法：

``` c++
attr(optional) cv-auto ref-qualifier(optional) [ identifier-list ] = expression;
attr(optional) cv-auto ref-qualifier(optional) [ identifier-list ] { expression };
attr(optional) cv-auto ref-qualifier(optional) [ identifier-list ] ( expression );
```

各个部分的说明如下：

1. attr：可选的属性序列
2. cv-auto：const/volatile/static …
3. ref-qualifier：&/&&
4. identifier-list：用逗号分隔的标识符名称的列表
5. initializer：包括 = expression/{expression}/(expression)三种初始化方式

结构化绑定声明将 identifier-list 中的所有标识符引入作为其外围作用域中的名字，并将他们绑定到 expression 所指代的对象中各个子对象或元素，这种绑定称为结构化绑定。

例如：

``` c++
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,int> m;
    auto &&[it, inserted] = m.insert({1, 1});
    if(inserted)
        cout << "inserted successfully!" << endl;
    for(auto &[k, v] : m)
        cout << "{" << k << "," << v << "}" << endl;
    return 0;
}
// inserted successfully!
// {1,1}
```

### 2. 结构化绑定的实现过程

1. 绑定数组：标识符的数量必须等于数组的元素个数
2. 绑定元组：标识符的个数必须要元素的大小相同
3. 绑定结构体：现有对象的别名







## 0x11 bind：传参还是传引用？

bind 对于非占位符传递的参数，都是传入他们的拷贝，即使函数是使用引用来接受的，例如：

``` c++
#include <iostream>
using namespace std;
using namespace std::placeholders;

struct Foo {
    int val;  
    Foo(int _val) : val(_val) {}
    Foo(Foo &f) : val(f.val) {
        cout << "copy ctor" << endl;
    }
};

void pass(Foo &f)
{
    f.val = 20;
}

int main()
{
    Foo obj(1024);
    auto f = bind(pass, obj);
    cout << obj.val << endl;
    return 0;
}
// copy ctor
// 1024
```

如果想传引用，我们必须加上 ref()，即：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

struct Foo {
    int val;  
    Foo(int _val) : val(_val) {}
    Foo(Foo &f) : val(f.val) {
        cout << "copy ctor" << endl;
    }
};

void pass(Foo &f)
{
    cout << &f << endl;
    f.val = 666;
}

int main()
{
    Foo obj(1024);
    cout << &obj << endl;
    auto f = bind(pass, std::ref(obj));
    f();
    cout << obj.val << endl;
    return 0;
}
// 0x7fff45c0cc24
// 0x7fff45c0cc24
// 666
```



## 0x12 sizeof-ptr/array

``` C+++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int *p = new int[10];
    int a[10];
    cout << sizeof(p) << endl << sizeof(a) << endl;
    //8, 40
    delete(p);
    return 0;
}
```



## 0x13 退出函数 

程序编译后执行过程是这样的：

1. 开工函数：初始化全局对象和全局static对象
2. main函数
3. 收工函数：自动析构开工时初始化的全局对象和全局static对象

abort, exit, return 做的事情。

1. return返回后会执行收工函数，会析构局部对象和static对象（heap不属于局部对象）

2. exit会执行收工函数，abort不会

3. exit和abort都不会自动析构局部非static对象

---

下面，我们分别声明global，auto，global static，auto static 共4个对象进行测试：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

struct Foo {
    Foo(string _s) : s(_s) {
        cout << "[ctor] ";
        cout << _s << endl;
    }
    ~Foo() {
        cout << "[dtor] ";
        cout << s << endl;
    }
    string s;
};

static Foo b("I am global static");	// (1)
Foo f("I am global");		// (2)

void func()
{
    cout << "f() begin()" << endl;
    static Foo bb("I am auto static");    // (3)
    Foo ff("I am auto");			// (4)
    cout << "f() end" << endl; 
    // return ;	// test1
    // exit(1);	// test2
    // abort();	// test3
}

int main()
{
    cout << "main() begin\n";
    func();
    cout << "main() end\n";        
    return 0;
}
```

运行结果

```shell
# return
[ctor] I am global static
[ctor] I am global
main() begin
f() begin()
[ctor] I am auto static
[ctor] I am auto
f() end
[dtor] I am auto
main() end
[dtor] I am auto static
[dtor] I am global
[dtor] I am global static
# exit(0)
[ctor] I am global static
[ctor] I am global
main() begin
f() begin()
[ctor] I am auto static
[ctor] I am auto
f() end
[dtor] I am auto static	## ！！
[dtor] I am global
[dtor] I am global static
# abort()
[ctor] I am global static
[ctor] I am global
main() begin
f() begin()
[ctor] I am auto static	## ！！
[ctor] I am auto	## ！！
f() end
Aborted	## ！！
```

在运行结果中我们可以发现

1. return 会析构全部四个对象，也就是说，它[啥都干]。

1. exit

   * 会执行收工函数析构（全局对象）和（全局static对象）

   * 析构函数内static对象
   * 不会析构局部对象，因为程序直接退出，栈没回收。

   也就是说，只“抛弃”当前函数内的非static局部。

2. abort

   * 不会执行收工函数，因为（全局对象）和（全局static读喜庆）不会析构
   * （局部对象）和（函数内static对象）也不会析构

   也就是说，它[啥也不干]。。



## 0x14 求值顺序和压栈顺序和评估求值

``` c++
int i = 1;
printf("%d, %d, %d\n", i ++ , ++ i, i ++ );
```

归于上面 printf 的结果，是未定义的。

你可能会问，printf 不就是一个参数，而参数的入栈顺序不是自右向左吗？怎么还是未定义行为呢？

是的，入栈顺序是如此，但是，入栈的是参数，我们需要先将上面的 printf 转换为下面的形式：

``` c++
int i = 1;
int tmp1 = i ++ ;
int tmp2 = ++ i;
int tmp3 = i ++ ;
printf("%d, %d, %d\n", tmp1 , tmp2, tmp3 );
```

> 函数调用的过程，要先计算所有实参的值，这一步就叫做<font color = blue>“评估求值”</font>，然后将实参的计算结果压栈。
>
> <font color = blue>C++ 并未规定评估求值的顺序。</font>

因此，对于 tmp[1,2,3] 的求值顺序是不确定的，也就是说，计算机可能先求 tmp2，在求 tmp3，最后求 tmp1，或者先求 tmp3都是有可能的。

因此说，上面的 printf 的结果未定义，是因为求值顺序的未定义导致的。因此说，下面的也是未定义行为：

`int i = (j ++)  + j;`



## 0x15 智能指针的尺寸问题 [TODO P119]



## 0x16 shared_ptr 注意事项

[本文参考自](https://blog.csdn.net/m0_51955470/article/details/118075384?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0-118075384-blog-116194213.pc_relevant_3mothn_strategy_and_data_recovery&spm=1001.2101.3001.4242.1&utm_relevant_index=3)

1.不能使用一个原始地址初始化多个共享智能指针

> 否则会导致多次析构函



2.函数不能返回管理了 this 的共享智能指针对象

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

struct Foo {
    shared_ptr<Foo> getSharedPtr() {
        return shared_ptr<Foo>(this);
    }
    ~Foo() {
        cout << "Dtor" << endl;
    }
};

int main()
{
    shared_ptr<Foo> sp1(make_shared<Foo>());
    cout << sp1.use_count() << endl;    // 1
    shared_ptr<Foo> sp2 = sp1->getSharedPtr();  
    cout << sp2.use_count() << endl;    // 1
    exit(0);
    return 0;
}
```

> 上面的代码会 【doublefree】
>
> 通过 ues_count 我们可以发现，sp2 并未共享 sp2。
>
> 这是因为，sp2并非直接使用sp1来初始化，它通过sp1的this指针来初始化，所以编译器认定sp2并未共享sp1。
>
> 也就是说，我们通过一层间接性迷惑了编译器。。。

这个问题可以通过 weak_ptr 来解决，通过 wek_ptr 返回管理 this 资源的共享智能指针对象 shared_ptr。C++11 中为我们提供了一个模板类叫做 std::enable_shared_from_this，这个类中有一个方法叫做 **shared_from_this()**，通过这个方法可以返回一个共享智能指针，在函数的内部就是使用 weak_ptr 来监测 this 对象，并通过调用 weak_ptr 的 lock() 方法返回一个 shared_ptr 对象。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

// 继承该模板类
struct Foo : public enable_shared_from_this<Foo> { 
    shared_ptr<Foo> getSharedPtr() {
        return shared_from_this();
    }
    ~Foo() {
        cout << "Dtor" << endl;
    }
};

int main()
{
    shared_ptr<Foo> sp1(make_shared<Foo>());
    cout << sp1.use_count() << endl;    // 1
    shared_ptr<Foo> sp2 = sp1->getSharedPtr();  
    cout << sp2.use_count() << endl;    // 2
    return 0;
}
```



3.共享指针不能循环引用

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

struct A;
struct B;

struct A { 
    shared_ptr<B> pa;
    ~A() {
        cout << "DtorA" << endl;
    }
};
struct B { 
    shared_ptr<A> pb;
    ~B() {
        cout << "DtorB" << endl;
    }
};


int main()
{
    shared_ptr<A> spa(new A);
    shared_ptr<B> spb(new B);
    cout << spa.use_count() << endl;
    cout << spb.use_count() << endl;
    spa->pa = spb;
    spb->pb = spa;
    return 0;
}
// 
```

此时 spa 和 spb 就形成了环状引用。其内部大概是如图所示：

![img](https://s3.bmp.ovh/imgs/2023/03/11/770d8d28914ddff7.jpg)

如图，我们要删除 spa，就要断开 pb 指向 spa 的链接，而要断开 pb 指向 spa 的链接，就要析构 pb，而要析构 pb，就要析构 spb，而要析构 spb，就要断开 pa 指向 spb 的链接，而要断开 pa 指向 spb 的链接，就要析构 spa，绕了一圈又绕回来了，还啥都没解决 😅。

> 注意，所谓的环状引用并不是说，有两个共享指针 a 和 b，a 指向 b，b 指向 a，这是不可能的。
>
> 而是说，a内部有个 sa，b内部有个sb，sa指向b，sb指向a，是他们内部的对象和a与b之间构成了环，而不是a与b构成了环。
>
> 即，真正的环应该如下图所示：
>
> ![cycle](https://s3.bmp.ovh/imgs/2023/03/11/ec692ded37d8cf56.jpg)

在 spa 和 spb 离开作用域之后，他们的引用计数都是1，就会发生资源泄漏。解决方法就是使用 weak_ptr：

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <memory>

using namespace std;

struct A;
struct B;

struct A { 
    weak_ptr<B> pa;
    ~A() {
        cout << "DtorA" << endl;
    }
};
struct B { 
    weak_ptr<A> pb;
    ~B() {
        cout << "DtorB" << endl;
    }
};


int main()
{
    shared_ptr<A> spa(new A);
    shared_ptr<B> spb(new B);
    cout << spa.use_count() << endl;    // 1
    cout << spb.use_count() << endl;    // 1
    spa->pa = spb;
    spb->pb = spa;
    cout << spa.use_count() << endl;    // 1
    cout << spb.use_count() << endl;    // 1
    return 0;
}
```

可见，weak_ptr 并不会增加引用计数。spa 和 spb 成功析构。

## 0x17 weak_ptr 推迟析构 p139



## 0x18 lambda 表达式杂项

### 1. 谓词

返回 bool 类型的放函数称为“谓词”

如果 operator() 接受一个函数，叫做一元谓词

如果 operator() 接受两个函数，叫做二元谓词

### 2. 闭包(closure)

wiki定义：

> *In programming languages, a **closure**, also **lexical closure** or **function closure**, is a technique for implementing **lexically scoped name binding** in a language with **first-class functions***

简单来说，闭包是指「带有状态的函数」，这里的状态指的是调用环境的上下文。一旦函数带上了状态，它就是闭包。这里的“带上状态”，意思是这个闭包拥有属于自己的变量，这些变量的值在闭包创建的时候设置，并在调用闭包的时候，可以访问这些变量。函数是代码，状态是一组函数外部的变量，将它们绑定在一起，就形成了闭包。这个绑定的过程发生在运行时。所以闭包具有捕获并持有外部作用域变量的能力。

闭包只有在被调用时才执行操作，或者说运行时被捕获，即惰性求值，所以闭包可以被用来定义控制结构。

lambda 表达式在运行时就会创建一个闭包。

### 3. 闭包类

闭包类就是实例话闭包的类，每个lambda表达式都会触发编译器生成一个独一无二的闭包类。

### 4. 全局变量

lambda 可以无需捕获就是用全局变量，例如：

``` c++
#include <iostream>
using namespace std;

static int x = 10;
int y = 20;

int main()
{
    auto f = []() {
        cout << x << ' ' << y << endl;
    };
    f();
    return 0;
}
```



## 0x19 通过模板推导返回数组大小

``` C++
#include <iostream>
#include <map>
using namespace std;

template<typename T, size_t N>
constexpr size_t getSize(T (&arr)[N]) noexcept   // 必须是引用
{
    return N;
}

int main()
{
    int a[3] = {1, 2, 3};
    int b[getSize(a)] = {1, 2, 3};
    for(int i = 0; i < getSize(b); i ++ )
        cout << b[i] << endl;
    return 0;
}
```

## 0x1a vector\<bool>

``` c++
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<bool> v;
    for(int i = 0; i < 10; i ++ )
        v.push_back(i);
    for(int i = 0; i < 10; i ++ )
        cout << v[i] << ' ';
    cout << endl;
    for(int i = 0; i < 10; i ++ )
        cout << sizeof(v[i]) << ' ';	// 16
    cout << endl;
    cout << sizeof(v) << endl;
    return 0;
}
// 0 1 1 1 1 1 1 1 1 1 
// 16 16 16 16 16 16 16 16 16 16 
// 40

```

我们对 v[i] 取 size，得到的结果是 16，dddd。

vector\<bool> 并不是 bool



## 0x1b Compiler Optimization

>  [本文参考自](https://oi-wiki.org/lang/optimizations/)

什么是优化：在保持语义不变的情况下，对程序运行速度、程序可执行文件大小做出改进。

常见的编译器优化：

1. Constant Folding（常量折叠），如果一个表达式可以确定为常量，在他的下一个定义前，可以进行常量传播。

2. Deadcode Elimination（死代码消除），顾名思义，就是一段代码没用上就会被删除。
3. Loop Rotate（循环旋转），将循环从 for 形式，转换为 do-while 形式，前面再多加一个条件判断。这个变换主要为其他变换做准备。
4. Loop Invariant Code Motion（循环不变量外提），与上面的循环旋转联系起来了。
5. Loop Unroll（循环展开）。
6. Loop Unswitching（循环判断外提）。
7. Code Layout Optimization（代码布局优化），冷热代码分离，不要穿插，可以使用函数分离冷代码。
8. Function Inlining（函数内联），函数内联有时可能更慢。
9. Tail Call Optimization（尾调用优化），如果函数调用位于函数尾部，我们可以不保留外层函数的调用记录，直接用内层函数取代。
10. Strength Reduction（强度削减）
11. Auto-Vectorization（自动向量化）
12. inline 关键字在现代 C++ 被当作是一种链接、与导出符号的语义行为，而不是做函数内联。是否内联由编译器自行决定。
13. 现代编译器会直接忽略你的 `register` 关键字，你自己认为的寄存器分配一般没有编译器直接跑寄存器分配算法来的聪明。此关键字于 C++11 被弃用，于 C++17 被删除[1](https://oi-wiki.org/lang/optimizations/#fn:p0001r1)。



## 0x1c sanitizer

>  [ref other](https://wizardforcel.gitbooks.io/100-gcc-tips/content/address-sanitizer.html)
>
> [ref main](https://oi-wiki.org/lang/optimizations/#always_inline__force_inline)

理智保证器。在运行时检查你的程序是否有未定义行为、数组越界、空指针，等等功能。 在本地调试模式下，建议开启一些 sanitizer，可以极大缩短你的 Debug 时间。这些 sanitizer 由 Google 开发，绝大多数可以在 GCC 和 Clang 中使用。sanitizer 在 LLVM 中更加成熟，因此推荐选手本地使用 Clang 编译器进行相关除错。

### 1. Address Sanitizer -fsanitize=address

`gcc -fsanitize=address -g -o a a.c`

- 越界
- 释放后使用 (use-after-free)
- 返回后使用 (use-after-return)
- 重复释放 (double-free)
- 内存泄漏 (memory-leaks)
- 离开作用域后使用 (use-after-scope)

应用这项检查会让你的程序慢 2x 左右。

### 2.Undefined Behavior Sanitizer -fsanitize=undefined

- 位运算溢出，例如 32 位整数左移 72 位
- 有符号整数溢出
- 浮点数转换到整数数据溢出





## 0x1d









































