#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int g[N][N];

int main()
{
    cin >> n >> m;
    for(int j = 1; j <= n * m; j ++ )
    {
        string s;   cin >> s;
        int len = s.length();
        int x = 1, y = 1;
        for (int i = 0; i < len; i ++ )
        {
            if(s[i] == '1' && y < m)    y ++ ;
            else if(s[i] == '2' && x < n)    x ++ ;    
            else if(s[i] == '3' && y > 1)    y -- ;
            else if(s[i] == '4' && x > 1)   x -- ;
        }
        if(!g[x][y])    g[x][y] = j;
    }
    
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            cout << g[i][j];
            if(j != m)  cout << ' ';
        }
        cout << endl;
    }
    
    
    
    return 0;
}