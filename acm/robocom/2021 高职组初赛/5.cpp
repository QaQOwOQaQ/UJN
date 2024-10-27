#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

int T;

bool check(int n)
{
    int t = sqrt(n);
    if((long long)t * t == n)  return true;
    return false;
}

signed main()
{
    cin >> T;
    while(T -- )
    {
        int n;  cin >> n;
        

        string s = to_string(n);
        int len = s.length();
        
        if(len & 1) 
        {
            cout << 0 << endl;
            continue;
        }
        
        int a = 0, b = 0;
        for(int i = 0; i < len / 2; i ++ )  a = a * 10 + s[i] - '0';
        for(int i = len / 2; i < len; i ++ )  b = b * 10 + s[i] - '0';
        
        int res = 0;
        if(b - a == 1) //zeng yi shu
        {
            if(check(n))    res = 2;
            else    res = 1;
        }
        
        cout << res << endl;
    }

    return 0;
}