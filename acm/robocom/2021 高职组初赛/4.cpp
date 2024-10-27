#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int check(char ch)
{
    if(ch >= 'A' && ch <= 'Z')  return 1;
    else if(ch >= 'a' && ch <= 'z') return 0;
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while(T -- )
    {
        bool flag = true;
        string s;
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len; i ++ )
        {
            char ch = s[i];
            if(i == len - 1)    break;
            if(check(ch) == -1) flag = false;
            else if(check(ch) == 1) // da xie
            {
                if(s[i + 1] == s[i] + 32 || s[i + 1] == s[i] + 1)   continue;
                else    flag = false;
            }
            else // xiao xie
            {
                if(s[i + 1] == s[i] - 32 || s[i + 1] == s[i] - 1)   continue;
                else    flag = false;
            }
        }
        if(flag)    cout << 'Y' << endl;
        else    cout << 'N' << endl;
    }
    
    return 0;
}