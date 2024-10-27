#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000010;

typedef long long LL;

int n, a[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int d = 0, n;  
    cin >> n;
    for(int i = 0; i < n; i ++ )    cin >> a[i];
    sort(a, a + n);
    
    for(int i = 1; i < n; i ++ )
    {
        d = gcd(d, a[i] - a[i - 1]);
    }   
    
    LL res;
    if(d)   res = (LL)(a[n - 1] - a[0]) / d + 1;
    else res = n;
    cout << res;
    
    
    return 0;
}