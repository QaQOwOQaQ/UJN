//数列求值
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e8;

long long a[N];

int main()
{
    int n = 20190324;
    a[0] = 0;
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    a[4] = 3;
    for(int i = 5; i <= n; i ++ )
    {
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % 10000;
    }
    cout << a[n] << endl;

    
    return 0;
}