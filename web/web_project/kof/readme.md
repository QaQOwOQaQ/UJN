# Web 中期项目 -- 拳皇

## ref 
[连招](https://www.acwing.com/solution/content/114448/)

## 3个元素
div-kof
    background
    player1
    player2

为了使得图片的刷新频率可以被人眼看成动画,刷新频率至少为30帧(每秒刷新30次),我们这里刷新60帧

## jquery中变量加$和不加$有什么区别
一般在给jquery对象取名的时候在前面加$。 一看就知道是jquery对象。
变量命名规则中起始字符可以是 字母,下划线(_),美元符($),只是很多的js库喜欢使用$作为全局变量标志。
jQuery也不例外.加上$,作为jQuery变量标志更容易进行区分。
在使用jQuery 中，如果一个变量被$();包裹。那么说明这个变量需要包装成jQuery对象才可以使用。
而在jQuery自己的作用域所创建的变量不需要加$();包裹。举一个很简单的例子：比如，一个在js中的this指针。而这个指针需要在jQuery中使用，那么就需要用$();包裹成jQuery中的对象，也就需要这样写：$(this)。
如果是一个变量起名为$xxx，而另一个变量名为xxx。那么这是一种良好的代码习惯。是区分使用jQuery创建的变量和javascript自己创建的变量。

## 聚焦
聚焦的意思就是可以接受键盘的输入
聚焦的地方就是键盘输入的地方


## 操纵canvas对象
canvas 起初是空白的。为了展示，首先脚本需要找到渲染上下文，然后在它的上面绘制。<canvas> 元素有一个叫做 getContext() 的方法，这个方法是用来获得渲染上下文和它的绘画功能。getContext()接受一个参数，即上下文的类型。对于 2D 图像而言，如本教程，你可以使用 CanvasRenderingContext2D。
``` javascript
var canvas = document.getElementById("tutorial");
var ctx = canvas.getContext("2d");
```
代码的第一行通过使用 document.getElementById() 方法来为 <canvas> 元素得到 DOM 对象。一旦有了元素对象，你可以通过使用它的 getContext() 方法来访问绘画上下文。

也就是说，我们对canvas都是通过ctx来操纵的，操纵他们的渲染...

## 连招
通过stack实现

## utils
实用工具；实用菜单；实用程序类

## enum
https://segmentfault.com/a/1190000037644462

## 动作
有限状态机

## 攻击判定
在二维动画中，通常是设置攻击范围为一个二维区域，目标对象为一个二维区域，当这连个区域有重叠时，表示攻击生效
有交集 => 水平和垂直方向都有交集

## line-height 实现单行文字垂直居中原理
核心原理：line-height=上距离+内容高度+下距离
上下距离相等，但由于div大小的限制，会导致上距离or下距离超出div的范围，从而显得是文字向下or向上偏移了，而当上下距离不超出div范围时，由于上下距离相等，文字自然垂直居中
https://blog.csdn.net/NDKHBWH/article/details/104698408

## 为啥血量要设置两个div
一个div固定，一个div根据血量变化
可以理解为，一个为容器（不变），一个为液体（变化）
如果我们要实现流血效果，可以在内部设置两个div，其中红色的div比绿色的div变化慢

## 击退功能

## 键盘按键逻辑
set

## 结束游戏?