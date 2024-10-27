/*
其实相当简单的一道题，是我相同太复杂了
传递的高度值是不变的！！！
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n, m, ans;
int w[N];
vector<int> g[N];

void dfs(int u, int h)
{ 
    for(int i = 0; i < g[u].size(); i ++ )
    {
        int j = g[u][i];
        if(w[j] <= h)    ans ++ ;
        dfs(j, h);//写为dfs(j, high[j])得0分！！！
    }
}

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i ++ )   cin >> w[i];

    for(int i = 1; i <= n; i ++ )   dfs(i, w[i]);

    cout << ans << endl;
    
    return 0;
}