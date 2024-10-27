#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int n, m, q, res = 1e9, num, id;
int pre[N];
int g[N][N];

int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for(int i = 1; i <= n; i ++ )   g[i][i] = 0;    
    
    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    cin >> q;
    for(int k = 1; k <= q; k ++ )
    {
        // cout << "new" << endl;
        unordered_set<int> s;
        int cnt, sum = 0;
        bool flag = true;
        
        cin >> cnt;
        for(int i = 1; i <= cnt; i ++ ) 
        {
            cin >> pre[i];
            s.insert(pre[i]);
        }
        
        pre[0] = 0;
        pre[cnt + 1] = 0;
        
        if((int)s.size() < n || cnt > n)    
        {
            flag = false;
            // cout << "wrong1" << endl;
        }
        
        for(int i = 1; i <= cnt + 1; i ++ )
        {
            int a = pre[i - 1], b = pre[i];
            // cout << a << ' ' << b << endl;
            if(g[a][b] == INF)    
            {
                flag = false;
                // cout << "wrong2: " << i << " " << a << " " << b << endl;
            }
            sum += g[a][b];
        }

        if(flag)   
        {
            // cout << "ac: " << k << endl;
            num ++ ;
            if(sum < res)
            {
                res = sum;
                id = k;
            }
        }
    }
    
    cout << num << endl;
    cout << id << ' ' << res << endl;

    
    return 0;
}