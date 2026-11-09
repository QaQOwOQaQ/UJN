# Web

## TODO

[（1）一个有意思的博客](https://www.acwing.com/user/myspace/blog/11468/)

- 基础数据类型有哪些
- 如何使用BigInt
- arguments是什么，如何使用
- 类数组
- 浅拷贝代码输出题，判断输出什么
- JS的垃圾回收机制
- 手写深拷贝
- 手写call方法
- 手写防抖
- localstorage,sessionstorage,cookie区别
- 前端怎么获取token
- 用JS存储cookie
- typeof null,typeof undefined结果，如何用instanceof判断数组
- 如何实现继承

（2）click, dblclick bug

（3）浅拷贝，深拷贝，``==``，``====``

（4）react基于class，vue基于function

## document 

[WDN: document](https://developer.mozilla.org/zh-CN/)

[bootstrap library：设计好的组件](https://v5.bootcss.com/)

[ES6 introduce [TODO]](https://www.bookstack.cn/read/es6-3rd/sidebar.md)

[Canvas：图形和动画](https://developer.mozilla.org/zh-CN/docs/Web/API/Canvas_API/Tutorial)

## ref

[blog：重学前端 [TODO]](https://doc.vercel.app/frontend/web/80240.html)

[Web 应用课](https://www.acwing.com/activity/content/1150/)

[js module 的解释](https://juejin.cn/post/7023218660630069279)

[bootstrap(相应,引导):响应式CSS库]

[canvas]

## 0x00 缩写&英文

* html: Hyper Text Markup Language

* ul: unordered lists的缩写 (无序列表)

* li: list item的缩写 （列表项目）

* ol: ordered lists的缩写（有序列表）

* dl: definition lists的英文缩写 (自定义列表)

* dt: definition term的缩写 (自定义列表组)

* dd: definition description的缩写（自定义列表描述）

* nl: navigation lists的英文缩写 （导航列表）

* tr: table row的缩写 （表格中的一行）

* th: table header cell的缩写 （表格中的表头）

* td: table data cell的缩写 （表格中的一个单元格）

* cell : (巢)[翻译的好怪.] 蜗牛博客注：应为单元格

* cellpadding （巢补白）

* cellspacing （巢空间）

* thead: table header

* css：cascading style sheets(层叠样式表)

* birghtness：通明度

* indent：**to make a space** at the edge or on the surface of something: be indented from Each new paragraph should be indented about two centimetres from the margin.

* blur：模糊

* opacity：透明度

* dash：破折号，（少量，猛冲）

* animate: 有生命的，活的，在 css 中表示动画

  

## 0x01 html

### 1. 块元素

div 是块元素，span是行内元素。块内元素默认换行，行内元素不换行，其他多是对这两个的 css 修饰。

例如：p 就是多了行间距

### 2. nbsp

nbsp：non-breaking space

"nbsp"是"non-breaking space"的缩写，意思是“不间断空格”，它是HTML中的一个特殊字符实体。与普通空格字符不同的是，使用"nbsp"可以保证在网页文本中不会出现断行。在HTML中，如果在两个单词之间使用普通空格，当浏览器需要自动调整行宽时，可能会出现单词被分割的情况，这会影响网页的排版效果。但如果使用"nbsp"，则浏览器不会在这个位置自动断行，保证单词不会被分割。

在HTML中，"nbsp"的实体编码为" "，可以在HTML文本中使用这个编码来代替空格字符。例如，如果要在网页中插入一个不间断空格

### 3. label

label用来绑定一个input，通过id绑定，id唯一

### 4. url

一个url会包含多个参数，用？分隔，``url?参数名称=参数值&参数名称=参数值``

一个 button会提交他所在 form的所有内容，并且与位置无关，并且这些内容会在 url 上显式

password在 url上是明文，但在 https 传输时，会加密传输

###  5. href

```html
<a href='#'>传送到当前页面</a>
<a href='/'>传送到文档的根目录下（注意是文档的根目录）</a>
<a href='/login'>传送到文档的/login目录下</a>
```

## 0x02 css

如果将 html 比作楼房的骨架，那么 css 就是楼房的装饰。如果将 html 比作素颜，那么 css 就是在此基础上化妆。

css的格式为 `:` 分隔的 key-value

在 html 中引入 css 时需要加上 `type="stylesheet"`

### 1. 方向顺序

块元素四个方向的顺序默认为：上、右、下、左

如果我们指定的值少于四个，那么缺少的值为对边的值，例如左对应于右的值，上对应于下的值。

注意不同值之间以空格分隔而不是逗号。

### 2. css style sheet type

1. 行内样式表：单一标签内
2. 内部样式表：class (同一个标签一般具有唯一的 id，但可以有多个 class，用空格分割)
3. 外部样式表： 多个文件 `file_name.css`，通过 `link` 使用

### 3. class

一个标签可以有多个 class，定义时以空格分隔，但只能有一个 id

> 注意只能有一个 class 声明 ？
>
> 但一个 class 声明中可以包含多个 class_name

当一个标签有多个 class 时，渲染优先级与标签中各个 class 的声明顺序无关，而与 css 中 class 的定义顺序有关

### 4. 选择器

1. 标签选择器

2. id 选择器

3. class 选择器

4. （链接）伪类选择器：用于定义元素的特殊状态

   1. `:link` 链接访问前的样式（针对的是超链接）
   2. `:visited` 链接访问后的样式（针对的是超链接）
   3. `:hover` 鼠标悬停时的样式（超链接，按钮）
   4. `:active` 鼠标点击时的样式（超链接，按钮）
   5. `:focus` 聚焦时的样式（针对的是 input 框)

   hover 和 focus 的不同在于：前者只需要悬停，后者需要鼠标点击

5. （位置）伪类选择器 

   > `:nth-child(an+b)`: 选择是其父标签第 an+b个子元素的所有元素
   >
   > n是非负整数（0,1,2…)，下标从 1 开始

6. （目标）伪类选择器

   > `:target`：当 url 指向该元素时生效，一般是内部链接
   >
   > 例如：
   >
   > ``` HTML
   > <a href="#fuck">link fuck</a>
   > <p id="fuck">7</p>
   > ```
   >
   > 在链接之前 url 为：
   >
   > `http://127.0.0.1:5500/web/index.html`
   >
   > 在链接之后，url 会变成 :
   >
   > `http://127.0.0.1:5500/web/index.html#fuck`

7. 复合选择器

   * `element1, element2`：同时选择 1 和 2两个元素
   * `element.class1.class2` ：包含类 class1 和 class2 的元素（class 的顺序不重要）
   * `emelemt1 + element2`：紧跟在 element1 之后的 element2 元素
   * `element1 element2`：选择 element1 内的所有 element2 元素（element1 是 element2 的祖先节点即可）
   * `element1 > element2`：选择父标签是 element1 的所有 element2 元素

8. 通配符选择器

   * `*` ：选择所有标签

   * `[attribute]`：选择具有某个属性的所有标签

   * `[attribute=value]`：选择 `attribute` 值为 `value` 的所有标签

     > 例如：
     >
     > ``` html
     > div[id] {
     >  background-color: brown;
     > } /* 将所有带 id 属性的 div 标签颜色设为 brown  */
     > 
     > input[type=text] {
     > 	...
     > }
     > ```

9. 伪元素选择器

   * `::first-letter`：选择第一个字母
   * `first-line`：选择第一行
   * `selection`：选择已被选中的内容
   * `after`：可以在元素后插入内容
   * `before`：可以在元素前插入内容

   > 例如：可以通过 after 和 before 实现给所有 H1 标签添加书名号
   >
   > ``` HTML
   > <body>
   >  <style>
   >      h1::before {
   >          content: "《";
   >          color: lightblue;
   >      }
   >      h1::after {
   >          content: "》";
   >          color: lightblue;
   >      }
   >      p::first-letter {
   >          color: red;
   >      }
   >      p::selection {
   >          /* selection 能赢用的 css 属性不多，其中字体大小就不行 */
   >          color: lightgreen !important;	/* 优先级最高 */
   >      }
   >  </style>
   >  <h1>沁园春</h1>
   >      <P>北国风光，千里冰封，万里雪飘。望长城内外，惟馀莽莽；大河上下，顿失滔滔。
   >          山舞银蛇，原驰蜡象，欲与天公试比高。须晴日，看红妆素裹，分外妖娆。
   >      江山如此多娇，引无数英雄竞折腰。惜秦皇汉武，略输文采；唐宗宋祖，稍逊风骚。
   >      一代天骄，成吉思汗，只识弯弓射大雕。俱往矣，数风流人物，还看今朝。
   >      </P>
   >  <h1>悯农</h1>
   >      <P>怜悯农民，对现实社会的不满意。 “悯农”，古代很多诗人写过《悯农》诗，
   >          流传比较广泛的是唐代诗人的《悯农》诗，还有宋代诗人杨万里的《悯农》诗等。</P>
   >  <h1>静夜思</h1>
   >      <p>床前明月光，疑是地上霜。举头望明月，低头思故乡。</p>
   > </body>
   > ```



### 5. 样式渲染优先级

id选择器  >  class选择器

可以通过 `!important` 手动设置某个选择器为最高优先级

### 6. 颜色

网页上可以通过 F12 进入调试模式

图片之类可以通过 QQ 截图

### 7. test-align

justify：左右两端对齐（left align & right align），它通过让单词之间的间距变大实现

center：中心对齐

如果父标签有对齐，子标签会继承父标签的对齐

### 8. 长度单位

* `px`：屏幕上的像素点
* `%` 的大小是相对其<mark>父元素</mark>的百分比，最外层元素这值得百分比是相对应屏幕而言的。
* `em` 是相对于当前元素的字体大小，`1em` 就是一个字的宽度/高度。
* `vw`：相对于 view width 的百分比。
* `vh`：相对于 view height 的百分比。

### 9. test-shadow

``` SHELL
// 坐标系
-------> x
|
|
\/ y
```

四个参数分别是 `(OFFSET_X, OFFSET_Y, BLUR_RADIUS, COLOR)`

x 和 y 的偏移量负值就是往相反方向偏移，都为 0 则阴影位于文字正后方。

blur_radius 值越大，模糊半径越大，阴影也就越大越淡（wider and lighter），如果为 0 的话就是原文字的直接偏移。

### 10. font

font-weight:表示的是字体的粗细
		font-style: 表示字体是否是倾斜的 italic(斜体)
		font-family:表示的是字体，例如英文里面的带衬线字体，中文里面的草书这些。

### 11. background

渐变色

``` css
div {
     width: 500px;
     height: 500px;
     /* background-image: url('../images/dog.jpg'); */
     background-color: lightgreen;
     background-image: linear-gradient(rgba(255, 0, 255, 0.5), rgba(0, 255, 0, 0.5));
     /* css 在渲染时，先按照 lightgreen 渲染，然后再按照渐变色渲染*/
     background-size: 250px;
     background-repeat: repeat;
     background-position: 250px 250px;
}
```

实现图片的覆盖

``` html
<body>
 <style>
     .mydiv {
         background-image: url("./static/images/tiger.jpg");
         width: 500px;
         height: 500px;
         background-repeat: no-repeat;
         background-size: 100% 100%;
     }
     .mydiv > div {
         background-image: url("./static/images/dog.jpg");
         width: 250px;
         height: 250px;
         background-repeat: no-repeat;
         background-size: cover;
         opacity: 0.5;
     }
 </style>
 <div class="mydiv">
     <div></div>
 </div>
</body>
```

### 12. border

实现表格

``` html
<body>
 <style>
     td {
         width: 20px;
         height: 20px;
         border-style: solid;
         border-width: 3px;
     }
     table {
         border-style: solid;
         border-width: 3px;
         border-collapse: collapse;
     }
 </style>
 <table>
     <thead>
         <tr>
             <td>Name</td>
             <td>Age</td>
             <td>Sex</td>
         </tr>
     </thead>
     <tbody>
         <tr>
             <td>Alice</td>
             <td>18</td>
             <td>woman</td>
         </tr>
         <tr>
             <td>Bob</td>
             <td>22</td>
             <td>man</td>
         </tr>
         <tr>
             <td>Mike</td>
             <td>32</td>
             <td>man</td>
         </tr>
     </tbody>   
 </table>
</body>
```

### 13. 内外边距（padding，margin）& box-sizing

（1）内边距会改变块的大小，例如原本宽度为 `20px`，现在增加 `padding=10px`，则宽度变为 `20+10+10=40px`，事实上，`width = width + padding + border`，不过可以通过 `box-sizing` 设置 padding 和 border 是否影响 width

（2）在修改外边距时，有一个问题，就是子元素会带着父元素偏移，导致原本父元素没有 margin 的，但是因为子元素有 margin，导致父元素也有 margin 了，这可能是在设计时考虑到，当子元素有 padding 时，会超会父元素的范围，为了解决这个问题，有以下解决办法：

解决方法一：

``` html
<body>
    <style>
    .div-outer {
        width: 150px;
        height: 100px;
        background-color: lightblue;
        overflow: hidden;	// !!!
    }
    
    .div-inner {
        width: 100px;
        height: 100px;
        background-color: coral;
        margin: 20px;
    }
    </style>
    <div class="div-outer">
        <div class="div-inner"></div>
    </div>
</body>
```

解决方法二：

``` html
<body>
    <style>
    .div-outer {
        width: 150px;
        height: 100px;
        background-color: lightblue;
    }

    .div-outer::before {
        content: "";    /* 内容为空 */
        display: table;
    } 

    .div-inner {
        width: 100px;
        height: 100px;
        background-color: coral;
        margin: 20px;
    }
    </style>
    <div class="div-outer">
        <div class="div-inner"></div>
    </div>
</body>
```

在第一种方法中，子元素超出父元素的部分会隐藏，而在第二种方法中，子元素超出父元素的部分不会隐藏。

（3）当多个元素的 marigin 重叠时，会取 Max ，而不是取 Sum，当然我们应避免这种可能出现歧义的情况，因此一般只会定义 margin-down 而不是同时定义 marigin-top, margin-down

### 14. z-index 

z 轴相当于垂直于我们的轴，可以控制重叠元素的显式顺序

### 15. position

* static:正常/默认的布局行为
* relative：在不改变页面布局的前提下，调整元素位置
* absolute：元素会移出正常文档流，并不为元素预留空间
* fixed：相对于 viewport 的位置指定元素位置
* sticky：当元素在 viewport 之内时，是 static 布局，当元素移出 viewpoint 之外时，是 fixed 布局

示例：

``` html
<body style="margin: 0">
    <style>
    div {
        background-color: lightblue;
    }

    div div {
        background-color: lightgreen;
    }

    .div-inner1 {
        width: 50px;
        height: 400px;
    }

    .div-inner2 {
        width: 50px;
        height: 50px;
        background-color: aqua;
        position: sticky;
        left: 0;
        top: 0;

    }

    .div-inner3 {
        width: 50px;
        height: 400px;
    }

    .div-inner4 {
        width: 50px;
        height: 50px;
        background-color: aqua;
        position: sticky;
        left: 0;
        top: 0px;
    }

    .div-inner5 {
        width: 50px;
        height: 400px;
    }
    </style>
    <div class="div-outer">
        <div class="div-inner1">d1</div>
        <div class="div-inner2">d2</div>
        <div class="div-inner3">d3</div>
        <div class="div-inner4">d4</div>
        <div class="div-inner5">d5</div>
    </div>
</body>
```

### 16. float

如果我们通过 `display:inline_block` 属性将多个 div 放在同一行时，它们会有天然的 margin，如果我们希望去掉这些 margin，可以使用 float 属性

因此 float 最常用的情景是把所有 div 放在同一行

浮动元素是如何定位的：当一个元素浮动之后，它会被移出正常的文档流，然后向左或者向右平移，一直平移直到碰到了所处的容器的边框，或者碰到另外一个浮动的元素。

例如：

``` html
<body style="margin: 0">
    <style>
        div {
            background-color: lightgoldenrodyellow;
            width: 100vw;
            height: 100vh;
        }
        div div {
            width: 50px;
            height: 50px;
            background-color: lightblue;
            /* display: inline-block; */
            float: left;
        }
    </style>
    <div>
        <div>d1</div>
        <div>d2</div>
        <div>d3</div>
        <div>d4</div>
        <div>d5</div>
        <div>d1</div>
        <div>d2</div>
        <div>d3</div>
        <div>d4</div>
        <div>d5</div>
        <div>d1</div>
        <div>d2</div>
        <div>d3</div>
        <div>d4</div>
        <div>d5</div>
        <div>d1</div>
        <div>d2</div>
        <div>d3</div>
        <div>d4</div>
        <div>d5</div>
    </div>
</body>
```

因此说，只有属性设置为 float 的 div 才能 float，未设置为 float 的 div 不能 float

例如： 

``` html
<body>
    <style>
        div {
            width: 200px;
            height: 100px;
            margin: 3px;
            background-color: lightblue;
        }
        .innerdiv {
            width: 30px;
            height: 30px;
            background-color: antiquewhite;
            margin: 0px;
            float: left;
        }
        .notinnerdiv {
            width: 30px;
            height: 30px;
            background-color: antiquewhite;
            margin: 0px;
        }
    </style>
    <div> d0
        <div class="innerdiv">d1</div>
        <div class="innerdiv">d2</div>
        <div class="innerdiv">d3</div>
        <div class="notinnerdiv">d4</div>
    </div>
        
</body>
```

### 18. 响应式布局

所谓响应式布局就是根据设备的不同选择不同的布局，可以用 Bootstrap 构建快速、响应式布局的网站。

下面是一个根据窗口宽度大小更改布局的例子：

> css

``` CSS
.container {
    width: 80%;
    height: 100vh;
    background-color: lightblue;
}

.col {
    width: 33.33%;
    height: 100px;
    float: left;
    font-size: 30px;
    background-color: lightcoral;
    /* 水平居中 */
    text-align: center;
    /* 垂直居中：让文本的高度等于块的高度 */
    line-height: 100px;
    /* 表格 */
    border: 1px solid blueviolet;
    box-sizing: border-box;
}

@media(min-width: 768px) {
    .container {
        background-color: blue;
    }
    .lg1 {
        width: 100%;
    }
}

@media(min-width: 912px) {
    .container {
        background-color: yellow;
    }
    .md1 {
        width: 50%;
    }
    .md2 {
        width: 100%;
    }
}

@media(min-width: 1024px) {
    .container {
        background-color: green;
    }
    .sm1 {
        width: 33.33%;    
    }
    .sm2 {
        width: 33.33%; 
    }

    .sm3 {
        width: 33.33%; 
    }
}
```

> html

``` HTML
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>web</title>
    <link rel="stylesheet" href="static/css/style.css">
</head>
<body>
   <div class="container">
    <div class="col sm1 md1 lg1">用户名</div>
    <div class="col sm1 md1 lg1">密码</div>
    <div class="col sm1 md2 lg1">个人间接</div>
   </div>
</body>
</html>
```



## 0x03 css 技巧

### 1. 鼠标悬停时显示新的div

实现鼠标悬停在一个元素时显示另一个元素的两种方法：

1. 两个元素是祖先-孩子关系

   `.element:hover target {}`

2. 两个元素父亲相同且相邻

   `.element:hover + target {}`

通过透明度 opacity 和是否可见 visbility 两个属性来实现鼠标在某个 div(element) 悬停时显示另一个 div(target)，具体做法就是将 element和 target放到一个 container 当中，一开始将 target的 opacity 设置为 0，visbility 设置为 hidden，当鼠标悬停到 container 时，设置 target 的 opacity 为 1，visbility 为 visable 即可。

例如：

``` html
<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <title>纯CSS鼠标悬停显示div示例</title>
  <style>
    .container {
      position: relative;
    }

    .element {
      background-color: #f1f1f1;
      color: #333;
      padding: 10px;
    }

    .target {
      background-color: #333;
      color: #fff;
      padding: 10px;
      position: absolute;
      top: 100%;
      left: 0;
      opacity: 0;
      visibility: hidden;
      transition: opacity 0.3s ease-in-out;
    }

    .container:hover .target {
      opacity: 1;
      visibility: visible;
    }
  </style>
</head>
<body>
  <div class="container">
    <div class="element">显示的元素</div>
    <div class="target">目标元素</div>
  </div>
</body>
</html>
```

### 2. 实现水平和垂直居中

注意通过 `%` 修改元素位置时，是依据元素的<mark>左上边界</mark>来相对的，但实际上，我们应该依据中心线来相对便宜，因此也就是说，如果你设置 `margin-top: 50%`，元素其实并不是垂直居中的（实际上偏下了）。此时我们还需要将 `margin-top: 50%` 之后的 div 在往上偏移 `50%` 它自己的大小。

``` HTML
<body>
    <style>
      .outerdiv {
        width: 400px;
        height: 400px;
        background-color: lightgray;
      }
      .innerdiv {
        width: 100px;
        height: 100px;
        background-color: lightblue;
        /* 实现水平居中 */
        margin-left: auto;
        margin-right: auto;
        /* 实现垂直居中 */
        position: relative;
        top: 50%;		/*偏下了*/
        transform: translateY(-50%);	/*往上修正*/
      }
    </style>
      <div class="outerdiv">
      <div class="innerdiv">
      </div>
    </div>
</body>
```

当然，我们也可以通过 flex 属性实现

> flex 规定其内部元素的排列，因此如果我们要实现某些 div 的排列，应该设置其父亲元素的 flex
>
> 不过也需要注意某些标签是孩子使用的，例如 order

``` HTML
<body>
  <style>
    .outerdiv {
      width: 400px;
      height: 400px;
      background-color: lightgray;
      display: flex;
      /* 水平 */
      justify-content: center;
      /* 垂直 */
      align-items: center;
    }

    .innerdiv {
      width: 100px;
      height: 100px;
      background-color: lightblue;
    }
  </style>
  <div class="outerdiv">
    <div class="innerdiv">
    </div>
  </div>
</body>
```

实现文本的水平和垂直居中

``` HTML
<body>
    <style>
        .container {
            width: 80%;
            height: 100vh;
            background-color: lightblue;
        }
        .col {
            width: 33.33%;
            height: 100px;
            float: left;
            font-size: 30px;
            background-color: lightcoral;
            /* 水平居中 */
            text-align: center;
            /* 垂直居中：让文本的高度等于块的高度 */
            line-height: 100px;
            /* 表格 */
            border: 1px solid blueviolet;
            box-sizing: border-box;
        }
    </style>
   <div class="container">
    <div class="col">1</div>
    <div class="col">2</div>
    <div class="col">3</div>
   </div>
</body>
```

### 3. 使用bootstrap

包含下面两个文件，注意不要包含错了，有很多 `.min.css` 后缀，下面形式是“完全包”  `bootstrap-min.css`，其他是“分离包”（为了节省空间），即 `bootstrap-...-min.css`

然后直接复制代码就行了…

``` HTML
<link rel="stylesheet" href="./bootstrap-5.3.0-alpha1-dist/css/bootstrap.min.css">
<script src="./bootstrap-5.3.0-alpha1-dist/js/bootstrap.min.js"></script>
```

## 0x04 javascript

### 1. 代码规范

在大学，老师是这样写 js 事件的：例如定义一个 button 的点击事件

``` html
<button onclick="printf()"></button>
```

这就相当于在 html 中调用了 js，但我们希望的是通过 js 操控 html，而不是在 html 中调用 js ，即希望 js 对 html 不可见，这样就方便了代码的维护。

例如：有多个 button 的 onclick 事件是同一个函数，那如果我们后期想修改的话，需要修改这些所有的 button，显然不好。

### 2. [module](https://juejin.cn/post/7023218660630069279)

module：在JS中，一个文件或者脚本就是一个模块，模块可以声明哪些变量或函数供外部使用，也可以引入其他模块的变量与函数为自己所用，在模块中，使用`export`标记了可以从当前模块外部访问的变量和函数，使用`import`从其他模块导入所需要的功能

模块（module）有以下特性：

1. use strict（现代模式）（严格模式）：例如对一个未声明的变量赋值或者重复声明变量都将产生错误
2. 作用域：每个模块都有自己的顶级作用域，也就是说，一个模块中的顶级作用域变量和函数在其他模块中是不可见的
3. 模块代码解析：如果同一个模块被导入多次，那么它的代码只在第一次导入时便解析运行
4. this 的值：在JS模块中，`this`关键字的值`undefined`，非模块脚本的顶级 `this` 是全局对象，比如浏览器的`window`。

早期的 js 由于比较简单，没有模块的概念，这也就意味着，如果我们引入了一个 js 文件，那么这个 js 文件中所有的变量和函数都是全局可见的，那么如果我们引入了多个 js 文件，就可能会产生各种冲突，而模块的概念有效避免了这些问题。

因此我们推荐每个 js 都设置为 `type="module"`

### 3. js 调用方式

建议所有 script 都加上 `type=module`

（1）直接在 `<script></script>` 标签内写代码，例如：

``` HTML
<body>  
    <script>
        let name="Alice";
        console.log(name);
        alert(name);
    </script>
</body>
```

（2）引入 js 文件 `<script src="./index.js"></script>`，例如：

``` HTML
<!-- index.html -->
<body>  
    <script src="./static/js/index.js">
    </script>
</body>
<!-- index.js -->
let name="Alice";
console.log(name);
alert(name);
```

它实际上就相当于把 js 文件里面的内容直接展开，即相当于如下：

``` html
<body>  
    <script>
        let name="Alice";
        console.log(name);
        alert(name);
    </script>
</body>
```

（3）通过 export 和 import 引入

> export 和 import 只属于 module，因此必须设置 `type="script"`
>
> 在 import 时可以通过 as 设置别名

``` HTML
<!-- index.html -->
<body>  
    <script type="module">
        import { name as new_name } from "./static/js/index.js";
        console.log(name);
    </script>
</body>
<!-- index.js -->
let name = "Alice";
let age = 18;

export {
    name, age
}
```

### 4.  [变量](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#symbol_%E7%B1%BB%E5%9E%8B)

JavaScript 是一种有着[动态类型](https://zh.wikipedia.org/wiki/類型系統#靜態和動態檢查)的[动态](https://zh.wikipedia.org/wiki/动态语言)语言，JavaScript 中的变量与任何特定值类型没有任何关联，任何变量都可以被赋予（和重新赋予）各种类型的值。

JavaScript 也是一个[弱类型](https://zh.wikipedia.org/wiki/强弱类型)语言，这意味着当操作涉及不匹配的类型时，它允许隐式类型转换，而不是抛出类型错误。

#### 4.1 Primitive

除了 [Object](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#object) 以外，所有类型都定义了表示在语言最低层面的[不可变](https://developer.mozilla.org/zh-CN/docs/Glossary/Immutable)值。我们将这些值称为*原始值*。

> <mark>不可变值</mark>指的是，如果不创建一个全新的值替换它，它的内容是无法更改的。例如，我们不能修改 string 字符串的某个字符，除非修改整个字符串。这样做有很多好处：
>
> - 提高性能（不计划将来更改对象）
> - 为了减少内存使用（进行[对象引用 (en-US)](https://developer.mozilla.org/en-US/docs/Glossary/Object_reference)，而不是克隆整个对象）
> - 线程安全（多个线程可以引用同一对象，而不会相互干扰）
> - 降低开发人员的精神负担（对象的状态不会改变，其行为始终是一致的）

除了 [`null`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/null)，所有原始类型都可以使用 [`typeof`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/typeof) 运算符进行测试。`typeof null` 返回 `"object"`，因此必须使用 `=== null` 来测试 `null`。

Primitive type（值类型）（基本类型)

* number：[`Number`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Number) 类型是一种[基于 IEEE 754 标准的双精度 64 位二进制格式的值](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Number#number_编码)。虽然 number 在概念上是一个“数学的值”，并且总是隐式的编码为浮点类型，但是 JavaScript 提供了[位运算符](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Expressions_and_operators#位运算符)。当应用位运算符时，number 首先转换为 32 位整数。
* bigint：[`BigInt`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/BigInt) 类型在 Javascript 中是一个数字的原始值，它可以表示任意大小的整数。使用 BigInt，你可以安全地存储和操作巨大的整数，甚至超过 Number 的安全整数限制（[`Number.MAX_SAFE_INTEGER`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Number/MAX_SAFE_INTEGER)）。BigInt 值并不总是更精确的，也不总是比 number 精确，因为 BigInt 不能表示小数，但可以更精确地表示大整数。
* string：[`String`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/String) 类型表示文本数据并编码为 [UTF-16 码元](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/String#utf-16_字符、unicode_码位和字素簇（grapheme_clusters）)的 16 位无符号整数值序列。单引号与双引号均可。字符串中的每个字符为<mark>只读类型</mark>。
* boolean：布尔值，true / false
* undefined：未定义的变量，表示不含有值
* null：含有值，但值为空
* symbol：[`Symbol`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Symbol) 是**唯一**并且**不可变**的原始值并且可以用来作为对象属性的键。在某些程序语言当中，Symbol 也被称作“原子（atom）类型”。symbol 的目的是去创建一个唯一属性键，保证不会与其他代码中的键产生冲突。

以字符串为例，string type 既能表示 primitive ，也能表示 object

``` JAVA
const strPrim = "foo"; // 字面量是一个字符串原始值
const strPrim2 = String(1); // 被强制转换为字符串原始值“1”
const strPrim3 = String(true); // 被强制转换为字符串原始值“true”
const strObj = new String(strPrim); // 使用 `new` 关键字调用 `String` 构造函数返回一个字符串包装对象。

console.log(typeof strPrim); // "string"
console.log(typeof strPrim2); // "string"
console.log(typeof strPrim3); // "string"
console.log(typeof strObj); // "object"
```

#### 4.2 Object

在计算机科学中，对象（object）是指内存中的可以被[标识符](https://developer.mozilla.org/zh-CN/docs/Glossary/Identifier)引用的一块区域。在 JavaScript 中，对象是唯一[可变](https://developer.mozilla.org/zh-CN/docs/Glossary/Mutable)的值。事实上，[函数](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Functions)也是具有额外可*调用*能力的对象（callable object）。

在 JavaScript 中，对象可以被看作是一组<mark>属性的集合</mark>。用[对象字面量语法](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Guide/Grammar_and_types#对象字面量_object_literals)来定义一个对象时，会自动初始化一组有限的属性；然后，这些属性还可以被添加和移除。对象属性等价于键值对。属性键要么是[字符串](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#string-类型)类型，要么是 [symbol](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#symbol-类型)。属性值可以是任何类型的值，包括其他对象和函数，从而可以构建复杂的数据结构。

有两种对象属性的类型：[*数据*属性](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#数据属性)和[*访问器*属性](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#访问器属性)。每个属性都有对应的*特性*（attribute）

数据属性：

* [`value`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#value):通过属性访问器获取值。可以是任意的 JavaScript 值。
* [`writable`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#writable):一个布尔值，表示是否可以通过赋值来改变属性。
* [`enumerable`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#enumerable):一个布尔值，表示是否可以通过 [`for...in`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/for...in) 循环来枚举属性。
* [`configurable`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#configurable):一个布尔值，表示该属性是否可以删除，是否可以更改为访问器属性，并可以更改其特性。

访问器属性：

* [`get`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#get)：该函数使用一个空的参数列表，以便有权对值执行访问时，获取属性值。参见 [getter](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Functions/get)。可能是 `undefined`。

* [`set`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#set)使用包含分配值的参数调用的函数。每当尝试更改指定属性时执行。参见 [setter](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Functions/set)。可能是 `undefined`。

* [`enumerable`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#enumerable_2)：一个布尔值，表示是否可以通过 [`for...in`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/for...in) 循环来枚举属性。另请参阅[枚举性和属性所有权](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Enumerability_and_ownership_of_properties)，以了解枚举属性如何与其他函数和语法交互。

* [`configurable`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Data_structures#configurable_2)：一个布尔值，表示该属性是否可以删除，是否可以更改为访问器属性，并可以更改其特性。

  > 可以把 get 和 set 理解为，通过 get/set 设置函数，使得调用函数时无需加上 `()`，那么这个函数看起来就像是一个属性而不是方法，使得该对象更像是一个“对象”，而不是一个类。
  >
  > ``` html
  > <script>
  >             let obj = {
  >                 name: "xjy",    // 对象内赋值用:
  >                 get getname() {
  >                     return this.name; // 通过this调用属性
  >                 },
  >                 set setname(name) {
  >                     this.name = name;
  >                 } 
  >             };
  >             console.log(obj.getname);
  >             obj.setname = "jiayuan_xu";
  >             console.log(obj.getname);
  > </script>
  > ```

Object type（引用数据类型）（对象类型）

* array：[数组](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array)是一种以整数为键（integer-keyed）的属性并与长度（`length`）属性关联的常规对象，用 `[]` 表示，数组内元素类型可以不同，可以是任意类型。
* object：{name: "yxc", age: 18}，由花括号分隔。在括号内部，对象的属性以名称和值对的形式 (name : value) 来定义。属性由逗号分隔,其 `value` 可以是普通变量，数组，对象，<mark>函数</mark>等
* function
* date
* regex
* set, map
* json
* …

可以通过 `typeof var` 获取变量类型

``` html
<body>  
    <script type="module">
        let x = 10;
        const n = 10010;
        let y = {
        // 字典方式赋值时使用 : 而不是 = 
            name: "jyyyx",
            age: 20
        };
        // 对象有两种调用方式: dict方式和class方式
        console.log(y["name"], y.name);
        console.log(typeof x, typeof n, typeof y, typeof y.name, typeof y.age)
        // 也有一种奇怪写法
        let key = "name";
        console.log(y[key]);
        // 甚至可以为字典中不存在的key赋值
        y.school = "ujn";
        console.log(y.school);
        // 然后再删除这个key
        delete y.school;
        //  log 智能打印字典
        console.log(y);
        // 类似 python?
        let obj = [1,"false","string",false,3.13];
        for(var d in obj) {
            console.log(d + ":" +obj[d]);
        }
        // 定义有函数的对象
        
    </script>
</body>
```
### 5. 运算符
（1）`**`表示乘方

（2）类型转换运算符：`parseInt()`

（3）javaScript 提供三种不同的值比较运算：

- [`===`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Strict_equality) 严格相等（三个等号）
- [`==`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Equality) 宽松相等（两个等号）
- [`Object.is()`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Object/is)

选择哪个运算取决于你需要什么样的比较。简单来说：

- 在比较两个操作数时，双等号（`==`）将执行***类型转换***，并且会按照 IEEE 754 标准对 `NaN`、`-0` 和 `+0` 进行特殊处理（故 `NaN != NaN`，且 `-0 == +0`）；
- 三等号（`===`）做的比较与双等号相同（包括对 `NaN`、`-0` 和 `+0` 的特殊处理）但不进行类型转换；如果类型不同，则返回 `false`；
- `Object.is()` 既不进行类型转换，也不对 `NaN`、`-0` 和 `+0` 进行特殊处理（这使它和 `===` 在除了那些特殊数字值之外的情况具有相同的表现）。

例如：`"1" === 1; // false`，`“1” == 1; // true`

### 6. 输入输出

（1）格式化字符串

``` html
    <body>  
        <script type="module">
            let name = "jiayuan_xu";
            // 字符串中填入数值
            let s = `my name is ${name}`;
            console.log(s);
            // 定义多行字符串
            let code = `
#include<iostream>
using namespace std;
int main()
{
    int a, b;   cin >> a >> b;
    cout << a + b << endl;
    return 0;
}`
            console.log(code);
            // 保留两位小数（四舍五入?）
            let x = 1.23456;
            let s = `${x.toFixed(2)}`;
            console.log(s);
        </script>
    </body>
```

（2）从网页上输入输出

* 输入 – 从 HTML 与用户的交互中输入信息

* 输出 – 改变当前页面的 HTML 和 CSS

``` HTML
<!-- index.html -->
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web</title>
    <script type="module">
        import { main } from "./static/js/index.js";
        main(); // 注意引入之后还需要运行main函数
    </script>
</head>

<body>  
    <style>
        textarea {
            width: 200px;
            height: 100px;
            background-color: lightblue;
            font-size: 20px;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
    </style>
    
    <body>  
        <label for="textarea">input</label><br/>
        <textarea class="input-text" id="textarea"></textarea><br>
        <button class="copy-button">copy</button><br/>
        <button class="get-sum-button">get sum</button><br/>
        <textarea class="output-text" id="textarea"></textarea>
        
    </body>
</body>
</html>
```

``` javascript
// index.js
let input  =  document.querySelector(".input-text");
let copy_button =  document.querySelector(".copy-button")
let get_sum_button =  document.querySelector(".get-sum-button")
let output =  document.querySelector(".output-text");

export function main() {
    copy_button.addEventListener("click", function() {
        let s = input.value;
        output.innerHTML = s;
    })
    get_sum_button.addEventListener("click", function() {
        let s = input.value;
        let [a, b] = s.split(' ');
        a = parseFloat(a), b = parseFloat(b);
        let sum = a + b;
        output.innerHTML = `${sum.toFixed(2)}`;
    })
}
```

### 7. 属性和方法

属性和方法都可以通过函数实现，不同的是：

* 属性的调用不需要加上 `()`
* 方法的调用必须加上 `()`，

例如在数组中，length 就是属性，sort 就是方法。如果属性中有参数，通过 `obj.attricute_name = arguments;` 给出。  

### 8. hoisting（变量提升）

变量提升（Hoisting）被认为是，Javascript 中执行上下文（特别是创建和执行阶段）工作方式的一种认识。在 [ECMAScript® 2015 Language Specification](https://www.ecma-international.org/ecma-262/6.0/index.html) 之前的 JavaScript 文档中找不到变量提升（Hoisting）这个词。不过，需要注意的是，开始时，这个概念可能比较难理解，甚至恼人。

例如，从概念的字面意义上说，<font color=blue>“变量提升”意味着变量和函数的声明会在物理层面移动到代码的最前面，但这么说并不准确。实际上变量和函数声明在代码里的位置是不会动的，而是在编译阶段被放入内存中。</font>

> class 并不会被提升，因此必须先声明 class，再使用它

例如，以下代码可以正常运行，我们先调用再声明函数：

``` HTML
<script>
    dog_name("Alice");
    function dog_name(name) {
        console.log("dog name is " + name);
    }
</script>
```

即使我们在定义这个函数之前调用它，函数仍然可以工作。这是因为在 JavaScript 中**执行上下文**的工作方式造成的。

变量提升也适用于其他数据类型和变量。变量可以在声明之前进行初始化和使用。但是如果没有初始化，就不能使用它们。

函数和变量相比，会被优先提升。这意味着函数会被提升到更靠前的位置。

<font color=blue>但要注意，只有声明会被提升，而定义并不会，</font>因此下面的代码会报错 name 未初始化。

``` javascript
dog_name(name);
let name;
name = "Alice";
function dog_name(name) {
    console.log("dog name is " + name);
}
```

我们可以理解为，在编译之后，代码变成了：

```javascript
let name;
/*-------------------------------*/
dog_name(name);
name = "Alice";
function dog_name(name) {
    console.log("dog name is " + name);
}
```

同理下面也是未初始化错误：

``` javascript
console.log("x: " + x);
let x = 10;
```

### 9. class

实际上，类是“特殊的[函数](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Functions)”，就像你能够定义的[函数表达式](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/function)和[函数声明](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/function)一样，类语法有两个组成部分：[类表达式](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/class)和[类声明](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/class)。

**函数声明**和**类声明**之间的一个重要区别在于，函数声明会[提升](https://developer.mozilla.org/zh-CN/docs/Glossary/Hoisting)，类声明不会。你首先需要声明你的类，然后再访问它，否则代码将抛出[`ReferenceError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/ReferenceError)

类声明和类表达式的主体都执行在[严格模式](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Strict_mode)下。比如，构造函数，静态方法，原型方法，getter 和 setter 都在严格模式下执行。

下面是一个类例子：

``` javascript
class Rectangle {
    // Constructor
    constructor(width, height) {
        this.width = width;
        this.height = height;
    }
    // Getter
    get area() {
        return this.calcArea();
    }
    // Method
    calcArea() {
        return this.width * this.height;
    }
}
const square = new Rectangle(10, 10);
console.log(square.area);
```

#### 9.1 类表达式

**类表达式**是定义类的另一种方法。类表达式可以命名或不命名。命名类表达式的名称是该类体的局部名称。(不过，可以通过类的 (而不是一个实例的) [`name`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Function/name) 属性来检索它)。

``` javascript
// 未命名/匿名类
let Rectangle = class {
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
};
console.log(Rectangle.name);
// output: "Rectangle"

// 命名类
let Rectangle = class Rectangle22 {
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
};
console.log(Rectangle.name);
// 输出："Rectangle22"
```

#### 9.2 constructor

[constructor](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes/constructor)方法是一个特殊的方法，这种方法用于创建和初始化一个由`class`创建的对象。一个类只能拥有一个名为“constructor”的特殊方法。如果类包含多个`constructor`的方法，则将抛出 一个[`SyntaxError`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/SyntaxError) 。

一个构造函数可以使用 `super` 关键字来调用一个父类的构造函数。

#### 9.3 静态成员

[`static`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Classes/static) 关键字用来定义一个类的一个静态方法。调用静态方法不需要[实例化 (en-US)](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects#the_object_(class_instance)) 该类，但不能通过一个类实例调用静态方法。静态方法通常用于为一个应用程序创建工具函数。

实例的属性必须定义在类的方法里，静态的或原型的数据属性必须定义在类定义的外面。（和 cpp 一样）

``` javascript
<script>
    class Rectangle {
        // Constructor
        constructor(width, height) {
            this.width = width;
            this.height = height;
        }
        // Static Variable
        static name = "Rectangle";
        // Static Method
        static speak() {
            console.log(`I am a ${Rectangle.name}`);
        }
    }
Rectangle.speak();
</script>
```



#### 9.4 字段声明

（1）共有字段声明

``` javascript
class Rectangle {
  height = 0;
  width;
  constructor(height, width) {
    this.height = height;
    this.width = width;
  }
}
```

在声明字段时，我们不需要像 `let`、`const` 和 `var` 这样的关键字。

正如上面看到的，这个字段可以用也可以不用默认值来声明。

（2）私有字段声明

``` JAVASCRIPT
class Rectangle {
  #height = 0;
  #width;
  constructor(height, width) {
    this.#height = height;
    this.#width = width;
  }
}
```

私有字段仅能在字段声明中预先定义。（显然，因为外部不能访问它）

#### 9.5 extends

如果子类中定义了构造函数，那么它必须先调用 `super()` 才能使用 `this` 。

``` javascript
<script>
    class Animal {
        constructor(name) {
            this.name = name;
        }
        speak() {
            console.log(`${this.name} makes a noisy`);
        }
    }
class Dog extends Animal {
    constructor(name) {
        super(name);
    }
    speak() {
        console.log(`${this.name} barks`);
    }
}
let d = new Dog("Alice");
d.speak(); 
</script>
```

### 10. ECMAScript 和 JavaScript 的关系

一个常见的问题是，ECMAScript 和 JavaScript 到底是什么关系？

要讲清楚这个问题，需要回顾历史。1996 年 11 月，JavaScript 的创造者 Netscape 公司，决定将 JavaScript 提交给标准化组织 ECMA，希望这种语言能够成为国际标准。次年，ECMA 发布 262 号标准文件（ECMA-262）的第一版，规定了浏览器脚本语言的标准，并将这种语言称为 ECMAScript，这个版本就是 1.0 版。

该标准从一开始就是针对 JavaScript 语言制定的，但是之所以不叫 JavaScript，有两个原因。一是商标，Java 是 Sun 公司的商标，根据授权协议，只有 Netscape 公司可以合法地使用 JavaScript 这个名字，且 JavaScript 本身也已经被 Netscape 公司注册为商标。二是想体现这门语言的制定者是 ECMA，不是 Netscape，这样有利于保证这门语言的开放性和中立性。

因此，ECMAScript 和 JavaScript 的关系是，前者是后者的规格，后者是前者的一种实现（另外的 ECMAScript 方言还有 JScript 和 ActionScript）。日常场合，这两个词是可以互换的。

### 11. let

#### 11.1 基本用法

ES6 新增了`let`命令，用来声明变量。它的用法类似于`var`，但是所声明的变量，只在`let`命令所在的代码块内有效。

``` javascript
{
  let a = 10;
  var b = 1;
}
a // ReferenceError: a is not defined.
b // 1
```

`for`循环的计数器，就很合适使用`let`命令。

``` javascript
for (let i = 0; i < 10; i++) {
  // ...
}
console.log(i);
// ReferenceError: i is not defined
```

上面代码中，计数器`i`只在`for`循环体内有效，在循环体外引用就会报错。

下面的代码如果使用`var`，最后输出的是`10`。

```
var a = [];for (var i = 0; i < 10; i++) {  a[i] = function () {    console.log(i);  };}a[6](); // 10
```

上面代码中，变量`i`是`var`命令声明的，在全局范围内都有效，所以全局只有一个变量`i`。每一次循环，变量`i`的值都会发生改变，而循环内被赋给数组`a`的函数内部的`console.log(i)`，里面的`i`指向的就是全局的`i`。也就是说，所有数组`a`的成员里面的`i`，指向的都是同一个`i`，导致运行时输出的是最后一轮的`i`的值，也就是 10。

如果使用`let`，声明的变量仅在块级作用域内有效，最后输出的是 6。

```
var a = [];for (let i = 0; i < 10; i++) {  a[i] = function () {    console.log(i);  };}a[6](); // 6
```

上面代码中，变量`i`是`let`声明的，当前的`i`只在本轮循环有效，所以每一次循环的`i`其实都是一个新的变量，所以最后输出的是`6`。你可能会问，如果每一轮循环的变量`i`都是重新声明的，那它怎么知道上一轮循环的值，从而计算出本轮循环的值？这是因为 JavaScript 引擎内部会记住上一轮循环的值，初始化本轮的变量`i`时，就在上一轮循环的基础上进行计算。

另外，`for`循环还有一个特别之处，就是设置循环变量的那部分是一个父作用域，而循环体内部是一个单独的子作用域。

```
for (let i = 0; i < 3; i++) {  let i = 'abc';  console.log(i);}// abc// abc// abc
```

上面代码正确运行，输出了 3 次`abc`。这表明函数内部的变量`i`与循环变量`i`不在同一个作用域，有各自单独的作用域。

#### 11.2 不存在变量提升

`var`命令会发生“变量提升”现象，即变量可以在声明之前使用，值为`undefined`。这种现象多多少少是有些奇怪的，按照一般的逻辑，变量应该在声明语句之后才可以使用。

为了纠正这种现象，`let`命令改变了语法行为，它所声明的变量一定要在声明后使用，否则报错。

```
// var 的情况console.log(foo); // 输出undefinedvar foo = 2;// let 的情况console.log(bar); // 报错ReferenceErrorlet bar = 2;
```

上面代码中，变量`foo`用`var`命令声明，会发生变量提升，即脚本开始运行时，变量`foo`已经存在了，但是没有值，所以会输出`undefined`。变量`bar`用`let`命令声明，不会发生变量提升。这表示在声明它之前，变量`bar`是不存在的，这时如果用到它，就会抛出一个错误。

#### 11.3 Temporary dead zone

只要块级作用域内存在`let`命令，它所声明的变量就“绑定”（binding）这个区域，不再受外部的影响。

```
var tmp = 123;if (true) {  tmp = 'abc'; // ReferenceError  let tmp;}
```

上面代码中，存在全局变量`tmp`，但是块级作用域内`let`又声明了一个局部变量`tmp`，导致后者绑定这个块级作用域，所以在`let`声明变量前，对`tmp`赋值会报错。

ES6 明确规定，如果区块中存在`let`和`const`命令，这个区块对这些命令声明的变量，从一开始就形成了封闭作用域。凡是在声明之前就使用这些变量，就会报错。

总之，在代码块内，使用`let`命令声明变量之前，该变量都是不可用的。这在语法上，称为“暂时性死区”（temporal dead zone，简称 TDZ）。

```
if (true) {  // TDZ开始  tmp = 'abc'; // ReferenceError  console.log(tmp); // ReferenceError  let tmp; // TDZ结束  console.log(tmp); // undefined  tmp = 123;  console.log(tmp); // 123}
```

上面代码中，在`let`命令声明变量`tmp`之前，都属于变量`tmp`的“死区”。

“暂时性死区”也意味着`typeof`不再是一个百分之百安全的操作。

```
typeof x; // ReferenceErrorlet x;
```

上面代码中，变量`x`使用`let`命令声明，所以在声明之前，都属于`x`的“死区”，只要用到该变量就会报错。因此，`typeof`运行时就会抛出一个`ReferenceError`。

作为比较，如果一个变量根本没有被声明，使用`typeof`反而不会报错。

```
typeof undeclared_variable // "undefined"
```

上面代码中，`undeclared_variable`是一个不存在的变量名，结果返回“undefined”。所以，在没有`let`之前，`typeof`运算符是百分之百安全的，永远不会报错。现在这一点不成立了。这样的设计是为了让大家养成良好的编程习惯，变量一定要在声明之后使用，否则就报错。

有些“死区”比较隐蔽，不太容易发现。

```
function bar(x = y, y = 2) {  return [x, y];}bar(); // 报错
```

上面代码中，调用`bar`函数之所以报错（某些实现可能不报错），是因为参数`x`默认值等于另一个参数`y`，而此时`y`还没有声明，属于“死区”。如果`y`的默认值是`x`，就不会报错，因为此时`x`已经声明了。

```
function bar(x = 2, y = x) {  return [x, y];}bar(); // [2, 2]
```

另外，下面的代码也会报错，与`var`的行为不同。

```
// 不报错var x = x;// 报错let x = x;// ReferenceError: x is not defined
```

上面代码报错，也是因为暂时性死区。使用`let`声明变量时，只要变量在还没有声明完成前使用，就会报错。上面这行就属于这个情况，在变量`x`的声明语句还没有执行完成前，就去取`x`的值，导致报错”x 未定义“。

ES6 规定暂时性死区和`let`、`const`语句不出现变量提升，主要是为了减少运行时错误，防止在变量声明前就使用这个变量，从而导致意料之外的行为。这样的错误在 ES5 是很常见的，现在有了这种规定，避免此类错误就很容易了。

<font color=blue>总之，暂时性死区的本质就是，只要一进入当前作用域，所要使用的变量就已经存在了，但是不可获取，只有等到声明变量的那一行代码出现，才可以获取和使用该变量。</font>

#### 11.4 不允许重复声明

`let`不允许在相同作用域内，重复声明同一个变量。

```javascript
// 报错
function func() {  
    let a = 10;  
    var a = 1;
}
// 报错
function func() {  
    let a = 10;  
    let a = 1;
}
```

因此，不能在函数内部重新声明参数。

```javascript
function func(arg) {  
    let arg;
}
func() 
// 报错
function func(arg) {  
    {    
    	let arg;  
    }
}
func() 
// 不报错
```

### 12. var

即使是在严格模式下，使用 `var` 重复声明变量不会触发错误，变量的值也不会丢失，除非新的声明有初始化器。

``` javascript
var a = 1;
var a = 2;
console.log(a); // 2
var a;
console.log(a); // 2; not undefined
```

`var` 可以与 `function` 在同一作用域中声明同名变量。在这种情况下，`var` 声明的初始化器总是会覆盖函数的值，而无论它们的相对位置如何。这是因为函数声明会提升到作用域的顶部，而初始化器会在其后才被求值，因此会覆盖函数的值。

`var` 不能与 [`let`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/let)、[`const`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/const)、[`class`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/class) 或 [`import`](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Statements/import) 在同一作用域中声明同名变量。

> 更多内容请查看文档，现在不推荐使用 var

### 13. event

JavaScript的代码一般通过事件触发。

可以通过 `addEventListener` 函数为元素绑定事件的触发函数。

示例如下：

``` javascript
// index.js
let input  =  document.querySelector(".input-text");
let run_button =  document.querySelector(".run-button")
let output =  document.querySelector(".output-text");

export function main() {
    run_button.addEventListener("mouseup", function() {
        // do something
    })
}
```

``` html
<!-- index.html -->
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Web</title>
    <script type="module">
        import { main } from "./static/js/index.js";
        main(); // 注意引入之后还需要运行main函数
    </script>
</head>

<body>  
    <style>
        textarea {
            width: 200px;
            height: 100px;
            background-color: lightblue;
            font-size: 20px;
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }
    </style>
    
    <body>  
        <label for="textarea">input</label><br/>
        <textarea class="input-text" id="textarea"></textarea><br>
        <button class="run-button">run</button><br/>
        <textarea class="output-text" id="textarea"></textarea>
    </body>
</body>

</html>
```



#### 13.1 鼠标
* click：鼠标左键点击
* dblclick：鼠标左键双击
* contextmenu：鼠标右键点击
* mousedown：鼠标按下，包括左键、滚轮、右键
  * event.button：0表示左键，1表示中键，2表示右键
* mouseup：鼠标弹起，包括左键、滚轮、右键
  * event.button：0表示左键，1表示中键，2表示右键

#### 13.2 键盘
* keydown：某个键是否被按住，事件会连续触发
  * event.code：返回按的是哪个键event.altKey
  * event.ctrlKey、event.shiftKey分别表示是否同时按下了alt、ctrl、shift键。
* keyup：某个按键是否被释放
  * event常用属性同上
* keypress：紧跟在keydown事件后触发，只有按下字符键时触发。适用于判定用户输入的字符。
  * event常用属性同上

keydown、keyup、keypress的关系类似于鼠标的mousedown、mouseup、click

> keypress 包含了 keydown&keyup 一整个过程

#### 13.3 表单
* focus：聚焦某个元素
* blur：取消聚焦某个元素
* change：某个元素的内容发生了改变

> 所谓聚焦，就是鼠标点击

#### 13.4 窗口
需要作用到window元素上。

* resize：当窗口大小放生变化
* scroll：滚动指定的元素
* load：当元素被加载完成

### 14. jQuery

jquery 是 js 的一个常用库

#### 14.1 引入 jquery 库

* 在 `<head>`元素中添加：`<script src="https://cdn.acwing.com/static/jquery/js/jquery-3.3.1.min.js"></script>`

* 按 [jQuery官网](https://jquery.com/download/) 提示下载

#### 14.2 jquery 代码智能补全

VSCode 插件 `jQuery Code Snippets`

jquery代码智能补齐，只需输入字母“jq”即可获得所有可用jQuery代码片段的列表。

代码段快捷键对照表：[jQuery Code Snippets](https://marketplace.visualstudio.com/items?itemName=donjayamanne.jquerysnippets)

#### 14.3 [jquery 语法提示](https://www.jbea.cn/archives/590.html)

（1）下载**node.js**

下载地址：[Windows (x64)](https://nodejs.org/dist/v16.17.0/node-v16.17.0-x64.msi) [Windows (x32)](https://nodejs.org/dist/v16.17.0/node-v16.17.0-x86.msi) [Mac OS](https://nodejs.org/dist/v16.17.0/node-v16.17.0.pkg)

下载后，自行安装即可，安装结束后，进入命令行提示符，输入： `npm -v` 即可查看node.js的对应的版本号。

（2）在 .vscode 所在目录下执行 `npm install @types/jquery -D`

如果在项目中出现 `node_modules` 就成功了。

#### 14.4 event.name

当存在多个相同类型的事件触发函数时，可以通过 `event.name` 来区分，例如：

``` JAVASCRIPT
let main = () => {
    $(".run").on("click.first", function() {
            alert("run.first");
    });
    $(".run").on("click.second", function() {
        alert("run.second");
        $(".run").off("click.first");
    });
}
```

我们给第一个 `class=run` 的元素添加了两个 `click` 事件，通过 `first` 和 `sceond` 进行区分。

#### 14.5 命名规范

注意 jquery 中的方法使用驼峰命名规范，因此要注意你的书写是否符合规范，例如：

``` JAVASCRIPT
$("div").fadein(2000);	// false
$("div").fadeIn(2000);	// true
```

#### 14.6 [jQuery Selector](https://www.runoob.com/jquery/jquery-ref-selectors.html)

注意与 javascript 的 `document.querySelector` 不同，

* `document.querySelector` 只选择**第一个**符合条件的元素
* jQuery  的 `$(selector)` 会选择**所有**满足条件的元素。



#### 14.7 对HTML内容、文本的操作

* `$Selector.html()`：返回，修改 html 标签内容
* `$Selector.text()`：返回，修改文本内容
* `$Selector.val`：返回，修改文本内容（多针对 text, textarea??)

#### 14.8 jquery 的选择器和 js 的选择器

通过 juqery 选择器获得的元素，调用 `ele.style.width` 显示`undefined`，而通过 `querySelector` 选择器获得的元素调用该属性能正确显式。

 我猜可能是 jquery 选择器和 `querySelector` 选择器返回元素的 “数据格式” 不同，其实也显然， jquery 选择器返回所有满足条件的元素，而 `querySelector` 只返回满足条件的第一个元素，如果我们调用 `ele.style.width` 属性，jquery 可能有多个匹配的元素，那么我们到底该返回哪一个呢？不知道，只好返回 `undefined` 了。

不过 jquery 有专门的函数用来返回 `width` 属性，那就是 `ele.cs("width")`。

下面是实现动画的例子：

（1）jquery 选择器：按下按钮即可实现动画

``` javascript
let main = () => {
    let btn = $(".run");
    let div = $(".div1");
    
    let step = (timestamp) => {
        let new_width = div.css("width");   // 返回一个带单位的字符串: 123px
        new_width = new_width.substr(0, new_width.length - 2);  // 去掉单位: 123
        new_width = parseInt(new_width) + 1; // +1: 124
        new_width = new_width + "px";   // 加上单位：124px
        div.css("width", new_width);
        requestAnimationFrame(step);
    };

    btn.on("click", function() {
        requestAnimationFrame(step);
    });
}
```

（2）querySelector 选择器：按下按钮即可实现动画

``` javascript
let main = () => {
    let btn = $(".run");
    let div = document.querySelector(".div1");
    let step = (timestamp) => {
        console.log(div.clientWidth);
        console.log(div.clientWidthidth + 1 + 'px');
        div.style.width = div.clientWidth + 1 + 'px';
        requestAnimationFrame(step);
    };
    btn.on("click", function() {
        requestAnimationFrame(step);
    });
}
```

#### 14.9 click,dblclick BUG

在 dbl click的时候，我们会按照下面顺序执行：

``` C++
clickdown;
clickup;
clickpress;
clickdown;
clickup;
clickpress;
dblckick;
```

可以发现，我们先触发了两次 click，但有时候我们并不想在双击的时候触发单击，那么该怎么办呢？

### 15. 3 Ajax

#### 15.1 概念

**Ajax**：Asynchronous Javascript And XML （异步的Javascript和XML），Ajax其实就是浏览器与服务器之间的一种**异步通信方式**。

**异步的javascript**：它可以异步的向服务器发送请求，在等待相应的过程中，不会阻塞当前页面，在这种情况下，浏览器可以做自己的事情。直到成功获取响应后，浏览器才开始处理相应数据。

**XML**：是前后端数据通信时传输数据的一种格式，但现在不常用，取而代之的是JSON格式。

**总之**：Ajax就是在浏览器不重新加载网页的情况下，对网页的某部分进行更新。

所以Ajax最大的优点就是，发送请求的时候不会影响用户的操作，相当于两条平行线一样，“你忙你的，我忙我的”，不需要去等待页面的跳转而浪费时间。

#### 15.2 使用

一般通过jquery使用ajax，现在项目中下载jquery： `npm instal jquery`

ajax的主要信息：

* url：请求地址

* type：请求方式

* data：发送到服务器的数据（将自动转换为请求字符串格式）

	发送到服务器的数据，格式是json格式或者json字符串格式。如果是 GET 请求，系统就通过 url 传递；如果是 POST 请求，系统就通过设置请求体传递。

* success：请求成功返回的回调函数

	该回调函数中的第一个参数是服务器返回的数据（拿到的只是数据），它会自动根据服务端响应的 Content-type 自动转换为对象，如果服务端没有设置响应头Content-type，返回的还是字符串类型的数据。

例如：

``` javascript
$.ajax({
   url: 'www.baidu.com',
    type: 'get',
    data: {
    	id: 1,
    	name: 'Alice',
	},
    dataType: 'json',	// 用于设置响应体的类型 注意 跟 data 参数没关系！！！
    success: function(res) {
       	// 一旦设置的 dataType 选项，就不再关心 服务端 响应的 Content-Type 了
        // 客户端会主观认为服务端返回的就是 JSON 格式的字符串
    	console.log(res);
	},
});
```

### 其他 API

<mark>不懂就查 MDN</mark>

* setTimeout, setInterval

* requestAnimationFrame

  > 区分 requestAnimationFrame 和  setTimeout与setInterval 的区别
  >
  > * requestAnimationFrame渲染动画的效果更好，性能更加。该函数可以保证每两次调用之间的时间间隔相同，但setTimeout与setInterval不能保证这点。
  > * setTmeout两次调用之间的间隔包含回调函数的执行时间；
  > * setInterval只能保证按固定时间间隔将回调函数压入栈中，但具体的执行时间间隔仍然受回调函数的执行时间影响。
  > * 当页面在后台时，因为页面不再渲染，因此requestAnimationFrame不再执行。但setTimeout与setInterval函数会继续执行。

* Map, Set

* localStorage

  > server 端存信息的几种方式： 云盘、mysql、redis ； 
  >
  > client 端存信息的几种方式：内存、storage。
  >
  > 存在 storage 中的内容会一直保存，你可以在调试模式下的 Application 中查看它，不过它只存在我们指定的网页中，换一个网页就不存在了。

* JSON

  > `JSON.stringify`
  >
  > ify ---为后缀, 使成，使……化
  >
  > 和 ize类似
  >
  > ize---为后缀,做成，变成，……化
  >
  > serial --> serialize：序列化
  >
  >
  > simple-->simplify 简单化，简化     
  >
  > string --> stringify ：字符串化

* date
* WebSocket
* window
* canvas



## 0x05 [从浏览器地址栏输入URL到显示页面的步骤](https://www.acwing.com/file_system/file/content/whole/index/content/4978948/)

1. 在浏览器地址栏输⼊URL
2. 浏览器查看缓存，如果请求资源在缓存中并且新鲜，跳转到转码步骤
   - 如果资源未缓存，发起新请求
   - 如果已缓存，检验是否⾜够新鲜，⾜够新鲜直接提供给客户端，否则与服务器进⾏验
     证。
   - 检验新鲜通常有两个HTTP头进⾏控制 Expires 和 Cache-Control ：
     HTTP1.0提供Expires，值为⼀个绝对时间表示缓存新鲜⽇期
     HTTP1.1增加了Cache-Control: max-age=,值为以秒为单位的最⼤新鲜时间
3. 浏览器解析URL获取协议，主机，端⼝，path
4. 浏览器组装⼀个HTTP（GET）请求报⽂
5. 浏览器获取主机ip地址，过程如下：
   - 浏览器缓存
   - 本机缓存
   - hosts⽂件
   - 路由器缓存
   - ISP DNS缓存
   - DNS递归查询（可能存在负载均衡导致每次IP不⼀样）
6. 打开⼀个socket与⽬标IP地址，端⼝建⽴TCP链接，三次握⼿
7. TCP链接建⽴后发送HTTP请求
8. 服务器接受请求并解析，将请求转发到服务程序，如虚拟主机使⽤HTTP Host头部判断请
   求的服务程序
9. 服务器检查HTTP请求头是否包含缓存验证信息如果验证缓存新鲜，返回304等对应状态码
10. 处理程序读取完整请求并准备HTTP响应，可能需要查询数据库等操作
11. 服务器将响应报⽂通过TCP连接发送回浏览器
12. 浏览器接收HTTP响应，然后根据情况选择关闭TCP连接或者保留重⽤，关闭TCP连接的四
    次握⼿
13. 浏览器检查响应状态吗：是否为1XX，3XX， 4XX， 5XX，这些情况处理与2XX不同
14. 如果资源可缓存，进⾏缓存
15. 对响应进⾏解码（例如gzip压缩）
16. 根据资源类型决定如何处理（假设资源为HTML⽂档）
17. 解析HTML⽂档，构件DOM树，下载资源，构造CSSOM树，执⾏js脚本，这些操作没有严
    格的先后顺序
18. 构建DOM树
19. 解析过程中遇到图⽚、样式表、js⽂件，启动下载
20. 构建CSSOM树
21. 根据DOM树和CSSOM树构建渲染树
22. js解析
23. 显示⻚⾯（HTML解析过程中会逐步显示⻚⾯）

## 0x06 react 框架

### day1

npm源：`https://registry.npmmirror.com`

----

[TODO]什么时候要用 npx？

例如：`npx create-react-app my-app`，去掉npx也可以执行



数据驱动，DOM树。

----

react 中写 JSX，然后 JSX 再编译成 JS，因为 JSX 更好写。

node就一个“脱离”浏览器的js运行环境

react每一个项目都是一个新文件夹。

----

`box.jsx`

``` jsx
import React, { Component } from 'react';

// 看起来这里没用到React,但仍必须把React引入进来
// 因为在将JSX转化为JS的过程中,需要用到React
// 将JSX中的html解释为函数调用

class Box extends Component {
    // state只是一个变量
    state = {  
        x: 1,
        colors: ["red", "blue", "green"],
    } 
    toString() {
        // es6 语法
        let {x} = this.state;
        return `x:${x}`;
    }
    // 注意下面不是在写css,而是在定义一个dict变量
    // JSX中通过dict变量实现css时,需要把a-b写为aB(驼峰)
    getStyles() {
        let styles = {
            width: "100px",
            height: "50px",
            backgroundColor: "red",
            textAlign: "center",
            lineHeight: "50px",
            borderRadius: "5px",
            marginLeft: this.state.x + 10,   // 这里不需要加{}
        }
        // 根据数据的change改变style
        if(this.state.x > 8)    // 9~   
            styles.backgroundColor = "orange";
        else if(this.state.x > 2) // 3~8
            styles.backgroundColor = "lightblue";
        return styles;
    }
    /*  react更新html页面的原理:
        每次setState都重新执行一次render,执行render中的所有语句,但此时不会渲染html
        执行完毕之后,react生成一个virtual DOM Tree,然后与原本的DOM Tree对比
        如果不一样（说明发生了变化），才重新渲染，从而减少工作量*/
    /* 下面的handler需要写成箭头形成从而绑定：
        在JavaScript中，函数里的this指向的是执行时的调用者，而非定义时所在的对象
        如果我们直接写成普通函数的形式，当我们点击按钮时，调用者是一个“onclick”事件？
        其实显示为undefined，总之，调用者不是我们的classBox，也就是说，
        this此时绑定的对象是undefined，而不是classBox，因此修改this.x无效
        所以说我们要重新设置this，使得我们调用时不重新绑定this的值
        即使this的值为其定义时所在的对象，当我们调用它时不会改变,通过箭头函数可以实现这个功能
        e.g. handleClickLeft {} 无效写法*/
    handleClickLeft = () => {
        // console.log("left", this);
        this.setState({
            x: this.state.x - 1,
        });
    }
    handleClickRight = () => {
        // console.log("right", this);
        this.setState({
            x: this.state.x + 1,
        });
    }
    // render 返回构造的html?
    render() { 
        // 注意必须用圆括号括起来
        return (
            // 一个用来满足语法要求的标签，不会被渲染
            // 如果我们用div包装，会多一个无用的div
            // 因为最外层有一个id为root的div了
            <React.Fragment>
                <h1>Hello,World!</h1>
                {/* JSX里所有的逻辑都需要用{}括起来,
                对于花括号中的内容,会被执行,注意不需要加$*/}
                <div style={this.getStyles()}>{this.state.x}</div>
                <div>{this.toString()}</div>
                {/* m-3是bootstrap的一个简写方式,即:margin=3,不过要注意
                m-2要放在class里面 */}
                {/* 注意下面的onclick事件,函数要写为fun而不是fun(),前者是绑定一个函数,
                后者是绑定一个返回值,如果我们希望传入参数，可以让onclick函数为lambda形式，然后定义一个带参数的函数，让这个lambda函数调用我们定义的带参函数即可*/}
                <button type="button" onClick={this.handleClickLeft} class="btn btn-info  m-3">left</button>
                <button type="button" onClick={this.handleClickRight} class="btn btn-primary m-3" >right</button>
                {this.state.colors.map(color => (
                    <div ket={color}>{color}</div>
                ))}                
            </React.Fragment>
        );
    }
}
 
export default Box;
```

react 会对 js文件进行打包压缩，右键网页查看源代码，发现html只link了一个js文件：` <script defer src="/static/js/bundle.js"></script>` 

map调用必须给元素加一个key属性，方便react虚拟dom树查找

---

### day2

数组和对象的展开 `...obj` 是浅拷贝，它获取的是对象的地址而不是对象的值



sfc: statelesss function component

函数组件相当于只有render函数，props作为参数传入

没有使用state就可以用(无状态)函数组件。

## project

nodejs的思想和我们些项目的思想都是一样的：一个div，一个id，剩下的都在js中实现

在些项目时，最好从上往下开发，如果从下往上开发，经常需要重构带代码。

通过 `div.card>div.card-body` 将要渲染在html上的内容封装为一个 card（方框），更漂亮。

## ES,JS,TS

什么是ES6？

ES6的全称是ECMAScript 6.0，其实看到6.0这里，大家心里就明白一点，它是某一个标准的版本，没错。

那么ES6和JS是什么关系？这里，我们可以简单的理解为，ES6是JS的语言规范，嗯这里理解就OK，因为一些版权问题，ECMAScript不能叫JavaScript，所以，就出现ECMAScript这么个玩意儿。

那么6.0是什么意思？其实，就是JS下一代的语法标准，6.0版本的JS，可以这样理解，在2015年6月正式发布的6.0，而现在许多JS框架、项目等，还在遵循ES5标准。

那么什么又是TS（TypeScript）呢？

可以这样理解，TS是JS的超集，什么意思呢？可以理解为，TS比JS更强大，“功能更全”，但是TS多了一个编译的步骤，最后，还是编译成JS代码，这样理解，虽然不太严谨，但是最为直观。

## vue

### ref_todo

[web hash history](https://www.cnblogs.com/miangao/p/17092662.html)

### day1

vue 国内用的比较多，react国外用的的比较多。

vue ui中的以来就是我们安装的包，例如bootstrap包。

插件：

* router：路由
* vuex：在多个组件之间维护同一个数据，类似react的redux

依赖：

* bootstrap：让程序员做“美工”的工作

任务：

* serve：开发环境，用于调试
* build：生产环境

同react一样，vue也会把所有所有js文件打包成一个js，右键查看网页源代码，可以看到`  <script defer src="/js/chunk-vendors.js"></script><script defer src="/js/app.js"></script></head>`> 。

网页渲染模型/方式：

* 后端渲染模型：client每请求一个页面，就给server发送一个请求，然后server返回client请求的页面
* 前端渲染模型：client第一次请求页面时，无论请求哪一个页面，server都会把所有页面的打包成一个js返回给client，这样client下次请求一个新页面时，不会再给server发送请求，而是在前端直接通过js渲染出来
* 这个可以在F12中的Network里面观察，如果我们使用的是后端渲染模型，则每次请求新页面，页面都会刷新一下，且会有新的内容从服务器返回。如果我们使用的是前端渲染模型，页面不会刷新，且网络中没有新的server传输。

``` HTML
<a>实际上是后端渲染模型
<a class="navbar-brand" href="/">BBspace</a>
    
vue提供了标签<route-lin>可以用来实现前端渲染
<route-link to={name: 'name'}></route-link>
其中'name'就是我们在/router/index.js里面变量routes中指定的name
```

vue页面：

* 每一个页面都是`.vue`文件
* 一个vue文件包含三个部分（从上到下)：html，js，cssS

style：scoped：

* vue中css的一个好处，通过设置css为scope，从而使得不同组件之间的css样式不会相互影响，其原理就是给标签加上一个随机值？

解决VSCode打开VUE项目时自动提示一条报错信息No Babel config file detected问题:

* 在vue项目中的package.json文件中使用eslintConfig字段来定义 ESLint 配置

	``` JSON
	"parserOptions": {
	    "parser": "@babel/eslint-parser",
	    "requireConfigFile": false  // add
	},
	```

App.vue 是vue项目的根组件，如果我们想引入 bootstrp，需要从该文件中引入。

vscode 插件：

* 安装了这两个插件：vetur && eslint 就各种报错，删去就没事了。。。

vue命名要求：

* 文件名必须是多单词，不能是一个单词

vue components:

* 注意拼写，是components 而不是compoents
* 组件在import引入后，其实就是作为一个class tag
* template中用到的组件都必须放到components中

ref vs. reactive:

* ref可以重新赋值，但运算慢
* reactive不可以重新赋值，但运算快

name:name 

* 可以简写为name

vue 绑定属性：

* template设置属性时，不会把`“”`里面的内容解释为字符串，而是一个表达式。

html template `{{}}`：

* 在 HTML 中，双大括号表达式通常用于表示动态生成的内容，这是一种模板语法的使用。这意味着你可以在表达式中使用变量、运算符和函数调用等JavaScript语法，从而实现更复杂的逻辑和数据操作。

信息传递：

* 父组件通过props和context向子组件传递信息

	父组件将这些信息放到 class tag中，分别通过属性`:`和事件`@`

* 子组件通过emit向父组件传递信息

	大致流程为：

	1.  先触发子组件绑定的函数 `tag`
	2. 子组件的函数调用emit `setup`
	3. emit调用父组件的事件 `tag`
	4. 父组件的事件调用父组件对应其绑定的函数 `setup`

	由于子组件和父组件都需要调用函数，因此最好让这两个函数同名，让他们之间的关系更明显。

key属性：

* 类似react，vue的循环也需要一个key属性，用来实现优化。通常可以在for循环时获取index，然后利用该index作为key，不过使用index作为下标有一个风险就是当我们删除或者插入元素后，后续元素的index可能发生变化，因此并不推荐使用下标。



### day2

在vue里面，我们维护的是一个树形结构，这就导致非父子节点之间传输数据十分不方便，为了解决这个问题，vue引入了“全局变量”：vuex，类似于react的redux。

* GET参数：url，不太安全

* POST参数：body，安全



所谓浏览器的异步就是，如果我们的某个请求使得浏览器需要等待，那么浏览器就会先去执行其他请求。一般默认访问链接是异步的？

bug：只要刷新登录状态就会消失，解决方案：将access存在localStorage里面。

有很多操作需要我们分别在前端和后端处理，例如我们希望删除一个用户发送的信息，我们既要在前端删除掉这个内容，又要在后端真的删除掉这个数据，否则前后端数据就会不一致。如果我们只在前端删除，而没有在后端删除，那么用户的删除就是在骗自己，因为下次登录时该信息仍会显示，因为他没有在后端删除掉。

## bootstrap

container，fluid：响应式布局

响应式调整页面的布局，如果们需要这么做，就把目标内容用一个 div，class=container括起来就行了。

