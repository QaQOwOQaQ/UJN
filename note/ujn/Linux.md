# 写在前面

- [入门视频](https://www.bilibili.com/video/BV16Q4y1y7xS?p=58&spm_id_from=pageDriver)
- [命令搜索](https://g-ghy.github.io/linux-command/#!kw=.)
- [Git学习](https://learngitbranching.js.org/?locale=zh_CN)
- [ACWing工程答案](https://www.acwing.com/activity/content/code/content/2241576/)

------

# 一、Linux目录

## 目录表示方法

```bash
/       根目录
./      当前目录
.       当前目录
../     父目录
../..   祖父目录
```

## cd命令使用技巧

```bash
cd      进入用户主目录
cd ~    进入用户主目录
cd -    返回进入此目录之前所在目录
cd ..   返回上一级目录
cd ../..返回上两级目录
cd !$   把上个命令的参数作为cd参数使用
```

## '.'和'./'区别

- `.`：执行文件/表示当前目录
- `./`：执行当前目录下的文件
- **共同点**：都表示当前目录，但`./`专用于执行文件

------

# 二、配置ssh免密登录

1. 修改配置文件：

   ```bash
   vim .ssh/config
   ```

   添加内容：

   ```bash
   Host 免密登录名
     HostName ip
     User 用户名
     Port 端口号
   ```

2. 复制公钥：

   ```
   ssh-copy-id 免密登录名
   ```

------

# 三、标准输入和命令参数

## 错误示例

```bash
find / -name test.sh | rm  # 错误！
```

## 正确解决方案

1. 

   ```bash
   rm -rf $(find / -name test.sh)
   ```

2. bash使用xargs：

   ```bash
   find / -name test.sh | xargs rm -rf
   ```

## 核心区别

- 管道符`|`：将数据作为标准输入
- `$()`：将数据作为命令行参数
- `xargs`：将标准输入转为命令行参数

------

# 四、查找多文件

## 错误示例

```bash
find /tmp -maxdepth 1 -mtime 30 -name *.pdf
# 报错：find: paths must precede expression
```

## 正确写法

```bash
find ./ -mtime +30 -type f -name '*.php'
```

## 原理说明

- 星号会被Shell展开为当前目录所有文件
- 解决方案：
  - 加单引号：`'*.txt'`
  - 转义：`\*.txt`

------

# 五、持久化修改环境变量

1. 修改`~/.bashrc`文件（隐藏文件）

2. 在文件末尾添加修改命令

3. 使修改生效：

   ```bash
   source ~/.bashrc
   ```

------

# 六、Docker

## 核心概念

- **镜像(Image)**：模板
- **容器(Container)**：镜像的实例
- 继承关系：镜像可以基于其他镜像/容器创建
- 空间优化：相同部分只保存一份

## 常用操作

### 镜像操作

```bash
docker save -o 文件名 镜像名称    # 导出
docker image rm IMAGE          # 删除
```

### 容器操作

```bash
docker ps -a                   # 查看所有容器
docker start/stop CONTAINER    # 启停容器
docker run -it CONTAINER       # 创建并进入容器
docker rm CONTAINER            # 删除容器
docker container prune         # 清理已停止容器
```

### 端口映射示例

```bash
docker run -p 20000:22 --name my_docker_server -itd docker_lesson:1.0
```

------

# 七、Git

## 核心概念

```
工作区 → 暂存区 → 版本库
        (缓冲区)
```

## 基础配置

```bash
git config --global user.name xxx
git config --global user.email xxx@yyy.com
git init
```

## 文件操作

### 撤销修改

```bash
git restore xx          # 用暂存区版本撤销工作区修改
git restore --staged xx # 撤销暂存区修改
```

### 删除文件

```bash
git rm filename         # 删除工作区和暂存区文件
git rm --cached filename # 仅删除暂存区文件
```

## 项目上传流程

```bash
git remote add origin git@git.acwing.com:Tigger/git.git
git add .
git commit -m "Initial commit"
git push -u origin main
```
