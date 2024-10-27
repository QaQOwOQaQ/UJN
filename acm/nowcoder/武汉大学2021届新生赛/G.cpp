/*
    之前在ACwing上刷到过类似的题，那道题目更复杂一点，需要三个交换操作
    而这道题主只需要两个交换操作，pos和val
    Wrong了6发，哎，还是细节不到位，逻辑也不是那么清晰，逻辑Wrong了5发，细节Wrong了1发
    但总归是做出来了，起码说学到了东西！
    这道题目容易犯的一个细节错误就是找中间人那一步
    我们的中间人必须从我(me)的后面找
    不然，如果我们在me之前找到一个中间人并交换顺序
    那么我们之前拍好的顺序就被打乱了！
    其次就是一些逻辑问题了，几个swap我竟然都搞不清楚！但理清逻辑就很简单了！！！
*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define debug(a, b) \
    cout << a << " " << b << endl

using namespace std;

const int N = 2020;

int n, w[N];
int m, pos[N], g[N][N];
int idx;
pair<int, int> res[N];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    for(int i = 2; i <= n; i ++ )
        for(int j = i; j <= n; j ++ )
            if(gcd(i, j) == 1)
            {
                g[i][j] = 1;
                g[j][i] = 1;
            }
    
    
    for(int i = 2; i <= n; i ++ )   
    {
        cin >> w[i];
        pos[w[i]] = i;
    }
    
    for(int i = 2; i <= n; i ++ )
    {
        if(w[i] != i)
        {
            int occupy = w[i];//占领者val
            int pos_occupy = pos[w[i]];//占领者位置
            
            int me = i;//我的val
            int pos_me = pos[i];//我的位置
            
            if(g[occupy][me]) 
            {
                m ++ ;
                //
                // cout << "Two: " << me << " "  << occupy << endl;
                // cout << "Pos: " << pos_me << " " << pos_occupy << endl;
                //
                res[idx ++ ] = {pos_me - 1, pos_occupy - 1};
                swap(pos[occupy], pos[me]);                
                swap(w[pos_occupy], w[pos_me]);
                //
                // for(int i = 2; i <= n; i ++ )   cout << w[i] << " ";
                // cout << endl;
                //
            }
            else//需要中间人mid,中间人要在i的后面找,不能影响之前已经排好的顺序
            {
                for(int j = i + 1; j <= n; j ++ )
                {
                    if(g[me][j] && g[j][occupy])
                    {
                        int pos_mid = pos[j];//中间人的位置
                        int mid = j;//中间人val
                        //
                        // cout << "Three: " << me << " " << mid << " " << occupy << endl; 
                        //
                        m += 2;
                        //中间人与占用者互换
                        //中间人成为新的占用者,我与新的占用者互换
                        
                        res[idx ++ ] = {pos_occupy - 1, pos_mid - 1};
                        res[idx ++ ] = {pos_me - 1, pos_occupy - 1};
                        
                        w[pos_occupy] = me;
                        w[pos_me] = mid;
                        w[pos_mid] = occupy;
                        
                        pos[occupy] = pos_mid;
                        pos[me] = pos_occupy;
                        pos[mid] = pos_me;
                        
                        //
                        // for(int i = 2; i <= n; i ++ )   cout << w[i] << " ";
                        // cout << endl;
                        // for(int i = 2; i <= n; i ++ )   cout << pos[i] << " ";
                        // cout << endl;
                        //
                        break;
                    }
                }
            }
        }
        // cout << w[i] << endl;
    }
    
    cout << m << endl;
    for(int i = 0; i < idx; i ++ )
        debug(res[i].first, res[i].second);

    
    return 0;
}