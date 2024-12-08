## ref

[bilibili 视频讲解](https://www.bilibili.com/video/BV14s4y1g7Zj/?spm_id_from=333.337.search-card.all.click&vd_source=38033fe3a1f136728a1d6f8acf710b51)	 [配套教程（上）](https://subingwen.cn/cmake/CMake-primer/)	 [配套教程（下）](https://subingwen.cn/cmake/CMake-advanced/)

[官方文档-en](https://cmake.org/cmake/help/v3.26/manual/cmake-commands.7.html) 	[民间？中文文档](https://runebook.dev/zh/docs/cmake/-index-)

[book: CMake Cookbook -ch](https://www.bookstack.cn/read/CMake-Cookbook/content-preface-preface-chinese.md)	

[book: Modern CMake -ch](https://www.bookstack.cn/read/Modern-CMake-CN-Modern-CMake-zh_CN/08ad6f6237beace2.md)

## QA

要注意关于库的函数中，主要是两类：

1. 构件库 `add_library`
2. 链接到已经构建的库 `target_link_libraries`, `link_libraries`

此外可以通过 `set(LIBRARY_OUTPUT_PATH)` 修改构建出的库的路径

## TODO_Blog

[message()](https://blog.csdn.net/hp_cpp/article/details/110373926)

[动态库链接选项](https://zhuanlan.zhihu.com/p/493493849)

[动态库链接选项/传递性](https://chunleili.github.io/cmake/understanding-INTERFACE)

## makefile

cmake 是一个构建工具，它用来构建马克file。

makefile 不能跨平台，cmake根据不同的平台生成不同的makefile

cmake除了能生成makefile，还能生成库（静态库/动态库），这样目标程序直接引入使用库即可，而不用直接使用源文件，因为源文件有很多个，而库文件只有一个。

cmake构建makefile，然后在执行make命令生成目标可执行文件。

> 注意执行完 cmake 之后还需要执行 make

## cmake脚本

编写CMake实际上就是编写`CMakeLists.txt`脚本（注意大小写）

`cmake ..` 

`cmake ../CMakeLists.txt`

变量的值默认是string类型，因此说如果我们希望传入一个整数，需要类型转换

变量名推荐大写，更醒目。

在指定路径时，最好使用绝对路径，不然当项目位置移动时，相对路径就不准了。

注意CMake不使用`,`作为分隔符，而是使用空格作为分隔符

set既可以设置自定义变量，也可以设置CMake自带的宏

----

micro`PROJECT_SOURCE_DIR`：对应的就是我们 `cmake dir` 的dir。但其实就是我们 `CMakeLists.txt` 的路径，因为我们 `cmake dir` 的dir 本质上就是 `CMakeLists.txt` 文件所在路径。

要注意在使用这个宏之前，先声明`project(project_name)`，否则会报错：

``` CMAKE
set(EXECUTABLE_OUTPUT_PATH /root/xjy/tmp/run)
set(CMAKE_CXX_standard 11)

# set(SRC add.cpp;sub.cpp;mul.cpp;div.cpp;main.cpp)

aux_source_directory(${PROJECT_SOURCE_DIR} SRC)
project(calculation)

cmake_minimum_required(VERSION 3.15)

add_executable(app ${SRC})
############# Error ##################
CMake Error at CMakeLists.txt:6 (aux_source_directory):
  aux_source_directory called with incorrect number of arguments
```

micro `CMAKE_CURRENT_SOURCE_DIR` 对应的直接就是 `CMakeLists.txt` 文件所在的路径，没有中间商 `CMake DIR`，一步到位了。

因此说这连个宏存储的值其实都是一样的。

---

目前来看 `file` 和 `aux_source_directory` 的区别就是，`file` 必须指定搜索文件的后缀，而 `aux_source_directory` 不能指定。

---

`include "head.h"` 只会从当前目录下查找 `head.h`

----

`cmake` 生成动态库。

库文件的本质其实还是代码，只不过是从文本格式变成了二进制格式。

库文件的命名：`lib+库名字+后缀`

后缀格式：`.so:Shared Object file`

| 库类型\平台 | Linux | windows |
| ----------- | ----- | ------- |
| 静态库      | .a    | .lib    |
| 动态库      | .so   | .dll    |

动态库是一个可执行文件，在终端中显示为绿色，静态库不是可执行文件。

当同时构建动态库和静态库时，它们的名字不能相同，但如果分两次构建，他们的名字可以相同。

 动态库和静态库只不过是对源文件的打包，其本质就是把文本形式的源文件打包为二进制格式的库文件，因为计算机只能直接处理二进制文件。

如果希望我们的库文件被使用，或者说是发行我们的库文件，需要将 `库文件` 与 `头文件` 一起打包，头文件包含了库文件中功能的声明，如果不包含头文件，使用者无法得知库文件中到底提供了什么功能。

在链接库文件时，如果是系统库，直接连接即可，如果是我们自定义的库，还需要指定目录。

静态库会被打包到可执行目标文件中，动态库不会。动态库又称为共享库，因为它虽然被调用后会放在内存中，但是可以被多个进程共享，从而优化内存，保护数据。

静态库link时机一般是 `add_executable` 之前，而动态库在其之后。

---

嵌套CMake，父节点里的变量可以在子节点中使用，反之不行。
