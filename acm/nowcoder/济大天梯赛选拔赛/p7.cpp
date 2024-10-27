#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010, M = 200010;

int n, m, q;
int h[N], e[M], ne[M], c[N], d[N], idx;
int per[N];//percent

void add(int a, int b, int x, int y)
{
    c[idx] = x, d[idx] = y;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int djikstra(int u)
{
    
}

int main()
{
    cin >> n >> m >> q;
    while(m -- )
    {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        add(a, b, x, y);
    }
    
    for(int i = 1; i <= n; i ++ )   cin >> per[i];
    
    while(q -- )
    {
        int city, money, res = 0;
        cin >> city >> money;
        per[city] = money;
        res = djikstra(1);
    }
    
    return 0;
}