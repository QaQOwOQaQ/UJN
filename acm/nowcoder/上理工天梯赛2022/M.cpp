/*
//纯暴力，竟然过了！可能是数据太弱了！
//但纯暴力你也可能写错！
//题目给定的l和r不一定是l<r的，所以当l>r得时候要交换大小！
//并且这一点你从样例中看不出来！所以你需要多积累！
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, w[N], l, r, op, k, q;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ )  cin >> w[i];
    
    for(int i = 1; i <= q; i ++ )
    {
        cin >> op >> l >> r;
        if(l > r)   swap(l, r);
        if(op == 0)
        {
            cin >> k;
            for(int i = l; i <= r; i ++ )   w[i] += k;
        }
        else if(op == 1)
        {
            long long sum = 0;
            for(int i = l; i <= r; i ++ )   sum += (long long)w[i];
            cout << sum << endl;
        }
        else
        {
            int res = w[l];
            for(int i = l + 1; i <= r; i ++ )   res = gcd(res, w[i]);
            cout << res << endl;
        }
    }
    
    return 0;
}
*/