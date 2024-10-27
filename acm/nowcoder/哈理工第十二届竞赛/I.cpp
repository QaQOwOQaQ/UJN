/*
读懂题意就很简单了
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2000;

int T, n, w[N], a[N];

int main()
{
    cin >> T;
    while(T -- )
    {
        cin >> n;
        for(int i = 1; i <= n; i ++ )    cin >> w[i];
        sort(w + 1, w + n + 1);
        long long res = 0;
        for(int i = 1; i <= n; i ++ )
            a[i] = (w[i] - w[i - 1]);
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i ++ )
            res += a[i] * (n - i + 1);
        cout << res << endl;
    }
    
    return 0;
}
/*
20 50 60 -- > 20 30 10
10 + 10+20 +10+20+30
200 70 40 10 -- > 10 40 70 200
10 30 30 130
10 + 10+30 + 10+30+30 + 10+30+30+130
=10+40+70+200
98*/
