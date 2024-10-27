#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 10010;

int n, root, pre[N], depth, tail;
vector<int> g[N];
stack<int> res;

void dfs(int u, int d)
{
    if(d > depth)
    {
        depth = d;
        tail = u;
    }
    
    for(int i = 0; i < g[u].size(); i ++ )
        dfs(g[u][i], d + 1);
    
}

int main()
{
    memset(pre, -1, sizeof pre);
    cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int k;  cin >> k;
        while(k -- )
        {
            int x;  cin >> x;
            pre[x] = i;
            g[i].push_back(x);
        }
        sort(g[i].begin(), g[i].end());
    }
    
    for(int i = 0; i < n; i ++ )
        if(pre[i] == -1)
        {
            root = i;
            break;
        }
        
    depth = 1;
    dfs(root, 1);
    
    // cout << "tail: " << tail << endl;
    while(tail != -1)
    {
        res.push(tail);
        tail = pre[tail];
    }
    
    bool flag = false;
    cout << res.size() << endl;
    while(res.size())
    {
        if(flag) cout << " ";
        else flag = true;
        cout << res.top();
        res.pop();
    }
    return 0;
}