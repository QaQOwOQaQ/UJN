//10
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010, M = 20010;

int n, m, query, k;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void bfs(int u)
{
    st[u] = true;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])  bfs(j);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for(int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);  add(b, a);
    }
    cin >> query;
    while(query -- )
    {
        cin >> k;
        memset(st, false, sizeof st);
        for(int i = 0; i < k; i ++ )
        {
            int x;
            cin >> x;
            st[x] = true;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i ++ )
        {
            if(!st[i])  bfs(i), cnt ++ ;
        }
        if(cnt == n - k)    puts("YES");
        else    puts("NO");
    }
    
    return 0;
}