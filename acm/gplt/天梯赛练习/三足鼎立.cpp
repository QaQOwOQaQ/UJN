#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 100010;

int n, a[N];
long long p = 0;

bool check(int a, int b, int c)
{
    if(a + b <= c || a + c <= b || b + c <= a)   return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i ++ )    cin >> a[i];
    sort(a, a + n);

    
    long long res = 0;
    
    for(int i = 0; i < n - 1; i ++ )
    {
        int maxn = a[i] + p, minx = abs(a[i] - p);
        
        int l = i + 1, r = n - 1;
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(a[mid] > minx)   r = mid;
            else    l = mid + 1;
        }
        int last = r;
        
        l = i + 1, r = n - 1;
        while(l < r)
        {
            int mid = l + r + 1 >> 1;
            if(a[mid] < maxn)   l = mid;
            else    r = mid - 1;
        }
        
        // cout << last << ' ' << r << endl;
        
        if(r == last)
        {
            if(check(a[last], a[i], p)) res ++ ;
        }
        else if(last > r)    continue;
        else    res += (r - last + 1);
    }
    cout << res << endl;
    
    return 0;
}

