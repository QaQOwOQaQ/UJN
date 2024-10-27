#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    int res = 0;
    cin >> s;
    int len = s.length();
    for(int i = 1; i < s.length(); i ++ )
    {
        string t1 = s.substr(0, i);
        string t2 = s.substr(i);
        int t = stoi(t1) + stoi(t2);
        res = max(t, res);
    }
    cout << res << endl;
    
    return 0;
}