#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

stack<int> stk;
multiset<int> up, down;

void adjust()
{
    while(up.size() > down.size())
    {
        down.insert(*up.begin());
        up.erase(up.begin());
    }
    
    while(down.size() > up.size() + 1)
    {
        auto it = down.end();
        it -- ;
        up.insert(*it);
        down.erase(it);
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    while (n -- )
    {
        string s;   cin >> s;
        if(s == "Push")
        {
            int x;  cin >> x;
            stk.push(x);
            if(up.empty() || x < *up.begin())   down.insert(x);
            else    up.insert(x);
        }
        else if(s == "Pop")
        {
            if(stk.empty()) cout << "Invalid" << endl;
            else
            {
                int x = stk.top();
                stk.pop();
                cout << x << endl;
                auto it = down.end();
                it -- ;
                if(x <= *it) down.erase(down.find(x));
                else    up.erase(up.find(x));
            }
        }
        else
        {
            if(stk.empty()) cout << "Invalid" << endl;
            else
            {
                auto it = down.end();
                it -- ;
                cout << *it << endl;
            }
        }
        adjust();
    }
    
    return 0;
}