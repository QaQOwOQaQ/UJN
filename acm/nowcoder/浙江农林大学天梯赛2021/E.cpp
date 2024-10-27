/*
学到了toupper() 和tolower()函数
上面的函数是对字符的操作，不是对字符串的操作
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cnt[30];

int main()
{
    string s;   
    getline(cin, s);
    
        for(int i = 0; i < s.size(); i ++ )
        {
            int t;
            if(s[i] >= 'A' && s[i] <= 'Z')  t = s[i] - 'A';
            else if(s[i] >= 'a' && s[i] <= 'z')    t = s[i] - 'a';
            else    continue;
            cnt[t] ++ ;
        }    
    

    for(int i = 0; i < 26; i ++ )
    {
        if(!cnt[i]) 
        {
            char ch = 'a' + i;
            cout << ch << endl;
        }
    }
    return 0;
}