#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010, M = 1000100;

int n;
double z[N], r, res = 0;
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
    queue<int> q;
    q.push(u);
    while(q.size())
    {
        auto t = q.front(); q.pop();
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(j)
            {
                z[j] = (z[t] - z[t] * r);
                q.push(j);
            }
            else    //得到者
                res += z[t] * w[i];
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> z[0] >> r;
    r /= 100;
    
    for(int i = 0; i < n; i ++ )
    {
        int k;  cin >> k;
        if(!k)  
        {
            int t;   cin >> t;
            add(i, 0, t);
        }
        else
        {
            for(int j = 0; j < k; j ++ )
            {
                int t;  cin >> t;
                add(i, t, 0);
            }
        }
    }
    
    dfs(0);
    
    int ans = (int)res;
    printf("%d", ans);
    return 0;
}
