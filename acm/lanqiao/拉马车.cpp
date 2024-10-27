/*
双端队列！
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <set>
#include <queue>

#define int long long
#define debug(val) \
    cout << #val << " = " << val << endl;

using namespace std;

signed main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        stack<char> t;
        deque<char> a, b;
        int cnt = 0;
        set<char> s;
        bool flag = true;//true->A
        bool has_answer = true;
        
        for(int i = 0; i < s1.length(); i ++ )
            a.push_back(s1[i]);
        for(int i = 0; i < s2.length(); i ++ )
            b.push_back(s2[i]);
            
        while(a.size() && b.size())    
        {
            if(cnt > 10000)
            {
                has_answer = false;
                break;
            }
            if(flag)//a
            {
                auto c = a.front();
                if(!s.count(c)) //Not in set
                {
                    a.pop_front();
                    s.insert(c);
                    t.push(c);
                    flag = false;
                }
                else
                {
                    a.pop_front();
                    a.push_back(c);
                    while(s.count(c))//eat
                    {
                        auto cc = t.top();
                        t.pop();
                        // debug(cc);
                        s.erase(cc);
                        a.push_back(cc);
                    }
                    // break;
                }
            }
            else
            {
                auto c = b.front();
                if(!s.count(c))
                {
                    b.pop_front();
                    t.push(c);
                    s.insert(c);
                    flag = true;
                }
                else
                {
                    b.pop_front();
                    b.push_back(c);
                    while(s.count(c))
                    {
                        auto cc = t.top();
                        t.pop();
                        // debug(cc);
                        b.push_back(cc);
                        s.erase(cc);
                    }
                    // cout << "bwin" << endl;
                    // break;
                }
            }
            cnt ++ ;
        }
        if(!has_answer) cout << -1;
        else
        {
            // debug(cnt);
            for(auto &x : a)    cout << x;
            // cout << endl;
            
            for(auto &x : b)    cout << x;
            // cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}