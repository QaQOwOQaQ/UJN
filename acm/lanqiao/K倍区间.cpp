#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long
#define endl '\n'

using namespace std;

const int N = 100010;

int n, k, s[N], cnt[N];

signed main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        s[i] = (s[i] + s[i - 1]) % k;
    }
    
    int res = 0;
    cnt[0] = 1;
    for(int i = 1; i <= n; i ++ )
    {
        res += (cnt[s[i]] ++ );
    }
    cout << res << endl;
    
}