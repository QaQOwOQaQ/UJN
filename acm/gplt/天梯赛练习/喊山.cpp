#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10010, M = 20010;

int n, m, k;
int h[N], e[M], ne[M], idx;
bool st[N];
int dist[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(int u)
{
    int res = 0;
    queue<int> q;
    q.push(u);
    st[u] = true;
    while(q.size())
    {
        auto t = q.front(); q.pop();
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!st[j])
            {
                dist[j] = dist[t] + 1;
                st[j] = true;
                q.push(j);
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);  add(b, a);
    }
    
    while(k -- )
    {
        int x;  cin >> x;
        memset(st, false, sizeof st);
        memset(dist, 0, sizeof dist);
        bfs(x);
        int depth = 0, ver = 0;
        for(int i = 1; i <= n; i ++ )
        {
            if(dist[i] > depth)  depth = dist[i], ver = i;
        }
        cout << ver << endl;
    }
    
    
    return 0;
}