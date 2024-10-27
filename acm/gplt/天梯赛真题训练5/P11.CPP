#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

const int N = 51000, M = 10000010;

int h[N], e[M], ne[M], idx;
int n, m, k, q;
int color[N];

void add(int a, int b)  
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool bfs(int t)
{
    for(int i = h[t]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(color[j] == color[t])    return false;
    }
    
    return true;
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
    
    cin >> q;
    for(int i = 0; i < q; i ++ )
    {
        set<int> S;
        for(int i = 1; i <= n; i ++ )   
        {
            cin >> color[i];
            S.insert(color[i]);
        }
        
        if(S.size() != k)    puts("No");
        //非常非常的坑人，这k中颜色你必须都用！！！
        else
        {
            bool flag = true;
            for(int i = 1; i <= n; i ++ )
            {
                if(!bfs(i)) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag)    puts("Yes");
            else    puts("No");
        }
        
    }
    
    return 0;
}