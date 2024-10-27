//细节决定成败
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

int cnt[30];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i ++ )
    {
        int t = s[i] - 'a' + 1;
        cnt[t] ++ ;
    }
    LL res = 0;
    //超级恶心，相邻不仅仅是ab，还可能是ba！！！
    for(int i = 0; i < n; i ++ )
    {
        int t = s[i] - 'a' + 1;
        res += cnt[t + 1];
        res += cnt[t - 1];
        cnt[t] -- ;
    }
    cout << res << endl;
    return 0;
}