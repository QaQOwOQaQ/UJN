#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 2019, res;

bool check(int a, int b, int c)
{
    if(a == b || b == c || a == c)  return false;
    if(c < b)   return false;
    while(a)
    {
        if(a % 10 == 2 || a % 10 == 4)  return false;
        a /= 10;
    }
    while(b)
    {
        if(b % 10 == 2 || b % 10 == 4)  return false;
        b /= 10;
    }
    while(c)
    {
        if(c % 10 == 2 || c % 10 == 4)  return false;
        c /= 10;
    }
    return true;
}

int main()
{
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = i; i + j <= n; j ++ )
        {
            int t = n - (i + j);
            if(check(i, j, t))  res++;
        }
    }
    cout << res << endl;
    return 0;
    
}