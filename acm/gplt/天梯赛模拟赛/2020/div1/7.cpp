#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long 

using namespace std;

bool check(string s)
{
    int x = 0;
    for(int i = 0; i < s.size(); i ++ )
        x = x * 10 + s[i] - '0';
    if(x == 1)  return false;
    if(x == 2)  return true;
    for(int i = 2; i <= x / i; i ++ )
        if(x % i == 0)  return false;
    return true;
}

signed main()
{
    int n, k;
    string s;

    cin >> n >> k >> s;
    for(int i = 0; i + k - 1 < n; i ++ )
    {
        // r = i + k - 1
        string cur = s.substr(i, k);
        if(check(cur)) 
        {
            cout << cur << endl;
            return 0;
        }
    }
    puts("404");
    
    return 0;
}