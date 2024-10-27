#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    while(m -- )
    {
        string s;
        cin >> s;
        int res = 0;
        for(int i = 0; i < n; i ++ )
        {
            if(s[i]=='y')   res=res*2;
            else    res=res*2+1;
        }
        cout << (res + 1) << endl;
    }
    
    return 0;
}