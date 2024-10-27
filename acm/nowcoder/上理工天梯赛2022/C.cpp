/*
细节：一个物品可能多次出现
预处理即可
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

bool check(char ch)
{
    if(ch >= '0' && ch <= '9')  return true;
    return false;
}

map<string, int> m;

int main()
{
    string s;   
    getline(cin, s);
    s += "a";
    int len = s.length();
    
    string t = "";
    int num = 0;
    bool flag = true;
    for(int i = 0; i < len; i ++ )
    {
        if(!check(s[i])) //'a' or ' '
        {
            if(s[i] == ' ') continue;
            if(flag)//'a'
            {
                m[t] += num;
                t = "";
                num = 0;
                flag = false;
            }
            t += s[i];
        }
        else//'1'
        {
            flag = true;
            num = num * 10 + s[i] - '0';
        }
    }
    
   // for(auto &x : m)    cout << x.first << " " << x.second << endl;
    
    int n;  cin >> n;
    while(n -- )
    {
        string p;   cin >> p;
        cout << m[p] << endl;
    }
    return 0;
}