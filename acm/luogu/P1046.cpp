#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a[10];
    for(int i = 0; i < 10; i ++ )   cin >> a[i];
    int x;  cin >> x;
    x += 30;
    int res = 0;
    for(int i = 0; i < 10; i ++ )
        res += a[i] <= x;
    cout << res << endl;
    return 0;
}