/*============  binary_search + dijkstra/bfs/dfs ===========*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> PII;
const int N = 1e4 + 10, M = 4e4 + 10, INF = 0x3f3f3f3f;

int n, m, start, goal;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dijkstra(int limit)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, start});
    while(q.size())
    {
        auto [distance, ver] = q.top();   q.pop();
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(w[i] > limit)   continue;
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return dist[goal] != INF;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> start >> goal;
    int l = 0, r = 0;
    while(m -- )
    {
        int a, b, c;    cin >> a >> b >> c;
        add(a, b, c);   add(b, a, c);
        r = max(r, c);
    }
    while(l < r)
    {
        int mid = l + r >> 1;
        if(dijkstra(mid))   r = mid;
        else    l = mid + 1;
    }
    cout << l << endl;
    return 0;
}

/*=============== kruskal ===============*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10, M = N << 2;

typedef struct edge_t {
    int a, b, c;
    bool operator<(const edge_t &x) const {
        return c < x.c;
    }
} Edge;

int n, m, hh, tt;
int h[N], e[M], w[M], ne[M], idx;
int pre[N];
Edge edges[M];

int find(int x) {
    if(pre[x] == x) return x;
    return pre[x] = find(pre[x]);
}

int main()
{
    cin >> n >> m >> hh >> tt;
    for(int i = 0; i < m; i ++ )
    {
        int a, b, c;    cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    sort(edges, edges + m);
    for(int i = 0; i < N; i ++ )    pre[i] = i;
    for(int i = 0; i < m; i ++ )
    {
        auto [a, b, c] = edges[i];
        int fa = find(a), fb = find(b);
        if(fa != fb) pre[fa] = fb;
        if(find(hh) == find(tt))
        {
            cout << c << endl;
            return 0;
        }
    }
    return 0;
}