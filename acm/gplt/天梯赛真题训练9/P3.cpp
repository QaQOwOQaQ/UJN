#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int x;
    cin >> x;
    int res = (x + 2) % 7;
    if(res == 0)    res = 7;
    cout << res;
    return 0;
}