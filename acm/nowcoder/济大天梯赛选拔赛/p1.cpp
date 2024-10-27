#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int a, b, n;
vector<int> res;

int main()
{
    cin >> a >> b >> n;
    res.push_back(a);
    res.push_back(b);
    for(int i = 0; i < n; i ++ )
    {
        int t = res[i] * res[i + 1];
        stack<int> st;
        if(!t)  res.push_back(0);
        else
        {
            while(t)
            {
                st.push(t % 10);
                t /= 10;
            }
            while(st.size())
            {
                res.push_back(st.top());
                st.pop();
            }
        }
    }
    for(int i = 0; i < n; i ++ )
    {
        cout << res[i];
        if(i != n - 1)  cout << " ";
    }
    
    return 0;
}