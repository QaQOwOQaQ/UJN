// 注意输入字符串可能存在空格
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    getchar();
    while(T -- )
    {
        string s; 
        getline(cin, s);
        if(s.size() < 6)    
        {
            puts("Your password is tai duan le.");
            continue;
        }
        bool invalid = false;
        bool num = false;
        bool alpha = false;
        for(auto &ch : s)
        {
            if(ch == '.')  continue ;
            if(ch >= '0' && ch <= '9')  num = true;
            else if(isalpha(ch))   alpha = true;
            else invalid = true;
        }
        if(invalid)     puts("Your password is tai luan le.");
        else if(!num)   puts("Your password needs shu zi.");
        else if(!alpha) puts("Your password needs zi mu.");
        else            puts("Your password is wan mei.");
    }
    return 0;
}