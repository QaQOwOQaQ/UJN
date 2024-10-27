# MIT Linear Algebra

## 0x00 preface

[笔记](https://randomwalk.top/archives/569)

[笔记2](https://zhuanlan.zhihu.com/p/45707832)

[矩阵相乘的变换为什么总会伴随“颠倒”顺序？](https://www.zhihu.com/question/430903721)

[理解矩阵](https://blog.csdn.net/myan/article/details/647511)

[**为什么可逆矩阵又叫“非奇异矩阵(non-singular matrix)”?**](https://blog.51cto.com/marsggbo/2799623)

## 0x01  TODO

截止到 `p22 28:00`

## 0x02 note

### 1. 矩阵除法

矩阵的乘除不能简单的看成数字间的乘除。矩阵代表一个映射法则。比如y=Ax说的是ｘ通过Ａ映射变成了ｙ。现在我想知道怎样才能从ｙ回到ｘ，答案就是Ａ的逆。并且Ａ的逆不一定存在就像不是所有的映射都有逆映射。

> [ref](https://www.zhihu.com/question/27737069)

> jyyyx：矩阵不存在除法的形式，只有乘以逆！
>
> 例如：$A*B=C*D*X$
>
> $X != \frac{A*B}{C*D}$ (错误，不应该从除法的角度考虑)
>
> $X == C^{-1} * D^{-1} *A * B$（正确，应该从逆的角度考虑） 



# MIT18.06 Linear Algebra

## 0x00 TODO

[1](https://www.zhihu.com/question/28623194/answer/135658852)

[2](http://www.matrix67.com/blog/)

[3](http://www.matrix67.com/blog/archives/4294)

## 0x01 站在巨人的肩膀上

[课程视频](https://www.bilibili.com/video/BV16Z4y1U7oU/?spm_id_from=333.337.search-card.all.click&vd_source=38033fe3a1f136728a1d6f8acf710b51)

[线性代数的本质](https://www.bilibili.com/video/BV1ib411t7YR/?spm_id_from=333.337.search-card.all.click&vd_source=38033fe3a1f136728a1d6f8acf710b51)

[官网](https://mitmath.github.io/1806/)

[笔记1](https://www.zhihu.com/column/c_1086313475025907712)

[笔记2](https://zhuanlan.zhihu.com/p/45707832)

– 课本 – 

[线性代数引论 (豆瓣) (douban.com)](https://book.douban.com/subject/1231156/)

[线性代数的几何意义 (豆瓣) (douban.com)](https://book.douban.com/subject/26651221/)

[Introduction to Linear Algebra (mit.edu)](https://math.mit.edu/~gs/linearalgebra/)

[线性代数 第五版中译版（ Introduction to Linear Algebra 5th edition中译版）_Gilbert Strang_孔夫子旧书网 (kongfz.com)](https://book.kongfz.com/424918/3901589216/)

## 0x01 方程组的几何表示

[向量、向量的加减法与向量的数乘](https://sxyd.sdut.edu.cn/_upload/tpl/02/32/562/template562/onlineLearning/gaodengshuxueshang/lesson/7.2%20%20xiangliangdeyunsuan.htm)

[向量](https://blog.csdn.net/deepdsp/article/details/24358403)

AX=b，A是系数矩阵，b是结果，X是未知量的集合

行图像，列图像

两点成线，三点成面

两个相交的平面可以确定一条直线

## 0x02 矩阵消元（高斯消元）

矩阵并不总是有解

主元：系数矩阵左上到右下的元素（主元不能为0，如果0占据了主元的位置，交换行即可）

主元行：当前处理的主元所在行

主元列：当前处理的主元所在列

高斯消元法：主元行不变，主元行下面的每一行的主元列的系数消为0，最后可以得到一个上三角矩阵，然后从下而上（回代）就能计算出解（高斯消元有点像从上而天下（递归）的过程）

矩阵消元的过程就是得到上三角矩阵的过程（matlab即是如此）

增广矩阵U：增广就是增加的意思，相对于系数矩阵，增广矩阵就是新增加的一列

矩阵乘向量的结果是矩阵列的线性组合，如下图所示：

![img](https://s3.bmp.ovh/imgs/2023/01/31/10cab963b7fa1217.png)

![](https://s3.bmp.ovh/imgs/2023/01/31/2bba32a013070559.png)

矩阵乘一列得到一列，一行乘矩阵得到一行

如果要通过矩阵E对矩阵A进行行变换，就要`E*A`，如果进行列变换，就要`A*E`。换言之，列变换时，矩阵右乘，行变换时，矩阵左乘。如下图：

![i](https://s3.bmp.ovh/imgs/2023/01/31/1e39da271140943f.png)

(列变换，一次取一列进行检验，得到一列)

具体为，先取列01，再取列10，分别与[ab|cd]相乘

![img](https://s3.bmp.ovh/imgs/2023/01/31/caa3a8c7c2811290.png)

（行变换，一次取一行进行检验，得到一行）

具体为：先取行01，再取行10，分别于[ab|cd]相乘







单位矩阵：用单位矩阵乘矩阵M，矩阵M不变

初等矩阵：改变矩阵某一行

置换矩阵P：permutation(置换)，交换矩阵的行

对于矩阵A,B,C，`A*B*C`中A,B,C的位置顺序不可变，不可以变为`B*C*A`，但是乘法的顺序是可变的，例如我们可以先求`B*C`，也可以先求`A*B`。这可以看做矩阵中存在一对改变乘法顺序的括号，我们可以改变括号的位置，就前面的例子而言，先求`B*C`就是`A*(B*C)`，先求`A*B`就是`(A*B)*C`。这种可以“移动括号”的定律的学名就叫做“结合律”。也就是说，**矩阵乘法满足结合律，不满足交换律**。

 

## 0x03 乘法与逆矩阵

`矩阵*逆矩阵=单位矩阵`



