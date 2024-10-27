#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20010, INF = 0x3f3f3f3f;

int n;
int minx = INF, maxn = -INF;
int cnt1, cnt2;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int t;
        cin >> t;
        if(t > maxn)
        {
            maxn = t;
            cnt1 = 1;
        }
        else if(t == maxn)   cnt1 ++ ;
        if(t < minx)
        {
            minx = t;
            cnt2 = 1;
        }
        else if(t == minx)   cnt2 ++ ;
    }
    cout << minx << " " << cnt2 << endl << maxn << " " << cnt1 << endl;
    return 0;
}