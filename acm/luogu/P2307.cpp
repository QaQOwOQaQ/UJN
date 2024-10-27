// 边双向连通
// 小希希望任意两个房间有且仅有一条路径可以相通
// 除非走了回头路
// 思路：满足题目要求的图一定是一棵树（任意两个点最多只有一条路径
// 注意不能是森林（要求必须有一条路径
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 100010;

int root;
bool st[N];
vector<int> h[N];
bool has_res;

void add(int a, int b)
{
    h[a].push_back(b);
    h[b].push_back(a);
}

// Tree的遍历
void dfs(int u, int fa)
{
    if(st[u])   has_res = false;
    if(!has_res)    return ;
    st[u] = true;
    for(auto &ne : h[u])
        if(ne != fa)
            dfs(ne, u);
}

int main()
{
    int a, b;
    while(cin >> a >> b, a != -1 || b != -1)
    {
        root = a;
        has_res = true;
        unordered_set<int> ass;
        memset(st, false, sizeof st);
        for(int i = 0; i < N; i ++ )   h[i].clear();

        add(a, b);
        ass.insert(a), ass.insert(b);
        while(cin >> a >> b, a || b)
        {
            ass.insert(a), ass.insert(b);
            add(a, b);
        }
        
        // 先判断路径是否惟一
        dfs(root, -1);
        // 在判断是否存在路径
        for(auto &x : ass)
            if(has_res && !st[x])  has_res = false;
        cout << has_res << endl;
    }
    return 0;
}