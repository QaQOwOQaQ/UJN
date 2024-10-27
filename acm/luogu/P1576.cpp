#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 2010, M = 200010;

int n, m, start, goal;
int h[N], e[M], ne[M], w[M], idx;
double dist[N];
bool st[N];

typedef pair<double,int> PII;

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

double dijkstra()
{
    for(int i = 0; i < N; i ++ )   dist[i] = 1e10;
    dist[goal] = 100;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({dist[goal], goal});
    while(q.size())
    {
        auto [distance, ver] = q.top(); q.pop();
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            double new_dist = distance / (1 - 1.0 * w[i] / 100);
            if(dist[j] > new_dist)
            {
                dist[j] = new_dist;
                q.push({dist[j], j});
            }
        }
    }
    return dist[start];
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m -- )
    {
        int a, b, c;    cin >> a >> b >> c;
        add(a, b, c);   add(b, a, c);
    }
    cin >> start >> goal;
    printf("%.8lf\n", dijkstra());
    return 0;
}