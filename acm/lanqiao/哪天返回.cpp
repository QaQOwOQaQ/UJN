#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int res = 0;
    int d = 1;
    for(int i = 1; i <= 108; i ++ )
    {
        res += d;
        d += 2;
        if(res >= 108)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}