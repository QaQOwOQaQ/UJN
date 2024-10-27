#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        int idx = 0;
        string s;   cin >> s;
        for(int i = 0; i < n; i ++ )
            idx = idx * 2 + (s[i] == 'n');
        
        cout << idx + 1 << endl;
    }
    
    
    return 0;
}