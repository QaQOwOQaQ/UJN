# Qt

## Ref

[基础教程视频](https://www.bilibili.com/video/BV1g4411H78N/?p=1&vd_source=38033fe3a1f136728a1d6f8acf710b51)

[QT项目的编译，运行，发布](https://www.cnblogs.com/xieweikai/p/6817739.html)

## English

* widge: 小工具
* pixel：像素
* compat: 兼容，相容
* codec: 编码译码器

## Shortcut Key

* ctrl + r ： 运行
* ctrl + b ： 编译
* ctrl + f ： 查找
* ctrl + shift + ↑/↓ ： 平移一行
* ctrl + i : 自动对齐
* F4 : 同名 .h 和 .cpp 文件的切换
* D:\qt_cpp\5.14.2\msvc2015_64\bin ： 帮助文档



## QA

### 1. 解决 Qstring 输出引号

Debug 模式下，Qstring 类型会输出引号的问题：先将 Qstring 转成 QByteArray 再转成 char*

``` c++
Qstring str;
QDebug() << str.toUtf8().data();
```



## 0x01 基础构件

### 1 main.cpp

Qwidget 父类，QMainWindow， QDialog  

``` C++
// main.cpp
#include "mywidget.h"
#include <QApplication> //  包含一个应用程序类的文件

int main(int argc, char *argv[])
{
    // a为应用程序对象,有且仅有一个
    QApplication a(argc, argv);
    // 窗口对象，默认不显示
    myWidget w;
    w.show();
    // 让应用程序对象进入消息循环
    return a.exec();
}
```

### 2  project_name.pro 

* `.pro` project 文件

* `.sln` solution

``` shell
QT       += core gui
# qt 包含的模块：core & gui
# 此外还有比如 network 等模块 ... 

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# qt 版本>4，包含模块 widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mywidget.cpp

HEADERS += \
    mywidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

```

### 3. project_name.h

``` c++
#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QMainWindow>

class myWidget : public QMainWindow
{
    // 允许代码中使用信号和槽机制
    Q_OBJECT

public:
    myWidget(QWidget *parent = nullptr);
    ~myWidget();
};
#endif // MYWIDGET_H
```

### 4. object tree

对象树的主要目的：当父类被释放之后，也会调用其孩子的析构函数，注意这里的父类并不是继承意义上的父类。

我们可以把 dtor 过程理解为树的后序遍历，也就是会先析构孩子，最后析构父亲。

对象树实际上简化了垃圾回收机制，所有 Qobject 的孩子都会自己会动内存。

### 5. Qt window 坐标系

``` C++
(0.0) --> (X)
|
↓
(y) 
```

## 0x02 signal & slot

类似 js 中的事件。可以理解为，发送方发出信号，送到接收方的槽里面。信号和槽既可以是自定义的，也可以是内置的。

信号槽机制的优点是，松散耦合，信号发送端和接收端本身是没有关联的，通过 connect 连接将两端耦合在一起。

`connect(信号的发送者, 发送的具体信号, 信号的接收者, 信号的处理(槽))`

注意具体信号所属对象可以不是信号的发送者，例如不同 class button，他们发出的 click 信号都是一样的，因此可以这么写：

`connect(mbtn, &QPushButton::clicked, this, &QWidget::close);`

其中，`mbtn` 的 class 类型是 `myPushButton`

----

信号也可以直接连接信号

一个信号可以连接多个槽函数

信号和参数个数可以大于槽函数的参数个数，但是类型必须一一对应，也就是说，信号中的参数槽可以不处理，但是槽要处理的参数信号必须给出，要注意内置信号也有参数，例如 `clicked` 信号就有一个 bool 参数



## 0x03 lambda & auto

使用 lambda 的一个好处就是，我们可以通过 lambda 的参数捕获机制获取参数，而不是将参数传递进来，这样就可以避免 signal 和 slot 的参数匹配限制，更好的实现 slot 的功能。否则，例如按钮的 click 事件，我们只只能 connect 一个无参 or 只有一个 bool 参数的 slot function

qt 支持 auto，事实上，在 `.pro` 文件中，我们有这么一行：

``` SHELL
CONFIG += c++11
```

## 0x04 dialog

对话框分类：

1. 模态对话框 exec：阻塞模式，打开之后不可以对其他窗口进行操作
2. 非模态对话框 show：非阻塞模式，打开之后可以对其他窗口进行操作

当模态对话框和非模态对话框都是 stack 上的变量时，非模态对话框会一闪而过，因为当函数结束之后，它作为局部变量释放了，那么对话框自然就消失了。但是模态不会，因为模态会阻塞程序的执行（阻塞到 exec 指令）。如果我们希望保留非模态对话框，可以将其分配在 heap 上。这样 slot 函数执行结束之后，对话框会保留，并且我们还可以进行其他操作。

但是上面那样做会产生一个问题，就是 Qt 虽然有垃圾自动回收机制，但是要等到父类释放子类才会释放，对于 dialog 来说，它的父类是最高层的 Object。那么，如果我们在函数内部声明了 heap 上的 dialog 对象，那么当函数执行结束，且程序未结束期间，dialog 的内存实际上是泄露了的，也就是说，如果我们此时打开并关闭了 1000 个 dialog 窗口，那么我们就泄露了 1000 份 dialog 内存，直到整个窗口被关闭时才会被释放。因此我们需要对非模态的对话框添加一个属性 `Qt::WA_DeleteOnClose`

> 可以发现，`exec()` 都是阻塞执行函数，例如 main 中的 `exec()` 也是阻塞执行。



## 0x05 layout

所谓“栅格布局”，就是按照几行几列的的布局（既垂直布局，又水平布局）

## 0x06 controls

button

* tool button 主要是用于显示图片的

* radio button 单选按钮

* click button 多选按钮

tree

* 感觉像表格？

input widgets

* Combo Box 下拉框
* font Combo Box 字体下拉框
* Line Edit 单行文本
* Text Edit 多行文本
* Plain Text Edit 纯文本（无颜色，粗体，斜线，下划线…）
* Spin Box 整形数字递增器
* Double Spin Box 双精度数字递增器
* Time Edit 
* Date Edit
* Date/Time Edit
* Dial 旋转按钮
* Horizontal Scroll Bar  滚动条
* Vertical Scroll Bar
* Horizontal Slide 进度条
* Vertical Slide
* Key Sequence Edit ??

dijplay widget

* 自定义控件，注意父类可以是类体系中的子类，而构造函数中的参数最好是基类，因为基类既可以接受基类也可以接受基类的子类

* label 可以显示文字，图片，gif 动图

  > - 使用`setPixmap()`来显示图像时，你直接处理的是像素数据，这对于图像和图标的显示非常有效率。
  > - 使用`setPicture()`则是处理一个绘图命令序列的重放，这对于复杂的图形绘制和跨多个渲染目标的绘图操作重用更加适合。

self define widget：相当于是把一个自定义ui作为我们的子当以控件

* qt 设计师界面，添加新 ui
* 通过“提升为”添加子自定义控件

## 0x07 QEvent

实现 Qt 中的事件通常要自定义一个控件

## 0x08 类提升中的全局包含

打勾✔后ui_xxx.h 包含的时候就是 <>

```cpp
#include <xxxxxx.h>
```

不打勾就是 “”

```text
#include "xxxxx.h"
```

## 0x09 定时器

两种定义计时器的方法

## 0x0A 事件过滤

``` c++
		app
        ↓
        fliter
        ↓
        event
 /       /      \
event1   event2   event3
```

### 1. event

`bool event(QEvent *e)`

event 相当于所有 event 的一个上层 “抽象”/“中介”？

### 2. filter

1. 给控件安装 fliter
2. 重写 eventfilter

## 0x0B 绘图

painterDevice 用来表示你要画在哪，是在当前窗口（this），还是其他地方

``` C++
QPainter -> QPainterEngine -> QPaintDevice 	
```

色深（灰度值）

> 一般来说，像素的灰度值为 0~255
>
> * QPixmap：0~255
> * QBitmap: 0 / 255(白 / 黑)

 注意 QPicture 并不是用来显示图片的，QImage 才是

## 0x0C 文件处理

`class codeForName` 找不到的解决方法：

> 在  `.pro` 文件中加上 `QT += core5compat`

qFile 默认支持的格式是 UTF-8，因此如果不是这个格式需要转格式
