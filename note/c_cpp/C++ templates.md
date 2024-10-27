# C++ templates

## Preface

## English

instantiation：实例化

paradigm：范例

## P1 基础

### 1. 函数模板

当自定义的函数和 `std` 的函数名重复时，使用 `::` 调用我们定义的全局函数。

``` c++
template<typename T>
inline T const& max(T const& a, T const& b)
{
    cout << "max\n";
    return a < b ? b : a;
}

int main()
{
    cout << ::max(1,2) << endl;
    return 0;
}
```

模板会被编译两次：

1. 实例化之前，先检查模板代码本身，查看语法是否正确。
2. 实例化期间，检查模板代码，查看是否所有的调用都有效，例如某些类型可能无法调用某些函数，以及类型是否匹配，在上面的例子中，如果我们传入两个不同的类型，就会编译错误。

模板类型可以显示制定，例如下面形式编译可以通过：

``` c++
int i= 1;
double d =3.13;
cout << ::max<double>(i, d) << endl;
```

为了解决参数必须相同的问题，我们可以指定两个模板参数，但是我们必须指定返回类型，指定返回类型比较麻烦：

``` c++
template<typename T1, typename T2>
inline auto max(T2 const& a, T1 const& b) -> decltype(a + b)
{
    return a < b ? b : a;
}

int main()
{
    cout << ::max(3, 3.13) << endl;
    return 0;
}
```

另外，你还可以重载模板函数，但要确保函数模板的所有重载版本的声明都位于它们被调用的位置之前。



