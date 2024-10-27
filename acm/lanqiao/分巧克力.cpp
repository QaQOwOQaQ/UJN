#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, k, maxn;
PII p[N];

bool check(int x)
{
    int res = 0;
    for(int i = 0; i < n; i ++ )
        res += (p[i].first / x) * (p[i].second / x);
        
    return res >= k;
}

signed main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        maxn = max(maxn, x);
        maxn = max(maxn, y);
        p[i] = {x, y};
    }
    
    int l = 1, r = maxn;
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check(mid))  l = mid;
        else    r = mid - 1;
    }
    
    cout << l << endl;
    
    
    return 0;
}