/*
有一个细节就是炸弹可以在一个地方炸多次
否则当n=1，只有一个格子
剩下两个炸弹没地方炸了！
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, st[20][20];
long long w[20][20], res;
bool vis[20][20];
int dx[9] = {0, 0, 0, 0, 0, 1, -1, 2, -2}, dy[9] = {0, 1, -1, 2, -2, 0, 0, 0, 0};

void dfs(int u, long long val)
{
    if(u > 3)   
    {
        res = max(res, val);
        return ;
    }
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            // if(!vis[i][j])//no boom
            {
                vis[i][j] = true;//boom ed
                long long t = 0;
                
                for(int k = 0; k < 9; k ++ )
                {
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 1 || y < 1 || x > n || y > n)    continue;
                    if(!st[x][y]) t += w[x][y];
                    st[x][y] ++ ;
                }

                //go on
                dfs(u + 1, val + t);
                
                //back
                // vis[i][j] = false;
                for(int k = 0; k < 9; k ++ )
                {
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 1 || y < 1 || x > n || y > n)    continue;
                    st[x][y] -- ;
                }
            }
        }
    }
    
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )
            cin >> w[i][j];
    
    dfs(1, 0);
    
    cout << res << endl;
    
    
    return 0;
}