// 0分
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 510, M = 100010;

int n, m, k;
int h[N], e[M], ne[M], idx;
bool control[N], st[N], have[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool is_alert()
{
    memset(have, false, sizeof have);
    memset(st, false, sizeof st);
    queue<int> q;
    
    for(int i = 0; i < n; i ++ )    //添加一个没被占领的城市
        if(!control[i]) 
        {
            q.push(i);
            have[i] = true;
            st[i] = true;
            break;
        }
        
    while(q.size())
    {
        auto t = q.front(); 
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!control[j] && !st[j])
            {
                q.push(j);
                have[j] = true;
                st[j] = true;
            }
        }
    }
    
    for(int i = 0; i < n; i ++ )
        if(!control[i] && !have[i]) return false;
    return true;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while(m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);  add(b, a);
    }
    
    cin >> k;
    for(int i = 1; i <= k; i ++ )
    {
        bool last = is_alert(); //是否可以触发警告
        int c;
        scanf("%d", &c);
        control[c] = true;
        bool now = is_alert();
        cout << last << " " << now << " ";
        if(!last || (last && now))   printf("City %d is lost.\n", c);
        else printf("Red Alert: City 0 is lost!\n", c);
    }
    if(k == n)  puts("Game Over.");
    
    return 0;
}