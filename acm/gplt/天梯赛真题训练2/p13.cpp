#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 1010;

int h[N], e[M], ne[M], len[M], time[M];
int dist[N], n, m;
bool st[N];

void add(int a, int b, int c, int d)
{
    len[idx] = c;
    time[idx] = d;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int main()
{
    cin >> n >> m;
    while(n -- )
    {
        int a, b, f, l, t;
        cin >> a >> b >> f >> l >> t;
        if(f == 0)  
        {
            add(a, b, l, t);
            add(b, a, l, t);
        }
        else    add(a, b, l, t)
    }
    cin >> v1 >> v2;
    
    
    
    return 0;
}