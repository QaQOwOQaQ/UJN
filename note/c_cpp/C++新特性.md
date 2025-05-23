

# 现代C++语言核心特性解析

## 1. variadic template

variadic: variable parament number and variable type which can be different

通过可变参数+递归实现一些操作

* 泛化和特化？

* hash？

* tuple？





## 2. nullptr

避免了C中NULL定义为0，而0是个整数类型的问题，nullptr的类型是`std::nullptr_t`

## 3. uniform initialization

为了解决C++之前初始化混乱（赋值号，小括号`parentheses`，大括号`braces`）的问题，C++11统一使用大括号来初始化。

``` C++
vector<int> vec{1, 2, 3};
int values[] {1, 2, 3};
```

例如上面的初始化就没有使用到小括号和赋值号 

大括号初始化的实质就是将 `{}` 里面的内容转化为一个 `initializer_list<T>` 来实现的，其内部是一个 `array<T,n>`，如果接收参数也是 `initializer_list<T>`，直接传过去，否则逐个分解在传过去。

如果使用`{}`进行初始化，则不能`narrowing convert`,由此可见统一初始化比较严格。

现在标准库中绝大多数算法和容器都能接受`initializer_list<T>`

## 4. explicit

* explicit for ctor taking one argument
* explicit for ctor taking more than one argument(暂时不知道有啥用)

无论是内置类型还是类类型，都支持这 4 种形式的初始化：

```cpp
int i1=0;   // (1)
int i2={0}; // (2)
int i3{0};  // (3)
int i4(0);  // (4)

std::string s1="hello";   // (1)
std::string s2={"hello"}; // (2)
std::string s3{"hello"};  // (3)
std::string s4("hello");  // (4)
```

C++ 通常会对 (2)(3) 两种形式做相同的处理，除了以下几种特殊情况：

- (2)不可用于构造函数初始值列表，而(3)可以
- 使用 auto 自动推导类型时，(2)(3)两种形式推导的结果不同：
  - auto i2 = {0}; // (2) i2 类型推导为 std::initializer_list
  - auto i3 {0}; // (3) i3 类型推导为 int
  - auto m2 = {0,1}; // (2) m2 类型推导为 std::initializer_list
  - auto m3 {0,1}; // (3) error: initializer for variable 'm3' with type 'auto' contains multiple expressions
- 对于不可拷贝对象（如 thread、atomic），(2)(3)结果不同
  - thread t2={f}; // error: chosen constructor is explicit in copy-initialization
  - thread t3{f}; // ok

## 5. alias template

## 6. template template argument

## 7. noexcept

move function注意不要抛出异常，否则容器（e.g. vector）不会调用

## 8. override,final

用于告诉编译器来帮你检查语法是否正确

final既可用于修斯class继承，也可用于修饰函数覆写

## 9. decltype

define a type equivalent to the type of an expresstion

1. declare return type
2. metaprogramming  
3. pass the type of a lambda: the type of lambda may be difficult to define

> 容器的比较函数传过去的应该是type

## 10. lambda

lambda **allowing** the definition of inline funtionality

``` c++
// 格式
auto f = [...](...)mutable throwSpec -> retType {
    ...
}
```

lambda的经典错误：

``` c++
int main()
{
    int id = 0;
    auto f = [id]() mutable {
        cout << id << endl;
        ++ id;
    };
    id = 10;
    f();
    f();
    f();
    cout << "id: " << id << endl;
    return 0;
}
```

误认为三个`f()`打印出来的值为10，11，12，其实是0，1，2。这是因为`f`看不到它后面的`id=10`，其实从lambda的本质能更好的看出：

``` c++
class Functor {
private:
    int id;
public:
    void operator()() {
        cout << id << endl;
        ++ id;
    }
};
```

当lambda创建的时候，它相当于直接把id作为他的非const数据成员了，后续对id的更改都是对它自己的那个id的更改，因此说它对外部的id无影响。

mutable的意思是，**可以在lambda中修改外部的数据，但修改之后的结果并不会同步到外部的数据。**

但如果是引用的话，后续对id的更改对lambda可见。

但要注意的是，lambda虽然神似functor，但它本质上依然不是functor？它没有默认构造函数等

## 11. non-type template parameters

例如array，他会传入一个整数表示array的大小，这就是非类型模板参数

## 12. tuple

实现tuple？

继承不会增加子类的空间

## 13. rvalue reference

rvalue can help solve the problem of unnecessary coping and enable pefect forwarding.

* lvalue: 可以出现在operator=左侧
* rvalue：只能出现在operator=右侧

you need to inform C++ that your move ctor and dtor does not throw exception.

底层实现是通过指针的浅拷贝，需要注意的是在浅拷贝之后，将原指针置为NULL，否则后续原指针所指对象生命结束时，可能把数据销毁，导致悬挂指针。

左值如何实现右值引用？`std::move()`

## 14. perfect forwarding 

perfect forwarding allows you to weite a single **function template** that takes n arbitrary arguments and forwards them transparently to another arbitrary funtion. The nature of the arguments(e.g. modifiable, const, lvalue, rvalue) is perserved in this forwarding process.

实现？		

## 15. array

数组的typedef：

``` C++
typedef int T[100]; 
T a;
```

## 16. hash

经验：当元素个数大于桶的个数，就将桶的个数扩展为原来的两倍

任意复杂类型的哈数值都可以表示为基本类型hash值的组合