#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long
#define debug(val)  cout << #val << " = " << val << endl

using namespace std;

int n, m, T;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    while(T -- )
    {
        int cnt = 0;
        cin >> n >> m;
        while(n && m)
        {
            if(n >= m)
            {
                int t = n / m;
                cnt += t;
                n -= t * m;
                // cout << n << " " << m << endl;
            }
            else
            {
                int t = m / n;
                cnt += t;
                m -= t * n;
                // cout << n << " " << m << endl;
            }
        }
        cout << cnt << endl;
    }
    
    return 0;
}