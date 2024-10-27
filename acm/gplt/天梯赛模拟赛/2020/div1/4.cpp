#include <iostream>
using namespace std;
int main()
{
    /*
    纸牌会变成等量的硬币
    而硬币变成纸牌时，纸牌的数量会加倍
    */
    int cnt1, n, cnt2 = 0;
    cin >> cnt1 >> n;
    for(int i = 0; i < n; i ++ )
    {
        if(i & 1)   cnt1 = cnt2 << 1, cnt2 = 0;
        else cnt2 = cnt1, cnt1 = 0;        
    }
    if(cnt1)    cout << 0 << ' ' << cnt1 << endl;
    else        cout << 1 << ' ' << cnt2 << endl;
}