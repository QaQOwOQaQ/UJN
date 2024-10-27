#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

void check(string s)
{
    if(s[0] - '0' + s[1] - '0' + s[2] - '0' == s[3] - '0' + s[4] - '0' + s[5] - '0')
        puts("You are lucky!");
    else    
        puts("Wish you good luck.");
}

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        string s;
        cin >> s;
        check(s);
    }
    
    return 0;
}