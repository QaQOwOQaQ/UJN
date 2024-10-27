// 区间DP
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 1010, M = 110;

int n, m, k;
int w[M], idx;
int f[M][M];

/* 逆向考虑，直接从最终分离的结果考虑回溯考虑
相当于我们每次都要合并两个区间,送的肉的数量=两个区间大小之和
注意合并区间时,新区间大小=两个区间大小+1(放入新囚犯)
由于每次只能合并两个相邻区间,因此只能用区间DP而不能用Huffman_Tree
*/

int main()
{
    cin >> n >> m;
    int pre = 1;
    for(int i = 0; i < m; i ++ )
    {
        int cur;    cin >> cur;
        // [pre,cur-1]
        w[ ++ idx] = cur - pre;
        pre = cur + 1;
    }
    // [pre,n]
    if(pre != n)    w[ ++ idx] = n - pre + 1;
    // for(int i = 1; i <= idx; i ++ ) cout << w[i] << " \n"[i == idx];
    for(int i = 1; i <= idx; i ++ ) w[i] += w[i - 1];
    memset(f, 0x3f, sizeof f);
    for(int i = 0; i < M; i ++ )    f[i][i] = 0;
    for(int len = 2; len <= idx; len ++ )
    {
        for(int l = 1; l + len - 1 <= idx; l ++ )
        {
            int r = l + len - 1;
            for(int k = l; k + 1 <= r; k ++ )
            {
                // del_node考虑新放进去的囚犯
                int del_node = k - l + r - (k + 1);
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + w[r] - w[l - 1] + del_node);
            }
        }
    }
    // for(int i = 1; i <= idx; i ++ )
    //     for(int j = 1; j <= idx; j ++ )
    //         cout << f[i][j] << " \n"[j == idx];
    cout << f[1][idx] << endl;
    return 0;
}