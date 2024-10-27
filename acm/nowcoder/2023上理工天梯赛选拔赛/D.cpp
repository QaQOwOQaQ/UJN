#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

#define int long long

using namespace std;

int n;
int cnt[4];
int y[2], x[2], c[2];

signed main()
{
    // 并且苹果不会在棒子上，棒子也不会压着苹果。
    // 从少到多依次有几颗苹果
    cin >> n;
    for(int i = 0; i < 2; i ++ )
    {
        cin >> x[i] >> y[i] >> c[i];
        if(y[i] < 0)    x[i] *= -1, y[i] *= -1, c[i] *= -1;
    }
    // by + ax + c == 0  --> wrong
    // by + ax + c < 0   --> 在棒子的右侧
    // by + ax + c > 0   --> 在棒子的左侧
    
    while (n -- )
    {
        int a, b;
        cin >> a >> b;
        if(b * y[0] + a * x[0] + c[0] < 0)
        {
            if(b * y[1] + a * x[1] + c[1] < 0)  cnt[0] ++ ;
            else    cnt[1] ++ ;
        }
        else 
        {
            if(b * y[1] + a * x[1] + c[1] < 0)  cnt[2] ++ ;
            else    cnt[3] ++ ;
        }
    }
    
    sort(cnt, cnt + 4);
    for(auto &x : cnt)  cout << x << ' ';
    cout << endl;
    
    
    return 0;
}