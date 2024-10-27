#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
string res;

int main()
{
    cin >> n;
    getchar();
    while (n -- )
    {
        string s;
        getline(cin, s);
        // cout << s << endl;
        int pos = s.find('T');
        int add = pos - 2;
        res += to_string(s[add] - 'A' + 1);
    }
    cout << res << endl;
    return 0;
}