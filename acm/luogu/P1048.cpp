#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 1010;

int m, n, f[M];

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int v, w;   cin >> v >> w;
        for(int j = m; j >= v; j -- )
            f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m] << endl;
    return 0;
}