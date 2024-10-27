#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 20010, INF = 0x3f3f3f3f;

int n, a[N];
int maxn = -1, minx = INF, cnt1, cnt2;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        if(x > maxn)
        {
            maxn = x;
            cnt1 = 1;
        }
        else if(x == maxn)   cnt1 ++ ;
        if(x < minx)
        {
            minx = x;
            cnt2 = 1;
        }
        else if(x == minx)  cnt2 ++ ;
    }
    cout << minx << " " << cnt2 << endl << maxn << " " << cnt1;
    cout << endl;
    
    return 0;
}