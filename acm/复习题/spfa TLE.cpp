#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int h[N], ne[N], e[N], idx, q[N], w[N];
int dist[N], n, m;
bool st[N];

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    st[1] = true;
    
    int hh = 0, tt = -1;    
    q[++ tt] = 1;
    while(hh <= tt)
    {
        st[hh] = false;
        int t = q[hh ++ ];
        
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])  q[++ tt] = j;
            }
        }
    }
    
    return dist[n];
    
}

int main()
{
    cin >> n >> m;
    
    memset(h, -1, sizeof h);
    while(m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    int t = spfa();
    if(t > INF / 2) cout << "impossible" << endl;
    else    cout << t << endl;
    

    
    return 0;
    
}
