//write approach 1
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

multiset<string> up;
multiset<string> down;

int main()
{
    string s, t = "";   int len;
    cin >> s;
    s += "*";
    bool flag = true;
    len = s.size();
    for(int i = 0; i < len; i ++ )
    {
        if(s[i] == '*' || s[i] == '/')
        {
            if(flag)    up.insert(t);
            else    //flag = false;
            {
                if(up.count(t)) up.erase(t);
                else    down.insert(t);
            }
            if(s[i] == '*') flag = true;
            else flag = false;
            t = "";
        }
        else t += s[i];
    }
    
    int n = up.size(), cnt = 0;
    for(auto &x : up)
    {
        cout << x;
        if(cnt != n - 1)    cout << "*";
        cnt ++ ;
    }
    if(!n)  cout << 1;
    cout << endl;
    
    n = down.size(), cnt = 0;
    for(auto &x : down)
    {
        cout << x;
        if(cnt != n - 1)    cout << "*";
        cnt ++ ;
    }
    if(!n)  cout << 1;
    return 0;
}



/*write approach 2
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

multiset<string> up;
multiset<string> down;

int main()
{
    string s, t = "";   int len;
    cin >> s;
    s = s + "*";
    bool flag = true;
    bool is_first = true;
    len = s.size();
    for(int i = 0, j = 0; i < len; i ++, j ++ )
    {
        if(s[i] == '*' || s[i] == '/')
        {
            if(is_first)    
            {
                t = s.substr(i - j, j);
                is_first = false;
            }
            else    t = s.substr(i - j + 1, j - 1);
            if(flag)    up.insert(t);
            else    //flag = false;
            {
                if(up.count(t)) up.erase(t);
                else    down.insert(t);
            }
            if(s[i] == '*') flag = true;
            else flag = false;
            j = 0;
        }
    }
    
    int n = up.size(), cnt = 0;
    for(auto &x : up)
    {
        cout << x;
        if(cnt != n - 1)    cout << "*";
        cnt ++ ;
    }
    if(!n)  cout << 1;
    cout << endl;
    
    n = down.size(), cnt = 0;
    for(auto &x : down)
    {
        cout << x;
        if(cnt != n - 1)    cout << "*";
        cnt ++ ;
    }
    if(!n)  cout << 1;
    return 0;
}
*/