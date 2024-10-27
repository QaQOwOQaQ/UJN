//二分+枚举
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 200010;

int n;
LL a[N], s[N], b[N];

bool check(int x)
{
    int l = x + 1, r = n;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(b[mid] > s[x]) l = mid + 1;
        else    r = mid;
    }
    return b[l] == s[x];
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int i = n; i >= 0; i -- )   b[i] = b[i + 1] + a[i];
    
    // for(int i = 1; i <= n; i ++ )   cout << b[i] << " ";
    // cout << endl;
    
    LL res = 0;
    for(int i = n; i >= 0; i -- )
    {
        if(check(i)) 
        {
            res = s[i];
            break;
        }
    }
    cout << res << endl;

    return 0;
}