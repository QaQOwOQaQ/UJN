#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a[10];

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i ++ )  a[s[i] - '0'] ++ ; 
    for(int i = 0; i <= 9; i ++ )
        if(a[i])    cout << i << ":" << a[i] << endl;
    
    
    return 0;
}