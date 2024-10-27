#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

string s;

bool check(string str)
{
    string t = str;
    reverse(str.begin(), str.end());
    if(t == str)    return true;
    return false;
}

int main()
{
    getline(cin, s);
    int len = s.length();
    for(int k = len; k >= 1; k -- )
    {
        for(int i = 0; i < len; i ++ )
        {
            if(i + k <= len && check(s.substr(i, k)))
            {
                cout << k << endl;
                return 0;
            }
        }
    }

    return 0;
}