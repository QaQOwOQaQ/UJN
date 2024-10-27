#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int get(int a, int b)
{
    return a * b / gcd(a, b);
}

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void work()
{
    priority_queue<PII, vector<PII>, greater<PII> > q;
    memset(st, false, sizeof st);
    q.push({0, 1});
    dist[1] = 0;
    while(q.size())
    {
        auto t = q.top(); 
        q.pop();
        int ver = t.y, d = t.x;
        if(st[ver]) continue;
        st[ver] = true;
        
        for(int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > d + w[i])
            {
                dist[j] = d + w[i];
                q.push({dist[j], j});
            }
        }
    }
}

int main()
{
    memset(dist, 0x3f, sizeof dist);
    memset(h, -1, sizeof h);
    
    for(int i = 1; i <= 2021; i ++ )
        for(int j = i + 1; j <= min(2021, 21 + i); j ++ )
        {
            add(i, j, get(i, j)), add(j, i, get(i, j));;
        }


    work();
    cout << dist[2021];

    
    return 0;
}