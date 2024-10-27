// 棋盘类状压DP
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector> 

using namespace std;

const int N = 8, M = 1 << N;

int n, m, res;
int w[N][N];
int f[N][M];    //f[i][j]枚举到第i行,第i行状态为j的方案数

vector<int> valid_line;
vector<int> valid_transfer[M];

// 预处理单行和行与行之间的合法转移
void init_valid_state()
{
    for(int i = 0; i < M; i ++ )
        if(!(i & (i << 1)))    
            valid_line.push_back(i);
        
    for(auto &st : valid_line)
        for(int j = 0; j < M; j ++ )
            if(!(st & j) && !(st & (j >> 1)) && !(st & (j << 1)))
                valid_transfer[st].push_back(j);
}

void init_and_input()
{
    memset(f, 0, sizeof f);
    memset(w, 0, sizeof w);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
        for(int j = 0; j < m; j ++ ) cin >> w[i][j];
}

int dp()
{
    // 因为需要用到上一行，i从1开始，避免下标0-1=-1的问题
    // 因为需要枚举二进制，因此j从0开始方便我们枚举
    int res = 0;
    for(int i = 1; i <= n; i ++ )   
    {
        for(int j = 0; j < 1 << m; j ++ )
        {
            // add:第i行状态为j时的价值
            int add = 0;
            for(int k = 0; k < m; k ++ )
                if(j >> k & 1)
                    add += w[i][k];
            // 枚举上一行可行的状态        
            for(auto &st : valid_transfer[j])
                f[i][j] = max(f[i][j], f[i - 1][st] + add);
            res = max(res, f[i][j]);
        }
    }
    return res;
}

int main()
{
    init_valid_state();
    int T;  cin >> T;
    while(T -- )
    {
        init_and_input();
        int res = dp();
        cout << res << endl;
    }
    return 0;
}