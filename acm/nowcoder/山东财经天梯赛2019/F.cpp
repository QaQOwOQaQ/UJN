#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

#define int long long 

using namespace std;

int n, idx;
set<int> s;

signed main()
{
    //每次只能将更小的插入队列
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x;  cin >> x;
        if(!s.size()) s.insert(x);
        else
        {
            auto it = upper_bound(s.begin(), s.end(), x);
            if(it == s.end())   s.insert(x);
            else
            {
                s.erase(*it);
                s.insert(x);
            }
        }
    }
    cout << s.size() << endl;
    
    return 0;
}