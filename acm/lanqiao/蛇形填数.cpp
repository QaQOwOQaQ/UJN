#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int g[100][100];

int main()
{
    int x = 1, y = 1;
    
    int cnt = 1;
    int d = 4;  //1 2 3 4 -- 上下左右
    
    g[x][y] = cnt ++ ;
    while(x <= 100 && y <= 100)
    {
        if(d == 4)  //right
        {
            g[x][++ y] = cnt ++ ;
            d = 3;
        }
        if(d == 2)  //down
        {
            g[++ x][y] = cnt ++ ;
            d = 1;
        }
        if(d == 3)  //left
        {
            while(y > 1)   g[++ x][-- y] = cnt ++ ;
            d = 2;
        }
        if(d == 1)  //up
        {
            while(x > 1)   g[-- x][++ y] = cnt ++ ;
            d = 4;
        }
    }
    
    
    // for(int i = 1; i <= 20; i ++ )
    // {
    //     for(int j = 1; j <= 20; j ++ )
    //         cout << g[i][j] << " ";
    //     cout << endl;
    // }
    
    cout << g[20][20] << endl;
    
    return 0;
}