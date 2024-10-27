#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s = "";
    for(int i = 0; i < 300; i ++ )  s += to_string(i);
    
    int idx, n, len, last;
    while(cin >> n)
    {
        idx = 1, last = 0;
        len = 1 + 2 * n - 1 + 2 * (n - 2);
        for(int i = 1; i <= n; i ++ )
        {
            if(i == n)
            {
                for(int j = 0; j < 2 * n - 1; j ++ )
                    cout << s[idx ++ ];
                cout << endl;
            }
            else
            {
                int l = n - (i - 1), r = n + i - 1;
                for(int j = 1; j <= n + (i - 1); j ++ )
                {
                    if(j == l)    cout << s[idx ++ ];
                    else if(j == r) cout << s[len - last], last ++ ;
                    else    cout << '.';
                }
                cout << endl;
            }
        }
    }
    
    
    
    return 0;
}