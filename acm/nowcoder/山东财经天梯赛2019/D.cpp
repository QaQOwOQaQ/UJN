#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 1e6 + 100;

int n, dp[N];
PII p[N];

bool cmp(PII a, PII b)
{
    return a.y < b.y;
}

signed main()
{
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int l, r;
        cin >> l >> r;
        p[i] = {l, r};
    }

    sort(p, p + n, cmp);
    for(int i = 0; i < n; i ++ )
    {
        int l = p[i].x, r = p[i].y;
        dp[r] = max(dp[r], dp[l] + r - l);        
    }
    
    int res = -1;
    for(int i = 0; i < n; i ++ )
        res = max(res, dp[p[i].y]);
    cout << res << endl;
    return 0;
}