#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n, m;
char g[N][N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y)
{
    g[x][y] = '0';
    for(int i = 0; i < 4; i ++ )
    {
        int a = x + dx[i], b = y + dy[i];
        if(a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '0')    continue;
        dfs(a, b);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )    cin >> g[i];
    int res = 0;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < m; j ++ )
        {
            if(g[i][j] >= '1' && g[i][j] <= '9')
            {
                res ++ ;
                dfs(i, j);
            }
        }
    cout << res << endl;
    return 0;
}