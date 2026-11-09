#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//¿ìËÙ³Ë
LL quick(LL a,LL b, LL mod) {
    return (a*b - (LL)((long double)a/mod*b)*mod+mod)%mod;
}

//¹êËÙ³Ë 
LL slow(LL a, LL k, LL mod)
{
    LL res = 0;
    while(k)
    {
        if(k & 1)res = (res + a) % mod;
        k >>= 1;
        a = 2 * a % mod;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    LL x = 0, m1, a1;
    cin >> m1 >> a1;
    for (int i = 0; i < n - 1; i ++ )
    {
        LL m2, a2;
        cin >> m2 >> a2;
        LL k1, k2;
        LL d = exgcd(m1, m2, k1, k2);
        if ((a2 - a1) % d)
        {
            x = -1;
            break;
        }

        k1 = slow(k1, (a2 - a1) / d, (m2/d));
        k1 = (k1 % (m2/d) + m2/d) % (m2/d);

        x = k1 * m1 + a1;

        a1 += k1 * m1;
        m1 = abs(m1 / d * m2);
    }

    if (x != -1) x = (a1 % m1 + m1) % m1;

    cout << x << endl;

    return 0;
}


