// O(N(N+M))
// O(NM) ~ O(N^3) ~ (625000000) ~ O(6e8)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 510, M = N * N;

int n, m, k;
int h[N], e[M], ne[M], idx;
int color[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u)
{
    st[u] = true;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(st[j])   continue;   // 去重
        if(color[j] == color[u])    return false;
        if(!dfs(j)) return false;
    }
    return true;
}

bool solve()
{
    // 必须恰好用k种颜色，太坑人了
    unordered_set<int> ass;
    for(int i = 1; i <= n; i ++ )   ass.insert(color[i]);
    if(ass.size() != k)  return false;
    // 染色法
    memset(st, false, sizeof st);
    for(int i = 1; i <= n; i ++ )
        if(!st[i] && !dfs(i))   return false;
    return true;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    int q;  cin >> q;
    while(q -- )
    {
        for(int i = 1; i <= n; i ++ )   cin >> color[i];
        bool res = solve();
        if(res) puts("Yes");
        else    puts("No");
    }
    return 0;
}