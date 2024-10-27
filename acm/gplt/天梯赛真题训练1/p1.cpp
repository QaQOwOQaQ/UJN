#include <iostream>
#include <cstring>
#include <algorithm>

typedef long long LL;

using namespace std;

int n;
int l, r;
int res, a, b;

int gcd(int x, int y)
{
    return y ? gcd(y, x % y) : x;    
}

int get(int x, int y)
{
    return x * y / gcd(x, y);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i ++ )
    {
        scanf("%d/%d", &l, &r);   
        if(!i)  a = l, b = r;
        else
        {
            int t = get(r, b);
            a = t / b * a + t / r * l;
            b = t; 
        }
        int t = abs(gcd(a, b)); //这里需要在化简
        a /= t, b /= t;
    }
    
    if(a % b == 0) printf("%d", a / b);
    else
    {
        int t = gcd(a, b);
        a /= t, b /= t;
        res = a / b;
        a -= res * b;
        if(!res)    printf("%d/%d\n", a ,b);
        else   printf("%d %d/%d\n", res, a, b);
    }
    
    return 0;
}