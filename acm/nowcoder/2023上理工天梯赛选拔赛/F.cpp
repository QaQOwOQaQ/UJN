// 几乎是dijkstra模板题了
// 只不过是多了一个条件
// 并且路径长度作为第二优先级条件罢了
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 1e5 + 10, M = 4e5 + 10;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

PII dij()
{
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0x3f, sizeof cnt);
    dist[1] = 0;
    cnt[1] = 1;
    // cnt, node
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({1, 1});
    while(q.size()) 
    {
        auto [count,u] = q.top();  q.pop();
        if(st[u])   continue;
        st[u] = true;
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(cnt[j] > cnt[u] + 1) 
            {
                cnt[j] = cnt[u] + 1;
                dist[j] = dist[u] + w[i];
                q.push({cnt[j], j});
            }
            else if(cnt[j] == cnt[u] + 1 && dist[j] > dist[u] + w[i])
            {
                dist[j] = dist[u] + w[i];
                q.push({cnt[j], j});
            }
        }
    }
    return {cnt[n], dist[n]};
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    auto res = dij();
    cout << res.first << ' ' << res.second << endl;
    return 0;
}