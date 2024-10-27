#include <iostream>
#include <cstring>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <vector>

using namespace std;

const int N = 110;

int pre[N], mid[N], n;
typedef struct tree{
    int num;
    struct tree *left, *right;
}TreeNode, *Tree;

Tree build(int pre[], int mid[], int size)
{
    int k, root;
    if(size <= 0)   return NULL;
    Tree t = new TreeNode;
    root = pre[0];
    t->num = root;
    
    for(int i = 0; i < size; i ++ )
    {
        if(mid[i] == root)
        {
            k = i;
            break;
        }
    }
    
	t->left = build(pre + 1, mid, k);//递归左右子树
	t->right = build(pre + k + 1, mid + k + 1, size - k - 1);
	return t;
}

void swapTree(Tree &t)
{
    if(t == NULL)   return ;
    
    Tree p = t->left;
    t->left = t->right;
    t->right = p;
    // swap(t->left, t->right);
    swapTree(t->left);
    swapTree(t->right);
}

void out(Tree &t, vector<int> &res)
{
    if(t == NULL)   return ;
    queue<Tree> q;
    q.push(t);
    while(q.size())
    {
        Tree s = q.front();
        q.pop();
        res.push_back(s->num);
        if(s->left) q.push(s->left);
        if(s->right)    q.push(s->right);
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++ )    cin >> mid[i];
    for(int i = 0; i < n; i ++ )    cin >> pre[i];
    Tree t = build(pre, mid, n);
    swapTree(t);
    vector<int> res;
    out(t, res);
    for(int i = 0; i < res.size(); i ++ )
    {
        cout << res[i];
        if(i != res.size() - 1) cout << " ";
    }
    return 0;
}