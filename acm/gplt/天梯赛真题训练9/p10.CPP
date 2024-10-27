/*
SB题目
不仅颜色个数要小于K
还要等于K，全用完
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 510, M = 2500000;

int n, m, k, q;
int h[N], e[M], ne[M], idx;
bool st[N];
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u)
{
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(color[j] == color[u])    return false;
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    
    while(m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    
    cin >> q;
    while(q -- )
    {
        set<int> s;
        string res = "Yes";
        for(int i = 1; i <= n; i ++ )   
        {
            cin >> color[i];
            s.insert(color[i]);
        }
        if((int)s.size() != k)
        {
            cout << "No" << endl;
            continue;
        } 
        
        for(int i = 1; i <= n; i ++ )
        {
            if(!dfs(i))
            {
                res = "No";
                break;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}