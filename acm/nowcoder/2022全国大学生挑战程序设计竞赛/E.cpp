#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
long long k;

int main()
{
    cin >> k >> n;
    for(int i = 0; i < n; i ++ )
    {
        k += min(k / 10, (long long)5);
        k += 5;
    }
    cout << k << endl;
    
    return 0;
}