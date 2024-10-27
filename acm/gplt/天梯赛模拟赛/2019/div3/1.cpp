// 一条是最快到达路线
// 一条是最短距离的路线

// 如果最快到达路线不唯一
// 则输出几条最快路线中最短的那条
// 题目保证这条路线是唯一的

// 而如果最短距离的路线不唯一
// 则输出途径节点数最少的那条，题目保证这条路线是唯一的。
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 510;

int n, m, hh, tt;
bool st[N];
int cnt[N];
int g1[N][N];
int g2[N][N];
int dist[N];
int pre[N];

void get(vector<int> &res, int &s)
{
    s = dist[tt];
    int u = tt;
    while(u != -1)  
    {
        res.push_back(u);
        u = pre[u];
    }
}

void dijkstra(int g[][N])
{
    memset(cnt, 0, sizeof cnt);
    memset(pre, -1, sizeof pre);
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[hh] = 0;
    
    for(int u = 0; u < n; u ++ )
    {
        int t = -1;
        for(int j = 0; j < n; j ++ )
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for(int j = 0; j < n; j ++ )
        {
            if(dist[j] > dist[t] + g[t][j])
            {
                dist[j] = dist[t] + g[t][j];
                pre[j] = t;
            }
        }
    }
}

void solve()
{
    vector<int> res1, res2;
    int s1, s2;
    
    dijkstra(g2);
    get(res2, s2);
    
    dijkstra(g1);
    get(res1, s1);
    
    if(res1 == res2)
    {
        printf("Time = %d; Distance = %d: ", s2, s1);
        int k = res1.size();
        for(int i = k - 1; i >= 0; i -- )
        {
            if(i == 0)  cout << res1[i] << endl;
            else    cout << res1[i] << " => ";
        } 
    }
    else
    {
        printf("Time = %d: ", s2);
        int k = res2.size();
        for(int i = k - 1; i >= 0; i -- )
        {
            if(i == 0)  cout << res2[i] << endl;
            else    cout << res2[i] << " => ";
        } 
        printf("Distance = %d: ", s1);
        k = res1.size();
        for(int i = k - 1; i >= 0; i -- )
        {
            if(i == 0)  cout << res1[i] << endl;
            else    cout << res1[i] << " => ";
        } 
    }
}

int main()
{
    memset(g1, 0x3f, sizeof g1);
    memset(g2, 0x3f, sizeof g2);
    for(int i = 0; i < N; i ++ )    g1[i][i] = g2[i][i] = 0;
    
    cin >> n >> m;
    for(int i = 0; i < m; i ++ )
    {
        int a, b, op, w1, w2;
        cin >> a >> b >> op >> w1 >> w2;
        
        g1[a][b] = min(g1[a][b], w1);
        if(!op)  g1[b][a] = min(g1[b][a], w1);
        
        g2[a][b] = min(g2[a][b], w2);
        if(!op)  g2[b][a] = min(g2[b][a], w2);
    }
    cin >> hh >> tt;
    solve();
    return 0;
}