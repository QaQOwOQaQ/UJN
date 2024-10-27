#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int res = a * b;
    string s = to_string(res);
    if(s == "0")    cout << s << endl;
    else
    {
        reverse(s.begin(), s.end());
        int i = 0;
        while(s[i] == '0')  i ++ ;
        for(i; s[i]; i ++ ) cout << s[i];
    }
    return 0;
}