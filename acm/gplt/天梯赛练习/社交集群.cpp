#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 1010;

int st[N], n, k, cnt;
int pre[N], num[N];

void init()
{
    for(int i = 0; i < N; i ++ )
    {
        num[i] = 1;
        pre[i] = i;
    }
}

int find(int x)
{
    if(pre[x] == x) return x;
    else    return pre[x] = find(pre[x]);
}

void join(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx != fy)    
    {
        pre[fx] = fy;
        num[fy] += num[fx];
    }
}

int main()
{
    init();
    cin >> n;
    
    cnt = n;
    for(int i = 1; i <= n; i ++ )
    {
        scanf("%d: ", &k);
        for(int j = 0; j < k; j ++ )
        {
            int x;  cin >> x;
            if(!st[x])  st[x] = i;
            else    //团体
            {
                join(i, st[x]);
                cnt -- ;
            }
        }
    }
    
    cout << cnt << endl;
    vector<int> res;
    for(int i = 1; i <= n; i ++ )
        if(find(i) == i)    res.push_back(num[i]);
    
    sort(res.begin(), res.end(), greater<int>() );
    for(int i = 0; i < res.size(); i ++ )
    {
        cout << res[i];
        if(i != res.size() - 1) cout << " ";
    }
    
    return 0;
}