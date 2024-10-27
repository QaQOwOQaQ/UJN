#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool check(int x)
{
    while(x)
    {
        int t = x % 10;
        if(t == 2 || t == 0 || t == 1 || t == 9)    return true;
        x /= 10;
    }
    return false;
}

int main()
{
    int res = 0;
    for(int i = 1; i <= 2019; i ++ )
    {
        if(check(i))    res += i;
    }
    cout << res << endl;
    
    return 0;
}