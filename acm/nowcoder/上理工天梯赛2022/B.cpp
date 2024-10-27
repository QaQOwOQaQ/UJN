/*
快速幂，竟然WRONG了两发，小丑！！！
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL n;

LL ksm(LL a, LL b, LL mod)
{
    LL res = 1;
    while(b)
    {
        if(b & 1)   res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res % mod;
}

int main()
{
    cin >> n;
    LL res = ksm(n, n, n + 2);
    cout << res << endl;
    
    return 0;
}