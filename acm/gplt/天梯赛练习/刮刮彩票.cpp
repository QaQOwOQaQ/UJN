#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int g[10][10];
bool st[10];
int vis[10][10];
int w[25]={0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,180,3600};

int main()
{
    int sx, sy;
    for(int i = 1; i <= 3; i ++ )
        for(int j = 1; j <= 3; j ++ )
        {
            cin >> g[i][j], st[g[i][j]] = true;
            if(!g[i][j])    sx = i, sy = j;
        }
    for(int i = 1; i <= 9; i ++ )
        if(!st[i])  
        {
            g[sx][sy] = i;
            break;
        }
    
    for(int i = 0; i < 3; i ++ )
    {
        int x, y;
        cin >> x >> y;
        cout << g[x][y] << endl;
    }
    
    int d, res = 0;
    cin >> d;
    if(d >= 1 && d <= 3)
    {
        for(int i = 1; i <= 3; i ++ )
            res += g[d][i];
    }
    else if(d >= 4 && d <= 6)
    {
        for(int i = 1; i <= 3; i ++ )
            res += g[i][d - 3];
    }
    else if(d == 7)
    {
        for(int i = 1; i <= 3; i ++ )
            res += g[i][i];
    }
    else if(d == 8)
    {
        for(int i = 1; i <= 3; i ++ )
            res += g[i][4 - i];
    }

    cout << w[res] << endl;
    
    return 0;
}