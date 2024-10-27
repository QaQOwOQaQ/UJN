/*
n这么小，m这么大，当然二分了
=。=
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100;

int n, a[N], eps, b[N];

bool check(int mid)
{
    memset(b, 0, sizeof b);
    b[0] = -1;
    for(int i = 1; i <= n; i ++ )
    {
        int l = a[i] - mid, r = a[i] + mid;
        if(r <= b[i - 1])   return false;
        b[i] = max(b[i - 1] + 1, l);
    }
    return true;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )    cin >> a[i];
    int l = 0, r = 1e9;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid))  r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}