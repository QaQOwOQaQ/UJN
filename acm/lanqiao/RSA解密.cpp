#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod =  1001733993063167141, C = 20190324;

LL ksm(LL a, LL b)
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
    for(int i = 1; ; i ++ )
    {
        if(ksm(i, 212353) == C)
        {
            cout << "res: " << i << endl;
            return 0;
        }
        cout << 1 << " ";
    }
    
    return 0;
}