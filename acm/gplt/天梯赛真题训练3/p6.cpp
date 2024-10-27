#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 60;

int n, f[N], w[N];
string s[N];
bool st[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   cin >> w[i] >> s[i];
    
    for(int i = 1; i <= n / 2; i ++ )
    {
        for(int j = n; j >= n / 2 + 1; j -- )
        {
            if(!st[j] && w[i] + w[j] == 1)
            {
                f[i] = j;
                st[j] = true;
                break;
            }
        }
    }
  
    for(int i = 1; i <= n / 2; i ++ )
        cout << s[i] << " " << s[f[i]] << endl;

    
    return 0;
}