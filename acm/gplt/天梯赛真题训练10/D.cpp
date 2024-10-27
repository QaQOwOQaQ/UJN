#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    
    int res = 100 * 100 / 2 - (100 - x) * y - x * y / 2 - (100 - y) * (100 - x) / 2;
    cout << res << endl;
    
    
    
    return 0;
}