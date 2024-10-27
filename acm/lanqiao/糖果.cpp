//爆搜50%分
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, INF = 0x3f3f3f3f;

vector<int> g[N];
int n, m, k;
set<int> s[N], has_res;
int res = INF;
bool st[N], has_find;
int vis[N];
PII p[N];

bool check()
{
    for(int i = 1; i <= m; i ++ )
        if(!vis[i]) return false;
    return true;
}

void dfs(int u)
{
    if(check())
    {
        res = min(res, u);
        return ;
    }
    if(u >= res) return ;
    for(int i = 1; i <= n; i ++ )
    {
        int t = p[i].y;
        if(!st[t])
        {
            st[t] = true;
            for(int j = 0; j < k; j ++ )    vis[g[t][j]] ++ ;
            dfs(u + 1);
            
            for(int j = 0; j < k; j ++ )    vis[g[t][j]] -- ;
            st[t] = false;
        }
    }
    
}

bool cmp(PII a, PII b)
{
    if(a.x == b.x)  return a.y < b.y;
    return a.x > b.x;
}

int main()
{
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 0; j < k; j ++ )
        {
            int x;  cin >> x;
            g[i].push_back(x);
            has_res.insert(x);
            s[i].insert(x);
        }
        p[i] = {s[i].size(), i};
    }
    
    if(has_res.size() == m) 
    {
        sort(p + 1, p + n + 1, cmp);
        dfs(0);
        cout << res << endl;
    }
    else    cout << -1 << endl;


    
    return 0;
}