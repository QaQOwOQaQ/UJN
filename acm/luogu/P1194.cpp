#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/* 思路：最小生成树 + 虚拟源点
我们把问题看做一个图，节点就是物品
边i->j就是已经有了物品i,购买物品j的最小价格
*/

const int N = 510;

int init_cost, n;
int g[N][N];
int dist[N];
bool st[N];

void init()
{
    cin >> init_cost >> n;
    for(int i = 0; i <= n; i ++ )
        for(int j = 0; j <= n; j ++ )
            g[i][j] = init_cost;
            
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )
        {
            int x;  cin >> x;
            // 唯一一个坑，让我踩到了
            // 题目说当x为0时，是没有优惠的情况
            if(x)   g[i][j] = min(g[i][j], x);
        }
}

int prim()
{
    int res = 0;
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    for(int i = 0; i <= n; i ++ )
    {
        int t = -1;
        for(int j = 0; j <= n; j ++ )
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        res += dist[t];
        // cout << "dist: " << dist[t] << endl;
        for(int j = 0; j <= n; j ++ )
            dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}

int main()
{
    init();
    int res = prim();
    cout << res << endl;
    return 0;
}