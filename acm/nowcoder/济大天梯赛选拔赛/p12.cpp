#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

int n, m, st[N];
vector<int> g[N];
vector<int> res;

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
    {
        int k;  cin >> k;
        g[i].push_back(0);//xiabiao cong 1 kaishi
        while(k -- )
        {
            int x;  cin >> x;
            g[i].push_back(x);
        }
    }
    
    int now = 1;
    while(m -- )
    {
        int op, ver; 
        cin >> op >> ver;
        if(op == 0) now = g[now][ver];
        
        else if(op == 1)
        {
            res.push_back(now);
            st[ver] = now; 
        }
        else if(op == 2)    now = st[ver];
    }
    
    res.push_back(now);
    for(auto &x : res)  cout << x << endl;
    
    return 0;
}