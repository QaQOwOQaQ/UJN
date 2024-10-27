// 17:50
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    long long res = 0;
    int x, n;
    cin >> x >> n;
    res += 250 * 5 * (n / 7);
    n = n % 7;
    while(n -- )
    {
        if(!(x == 6 || x == 7))
            res += 250;
        x = x + 1;
        if(x == 8)  x = 1;
    }
    cout << res << endl;
    return 0;
}