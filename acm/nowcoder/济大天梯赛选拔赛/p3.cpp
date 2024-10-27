#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 10010;

int n, m, limit, q;
vector<char> res;
stack<char> st[N];
stack<char> mid;

int main()
{
    cin >> n >> m >> limit;
    for(int i = 1; i <= n; i ++ )
    {
        string s;   cin >> s;
        for(int j = s.size() - 1; j >= 0; j -- )    st[i].push(s[j]);
    }
    
    while(cin >> q)
    {
        if(q == -1) break;

        if(!q && mid.size())
        {
            res.push_back(mid.top());
            mid.pop();
        }
        else
        {
            if(st[q].empty())   continue;
            else
            {
                if(mid.size() == limit)
                {
                    res.push_back(mid.top());
                    mid.pop();
                }
                mid.push(st[q].top());
                st[q].pop();
            }
        }
    }
    
    // cout << res.size() << endl;
    for(auto &x : res)   cout << x;
    
    
    return 0;
}