#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

int h[N], e[M], ne[M], idx;
int n, m, k;
int last, now;
bool f[N], st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
    st[u] = true;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j] && !f[j]) dfs(j);
    }
}

int getWays()
{
    memset(st, false, sizeof st);
    int sum = 0;
    for(int i = 0; i < n; i ++ )
    {
        if(!st[i])  
        {
            if(!f[i])   dfs(i); //如果这个城市没被攻占，遍历与它相连接的城市
            sum ++ ;
        }
    }
    
    return sum;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);  add(b, a);
    }
    
    cin >> k;
    last = getWays();
    // cout << "last: " << last << endl;
    for(int i = 1; i <= k; i ++ )
    {
        int c;  cin >> c;
        f[c] = true;
        now = getWays();
        // cout << "now: " << now << endl;
        //找出连通分量个数，如果去掉City c会使得连通分量增加至少2以上，就说明要发出红色警报了
        if(now <= last + 1) //+1表示的是增加了这个被攻占的城市
            printf("City %d is lost.\n",c);
        else 
            printf("Red Alert: City %d is lost!\n",c);
        last = now;
    }
    
    if(k == n)  puts("Game Over.");
    return 0;
}