#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, odd = 0;
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        if(x & 1)   odd ++ ;
    }
    cout << odd << " " << n - odd << endl;
   
    
    return 0;
}