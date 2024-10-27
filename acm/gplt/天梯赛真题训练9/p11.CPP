#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int N = 40;

int pre[N], mid[N], n;
vector<int> v;
typedef struct tree{
    int val;
    struct tree *left, *right;
}*Tree, TreeNode;

Tree build(int pre[], int mid[], int size)
{
    if(size <= 0)    return NULL;
    
    Tree p = new TreeNode;
    int root = pre[0], k;
    for(int i = 0; i < size; i ++ )
        if(mid[i] == root)
        {
            k = i;
            break;
        }
    p->val = root;
    p->left = build(pre + 1, mid, k);
    p->right = build(pre + 1 + k, mid + 1 + k, size - k - 1);
    
    return p;
}

void swapTree(Tree &t)
{
    if(t == NULL)   return ;
    
    Tree p = t->right;
    t->right = t->left;
    t->left = p;
    swapTree(t->left);
    swapTree(t->right);
}

void levelPrint(Tree &t)
{
    if(t == NULL)   return ;
    queue<Tree> q;
    q.push(t);
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        v.push_back(t->val);
        if(t->left) q.push(t->left);
        if(t->right)    q.push(t->right);
    }
    for(int i = 0; i < n; i ++ )
    {
        cout << v[i];
        if(i != n - 1)  cout << ' ';
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    cin >> mid[i];
    for(int j = 0; j < n; j ++ )    cin >> pre[j];
    
    Tree t = build(pre, mid, n);
    swapTree(t);
    levelPrint(t);
    
    
    return 0;
}