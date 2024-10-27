#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 23;

int n, k, res;
int a[N];
bool st[N];

bool check(int x)
{
    if(x < 2)   return false;
    for(int i = 2; i <= x / i; i ++ )
        if(x % i == 0)  return false;
    return true;
}

// start 保证有序，避免答案重复
void dfs(int u, int start, int sum)
{
    if(u == k)  
    {
        if(check(sum))  res ++ ;
        return ;
    }
    for(int i = start; i <= n; i ++ )
    {
        if(!st[i])
        {
            st[i] = true;
            dfs(u + 1, i + 1, sum + a[i]);
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i ++ )   cin >> a[i];
    dfs(0, 1, 0);
    cout << res << endl;
    return 0;
}