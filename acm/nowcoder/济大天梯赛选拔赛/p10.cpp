#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, k, m;

int main()
{
    cin >> n >> k >> m;
    int res = n - k * m;
    cout << max(res, 0) << endl;
    
    return 0;
}