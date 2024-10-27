#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int yes = 0, all = 0;
    for(int i = 0; i < s.length(); i ++ )
    {
        if(s[i] >= '0' && s[i] <= '9')  all ++ ;
        if(s[i] == '2') yes ++ ;
    }
    double res = yes * 1.0 / all;

    if(s[0] == '-')    res *= 1.5;
    if((s[s.length() - 1] - '0') % 2 == 0)   res *= 2;
    res *= 100;
    printf("%.2f%\n", res);
    
    
    
    return 0;
}