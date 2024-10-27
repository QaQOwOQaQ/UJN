#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    int n;  cin >> n;
    getchar();
    
    string res("");
    unordered_map<char,string> mp = {
        {'A', "1"},
        {'B', "2"},
        {'C', "3"},
        {'D', "4"}
    };
    while (n -- )
    {
        string s;
        getline(cin, s);
        if(s[2] == 'T')     res += mp[s[0]];
        if(s[6] == 'T')     res += mp[s[4]];
        if(s[10] == 'T')    res += mp[s[8]];
        if(s[14] == 'T')    res += mp[s[12]];
    }
    cout << res << endl;

    return 0;
}