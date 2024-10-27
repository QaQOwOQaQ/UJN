/*
 score:23
 测试点3,4段错误
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

#define int long long

using namespace std;

typedef pair<int, int> PII;

const int N = 10100;

int n, w[N], depth[N];
unordered_map<int, int> S;//记录树种的某个节点是否使用过
int max_depth;

void Insert(int v, int i, int p, int d)//插入的值,节点号,树中的节点,深度
{
    if(S[p] == 0) //该节点没有使用过
    {
        S[p] = v;
        depth[i] = d;
        max_depth = max(max_depth, d);
        return ;
    }
    else if(v > S[p]) Insert(v, i, p * 2 + 1, d + 1);
    else    Insert(v, i, p * 2, d + 1);
}

signed main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   cin >> w[i];
    
    for(int i = 1; i <= n; i ++ )
        Insert(w[i] + 1001, i, 1, 1);//+1001从1开始
    
    int cnt = 0;
    for(int i = 1; i <= n; i ++ )
        if(depth[i] == max_depth || depth[i] == max_depth - 1)
            cnt ++ ;
    
    // for(int i = 1; i <= n; i ++ )
    //     cout << depth[i] << ' ';
    // cout << endl;
    
    cout << cnt << endl;
    
    
    return 0;
}



/*Accpet
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int N = 1010;

int n, idx;
int w[N], l[N], r[N];
map<int, vector<int> > m;

void Insert(int &u, int v, int depth)
{
    if(u == 0)//如果节点的值为0
    {
       u = ++ idx;//二叉树的根节点下标为1
       w[idx] = v;
       m[depth].push_back(v);
       return ;
    }
    if(v > w[u])    Insert(r[u], v, depth + 1);
    else    Insert(l[u], v, depth + 1);
}

int main()
{
    cin >> n;
    
    int root = 0;// 传过去的是节点的值
    for(int i = 1; i <= n; i ++ )
    {
        int x;  cin >> x;
        Insert(root, x, 1);
    }
    
    int res = 0;
    if(n <= 1)  res = 1;
    else
    {
        res += m.rbegin()->second.size();
        m.erase(m.rbegin()->first);
        res += m.rbegin()->second.size();
    }
    cout << res << endl;
    
    return 0;
}


*/