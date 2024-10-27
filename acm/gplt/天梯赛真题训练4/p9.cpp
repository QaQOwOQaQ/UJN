#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, w[N];
int res, l, r;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )    cin >> w[i];
    sort(w + 1, w + n + 1);
    if(n & 1)   //odd
    {
        int mid = (n + 1) >> 1;
        for(int i = 1; i <= n; i ++ )
        {
            if(i < mid)  res += w[i];
            if(i > mid)  res -= w[i];
        }
        if(abs(res + w[mid]) >= abs(res - w[mid]))
        {
            res = res + w[mid];
            l = mid, r = n - mid;
        }
        else
        {
            res = res - w[mid];
            l = mid - 1, r = n - mid + 1;
        }
    }
    else    //even
    {
        l = r = n / 2;
        for(int i = 1; i <= n; i ++ )
        {
            if(i <= n / 2)  res += w[i];
            else    res -= w[i];
        }
    }
    
    printf("Outgoing #: %d\n", max(l, r));
    printf("Introverted #: %d\n", min(l, r));
    printf("Diff = %d\n", abs(res));
    return 0;
}