#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int len = s.length();
    bool f1 = true, f2 = true;
    int a = 0, b = 0;
    int i, j, k;
    
    for(k = 0; k < len; k ++ )
        if(s[k] != ' ') break;
    
    for(i = k; i < len; i ++ )
    {
        if(s[i] == ' ') break;
        if(f1 && s[i] >= '0' && s[i] <= '9')  a = a * 10 + s[i] - '0';
        else f1 = false;
        if(a > 1000)   f1 =false;
    }
    for(j = i + 1; j < len; j ++ )
    {
        if(f2 && s[j] >= '0' && s[j] <= '9')    b = b * 10 + s[j] - '0';
        else    f2 = false;
        if(b > 1000)   f2 = false;
    }
    if(a < 1)   f1 = false;
    if(b < 1)   f2 = false;
    f1 ? cout << a : cout << '?'; 
    cout << " + ";
    f2 ? cout << b : cout << '?';
    cout << " = ";
    if(f1 && f2)    cout << a + b << endl;
    else    cout << '?' << endl;

    return 0;
}