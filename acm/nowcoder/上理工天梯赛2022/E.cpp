#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 310;

int T, n, m, k, a, b, c, d;
bool map[N][N], vis[N][N];
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int ddx[8] = {0, 0, 0, 0, 1, 1, -1, -1};
int ddy[8] = {1, -1, 1, -1, 0, 0, 0, 0,};
int dist[N][N];

bool check(int x, int y)
{
    if(x <= 0 || y <= 0 || x > n || y > m)  return false;
    return true;
}

int bfs2(int x, int y)//American
{
    queue<PII> q;
    memset(dist, 0, sizeof dist);
    memset(vis, 0, sizeof vis);
    q.push({x, y});
    dist[x][y] = 0;
    vis[x][y] = true;
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        
        int distance = dist[t.x][t.y];
        if(t.x == c && t.y == d)    return distance;
        
        for(int i = 0; i < 8; i ++ )
        {
            int xx = t.x + dx[i], yy = t.y + dy[i];
            if(check(xx, yy) && !vis[xx][yy] && !map[xx][yy])
            {
                dist[xx][yy] = distance + 1;
                q.push({xx, yy});
                vis[xx][yy] = true;
            }
        }
    
    }
    return -1;
}

int bfs1(int x, int y)//china
{
    queue<PII> q;
    memset(dist, 0, sizeof dist);
    memset(vis, 0, sizeof vis);
    q.push({x, y});
    dist[x][y] = 0;
    vis[x][y] = true;
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        
        int distance = dist[t.x][t.y];
        if(t.x == c && t.y == d)    return distance;
        
        for(int i = 0; i < 8; i ++ )
        {
            int xx = t.x + dx[i], yy = t.y + dy[i];
            int nx = t.x + ddx[i], ny= t.y + ddy[i];
            //难点主要在于这里的边界判断
            //第一行的边界判断好理解
            //第二行是说，有可能走一步也会产生边界问题
            if(check(xx, yy) && !map[xx][yy] && !vis[xx][yy] &&
                 check(nx, ny) && !map[nx][ny])
            {
                dist[xx][yy] = distance + 1;
                q.push({xx, yy});
                vis[xx][yy] = true;
            }
        }
    }
    return -1;
}

int main()
{
    cin >> T ;
    while(T -- )
    {
        memset(map, 0, sizeof map);
        
        cin >> n >> m >> k >> a >> b >> c >> d;

        for(int i = 0; i < k; i ++ )
        {
            int x, y;
            cin >> x >> y;
            map[x][y] = true;
        }
        cout << bfs2(a, b) << " ";
        cout << bfs1(a, b) << endl;
    }
    
    
    return 0;
}