#### 2. 基本概念

- **JDK、JRE、JVM的关系**：
  - JDK：Java Development Kit，Java开发工具包
  - JRE: Java Runtime Environment，Java运行环境
  - JVM：Java Virtual Machine，Java虚拟机
  - JDK包含JRE，JRE包含JVM
  - JRE较于JVM多了一些库和包，JDK较与JRE多了编译和调试工具
- **JDK版本选择**
  - 目前JDK1.8（也叫JDK8，注意不是JDK18）用得最多
- **Java代码的编译运行流程**
  - 将Java源码编译成Java字节码
  - 使用JVM将Java字节码转化成机器码
  - JVM作用：跨平台、内存管理、安全
- **JSE、JEE、JME的区别**
  - JSE: Java Standard Edition，标准版
  - JEE：Java Enterprise Edition，企业版
  - JME: Java Mirco Edition，移动版
  - Spring是JEE的轻量级替代品
  - SpringBoot是Spring + 自动化配置

------

### 数据类型与运算

隐式数据类型可以从高到低转，不可以低到高转
[long类型详解](https://blog.csdn.net/shenhaiyushitiaoyu/article/details/109013954?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-109013954-blog-54583805.pc_relevant_antiscanv2&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-109013954-blog-54583805.pc_relevant_antiscanv2&utm_relevant_index=1)

------

### 开发相关

- `shift+f10`运行
- `sout`快速生成输出语句
- C++可以用`%s`输出一个字符串但不能输出一个String
- C++可以用字符数组表示字符串（`char a[] = "Hello,World!";`），但Java不行

------

### 对象比较

Java中判断两个对象是否相等不能直接用等号（比较的是地址），要用`a.equals(b)`

------

### 关键语法要点

1. `final`定义常量

2. 使用`float`和`long`进行强制类型转换：

   - 数字后加`L`或`F`，或前面加`(float)`/`(long)`
   - 自动转换规则说明（int→long, double→float）

3. 运算优先级：

   - 单目运算`+-`和赋值`=`自右向左
   - 一般运算自左向右

4. 浮点数转整数：

   ```java
   x = (int)10/3.0;  // wrong
   x = (int)(10/3.0); // correct
   ```

5. 关系运算符：

   - 优先级：算术 > 关系 > 赋值
   - `==`和`!=`优先级更低
   - 不能直接比较`true/false`与数字

6. 浮点运算误差处理：

   - `0.1*10 != 1`
   - 正确方法：`a - b < 1e-6`

7. Java不允许`while(数值)`写法（如`while(1)`）

8. `Math.random()` → [0, 1)

------

### 编程技巧

1. 数字反转算法：

   ```java
   while(goal){
     int t = goal % 10;
     goal /= 10;
     res = res * 10 + t;
   }
   ```

2. 循环标号：

   ```java
   Label:
   break Label;  // 结束多重循环
   ```

3. 控制小数位数：`%.2f`

4. 数组长度属性：`array.length`

5. 数组初始化：

   ```java
   int[] num = {1, 2, 3};  // 自动初始化为0
   ```

6. 引用类型说明（数组管理者概念）

7. for-each循环：

   ```java
   for(int k : data)
   ```

8. `\t`对齐功能说明

------

### 高级特性

1. 包裹类型方法：`Integer.bitCount(i)`
2. 字符串特性：
   - `String`是类，不可变
   - `s.charAt(i)`访问字符
3. 方法本质说明
4. 代码优化建议（单一出口原则）
5. 类型转换顺序：`char→int→double`
6. Java参数传递规则（值传递）
7. 函数调用内存机制

------

### 技术体系

#### 基础层

- Java基础
- 前端三件套（HTML/CSS/JS）
- jQuery/Ajax/Vue
- 微信小程序
- 动态网页开发

#### 进阶层

- JVM优化
- 数据结构算法
- 软件项目管理（Maven/SVN/Git/Jenkins）

#### 框架层

- SSM框架
- Mybatis-Plus
- Spring生态（Data/Boot）

#### 分布式

- Dubbo/Zookeeper
- SpringCloud/Eureka
- Skywalking

#### 中间件

- 消息队列（RocketMQ/Kafka）
- 数据库中间件（Sharding-JDBC）
- NoSQL（Redis/MongoDB）

#### 运维技术

- 服务器（Tomcat/Linux）
- 虚拟化（CentOS/Ubuntu/Virtualbox/Vmware）
- Docker容器

#### 解决方案

- 搜索（Elasticsearch/Lucene）
- 定时任务（Quartz/Elastic-Job）
- 安全（SpringSecurity）
- 工作流（Activiti）