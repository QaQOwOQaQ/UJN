/*
J题目数据范围存在20%的数据2 ≤ n ≤100且2 ≤ T ≤10；
另外存在20%的数据2 ≤ n ≤100且2 ≤ T ≤10^5；
另外存在10%的数据2 ≤ n ≤10^5且2 ≤ T ≤10。
对于100%的数据0 ≤ wi, vi, d i ≤10^5，2 ≤ n ≤10^5，2 ≤ T ≤10^5 
(广播消息，勿回^_^)
*/
/*
sb题目，需要开LL，边的数据没有给你
你需要开的很大很大，反正比点数大10倍可以过
恶心
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, LL> PII;
const int M = 400010, INF = 0x3f3f3f3f;

int n, m, q;
int h[M], e[M], ne[M], idx;
LL dist[M], w[M];//all pos -> 1
bool st[M];

void add(int a, int b, LL c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
void dijkstra()  // 求1号点到n号点的最短路距离
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        
        int ver = t.second;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}


int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while(m -- )
    {
        int a, b;
        LL c;
        scanf("%d%d%lld", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
    dijkstra();
    
    scanf("%d", &q);
    while(q -- )
    {
        int a, b;
        cin >> a >> b;
        LL res = dist[a] + dist[b];
        printf("%lld\n", res);
    }
    
    return 0;
}
/*
他每次会告诉你自己当前所在结点与任务地所在结点
无向图
史东薇尔城是一号结点
*/