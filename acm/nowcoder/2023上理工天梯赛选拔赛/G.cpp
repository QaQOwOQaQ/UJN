// 答案错误 + 运行超时
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e5 + 10;

unordered_map<int,int> ass;
int n, w[N];
int maxn;
long long res, sum;

void dfs(int u, int cur, int num)
{
    if(cur > maxn)  return ;
    if(u == 32)
    {
        // sum += ass[cur]; // wrong!
        // 不可以直接使用下标，否则会使main中ass的迭代器失效
        if(ass.count(cur)) sum += ass[cur];
        return ;
    }
    dfs(u + 1, cur, num);
    if(!(num >> u & 1)) 
        dfs(u + 1, cur + (1 << u), num);
}

void doTest()
{
    int test = 0;
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= n; j ++ )
            if((w[i] ^ w[j]) == w[i] + w[j])
            {
                // cout << w[i] << ' ' << w[j] << endl;
                test ++ ;
            }
    cout << test << endl;
}

int main()
{
    // ^ 是不进位的 +
    // 所以当 ^ 不进位时，^ == +
    // 否则 ^ != +
    cin >> n;
    for(int i = 1; i <= n; i ++ )  
    {
        cin >> w[i];
        maxn = max(maxn, w[i]);
        ass[w[i]] ++ ;
    }
    int res = 0;
    for(auto &x : ass)
    {
        sum = 0;
        dfs(0, 0, x.first);
        res += sum * x.second;
    }
    cout << res << endl;
    
    doTest();
    
    return 0;
}