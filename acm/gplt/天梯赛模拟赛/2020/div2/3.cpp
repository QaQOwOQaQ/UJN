// 数组模拟二叉搜索树
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int root, l[N], r[N];
int w[N];
int depth[N], max_depth;

int main()
{
    cin >> n;
    
    cin >> w[1];
    root = 1;
    max_depth = 1;
    depth[1] = 1;
    
    for(int i = 2; i <= n; i ++ )
    {
        cin >> w[i];
        int u = 1, pre = 0, _depth = 1;
        while(u)
        {
            _depth ++ ;
            pre = u;
            if(w[i] <= w[u])    u = l[u];
            else u = r[u];
        }
        if(w[i] <= w[pre])  l[pre] = i;
        else    r[pre] = i;
        depth[i] = _depth;
        max_depth = max(max_depth, _depth);
    }
    
    int res = 0;
    for(int i = 1; i <= n; i ++ )
        if(depth[i] == max_depth || depth[i] == max_depth - 1)
            res ++ ;
    cout << res << endl;
    return 0;
}