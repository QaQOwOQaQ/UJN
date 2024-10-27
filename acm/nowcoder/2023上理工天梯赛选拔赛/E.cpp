/*========*/
/*   dp   */
/*========*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 33;

int f[N][N][N][N];

void solve()
{
    int n;  cin >> n;
    int k = n >> 2;
    for(int i = 1; i <= n; i ++ )
    {
        int A, B, C, D;
        cin >> A >> B >> C >>D;
        for(int a = k; a >= 0; a -- )
            for(int b = k; b >= 0; b -- )
                for(int c = k; c >= 0; c -- )
                    for(int d = k; d >= 0; d -- )
                    {
                        if(a + b + c + d != i)  continue;
                        if(a > 0)   f[a][b][c][d] = max(f[a][b][c][d], f[a - 1][b][c][d] + A);
                        if(b > 0)   f[a][b][c][d] = max(f[a][b][c][d], f[a][b - 1][c][d] + B);
                        if(c > 0)   f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c - 1][d] + C);
                        if(d > 0)   f[a][b][c][d] = max(f[a][b][c][d], f[a][b][c][d - 1] + D);
                    }
    }
    cout << f[k][k][k][k] << endl;
}

int main()
{
    solve();
    return 0;
}