#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 200010;

int n, a[N];
int f[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )   cin >> a[i];
    
    for(int i = 1; i <= n; i ++ )
        f[i] = max(a[i], f[i - 1] + a[i]);

    int res = f[1];
    for(int i = 2; i <= n; i ++ )
        res = max(res, f[i]);
    
    cout << res << endl;
    
    return 0;
}