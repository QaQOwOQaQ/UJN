#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define int long long

using namespace std;

const int N = 100010;

vector<pair<int, int> > g[N];
int n, m;
int sum, maxn = -1;
bool st[N];

/*
void dfs(int u, int dist)Wrong!
{
    st[u] = true;
    if(!g[u].size())
    {
        maxn = max(maxn, dist);
        return ;
    }
    for(int i = 0; i < g[u].size(); i ++ )
    {
        int to = g[u][i].first, val = g[u][i].second;
        if(!st[to])     
            dfs(to, dist + val);
    }
}
*/


void dfs(int u, int dis)
{
    st[u] = 1;
    int len = g[u].size();
    if(len == 1 && st[g[u][0].first])
    {
        maxn = max(maxn, dis);
        return ;
    }
    for(int i = 0; i < len; i ++ )
    {
        if(!st[g[u][i].first])
            dfs(g[u][i].first, dis + g[u][i].second);
    }
}


signed main()
{
    cin >> n;   m = n - 1;
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b)   swap(a, b);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        sum += c;
    }
    dfs(1, 0);
    sum <<= 1;
    // cout << "maxn: " << maxn << endl;
    cout << sum - maxn << endl;
    
    return 0;
}