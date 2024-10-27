#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, INF = 0x3f3f3f3f;

int n, m;
int dist[N];
bool st[N];
int g[N][N];

int dijkstra(int start, int goal)
{
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    memset(st, false, sizeof st);

    for(int u = 1; u <= n; u ++ )
    {
        int t = -1;
        for(int i = 1; i <= n; i ++ )
            if(!st[i] && (t == -1 || dist[i] < dist[t]))
                t = i;
        st[t] = true;
        /*  debug 半小时的错误
        if(dist[t] == INF)  return -1;
        错误的原因在于，dijkstra是求单源最短路
        而例如 1->2 不可达，并不意味着 1->3 不可达！
        */
        for(int i = 1; i <= n; i ++ )
            dist[i] = min(dist[i], dist[t] + g[t][i]);
    }
    return dist[goal] == INF ? -1 : dist[goal];
}

signed main()
{
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i <= n; i ++ )    g[i][i] = 0;
    cin >> n >> m;
    while(m -- )
    {
        int op; cin >> op;
        if(op == 0)
        {
            int start, goal;    
            cin >> start >> goal;
            cout << dijkstra(start, goal) << endl;
        }
        else 
        {
            int a, b, c;    
            cin >> a >> b >> c;
            g[a][b] = g[b][a] = min(g[a][b], c);
        }
    }
    return 0;
}