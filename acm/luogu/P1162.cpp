#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 40;

int n;
int g[N][N];
bool st[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int fx, int fy)
{
    typedef pair<int,int> PII;
    bool is_bound = false;
    queue<PII> q;
    vector<PII> node;
    q.push({fx, fy});
    st[fx][fy] = true;
    while(q.size())
    {
        auto [x, y] = q.front();    q.pop();
        node.push_back({x, y});
        for(int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= n)
            {
                is_bound = true;
                continue;
            }
            if(g[a][b] || st[a][b]) continue;
            q.push({a, b});
            st[a][b] = true;
        }
    }
    if(!is_bound)
        for(auto [a, b] : node)
            g[a][b] = 2;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    
        for(int j = 0; j < n; j ++ )    cin >> g[i][j];
    
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
            if(!g[i][j] && !st[i][j])
                bfs(i, j);
    
    for(int i = 0; i < n; i ++ )    
        for(int j = 0; j < n; j ++ )    cout << g[i][j] << " \n"[j == n - 1];
        
    return 0;
}