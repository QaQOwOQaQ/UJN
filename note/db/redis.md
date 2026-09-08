# Redis

## 0x00 conf

### 1. Introduce

[菜鸟教程](https://www.runoob.com/redis/redis-tutorial.html)

### 2. 相关资源

[官网](https://redis.io/)

[SourceCode](https://github.com/redis/redis)

[命令参考](http://doc.redisfans.com/)

[在线命令测试](https://try.redis.io/)

### 3. [在Docker中使用Redis](https://cloud.tencent.com/developer/article/1678634)

1. 连接容器

2. 登陆 redis 用户界面：`redis-cli`

> **命令行界面**（英语：**C**ommand-**L**ine **I**nterface，缩写：**CLI**）是在[图形用户界面](https://zh.wikipedia.org/wiki/图形用户界面)得到普及之前使用最为广泛的[用户界面](https://zh.wikipedia.org/wiki/用户界面)，它通常不支持[鼠标](https://zh.wikipedia.org/wiki/鼠标)，用户通过[键盘](https://zh.wikipedia.org/wiki/键盘)输入指令，计算机接收到指令后，予以执行。也有人称之为**字符用户界面**（character user interface, CUI）。

### 4. 修改端口号

redis 默认端口号为 `6379`，而我已经有了一个 docker 容器占用了此端口号，因此我的 mac 本地和 ubuntu 都需要修改端口号。

1. 修改 conf 文件

>  `cd /etc/redis`，先备份 `redis.conf` 到 `redis_back.conf` 然后修改 `redis.conf` 中的 `port` 为没有被占用的端口号。

2. 重启 redis 使得 conf 文件生效

> `sudo ervice redis-server restart`

参考

> [ref here](https://blog.csdn.net/banfushen007/article/details/99316845)

### 5. 修改密码

1. 修改 conf 文件

> 找到 `#requirepass foobared` 这一行，将注释去掉，修改 `foobared` 为自己要设置的密码。
>
> 注意 vim 下 `:/` 搜索，查找下/上一个匹配项是 `n/N`，不是回车。

2. 重启 redis 使 conf 生效

> `sudo service redis-server restart`

### 6. redis-cli

`-a` 参数指定密码

`-p` 指定端口号

`-h` 指定 IP 地址

`–no-auth-warning` 忽略警告信息

如果你开启了密码，即使不指定密码也能登陆，但无法使用，有两种方式指定密码：

1. `redis-cli -a`，通过这种方式指定的密码会显示在 `command line`，不安全，因为通过 `history` 可以查看。
2. 通过 `redis-cli` 登陆之后，使用 `auth` 命令输入密码，虽然也会显示，但是他不会记录在 `history` 中。

> Do not use '-a', instead, running `auth password` explicitly in `redis-cli` shell. `Auth` command does not save in Redis-cli's command history.

### 7. Ubuntu 下 redis 数据目录

`/var/lib/redis` 下的 `dump.rdb` 文件



### 8. 下标

在 `redis` 世界中，下标从 0 开始



### 9. 事务

单个 Redis 命令的执行是原子性的，但 Redis 没有在事务上增加任何维持原子性的机制，所以 Redis 事务的执行并不是原子性的。

事务可以理解为一个打包的批量执行脚本，但批量指令并非原子化的操作，中间某条指令的失败不会导致前面已做指令的回滚，也不会造成后续的指令不做。

## 0x01 noun

daemonize：守护进程

blpop: blocking left pop

brpop: blocking right pop

sard: set cardinality(势,基数)

## 0x02 DataStruct

1. string
2. hash
3. list
4. set
5. zset(sorted set)



## 0x03 command

### 1. KEY

``` shell
keys pattrn
type key
rename key newname
exist key
del key
dump key
random key
select idx
```

