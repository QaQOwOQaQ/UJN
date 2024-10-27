#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k;
string s;

bool check(string str)
{
    long long t = 0;
    for(int i = 0; str[i]; i ++ )
        t = (long long)t * 10 + str[i] - '0';
    
    if(t < 2)   return 0;
    for(int i = 2; i <= t / i; i ++ )
        if(t % i == 0)  return 0;
    return 1;
}

int main()
{
   cin >> n >> k >> s;
   for(int i = 0; i <= n - k; i ++ )//取到等于！！！
   {
       string str = s.substr(i, k);
       if(check(str))
       {
           cout << str << endl;
           return 0;
       }
   }
    
    cout << 404 << endl;
    
    return 0;
}