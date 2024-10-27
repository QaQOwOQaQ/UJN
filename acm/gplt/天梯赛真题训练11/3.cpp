#include <iostream>

using namespace std;

int n, k, a, b;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        cin >> k;
        if(k & 1)   a ++ ;
        else    b ++ ;
    }    
    cout << a << " " << b << endl;
    return 0;
}