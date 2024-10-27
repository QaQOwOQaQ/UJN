#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 410, INF = 0x3f3f3f3f;

typedef pair<int,int> PII;

int n, m;
int startx, starty;
int dist[N][N];
bool st[N][N];
int dx[8] = {-1, -1, -2, -2, 1, 1, 2, 2};
int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};
PII pre[N][N];

void bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[startx][starty] = 0;
    queue<PII> q;
    q.push({startx, starty});
    st[startx][starty] = true;
    while(q.size())
    {
        auto [x, y] = q.front();    q.pop();
        for(int i = 0; i < 8; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if(a <= 0 || a > n || b <= 0 || b > m || st[a][b])    continue;
            pre[a][b] = {x, y};
            dist[a][b] = dist[x][y] + 1;
            st[a][b] = true;
            q.push({a, b});
        }
    }
}

int main()
{
    cin >> n >> m >> startx >> starty;
    bfs();
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ )
            cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " \n"[j == m];
    
    return 0;
}