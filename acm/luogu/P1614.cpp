#include <iostream>

using namespace std;

const int N = 3100;

int n, m, a[N];
int res = 3000000;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )   cin >> a[i], a[i] += a[i - 1];
    // [i - m + 1, i]
    for(int i = m; i <= n; i ++ )
        res = min(res, a[i] - a[i - m]);
    cout << res << endl;
    return 0;
}