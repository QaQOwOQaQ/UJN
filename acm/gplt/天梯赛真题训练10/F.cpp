#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    while(n -- )
    {
        cin >> s;
        int a = 0;
        for(int i = 0; i < 6; i ++ )
        {
            if(i <= 2)  a += s[i] - '0';
            else    a -= s[i] - '0';
        }
        if(a)   puts("Wish you good luck.");
        else    puts("You are lucky!");
    }
    
    return 0;
}