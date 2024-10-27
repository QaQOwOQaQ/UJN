/*
和天梯赛一道L3的题目很像
但是简单一点
总体来说很简单=。=
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 10010;

int n, m, q, k, ne;
int id, dist, diff;
set<int> g[N];

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    cin >> q;
    for(int u = 1; u <= q; u ++ )
    {
        cin >> k;
        set<int> s;
        int last = 0;
        bool is_ans = true;
        for(int i = 0; i < k; i ++ )
        {
            cin >> ne;
            s.insert(ne);
            if(!g[last].count(ne)) is_ans = false;
            last = ne;
        }
        if(!is_ans) continue;
        if(s.size() > diff) 
        {
            diff = s.size();
            dist = k;
            id = u;
        }
        else if(s.size() == diff)
        {
            if(k > dist)    
            {
                dist = k;
                id = u;
            }
        }
    }
    cout << id << endl;
    return 0;
}