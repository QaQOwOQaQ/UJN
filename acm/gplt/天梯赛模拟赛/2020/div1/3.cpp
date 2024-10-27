#include <iostream>
using namespace std;
int main()
{
    int n;  cin >> n;
    int odd = 0, even = 0;
    while(n -- )
    {
        int x;  cin >> x;
        if(x & 1)   odd ++ ;
        else    even ++ ;
    }
    cout << odd << ' ' << even << endl;
}