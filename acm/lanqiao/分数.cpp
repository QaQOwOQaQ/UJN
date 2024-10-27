#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL aa = 1, bb = 1;// a/b

LL gcd(LL a, LL b)
{
    return b ? gcd(b, a % b) : a;
}

LL getmin(LL a, LL b)
{
    return a * b / gcd(a, b);
}

inline LL sqr(int x)
{
    LL res = 1;
    for (int i = 0; i < x - 1; i ++ )
        res *= 2;
    return res;
}

int main()
{
    for(int i = 2; i <= 20; i ++ )
    {
        int y = sqr(i), x = 1;
        int t = getmin(bb, y);
        aa = aa * t / bb + x * t / y;
        bb = t;
        int p = gcd(aa, bb);
        aa /= p;
        bb /= p;
    }
    cout << aa << "/" << bb << endl;
}