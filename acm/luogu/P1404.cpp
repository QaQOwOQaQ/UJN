#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
// memory answer which have searched
// -1: not search
// 1 : is prime
// 0 : not prime
int st[10010]; 

int is_prime(int x)
{
    if(st[x] != -1)   return st[x];
    if(x < 2)   return 0;
    for(int i = 2; i <= x / i; i ++ )
        if(x % i == 0)
            return st[x] = 0;
    return st[x] = 1;
}

int main()
{
    memset(st, -1, sizeof st);
    cin >> n;
    for(int i = 4; i <= n; i += 2)
    {
        for(int j = 2; j <= n; j ++ )
        {
            if(is_prime(j) && is_prime(i - j))
            {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
    return 0;
}