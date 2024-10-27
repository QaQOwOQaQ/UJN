// Accept
// 优化：dfs里传递vector太多copy了
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct tree_t {
    int val;
    tree_t *left, *right;
    tree_t(int _val) : val(_val), left(nullptr), right(nullptr) {}
    tree_t() : tree_t(0) {}
} Tree;

void bfs(Tree *t, int n)
{
    int idx = 0;
    queue<Tree*> q;
    q.push(t);
    while(q.size())
    {
        int m = q.size();
        for(int i = 0; i < m; i ++ )
        {
            auto t = q.front(); q.pop();
            //行首尾不得有多余空格。
            if( ++ idx == n)    cout << t->val << endl;
            else    cout << t->val << ' ';
            if(t->left) q.push(t->left);
            if(t->right)    q.push(t->right);
        }
    }
}

void do_reserve(Tree *&t)
{
    queue<Tree*> q;
    q.push(t);
    while(q.size())
    {
        int n = q.size();
        for(int i = 0; i < n; i ++ )
        {
            auto t = q.front(); q.pop();
            swap(t->left, t->right);
            if(t->left) q.push(t->left);
            if(t->right)    q.push(t->right);
        }
    }
}

// 键值都是互不相等的正整数。
Tree* dfs(vector<int> &pre, vector<int> &mid)
{
    if(pre.size() == 0) return nullptr;
    
    int n = pre.size();
    int pos = find(mid.begin(), mid.end(), pre[0]) - mid.begin();
    Tree *root = new Tree(pre[0]);
    
    // mid
    vector<int> v2(mid.begin(), mid.begin() + pos);
    vector<int> v4(mid.begin() + pos + 1, mid.end());
    // pre
    vector<int> v1(pre.begin() + 1, pre.begin() + 1 + pos);
    vector<int> v3(pre.begin() + 1 + pos, pre.end());

    root->left = dfs(v1, v2);
    root->right = dfs(v3, v4);
    return root;
}

int main()
{
    Tree *t;
    int n;
    
    cin >> n;
    vector<int> pre(n), mid(n);    
    for(int i = 0; i < n; i ++ )    cin >> mid[i];
    for(int i = 0; i < n; i ++ )    cin >> pre[i];
    

    t = dfs(pre, mid);
    do_reserve(t);
    bfs(t, n);
    
    return 0;
}