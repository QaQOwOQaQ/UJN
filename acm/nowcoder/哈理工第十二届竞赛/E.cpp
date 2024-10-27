/*
    贪心方案：有‘a’选a
    加一个小优化，不要见到‘？’就while找！
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    while(T -- )
    {
        char ch = 'a';
        string s;   cin >> s;
        int len = s.length();
        for(int i = 0; i < len; i ++ )
        {
            if(s[i] != '?') 
            {
                cout << s[i];  
                ch = 'a';
            }
            else
            {
                char l = (i - 1 >= 0) ? s[i - 1] : '?';
                char r = (i + 1 < len) ? s[i + 1] : '?';
                while(ch == l || ch == r)   ch ++ ;
                s[i] = ch;
                if(ch == 'a')   ch ++ ;
                else    ch = 'a';
                cout << s[i];
            }
        }
        cout << endl;
    }
    
    return 0;
}