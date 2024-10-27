#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
 
using namespace std;
const int N = 1e5 + 10;
pair<int, int> a[N];
int n, m;
int main() 
{
    cin >> n >> m;
    for(int i = 1; i <= m; ++ i) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x < y) swap(x, y);
        a[i] = {x, y};
    }
    sort(a + 1, a + m + 1);
    int lim = a[1].first;
    int ans = 1;
    for(int i = 2; i <= m; ++ i) 
    {
        if(a[i].second < lim) continue;
        lim = a[i].first;
        ans ++;
    }
    cout<<ans<<endl;
}