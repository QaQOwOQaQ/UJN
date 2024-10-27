// 库存量、总售价、以及市场的最大需求量
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 1010;
typedef pair<int, int> PII;

int n, m;
PII w[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )    cin >> w[i].first;
    for(int i = 0; i < n; i ++ )    cin >> w[i].second;
    
    sort(w, w + n, [&](const PII &l, const PII &r){
        return (long long)l.second * r.first > (long long)l.first * r.second;
    });
    
    double res = 0;
    for(int i = 0; i < n; i ++ )
    {
        int cnt = min(m, w[i].first);
        // should cast to double
        res += (double)cnt * w[i].second / w[i].first;
        m -= cnt;
        if(m == 0)  break;
    }
    
    printf("%.2f\n", res);
    return 0;
}