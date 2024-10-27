#include <iostream>
#include <cstring>
#include <algorithm>

#define debug1(val) cout << #val << " = " << val

using namespace std;

const int N = 3010, INF = 0x3f3f3f3f;

int n, H, res;
int h[N], dp[N];

int main()
{
    cin >> n >> H;
    for(int i = 1; i <= n; i ++ ) cin >> h[i];
    sort(h + 1, h + 1 + n);
    
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i ++ )
        for(int j = H; j >= h[i]; j -- )
            dp[j] = min(dp[j], dp[j - h[i]] + 1);
    
    if(dp[H] == dp[N - 1])  cout << -1 << endl;
    else
    {
        cout << dp[H] << endl;
        int res = dp[H];
        for(int i = 1; i <= n; i ++ )
        {
            if(dp[H - h[i]] == res - 1)
            {
                cout << h[i] << ' ';
                H -= h[i];
                res -- ;
                if(!res)    break;
            }
        }
    }
    
    return 0;
}