// 04
#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int N = 10010;

int n, m, maxn, x;
stack<char> s[N];
vector<char> res;
stack<char> heap;

int main()
{
    cin >> n >> m >> maxn;
    for(int i = 1; i <= n; i ++ )
    {
        string str; cin >> str;
        for(int j = str.size() - 1; j >= 0; j -- )
            s[i].push(str[j]);
    }
    
    while(cin >> x)
    {
        if(x == -1) break;
        
        if(x == 0)
        {
            if(heap.size()) res.push_back(heap.top()), heap.pop();
        }
        else
        {
            if(s[x].size()) 
            {
                if(heap.size() == maxn)  res.push_back(heap.top()), heap.pop();
                heap.push(s[x].top()), s[x].pop();
            }
        }
        
    }
    
    
    for(auto &x : res)  cout << x;
    
    return 0;
}