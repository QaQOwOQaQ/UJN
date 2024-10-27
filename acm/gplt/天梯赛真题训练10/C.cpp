/*
注意题目没说诗的上下两句是等长度的！
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    while(n -- )
    {
        vector<string> v1, v2;
        bool f1 = true, f2 = true;
        while(cin >> s)
        {
            v1.push_back(s);
            if(s[s.length() - 1] == ',')   
            {
                if(s.size() < 4 || s.substr(s.length() - 4) != "ong,")  f1 = false;
                break;
            }
        }
        while(cin >> s)
        {
            v2.push_back(s);
            if(s[s.length() - 1] == '.')   
            {
                if(s.size() < 4 || s.substr(s.length() - 4) != "ong.")  f2 = false;
                break;
            }
        }
        if(!f1 || !f2)  cout << "Skipped" << endl;
        else
        {
            for(auto &x : v1)   cout << x << " ";
            for(int i = 0; i < v2.size() - 3; i ++ )    cout << v2[i] << " ";
            cout << "qiao ben zhong." << endl;
        }
    }
    return 0;
}