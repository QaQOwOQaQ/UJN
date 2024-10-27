#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    LL n, k;
    
    LL res = 0, t = 1;//t表示当前位于k进制的第几位
    cin >> n >> k;
    while(n)
    {
        if(n & 1)
        {
            res = (res + t) % mod;
        }
        t = t * k % mod;
        n >>= 1;
    }
    
    cout << res << endl;
    
    return 0;
}