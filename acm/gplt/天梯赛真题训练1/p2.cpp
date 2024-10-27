#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

string s, t;

int main()
{
    set<int> S;
    getline(cin, s);
    getline(cin, t);
    for(int i = 0; i < t.length(); i ++ )
    {
        int num = t[i];
        S.insert(num);
    }
    for(int i = 0; i < s.length(); i ++ )
    {
        int num = s[i];
        if(S.count(num))   continue;
        else    cout << s[i];
    }
    cout << endl;
    return 0;
}