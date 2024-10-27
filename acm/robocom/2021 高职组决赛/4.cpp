#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 11;

int n, m;
int w[N][N];
bool st[N];
bool happy[N], backup[N][N];
vector<int> res, ans;

bool check()
{
    for(int i = 1; i <= n; i ++ )
        if(!happy[i])   return false;
    return true;
}

void dfs(int u, int s)
{
    if(check())  
    {
        if(res.size() < ans.size()) ans = res;
        else if(res.size() == ans.size() && res < ans)  ans = res;
        return ;
    }
    
    for(int i = 1; i <= m; i ++ ) // 遍历所有玩具
    {
        if(!st[i])
        {
            st[i] = true;
            memcpy(backup[i], happy, sizeof happy);
            res.push_back(i);
            for(int j = 1; j <= n; j ++ )
            {
                if(w[i][j] == 1)    happy[j] = 1;
                else if(w[i][j] == -1)  happy[j] = 0;
            }
            
            dfs(u + 1, s);
            
            memcpy(happy, backup[i], sizeof backup[i]);
            res.pop_back();
            st[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m; i ++ ) // 玩具
        for(int j = 1; j <= n; j ++ ) // 猫
        {
            ans.push_back(i);
            cin >> w[i][j];
        }
        
    dfs(0, m);
    
    for(int i = 0; i < ans.size(); i ++ )   
    {
        cout << ans[i];
        if(i != ans.size() - 1) cout << ' ';
    }
    return 0;
}