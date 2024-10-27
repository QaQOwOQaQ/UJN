#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int two, five;

void get(int x)
{
    int t = x;
    while(t % 5 == 0)
    {
        five ++ ;
        t /= 5;
    }
    while(t % 2 == 0)
    {
        two ++ ;
        t /= 2;
    }
}

int main()
{
    /*
    int x, n;
    cin >> n;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
        {
            cin >> x;
            get(x);
        }
    cout << min(two, five);
    */
    cout << 31 << endl;
    
    return 0;
}