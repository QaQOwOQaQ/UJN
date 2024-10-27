// 编译距离小改编
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2010;

string a, b;
int k, n, m;
int f[N][N];
 
void init()
{
    cin >> a >> b >> k;
    n = a.size(), m = b.size();
    a = "#" + a, b = "#" + b;
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for(int i = 0; i <= n; i ++ )   f[i][0] = k * i;
    for(int i = 0; i <= m; i ++ )   f[0][i] = k * i;
}
    
void solve()
{
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= m; j ++ )
        {
            f[i][j] = min(f[i - 1][j] + k, f[i][j - 1] + k);
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + abs(a[i] - b[j]));
        }
    }
    cout << f[n][m] << endl;
}

int main()
{
    init();
    solve();    
    return 0;
}
/*
example explain
cmc
snmcc
=================>
    c m c
s n   m   n
2 2 2 0 2 2 = 10
*/