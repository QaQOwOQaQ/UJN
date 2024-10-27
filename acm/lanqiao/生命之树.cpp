#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 100010;
const LL INF = -0x3f3f3f3f3f3f3f3fl; 

vector<int> v[N];
int n;
LL f[N][3], w[N];
bool st[N];

void bfs(int u)
{
    st[u] = true;
    f[u][0] = 0;
    f[u][1] = w[u];
    for(int i = 0; i < v[u].size(); i ++ )
    {
        int ne = v[u][i];
        if(!st[ne])
        {
            bfs(ne);
            f[u][1] += max(f[ne][1], f[ne][0]);
        }
        else
            f[u][1] = max(f[u][1], w[u]);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   cin >> w[i];
    for(int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    bfs(1);

    LL res = INF;
    for(int i = 1; i <= n; i ++ )
    {
        //cout << f[i][1] << " " << f[i][0] << endl;
        res = max(res, f[i][1]);
        res = max(res, f[i][0]);
    }
    
    cout << res << endl;    
    
    return 0;
}