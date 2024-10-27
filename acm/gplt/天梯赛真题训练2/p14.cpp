#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10010, M = 20010;

int n, m, k;
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bfs(int u)
{
    int res = 0;
    memset(st, false, sizeof st);
    queue<int> q;
    q.push(u);
    st[u] = true;
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i], tmp = N;
            bool flag = false;
            if(!st[j])
            {
                q.push(j);
                st[j] = true;
                flag = true;
                tmp = min(tmp, j);
            }
            if(flag)    res = tmp;
        }
    }
    
    return res;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    
    while(m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);  add(b, a);
    }
    
    while(k -- )
    {
        int x;
        cin >> x;
        cout << bfs(x) << endl;
    }
    
    return 0;
}