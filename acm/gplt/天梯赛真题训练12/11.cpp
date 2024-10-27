#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 100010;

int n, w[N], m;
typedef struct tree{
    int val;
    struct tree *left, *right;
}*Tree, TreeNode;

void Build(Tree &t, int u, int x)
{
    if(u > m)   return ;
    t->val = x;
    t = new TreeNode;
    Build(t->left, u * 2, x);
    Build(t->right, u * 2 + 1, x);
}

void prePrint(Tree t)
{
    if(t == NULL)   return ;
    cout << t->val << " ";
    prePrint(t->left);
    prePrint(t->right);
}

void levelPrint(Tree t)
{
    vector<int> res;
    if(t == NULL)   return ;
    queue<Tree> q;
    q.push(t);
    while(q.size())
    {
        auto s = q.front();
        q.pop();
        res.push_back(s->val);
        if(s->left) q.push(s->left);
        if(s->right)    q.push(s->right);
    }
    
    cout << "levelPrint: " << endl; 
    int len = res.size();
    for(int i = 0; i < len; i ++ )   
    {
        cout << res[i];
        if(i != len - 1) cout << ' ';
    }
    cout << endl;
}

int main()
{
    cin >> n;
    m = n;
    Tree t = NULL;
    
    for(int i = 1; i <= n; i ++ )   
    {
        int x;
        cin >> x;
        Build(t, 1, x);
    }
    
    prePrint(t);
    // levelPrint(t);
    
    return 0;
}