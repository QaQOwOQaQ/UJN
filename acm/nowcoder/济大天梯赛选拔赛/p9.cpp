#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if(s.size() == 6)
        cout << s.substr(0, 4) << "-" << s.substr(4, 2);
    else
    {
        int year = (s[0] - '0') * 10 + s[1] - '0'; 
        if(year < 22)   cout << "20" << s.substr(0, 2) << "-" << s.substr(2, 2);
        else    cout << "19" << s.substr(0, 2) << "-" << s.substr(2, 2);
    }
    
    
    return 0;
}