// 01背包求完全装满的方案数
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

int n, m;
int f[M];   // f[j]:体积是j的方案数  

int main()
{
    f[0] = 1;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) 
    {
        int v;  cin >> v;
        for(int j = m; j >= v; j -- )
            f[j] += f[j - v];
    }
    cout << f[m] << endl;
    return 0;
}