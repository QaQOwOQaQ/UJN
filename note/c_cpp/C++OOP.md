



# C++ OOP

## 1. complex design

在class内定义的函数自动inline（inline只是对编译器的一种建议）

ctor的返回类型肯定是该class对象，所以无需写返回值

initialization list

overloading，overwrite

关于const的重载（const参数，const函数）

在单例模式中会把ctor设置为private

const对象只能调用const版本，non-const对象可以调用const和non-const版本

相同class的各个object互为友元

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数，因此在类中定义友元函数时，访问权限实质上并不对友元函数构成任何约束关系（但一般将其声明为private）

C++操作符就是个函数

所有成员函数都有一个隐藏的参数（this指针，指向调用的类对象）

引用相较于指针的一个好处就是传送者只需要传值（无需特殊符号），而无需考虑接受者是否以引用形式接收

typename()：创建临时对象，例如int()

运算符重载，根据是否需要用到this指针来决定放到全局还是class内，例如当我们执行 `cout << 1 << endl;` 时，意为通过`cout`对象调用`operator<<`，并传入参数`1`，因此说，重载输入输出运算符时，用不到输出对象的this指针，因此不能将其声明为类的成员函数，一般是声明为类的友元函数。

为什么重载输出运算符要返回引用？首先，通过返回引用可以在链式调用时避免临时对象的创建和销毁。其次，在C++中，设计重载运算符时，一个重要的原则就是尽量使自定义类型的行为与内置类型的行为一致。这样不仅使自定义类型的使用更自然，而且能够更好地融入C++语言的生态，提升语言的表达能力。返回引用正是遵循了这一原则。例如，内置类型的赋值操作返回的就是赋值后变量的引用，这使得连续赋值成为可能。通过使自定义类型的赋值运算符重载也返回引用，可以模仿这一行为，让自定义类型在使用时更加符合人们的直觉。例如，`(x=y)=z;`这条语句，在C++内置的int类型中，最后`x=z`，即`x=y`返回了`x`的引用，如果返回的是`x`的值，那么最后结果为`x=y`。

重载operator+时需要考虑隐式类型转换，例如我们封装了一个整数类型对象，如果我们将operator+声明为类的成员函数，那么`1+obj`似乎就不合法，因为整数1的operator+并没有针对obj的重载。因此此时将obj的operator+声明为友元函数更好。

## 2. string design

BigThree：拷贝构造，拷贝赋值，析构。当类中有指针时，需要重写这三个成员函数。

字符串长度的两种设计思路：`\0`结束符或者没有结束符但有一个整数表示长度。

检测self assignment。

----

ctor和dtor的行为如下：

``` C++
Complex *pc = new Complex(1, 2);
------------------------------>compile transfer
Complex *pc;
void *mem = operator new(sizeof(Complex));//分配内存
pc = static_cast<Complex*>(mem);//转型
pc->Complex::Complex(1, 2);//构造函数

delete pc;
------------------------------>compile transfer
Complex::~Complex(pc);//调用析构函数
operator delete(pc);//释放内存
```

 最后，要注意，我们不能显示直接调用ctor，这是标准所规定的，`Because constructors do not have names, they are never found during name lookup;`

----

内存块规定大小的一个好处：例如我们规定，内存块必须是16byte的倍数，那么二进制下，有4个bit是用不到的，这4个bit就可以另作他用，例如使用一个bit来标记这个内存块是否被使用。

如果我们不使用array delete去删除array new分配的内存，在我的电脑上测试，只会delete掉array[0]，说明此时delete会释放掉一些内存。

## 3. static

静态数据：与对象脱离，单独存放在内存中的一个区域，并且只有一份，注意在class中对于静态数据仅仅只是声明（如果是const则可以直接定义），对非静态数据成员是既声明又定义，因此在class外还需要对静态数据进行定义（分配内存）。另外就是这个定义必须是全局的而不是局部的，也即不能在函数中定义静态数据。（？？？）

静态函数：主要特征是没有this指针，因此用来处理静态数据，静态函数也可以被类实例以成员函数的形式调用。

分配内存的叫定义，声明只是说明了变量的数据类型和属性。

## 4. class relationship

composition表示has-a关系，关系双方的生命周期是同步的

delegation`/`composition by reference(pointer)`/`handler&body`/`pointer-to-implentation(pImpl)关系双方的生命周期不同步，因为指针可能没有指向一个对象。委托的好处是，通过指针指向不同的实现类对象，可以在不改变当前类的前提下实现不同的行为

inheritance表示is-a关系

## 5. convert function

转换函数没有return type，因为返回类型一定是你要转换的那个类型，并且一般要加上const

## 6. non-explicit-one-argument-function

小心隐式类型转换

## 7. pointer-like class

* 智能指针
* 迭代器

`->` 符号会传递（人为规定的，就是为了方便重载`->`）

`operator->`返回指针，``->``会传递

`operator*`返回引用

## 8. function-like class

所谓仿函数（functors）

## 9. template

成员模板，常用于处理派生，类型转换

模板特化，模板偏特化(个数/范围.e.g指针)

模板模板参数

注意标准库的容器一般有多个模板参数

## 10. standard library

container，algorithm，iterator，functors

## 11. varadic templates

注意`...`的位置

``` c++
void print() {}

template<typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    cout << firstArg << endl;
    print(args...);
    cout << "count of rest:" << sizeof...(args) << endl;
}

int main()
{
    print(__cplusplus, 1, 3.14, complex(1, 2));
    return 0;
}
```

## 12. ranged-base for

需要注意尽量使用传引用，引用相当于别名，且不可更改，java中所有对象都是reference

## 13. object model

子类对父类虚函数继承的仅仅只是使用权（地址，知道了函数的地址便可以使用函数），函数本身在内存中只有一份。

## 14. dynamic binding

指针+向上转型+虚函数

## 15. placement operator new/delete

我们虽然可以重载 member placement operator delete，但它们绝不会被delete调用。只有当new所调用的ctor抛出exception，才会调用这些重载版本的operator delete，主要用来归还未能完全创建成功的对象所占用的memory（理论上？）。