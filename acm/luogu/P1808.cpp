#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010;

int n;
string s[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        string t;   cin >> t;
        sort(t.begin(), t.end());
        s[i] = t;
    }
    sort(s, s + n);
    int res = 1;
    for(int i = 1; i < n; i ++ )
        if(s[i] != s[i - 1])
            res ++ ;
    cout << res << endl;
    return 0;
}