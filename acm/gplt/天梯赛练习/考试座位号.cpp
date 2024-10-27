#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
string s[N];
int b[N], e[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )
        cin >> s[i] >> b[i] >> e[i];
    
    
    cin >> m;
    while(m -- )
    {
        int t;
        cin >> t;
        for(int i = 0; i < n; i ++ )
        {
            if(b[i] == t)
            {
                cout << s[i] << " " << e[i] << endl;
                break;
            }
        }
    }
    
    return 0;
}