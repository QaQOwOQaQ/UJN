//Easy Dfs
//Can bfs or unite_find???
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 100010;

LL res;
int n, depth[N], idx = 1;
vector<int> g[N];

void dfs(int u, int d)
{
    depth[u] = d;
    for(int i = 0; i < g[u].size(); i ++ )
    {
        dfs(g[u][i], d + 1);
    }
    
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    
    dfs(1, 1);
    for(int i = 1; i <= n; i ++ )
    {
        if(g[i].size() == 0)
            res += depth[i] * i;
    }
    
    cout << res << endl;
    
    
    return 0;
}