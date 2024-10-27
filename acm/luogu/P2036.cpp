/*
总的酸度为每一种配料的酸度总乘积
总的苦度为每一种配料的苦度的总和
以使得酸度和苦度的绝对差最小
另外，我们必须添加至少一种配料，因为没有任何食物以水为配料的
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 11;

int n, res;
int suan[N];
int ku[N];  

// suan -> mul
// ku -> add
void dfs(int u, int cur_suan, int cur_ku, int cnt)
{
    // 注意下面不能写为 if(u == n && cnt) {}
    // 否则当u==n && !cnt 时，程序不会停止
    if(u == n)
    {
        if(cnt) res = min(res, abs(cur_suan - cur_ku));
        return ;
    }
    // 选
    dfs(u + 1, cur_suan * suan[u], cur_ku + ku[u], cnt + 1);
    // 不选
    dfs(u + 1, cur_suan, cur_ku, cnt);
}

int main()
{
    cin >> n;
    // while(cin >> n)
    {
        res = 2e9;
        for(int i = 0; i < n; i ++ )   cin >> suan[i] >> ku[i];
        dfs(0, 1, 0, 0);
        cout << res << endl;
    }
    return 0;
}