#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, INF = 0x3f3f3f3f;

int n, m, q, k, idx, cost;
int g[N][N];
PII w[N];

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    cin >> q;
    for(int u = 1; u <= q; u ++ )
    {
        cost = 0;
        bool flag = true;
        set<int> s;
        
        cin >> k;
        int last = 0;
        for(int i = 1; i <= k; i ++ )
        {
            int x;  cin >> x;   
            if(s.count(x))  flag = false;
            s.insert(x);
            cost += g[last][x];
            if(g[last][x] == INF)   flag = false;
            last = x;
        }
        if(g[0][last] == INF || s.size() < n)   flag = false; 
        if(flag)    w[idx ++ ] = {cost + g[0][last], u};
    }
    
    cout << idx << endl;
    sort(w, w + idx);
    cout << w[0].second << " " << w[0].first << endl;
    
    return 0;
}

/*
简单模拟题
钻晕了，搞了好久
*/