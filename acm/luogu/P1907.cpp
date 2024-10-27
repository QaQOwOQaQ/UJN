/*
Rome Road 可以驾驶马车 --> cost1
Dirt Road 不可以驾驶马车 --> cost2
走某条道路的不满值 = length * cost
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue> 

using namespace std;

const int N = 1100;

typedef pair<double, double> PDD;

int n;
double cost1, cost2; // Dirt, Roma
PDD p[N];
double w[N][N];
bool g[N][N];  // 是否有 Roma Road
double goalx, goaly;
double startx, starty;
int goal, start;
double dist[N];
bool st[N];

double get_dist(int a, int b)
{
    double dx = p[a].first - p[b].first;
    double dy = p[a].second - p[b].second;
    double len = sqrt(dx * dx + dy * dy);
    double cost = g[a][b] ? cost2 : cost1;
    return len * cost;
}

int find(double x, double y)
{
    for(int i = 1; i <= n; i ++ )
        if(p[i].first == x && p[i].second == y) 
            return i;
    p[ ++ n] = {x, y};
    return n;
}

double dijkstra()
{
    for(int i = 0; i <= n; i ++ )   dist[i] = 1e12;
    dist[start] = 0;
    for(int u = 1; u <= n; u ++ )
    {
        int t = -1;
        for(int i = 1; i <= n; i ++ )
            if(!st[i] && (t == -1 || dist[i] < dist[t]))
                t = i;
        st[t] = true;
        for(int i = 1; i <= n; i ++ )
            dist[i] = min(dist[i], dist[t] + w[t][i]);
    }
    return dist[goal];
}

void solve()
{
    cin >> cost1 >> cost2 >> n;
    for(int i = 1; i <= n; i ++ )   cin >> p[i].first >> p[i].second;
    
    int a, b;
    // 注意是双向边!不要只g[a][b]=true
    while(cin >> a >> b, a && b)   g[a][b] = g[b][a] = true;
    cin >> goalx >> goaly >> startx >> starty;
    goal = find(goalx, goaly);
    start = find(startx, starty);
    for(int i = 1; i <= n; i ++ )
        for(int j = i + 1; j <= n; j ++ )
            w[i][j] = w[j][i] = get_dist(i, j);

    printf("%.4lf\n", dijkstra());
}

int main()
{
    solve();
    return 0;
}
