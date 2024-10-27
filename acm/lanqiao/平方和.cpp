#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;

LL res = 0;

inline LL get(LL x)
{
    return (LL)x * x;
}

bool check(LL x)
{
    while(x)
    {
        LL t = x % 10;
        if(t == 1 || t == 2 || t == 9 || t == 0) return true;
        x /= 10;
    }
    return false;
}

int main()
{
    for(LL i = 1; i <= 2019; i ++ )
    {
        if(check(i))
            res += get(i);
    }
    cout << res << endl;
    
    return 0;
}