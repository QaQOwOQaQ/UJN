## RoBoCom

### preface

不收录大水题，考研之余的放松吧，刷题能麻木自己😭

傻逼模拟题一道也不可能再做了，纯粹的浪费时间，浪费生命！

### template

```  c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve()
{
    
}

int main()
{
    solve();
    return 0;
}
```



### 2021 高职组

#### 初赛 6 模拟

在这个二维码坐标系中，行其实是列，列其实是行，左下角为（1，1），右上角为（n，n）

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 110;

// case1: 4位整数
// case2: 两小问
// case3：分数

int n, m;
bool s[N][N];

void split(string s, int &x, int &y)
{
    int pos;
    if((pos = s.find(";")) != -1) // case3
    {
        x = stoi(s.substr(0, pos));
        y = stoi(s.substr(pos + 1));
    }
    else if((pos = s.find("/")) != -1) // case2
    {
        x = stoi(s.substr(0, pos));
        y = stoi(s.substr(pos + 1));
    }
    else // case1 
    {
        while(s.size() < 4) s = "0" + s;
        x = stoi(s.substr(0, 2));
        y = stoi(s.substr(2));
    }
    // cout << x << ' ' << y << endl;
}

void solve()
{
    cin >> n >> m;
    while(m -- )
    {
        string str;   cin >> str;
        int x = 0, y = 0;
        split(str, x, y);
        // 1->n
        // 2->n-1
        // n->1
        // x->y
        // --> x+y=n+1
        // --> y=n+1-x
        s[n + 1 - y][x] = true;
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            if(s[i][j]) cout << "#";
            else    cout << ".";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}
```

#### 初赛 7 sort

这里不用真sort，直接利用map即可。

``` c++
// 字典序递减输出丢失的票据的编号
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 110;

void solve()
{
    // map 第三个参数可以指定key的排序
    map<string,int, greater<string>> ass;
    int x;  cin >> x;
    while(x -- )    
    {
        string s;   cin >> s;
        // cout << "1: " << s << endl;
        ass[s] ++ ;
    }
    int y;  cin >> y;
    while(y -- )
    {
        string s;   cin >> s;
        // cout << "2: " << s << endl;
        ass[s] -- ;
    }
    for(auto &t : ass)
        if(t.second)
            for(int i = 0; i < t.second; i ++ )
                cout << t.first << endl;
}

int main()
{
    solve();
    return 0;
}
```



#### 复赛 2 进制转换

有一个点：当我们将10进制转换为其他进制时，如果使用辗转相除法，需要特判10进制数位0的情况。

``` c++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void doSolve(string s, int pre, int n)
{
    // convert to 10p
    int num = 0;
    for(auto &x : s)
    {
        if(isdigit(x)) // 0-9
            num = num * pre + (x - '0');
        else    
            num = num * pre + (x - 'A' + 10);
    }
    if(pre == 27)  
    {
        cout << num << endl;
        return ;
    }
    // convert to np
    if(!num)    // special judge
    {
        cout << 0 << endl;
        return ;
    }
    string res("");
    while(num) // if num==0, will not execute
    {
        int t = num % 27;
        if(t < 10)  res += to_string(t);
        else    res += char('A' + (t - 10));
        num /= 27;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

void solve()
{
    int T = 1;
    while(T -- )
    {
        string s;   int n;
        cin >> s >> n;
        doSolve(s, n, 37 - n);
    }
}

int main()
{
    solve();
    return 0;
}
```

#### 复赛







----



### 2021 本科组

#### 初赛 1 预处理+暴力

``` c++
// 字典序递减输出丢失的票据的编号
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 110;

int n, k;
int w[N];
unordered_set<int> ass; 
    
void solve()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++ )    cin >> w[i];
    
    for(int i = 0; i < n; i ++ )
        for(int j = i + 1; j < n; j ++ )
            for(int p = j + 1; p < n; p ++ )
                for(int q = p + 1; q < n; q ++ )    
                    // 需要判断一下能否整除
                    if((w[i] + w[j] + w[p] + w[q]) % 4 == 0)
                        ass.insert((w[i] + w[j] + w[p] + w[q]) / 4);
    
    while(k -- )
    {
        int cnt;    cin >> cnt;
        bool flag = true;
        while(cnt -- )
        {
            int x;  cin >> x;
            if(!ass.count(x))   
            {
                flag = false;
                // cout << "x: " << x << endl;
                // break; // 不能break，否则会中断数据的读入
            }
        }
        if(flag)    puts("Yes");
        else    puts("No");
    }
}

int main()
{
    solve();
    return 0;
}
```

#### 初赛 2 贪心+排序

比较有质量的一题，但是数据可能比较水？

``` c++
// 贪心，枚举斜率
// 对于每个斜率上的所有木棋
// 如果价值为1，那么就使用方案2
// 如果价值不为1，那么就使用方案1

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

// 斜率确定的情况下，我们只保存x坐标即可
// 对于 (0,y) 这种类型，存储y坐标
// string->斜率，vector<PII> 存储一个坐标和价值
unordered_map<string, vector<PII>> ass;
int n;

int gcd(int a, int b)
{
    return (a % b) ? gcd(b, a % b) : b;
}

string getk(int a, int b)
{
    return to_string(a) + "," + to_string(b);
}

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x, y, c;
        cin >> x >> y >> c;
        // 预处理
        if(!x) // (0,y)
        {
            int sign = y > 0 ? 1 : -1;
            ass[getk(0,-1 * sign)].push_back({y, c});
        }
        else if(!y) // (x,0)
        {
            int sign = x > 0 ? 1 : -1;
            ass[getk(sign * 1,0)].push_back({x, c});
        }
        else // x && y 
        {
            int sign = x > 0 ? 1 : -1;
            int d = gcd(x, y);
            int a = x / d, b = y / d;
            ass[getk(sign * a,b)].push_back({x, c});
        } 
    }
    int res = 0, cnt = 0;
    for(auto &it : ass)
    {
        // cout << "[" << it.first << "]: ";
        // for(auto &x : it.second)    cout << x.second << ' ';
        // cout << endl;
        
        // 记得排序，降序还是升序不重要，因为不影响连续的1在一起
        sort(it.second.begin(), it.second.end());
        bool is_one = false;
        for(auto &[x,c] : it.second)
        {
            if(c != 1)  is_one = false, cnt ++ ;
            else if(!is_one)   cnt ++ , is_one = true;
            res += c;
        }
    }
    cout << res << ' ' << cnt << endl;
}

int main()
{
    solve();
    return 0;
}
```



#### 初赛 3 最短路 + 模拟

最后一个点超时，因为边数可能无限大

因此正确方法为 O(N^3) 的朴素 dijkstra 或者floyd

``` c++
/*
打败怪兽需要的能量等于怪兽本身的能量
而怪兽一旦被打败，武器就归玩家所有 —— 当然缴获的武器价值越高，玩家就越开心。
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e3 + 10, M = 2e6 + 10;

int n, m, root;
int h[N], e[M], ne[M], w1[M], w2[M], idx;
int dist[N], val[N], pre[N];
bool st[N];

void add(int a, int b, int c1, int c2)
{
    w1[idx] = c1, w2[idx] = c2;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void init()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m -- )
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        add(a, b, c, d);
        add(b, a, c, d);
    }
}

int spfa(int u)
{
    memset(st, false, sizeof st);
    memset(val, 0, sizeof val);
    memset(pre, -1, sizeof pre);
    memset(dist, 0x3f, sizeof dist);
    
    queue<int> q;   q.push(u);
    st[u] = true;   dist[u] = 0;
    while(q.size())
    {
        auto t = q.front(); q.pop();
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w1[i])
            {
                dist[j] = dist[t] + w1[i];
                val[j] = val[t] + w2[i];
                pre[j] = t;
                if(!st[j])  q.push(j), st[j] = true;
            }
            else if(dist[j] == dist[t] + w1[i])
            {
                if(val[j] < val[t] + w2[i])
                {
                    val[j] = val[t] + w2[i];
                    pre[j] = t;
                    if(!st[j])  q.push(j), st[j] = true;
                }
            }
        }
    }
    // 助力了，题目说的是所有堡垒，而不仅仅是后面我们要攻克的堡垒，case2和case3
    int maxn = 0;
    for(int x = 1; x <= n; x ++ )  maxn = max(maxn, dist[x]);
    return maxn;
}

void getPos() // 找到空降地点
{
    int minx = 2e9;
    for(int i = 1; i <= n; i ++ )
    {
        int cur = spfa(i);
        if(cur < minx)    root = i, minx = cur;
    }
    cout << root << endl;
}

// 还是dfs漂亮
void dfs(int u)
{
    if(pre[u] == -1)    return ;
    dfs(pre[u]);
    cout << "->" << u;   
}

void outPath()
{
    int k;  cin >> k;
    while(k -- )    
    {
        int x;  cin >> x;
        cout << root;
        dfs(x);
        cout << endl;
        cout << dist[x] << ' ' << val[x] << endl;
    }
}

void solve()
{
    init();
    getPos();
    // 因为spfa会更新起点，所以需要设置pre为-1
    pre[root] = -1;
    spfa(root);
    outPath();
}

int main()
{
    solve();
    return 0;
}
```

#### 初赛 4 逆向思维 （好题）

样例解释：

``` c++
双向：
5 5 3
1 2
1 3
1 5
2 5
3 4

d1:4 3 -> 1
1 3
1 4
2 3

d2:5 3 -> 2
3 4
2 3
3 5

d3:1 3 -> 3
2 3
2 5
3 4
```

题目大意

> 给定我们一个图，依次删去一个点，问连通的边的个数，这应该是很**“经典”**的问题了，考虑连通性，我们可以使用并查集，但是并查集无法处理删边。

思路

> 我们可以逆向思考，正向删边，不就是反向加边吗？于是，我们可以保存查询，然后倒序处理，依次加边，然后用并查集就可以了。

代码

``` C++
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 50010;

int n, m, d;
bool st[N]; // st[i]=true --> 点i被删除
vector<int> res, ver;   // 保存答案和删除的节点
vector<vector<PII>> q;   // 保存查询
vector<int> g[N]; // 保存图中的边
int pre[N]; // 并查集

int find(int x)
{
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}

void init()
{
    cin >> n >> m >> d;
    while(m -- )
    {
        int a, b;   cin >> a >> b;
        // 双向边
        g[a].push_back(b);  g[b].push_back(a);
    }
    for(int i = 0; i < d; i ++ )
    {
        int c, k;   cin >> c >> k;
        st[c] = true;   ver.push_back(c); 
        vector<PII> thisq;
        while(k -- )
        {
            int a, b;   cin >> a >> b;
            thisq.push_back({a, b});
        }
        q.push_back(thisq);
    }
    /*---------*/
    for(int i = 1; i < N; i ++ )    pre[i] = i;
}

void add_edge()
{
    for(int i = 1; i <= n; i ++ )
    {
        if(!st[i])
        {
            for(auto &ne : g[i])
            {
                if(!st[ne]) pre[find(i)] = find(ne); 
            }
        }
    }
}

void query()
{
    vector<int> res;
    for(int i = d - 1; i >= 0; i -- )
    {
        auto thisq = q[i];
        int u = ver[i];
        int cnt = 0;
        // do query
        for(auto &[a,b] : thisq)
            if(find(a) != find(b))  cnt ++ ;
        res.push_back(cnt);
        // add edge
        st[u] = false;
        for(auto &ne : g[u])
            if(!st[ne]) pre[find(u)] = find(ne);
    }
    // 倒着输出
    for(int i = d - 1; i >= 0; i -- )   cout << res[i] << endl;
}

void solve()
{
    init();
    add_edge();
    query();
}

int main()
{
    solve();
    return 0;
}
```

