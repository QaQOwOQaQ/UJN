#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1100];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int k;  cin >> k;
        for(int j = 0; j < k; j ++ )
        {
            int t;
            cin >> t;   a[t] ++ ;
        }
    }
    
    int res = 0;
    for(int i = 1; i <= 1000; i ++ )
    {
        if(a[i] >= a[res]) res = i;
    }
    
    cout << res << " " << a[res] << endl;
    return 0;
}