#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int g, p, l ,t;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i ++ )
    {
        if(s[i] == 'G' || s[i] == 'g') g ++ ;
        if(s[i] == 'P' || s[i] == 'p') p ++ ;
        if(s[i] == 'L' || s[i] == 'l') l ++ ;
        if(s[i] == 'T' || s[i] == 't') t ++ ;
    }
    // cout << g << " " << p << " " << l << " " << t << endl;
    while(g || p || l || t)
    {
        if(g)   cout << 'G', g -- ;
        if(p)   cout << 'P', p -- ;
        if(l)   cout << 'L', l -- ;
        if(t)   cout << 'T', t -- ;
    }
    return 0;
}