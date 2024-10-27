#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char g[110][110], newg[110][110];

int main()
{
    char ch;
    int n;
    cin >> ch >> n;
    getchar();
    for(int i = 0; i < n; i ++ )
    {
        string s;   getline(cin, s);
        for(int j = 0; j < n; j ++ )   
            g[i][j] = s[j];
    }       
 
            
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
            newg[i][j] = g[n - 1 - i][n - 1 - j];
    
    bool flag = false;
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < n; j ++ )
            if(g[i][j] != newg[i][j])
            {
                flag = true;
                break;
            }
    
    if(!flag)    puts("bu yong dao le");
    for(int i = 0; i < n; i ++ )
    {
        for(int j = 0; j < n; j ++ )
        {
            if(newg[i][j] == ' ')   cout << ' ';
            else    cout << ch;
        }
        cout << endl;
    }
    
    
    
    return 0;
}