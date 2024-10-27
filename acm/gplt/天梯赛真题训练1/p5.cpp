#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n, res;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int t = 1;
        for(int j = 1; j <= i; j ++ )   t *= j;
        res += t;
    }
    cout << res << endl;
    
    return 0;
}