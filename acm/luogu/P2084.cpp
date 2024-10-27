#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int m;
    string s;
    cin >> m >> s;
    int len = s.size();
    bool is_start = false;
    for(int i = 0; i < len; i ++ )
    {
        if(s[i] != '0')
        {
            if(!is_start)   is_start = true;
            else    cout << "+";
            cout << s[i] << "*" << m << "^" << len - 1 - i;
        }
    }
    cout << endl;
    return 0;
}
