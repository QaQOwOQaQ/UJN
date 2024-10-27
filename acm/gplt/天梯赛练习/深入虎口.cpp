#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> v[N];
int n, k, pre[N];
int res, depth;

void dfs(int c, int u)
{
    if(u > depth)
    {
        depth = u;
        res = c;
    }
    for(int i = 0; i < v[c].size(); i ++ )
        dfs(v[c][i], u + 1);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= N; i ++ )   pre[i] = -1;
    for(int i = 1; i <= n; i ++ )
    {
        cin >> k;
        while(k -- )
        {
            int x;  cin >> x;
            v[i].push_back(x);
            pre[x] = i;
        }
    }
    
    int root = 1;
    while(pre[root] != -1)   root ++ ;
    
    dfs(root, 1);
    
    cout << res << endl;
    
    
    return 0;
}