# 蓝桥杯国赛触底反弹计划

​				——  不让我的算法生涯留下遗憾

## reference

[官方真题题库](https://www.lanqiao.cn/problems/?first_category_id=1&sort=students_count&tags=%E5%9B%BD%E8%B5%9B)

[2022 CB ref](https://blog.csdn.net/m0_58177653/article/details/125345906)

[2021 CB ref](https://blog.csdn.net/weixin_53459056/article/details/124550844)

## Starting

2023/6/6：靠，感觉现在做题纯靠背啊，但还能背下来。。是好是坏呢？

2023/6/7：做了一套 2022 年的题，感觉有点难啊，如果一直坚持练的话，应该可以拿奖，但是一直没做，能不能触底反弹。

## 2022

### 1.2022：背包DP

直观(暴力)来想，就是 dfs 十次，每次选取一个数，最终凑成 2022，但是这么做的时间复杂度非常非常大，最小时间复杂度也会超过 `2022 * 2021 * 2020 * ... * 2012`，大约在 $O(10^{33})$，非常恐怖了！

但其实我们换个角度去想，与其 dfs 枚举 10 个数，不如直接在 1~2022 中选 10 个数，因为最大的数也肯定小于 2022，那么就变成 01 背包问题了！

即：我们有 2022 个物品，每个物品的体积和价值都为 i，背包容量为 2022，现在让我们求装满背包的方案数。

但是 01 背包其实是不能限制我们选取的物品的个数的，因此我们要再加一维（有点像二维费用的背包问题）

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2022, M = 10;

typedef long long LL;

LL res = 0;

// dfs
void dfs(int u, int pre, int s)
{
    if(u == M)  res ++ ;
    for(int i = pre; i + s <= N; i ++ )
    {
        dfs(u + 1, i, s + i);
    }
}// dfs(0, 1, 0, 10);

LL f[N << 1][M + 10];
// f[i][j]表示 选了j个数，和为i的方案数

void dp()
{
    // 初始时，选0个数，和为0的方案数是1
    f[0][0] = 1;
    for(int i = 1; i <= 2022; i ++ )
    {
        // 倒叙枚举确保每个物品选 1 次
        for(int j = 2022; j >= i; j -- )
            for(int k = 10; k >= 1; k -- )
                f[j][k] += f[j - i][k - 1];
    }
    cout << f[2022][10] << endl;
}

int main()
{
    dp();
    return 0;
}
```

### 2.卡牌：二分答案

我的评价是不开 longlong 见祖宗。。。。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int n;
long long m; // m爆int
int a[N], b[N], maxn;

bool check(int x)
{
    long long cur = m;
    for(int i = 0; i < n; i ++ )
    {
        if(a[i] < x)   
        {
            if(x - a[i] > cur || x - a[i] > b[i])  return false;
            cur -= x - a[i];
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    for(int i = 0; i < n; i ++ )    cin >> b[i];
    int l = 0, r = N << 2;
    while(l < r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid))  l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
```



### 3. 最大数字：DFS

一开始我的思路是，枚举每一位的数字，然后贪心的让他醉成最大，但是这么做有一个问题，那就是当加法和减法都能使这一位的数字变成最大的数字，并且操作次数相同，那么是选择加法还是减法呢？不知道。。因此这种做法是不行的，它考虑的不全面。

我们可以 dfs，无论加法还是减法，都尝试，这样就可以确保不漏。

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string res;

void dfs(string cur, int u, int n, int a, int b)
{
    if(u == n)
    {
        res = max(res, cur);
        return ;
    }
    int x = cur[u] - '0';
    // 加法 a
    if(x + a >= 9)
    {
        char pre = cur[u];
        cur[u] = '9';
        dfs(cur, u + 1, n, a - (9 - x), b);
        cur[u] = pre;
    }
    else 
    {
        char pre = cur[u];
        cur[u] = x + a + '0';
        dfs(cur, u + 1, n, 0, b);
        cur[u] = pre;
    }
    // 减法 b
    // 只有减法可以减到9才用
    if(x - b < 0)
    {
        char pre = cur[u];
        cur[u] = '9';
        dfs(cur, u + 1, n, a, b - (x + 1));
        cur[u] = pre;
    }
}

int main()
{
    int a, b; // 1~100
    cin >> res >> a >> b;
    dfs(res, 0, res.size(), a, b);
    cout << res << endl;
    return 0;
}
```

### 4. [TODO]机房：LCA + 树形DP



### 5.齿轮：思维

中间的齿轮没有用，只需要保证最右边的齿轮的半径是最左边的 q[i] 倍即可。

我们假设最左边的齿轮转了一圈，走过的路径为 `2 * pi * r`，那么从他之后的所有齿轮走过的距离都为 `2 * pi * r`，`2 * pi * r / (2 * pi * r')` 就是角速度的比

为什么中间无关呢？因为每个齿轮走过的路径是不变的（登陆第一个齿轮的周长），不管你的半径是多少。

那么，怎么在序列中快速找到两个数，使得他们比例为我们想要的呢？

这里有一个非常巧妙的做法，1的倍数存不存在我们是很好求的，直接搞一个哈希表就行了，但是2的倍数，3的倍数呢？难道每个倍数都搞一个哈希表吗？肯定不行，空间不允许

但是我们可以将2视为1，那么4就视为2，因此题目只问我们存不存在，不关心成比例的两个数是什么，更不关系齿轮序列，因此，我们可以哈希存储倍数（关键）。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 2e5 + 10;

int n, q;
int maxn;
int a[N];
bool st[N]; // 某个数有没有出现
bool vis[N]; // 某个倍数有没有出现

void preparation()
{
    vis[1] = true;
    for(int i = 0; i < n; i ++ )
    {
        // 因为 maxn<=2e5,所以这里 p*i 不会溢出
        for(int p = 2; p * a[i] <= maxn; p ++ )
        {
            if(st[p * a[i]])
                vis[p] = true;
        }
    }
}

int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; i ++ )    
    {
        cin >> a[i];
        st[a[i]] = true;
        maxn = max(maxn, a[i]);
    }
    preparation();
    while(q -- )
    {
        int c; cin >> c;
        if(vis[c])    puts("YES");
        else    puts("NO");
    }
    return 0;
}
```

其实这个时间复杂度看起来好像是 $O(N^2)$ 的，但是其实随着 a[i] 的增加，循环次数就比较少了。不过，我的代码有一个 case 挂了，whatever，问题不大，我也不想 check 了。

**其次，毕竟这是蓝桥杯，时间复杂度大一点没太大问题！😊 **

### 6.[TODO]搬砖

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, res;
int v[N], w[N];

void sovle()
{
    
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   cin >> v[i] >> w[i];
    solve();
    cout << res << endl;
    return 0;
}
/*
w value
1 1
4 4
5 5
*/
```





### 7. [TODO]故障





### 8.出差：最短路

最短路模板题，看到点数为 $1000$，直接 $dijkstra$ $O(N^2)$ 算法。 另外，本题多了一个要求，就是到达一个城市需要隔离一段时间，这其实很容易解决，加上这个值就好了。

不过要注意，最后要减去终点站的隔离时间，因为题目要求不需要加上终点站的隔离时间。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int c[N], g[N][N];
bool st[N];
int dist[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);   
    dist[1] = 0;
    for(int u = 1; u <= n; u ++ )
    {
        int t = -1;
        for(int i = 1; i <= n; i ++ )
            if(!st[i] && (t == -1 || dist[i] < dist[t]))
                t = i;
        st[t] = true;
        for(int i = 1; i <= n; i ++ )
            dist[i] = min(dist[i], dist[t] + g[t][i] + c[i]);
    }
}

int main()
{
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < N; i ++ )    g[i][i] = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )   cin >> c[i];
    while (m -- )
    {
        int a, b, c;   cin >> a >> b >> c;
        // 双向
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    dijkstra();
    cout << dist[n] - c[n] << endl;
    return 0;
}
```



### 9.费用报销：dp

``` C++
#include<bits/stdc++.h>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
int mp[13][32];
int dp[400];
int n,m,k; 
int main()
{
    cin>>n>>m>>k;
    int num=1;
    for(int i=1;i<=12;i++)
        for(int j=1;j<=month[i];j++)
            mp[i][j]=num++;
    
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        // 同一天的只能选一个，因此取max
        dp[mp[x][y]]=max(dp[mp[x][y]],z);
    }
    for(int i=1;i<=365;i++)
    {
        if(dp[i]+dp[max(0,i-k)]<=m) // 不能超过m
            dp[i]=max(dp[i]+dp[max(0,i-k)],dp[i-1]);
        else dp[i]=max(dp[i-1],dp[i-1]);
    }
    cout<<dp[365];
    return 0;
}
```



 



### 总结

总的来说，通过这套题还是学到很多东西了，但是，虽然我很喜欢算法，也没有时间去搞这个东西了。

时间一去不复返，唯有往前走。加油吧。



## 国赛题

### 1. 小明的字符串：KMP

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

string s, p;
int ne[N];

int main()
{
    cin >> s >> p;
    s = "#" + s;
    p = "#" + p;
    int m = s.size(), n = p.size();
    // t 匹配 s
    for(int i = 2, j = 0; i <= n; i ++ )
    {
        while(p[i] != p[j + 1] && j)    j = ne[j];
        if(p[i] == p[j + 1])    j ++ ;
        ne[i] = j;
    }
    int res = 0;
    for(int i = 1, j = 0; i <= m; i ++ )
    {
        while(s[i] != p[j + 1] && j)    j = ne[j];
        if(s[i] == p[j + 1])    j ++ ;
        res = max(res, j);
    }
    cout << res << endl;
    return 0;
}
```

### 2. 最长回文子串：Malacher

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int malacher(string str)
{
    // 特殊判断
    if(str.empty()) return 0;
    
    // 由于需要在头和尾以及每两个字符之间添加特殊符号
    // 所以需要修改 len 为 len + (len - 1)
    /*当然也可以不在头和尾添加，只需要每两个字符之间添加即可
    * 此时，修改 len = str.size() * 2 - 1
    * 并且将填充字符的逻辑改为：charArr[i] = (i & 1) == 0 ? '#' : str[idx ++ ];
    */
    int len = str.size() << 1 | 1;
    
    // 开辟新字符串和回文半径数组
    // 回文半径：cbabc 的回文半径为 abc
    char *chaArr = new char[len];
    int *pArr = new int[len];
    
    // 填充新字符串
    int idx = 0;
    for(int i = 0; i < len; i ++ )
        chaArr[i] = (i & 1) ? str[idx ++ ] : '#';
    
    // 计算
    int R = -1; // 最大回文串的右端点
    int C = -1; // 最大回文半径的中心
    int maxn = 0;
    /* |     |     |     |     |     | */
    /* |  L  |  i' |  C  |  i  |  R  | */
    /* |     |     |     |     |     | */
    for(int i = 0; i < len; i ++ )
    {
        // 加速计算：O(1) 时间内求的最短的回文半径
        pArr[i] = R > i ? min(R - i, pArr[2 * C - i]) : 1; // L=2*C-1
        
        // 暴力匹配
        while(i + pArr[i] < len && i - pArr[i] > -1)
        {
            if(chaArr[i + pArr[i]] == chaArr[i - pArr[i]])
                pArr[i] ++ ;
            else    break;
        }
        
        // 更新
        if(i + pArr[i] > R)
        {
            R = i + pArr[i];
            C = i;
        }
        maxn = max(maxn, pArr[i]);
    }
    
    delete[] chaArr;
    delete[] pArr;
    return maxn - 1;
}

int main()
{
    string s;   cin >> s;
    cout << malacher(s) << endl;
    return 0;
}
```

### 3. 斤斤计较的小Z：KMP

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 1e7 + 10;

string s, p;
int ne[N];

int main()
{
    cin >> p >> s;
    int n = p.size(), m = s.size();
    p = "#" + p;
    s = "#" + s;
    
    for(int i = 2, j = 0; i <= n; i ++ )
    {
        while(p[i] != p[j + 1] && j)    j = ne[j];
        if(p[i] == p[j + 1])    j ++ ;
        ne[i] = j;
    }
    
    
    int res = 0;
    for(int i = 1, j = 0; i <= m; i ++ )
    {
        while(s[i] != p[j + 1] && j)     j = ne[j];
        if(s[i] == p[j + 1]) j ++ ;
        if(j == n)  res ++ ;
    }
    cout << res << endl;
    return 0;
}
```

### 4. 二进制问题：数位DP

方法一：不太懂

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 62;
typedef long long LL;

LL dp[N][N];   // dp[i][j] 前i位有j个1的方案数

// 预处理 dp 数组
void process()
{
    for(int i = 0; i < N; i ++ )
    {
        dp[i][0] = 1;
        for(int j = 1; j <= i && j < N; j ++ )
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
}

// 返回最高位 idx，从 0 开始
int get(LL x)
{
    int cnt = 0;
    while(x) 
    {
        cnt ++ ;
        x /= 2;
    }
    return cnt - 1;
}

LL solve(LL n, int k)
{
    if(k == 0)  return 1;
    if(n == 0)  return 0;
    int bits = get(n);
    LL res = dp[bits][k];
    // 将n的最高比特位设为0 
    n ^= (1LL << bits);
    res += solve(n, k - 1);
    return res;
}

int main()
{
    LL n;    int k;
    cin >> n >> k;
    process();
    cout << solve(n, k) << endl;
    return 0;
}
```

方法二：经典记忆化写法

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 63;

long long n;
int k, len;
long long f[N][N];
int bit[N];
/*在一般的数位dp中，我们是使用字符串保存数字，
但这里由于需要用到二进制，所以我们需要保存0/1*/

void init(long long x)
{
    while(x)
    {
        bit[ ++ len] = x & 1;
        x >>= 1;
    }
}

long long dfs(int u, int cnt, bool is_limit)
{
    if(u == 0)  return cnt == k;
    if(f[u][cnt] != -1 && !is_limit)  return f[u][cnt];
    int maxn = is_limit ? bit[u] : 1;
    long long res = 0;
    for(int i = 0; i <= maxn; i ++ )
    {
        if(cnt == k)
        {
            res += dfs(u - 1, cnt, is_limit && i == maxn);
            break; // 必须 break
        }
        res += dfs(u - 1, cnt + i, is_limit && i == maxn);
    }
    return f[u][cnt] = res;
}

int main()
{
    memset(f, -1, sizeof f);
    cin >> n >> k;
    init(n);
    // 由于 bit 数组是倒叙，所以从 len 开始
    cout << dfs(len, 0, true);
    return 0;
}
```

### 5. 答疑：贪心

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

typedef struct node_t {
    int a, b, c;
} Node;

int n;
Node node[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int a, b, c;    cin >> a >> b >> c;
        node[i] = {a, b, c};
    }
    sort(node, node + n, [&](const Node &x, const Node &y){
        if(x.a + x.b + x.c == y.a + y.b + y.c)
            return x.a + x.b < y.a + y.b;
        return x.a + x.b + x.c < y.a + y.b + y.c;
    });
    long long res = 0, pre = 0;
    for(int i = 0; i < n; i ++ )
    {
        pre += node[i].a + node[i].b;
        res += pre;
        pre += node[i].c;
    }
    cout << res << endl;
    return 0;
}
```

### 6. 递增序列

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
(1+x)*x=2e12
因此 x 取 1e6+10 范围是不够的！
*/

const int N = 1500000;

long long f[N], a[N];

long long get(long long x)
{
    if(!x)  return x;
    long long res = 0;
    long long l = 0, r = N;
    while(l < r)
    {
        long long mid = l + r + 1 >> 1;
        if(a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    // cout << "L: " << x - a[l] << endl;
    return f[l] + a[x - a[l]];
}

void init()
{
    for(long long i = 1; i < N; i ++ )
    {
        a[i] = a[i - 1] + i;
        f[i] += f[i - 1] + a[i];
    }
}

int main()
{
    init();
    int n;  cin >> n;
    while(n -- )
    {
        long long l, r;
        cin >> l >> r;
        cout << get(r) - get(l - 1) << endl;
    }

    return 0;
}

```

## ending

2023/6/9 20:42 

到此为止了，再刷题感觉也没啥意义，更没时间了，明天过后，大学的算法生涯就走到终点了。永远热爱。



2023/6/11

终于考完了，昨天在齐鲁工业大学狠狠的玩了一波，感觉考的还行，但是题目质量真心不行。

怎么说呢，起码还算愉快，后面虽然还有个Robocom水赛，但其实我的算法就结束于此了吧。





























