/*
    枚举 + 思维
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
long long res;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j + i <= n; j ++ )
        {
            int k = n - i - j;
            long long t = i * j * k;
            if(t > res) res = t;
        }
    }
    cout << res << endl;
    return 0;
}