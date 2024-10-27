#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> v[N], path;
int last, depth, root;
int n, pre[N];

void dfs(int val, int u)
{
    if(u > depth)
    {
        depth = u;
        last = val;
    }
    for(int i = 0; i < v[val].size(); i ++ )
        dfs(v[val][i], u + 1);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    pre[i] = -1;
        
    for(int i = 0; i < n; i ++ )
    {
        int k;  cin >> k;
        for(int j = 0; j < k; j ++ )
        {
            int x;  cin >> x;
            pre[x] = i;
            v[i].push_back(x);
        }
        sort(v[i].begin(), v[i].end());
    }
    
    for(int i = 0; i < n; i ++ )
        if(pre[i] == -1)
        {
            root = i;   break;
        }
    
    dfs(root, 1);
    
    while(last != -1)
    {
        path.push_back(last);
        last = pre[last];
    }
    
    cout << depth << endl;
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i ++ )
    {
        cout << path[i];
        if(i != path.size() - 1)    cout << " ";
    }
    
    
    return 0;
}