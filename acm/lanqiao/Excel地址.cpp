#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int x;
    while(cin >> x)
    {
        vector<int> v;
        string s;
        while(x)
        {
            int t = x % 26;
            if(!t)  t = 26;
            x -- ;
            x /= 26;
            v.push_back(t);
        }
        reverse(v.begin(), v.end());
        for(auto &x : v)
        {
            char ch = x + 'A' - 1;
            cout << ch;
        }
        cout << endl;
    }
    
    return 0;
}