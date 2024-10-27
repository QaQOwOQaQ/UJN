#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = 998244353;

int main()
{
    __int128 res;
    LL n;
    cin >> n;
    res = n % mod * n % mod;
    for(__int128 i = 1, j; i <= n; i = j + 1)
    {
        j = n / (n / i);
        res -= (n / i) * (j - i + 1) * (i + j) / 2;
    }
    cout << (long long)((res % mod + mod) % mod) << endl;    
    
    return 0;
}