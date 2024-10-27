/*模拟，得40分
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    string s;
    cin >> s;
    stack<int> res;
    int x = 0, n = s.size();
    
    int t = 0;
    bool flag = false, is_new = true;
    
    for(int i = 0; i < n; i ++ )
    {
        if(s[i] == 'x')
        {
            if(!res.size() || is_new) res.push(1);
            else
            {
                int maxn = res.top() + 1;
                res.pop();
                res.push(maxn);
            }
            is_new = false;
        }
        else if(s[i] == '(')    
        {
            is_new = true;
        }
        else if(s[i] == ')')
        {
            is_new = true;
            if(flag)// '|'
            {
                int x = res.top();    res.pop();
                int y = res.top();    res.pop();
                res.push(max(x, y));
                flag = false;
            }
            else
            {
                res.push(t);
                t = 0;
            }
        }
        else if(s[i] == '|')
        {
            is_new = true;
            if(flag)
            {
                int x = res.top();    res.pop();
                int y = res.top();    res.pop();
                res.push(max(x, y));
            }
            else flag = true;
        }
    }
    
    if(flag)
    {
        int x = res.top();    res.pop();
        int y = res.top();    res.pop();
        res.push(max(x, y));
    }
    
    if(res.size())
    {
        int sum = 0;
        while(res.size())
        {
            sum += res.top();
            // cout << "res.top: " << res.top() << endl;
            res.pop();
        }
        cout << sum << endl;
    }
    else cout << 0 << endl;
    
    return 0;
}
*/