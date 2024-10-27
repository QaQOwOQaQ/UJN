#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, M = 10010;

typedef struct edge_t {
    int a, b, c;
    bool operator<(const edge_t &x) const {
        return c < x.c;
    }
} Edge;

int n, m, k, pre[N];
Edge edges[M];

int find(int x)
{
    if(pre[x] == x) return pre[x];
    return pre[x] = find(pre[x]);
}

int main()
{
    for(int i = 0; i < N; i ++ )    pre[i] = i;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i ++ )
    {
        int a, b, c;    cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    sort(edges, edges + m);
    int s = n, cost = 0;
    for(int i = 0; i < m; i ++ )
    {
        if(s == k)  break;
        auto [a, b, c] = edges[i];
        int fa = find(a), fb = find(b);
        if(fa != fb)
        {
            s -- ;
            pre[fa] = fb;
            cost += c;
        }
    }
    if(s != k)  puts("No Answer");
    else    cout << cost << endl;
    return 0;
}