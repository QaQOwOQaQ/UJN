// 我是真的傻逼
// 1. 不好好看数据范围，M 开小了
// 2. 不好好看数据范围，f 可能爆int
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 1e7 + 10;

int n, m;
long long f[M];

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int v, w;   cin >> v >> w;
        for(int j = v; j <= m; j ++ )
            f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[m] << endl;
    return 0;
}