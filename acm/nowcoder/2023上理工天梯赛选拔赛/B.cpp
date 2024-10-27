#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n, k;
PII w[N];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i ++ )   cin >> w[i].x >> w[i].y;
    
    // 白天大的放在后面，晚上大的放在前面
    // diff = 晚上 - 早上
    sort(w, w + n, [&](const PII &lhs, PII &rhs){
        return lhs.y - lhs.x > rhs.y - rhs.x;
    });
    
    int res = 0;
    for(int i = 0; i < n; i ++ )
    {
        auto [a,b] = w[i];
        if( -- k >= 0) res += b;
        else    res += a;
        // cout << a << ' ' << b << endl;
    }
    
    cout << res << endl;
    return 0;
}