/*
预处理+读题认真！
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;  cin >> n;
    getchar();
    for(int u = 0; u < n; u ++ )
    {
        string res = "", t = "", s;
        getline(cin, s);
        // cout << s << endl;
        s += ' ';
        bool is_first = true, is_all_first = true;
        int len = s.length();
        for(int i = 0; i < len; i ++ )
        {
            if(s[i] == ' ')
            { 
                // cout << "t: " << t << endl;
                if(t != "") 
                {
                    res += t;
                    t = "";
                }
                is_first = true;
            }
            else
            {
                // cout << s[i] << " ";
                if(is_first)    
                {
                    if(is_all_first)    
                    {
                        is_first = false;
                        is_all_first = false;
                        t += tolower(s[i]);
                    }
                    else
                    {
                        is_first = false;
                        t += toupper(s[i]);
                    }
                }
                else    t += tolower(s[i]);
            }
        }
        cout << res << endl;
    }
    return 0;
}