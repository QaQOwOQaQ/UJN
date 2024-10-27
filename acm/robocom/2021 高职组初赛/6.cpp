#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100;

int n, m;
int g[N][N];

int main()
{
    cin >> n >> m;
    while (m -- )
    {
        string s;   cin >> s;
        int a = 0, b = 0, len = s.length();
        
        if((int)s.find(";") != -1) // 两问
        {
            bool flag = false;
            for(int i = 0; i < len; i ++ )
            {
                if(s[i] == ';') flag = true;
                else if(flag)   b = b * 10 + s[i] - '0';
                else    a = a * 10 + s[i] - '0';
            } 
        }
        else if((int)s.find("/") != -1) //  分数
        {
            bool flag = false;
            for(int i = 0; i < len; i ++ )
            {
                if(s[i] == '/') flag = true;
                else if(flag)   b = b * 10 + s[i] - '0';
                else    a = a * 10 + s[i] - '0';
            }
        }
        else // 数字
        {
            while(s.length() < 4)   s = "0" + s;
            a = (s[0] - '0') * 10 + s[1] - '0', b = (s[2] - '0') * 10 + s[3] - '0';
        }
        // cout << a << ' ' << b << endl;
        g[n - b + 1][a] = true;
    }
    
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = 1; j <= n; j ++ )
        {
            if(g[i][j]) cout << '#';
            else    cout << ".";
        }
        cout << endl;
    }
    
    return 0;
}