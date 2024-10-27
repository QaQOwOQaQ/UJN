#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n -- )
    {
        vector<string> v1, v2;
        bool flag = true;
        string s;
        while(cin >> s)
        {
            v1.push_back(s);  
            if(s[s.length() - 1] == ',')    
            {
                if(s.length() < 4 || s.substr(s.length() - 4, 4) != "ong,") flag = false;
                break;
            }
        }
        while(cin >> s)
        {
            v2.push_back(s);  
            if(s[s.length() - 1] == '.')    
            {
                if(s.length() < 4 || s.substr(s.length() - 4, 4) != "ong.") flag = false;
                break;
            }
        }
        if(!flag)   puts("Skipped");
        else
        {
            for(auto &x : v1)    cout  << x << " ";
            for(int i = 0; i < v2.size() - 3; i ++ ) cout << v2[i] << " ";
            cout << "qiao ben zhong.\n";
        }
    }
    
    return 0;
}