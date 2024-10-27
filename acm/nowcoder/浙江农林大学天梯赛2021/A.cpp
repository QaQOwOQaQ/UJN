/*
用dfs跑会超时，因为我们会遍历许多无关路径（不能构成拓扑排序）
所以我们要在可以构成拓扑排序的路径上遍历
即一遍进行拓扑排序，一边dp
dp其实很简单
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int res, w[N];
int in[N], f[N];
vector<int> g[N];
bool st[N];

void dfs(int u, int v)
{
    if(u == n)
    {
        res = max(res, v);
        return ;
    }
    
    for(int i = 0; i < g[u].size(); i ++ )
    {
        int t = g[u][i];
        st[t] = true;
        dfs(t, v + w[t]);
        st[t] = false;
    }
}

void topsort()
{
    queue<int> q;
    q.push(0);
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(auto x : g[t])
        {
            f[x] = max(f[x], f[t] + w[x]);
            if(! --in[x])  q.push(x);
        }
    }
}

int main()
{
    memset(f, -1, sizeof f);
    f[0] = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )   cin >> w[i];
    while(m -- )
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        in[b] ++ ;
    }
    
    topsort();
    
    // for(int i = 1; i <= n; i ++ )
    //     cout << f[i] << endl;
    cout << f[n] << endl;
    
    return 0;
}