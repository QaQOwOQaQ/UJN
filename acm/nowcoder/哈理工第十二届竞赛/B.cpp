/*
    超时，不会优化=。=
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

int T, hei, bai, k, q;

int ksm(int a, int b, int c)
{
    int res = 1;
    while(b)
    {
        if(b & 1)   res = res * a % c;
        b >>= 1;
        a = a * a % c;
    }
    return res % mod;
}


signed main()
{
    cin >> T;
    while(T -- )
    {
        int res = 1, sum;
        unordered_set<int> l, r;
        cin >> hei >> bai >> k >> q;
        sum = hei + bai;
        if(k > hei) res = 0;
        else
        {
            for(int i = 1, p = hei, q = sum; i <= k; i ++, p -- , q -- )
            {
                l.insert(p);
                r.insert(q);
            }
            
            // for(auto &x : l)    cout << x << " ";
            // cout << endl;
            // for(auto &x : r)    cout << x << " ";
            
            for(auto &x : r)    res = res * ksm(ksm(x, q, mod), mod - 2, mod) % mod;
            for(auto &x : l)    res = (res % mod * ksm(x, q, mod) % mod) % mod;
            cout << res << endl;
            
        }

        // cout << endl;
    }
    return 0;
}