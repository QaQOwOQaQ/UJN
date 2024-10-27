#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 11;

bool st[N];
int a[N];

void dfs(int u, int n)
{
    if(u == n)  
    {
        for(int i = 0; i < n; i ++ )    
            printf("%5d", a[i]);    // 卡格式,这里不要输出空格,恶心
        cout << endl;
    }
    for(int i = 1; i <= n; i ++ )
    {
        if(!st[i])
        {
            st[i] = true;
            a[u] = i;
            dfs(u + 1, n);
            st[i] = false;
        }
    }
}

int main()
{
    int n;  cin >> n;
    dfs(0, n);
    return 0;
}