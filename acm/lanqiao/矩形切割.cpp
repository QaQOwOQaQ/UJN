#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL res = 0;

int main()
{
    int l = 2019, r = 324;
    while(l != r)
    {
        if(l < r)   r -= l;
        else    l -= r;
        res ++ ;
    }
    cout << res + 1 << endl;
    
    return 0;
}