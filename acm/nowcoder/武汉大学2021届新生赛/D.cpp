#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long

using namespace std;

int calc(int d)
{
    int depth = 1;
    while(d != 1)
    {
        d = (1 + d) >> 1;
        depth ++ ;
    }
    return depth;
}

int dfs(int l, int r, int id)
{
    if(l == r)  return id;
    
    int mid = l + r >> 1;
    int depth_left = calc(mid - l + 1);
    int depth_right = calc(r - (mid + 1) + 1);
    if(depth_left > depth_right)    
        return dfs(l, mid, id << 1);
    else    
        return dfs(mid + 1, r, id << 1 | 1);
}

signed main()
{
    int T, n;
    cin >> T;
    while(T -- )
    {
        int n;  cin >> n;
        cout << dfs(1, n, 1) << endl;
    }
    
    return 0;
}