#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
/*
    1.密码必须由不少于6个字符组成
    2.只能有英文字母、数字和小数点 .
    3.还必须既有字母也有数字。
*/
int main()
{
    int n;  cin >> n;
    getchar();
    while(n -- )
    {
        string s;
        getline(cin, s);//可能会输入空格
        bool has_nod = false, has_digital = false, has_alphabet = false, has_len = false, has_other = false;
        int len = s.length();
        if(len >= 6)    has_len = true;
        for(int i = 0; i < len; i ++ )
        {
            if(s[i] >= '0' && s[i] <= '9')  has_digital = true;
            else if(s[i] == '.')    has_nod = true;
            else if(s[i] >= 'a' && s[i] <= 'z') has_alphabet = true;
            else if(s[i] >= 'A' && s[i] <= 'Z') has_alphabet = true;
            else    has_other = true;
        }
        if(!has_len)    puts("Your password is tai duan le.");
        else if(has_other)  puts("Your password is tai luan le.");
        else if(!has_digital)   puts("Your password needs shu zi.");
        else if(!has_alphabet)   puts("Your password needs zi mu.");
        else    puts("Your password is wan mei.");
    }
    
    
    
    return 0;
}