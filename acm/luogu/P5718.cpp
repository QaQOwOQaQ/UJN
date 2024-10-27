#include <iostream>

using namespace std;

const int MAX = 1000;

int main()
{
    int n, res = MAX + 10;
    cin >> n;
    while(n -- )    
    {
        int x;  cin >> x;
        res = min(res, x);
    }
    cout << res << endl;
    return 0;
}