/*
简单贪心
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

int T, n;
long long w[N], m[N];

int main()
{
    cin >> T;
    while(T -- )
    {
        long long res = 0;
        cin >> n;
        for(int i = 0; i < n; i ++ )    cin >> w[i];
        for(int i = 0; i < n; i ++ )    cin >> m[i];
        sort(w, w + n);
        sort(m, m + n, greater<int>());
        for(int i = 0; i < n; i ++ )    res += w[i] * m[i];
        cout << res << endl;
    }
    
    return 0;
}