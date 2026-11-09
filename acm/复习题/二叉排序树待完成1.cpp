#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct tree
{
	int val;
	struct tree *left, *right;
}Tree, TreeNode;

void Insert(Tree t, int key)
{
	if(t == NULL)
	{
		Tree newNode = new TrerNode;
		newNode->val = key;
		newNode->left = NULL;
		newNode->right = NULL;
	}
	else if(key < t->val)	
		Insert(t->left, key);
	else
		Insert(t->right, key);
}

Tree Search(Tree t, int key)
{
	if(t == NULL)	return false;
	if(key == t->val)	return t;
	else if(key < t->left)	return Search(t->left);
	else	return Search(t->rigtt);
}

void Delete(Tree t, int key)
{
	
}

bool query(Tree t, int key)
{
	if(t == NULL)
	{
		cout << "节点不存在" << endl; 
		return false;	
	}
	if(key == t->val)	
		Delete(t);
	else if(key < t->val)
		query(t->left, key)
	else
		query(t->right, key)	
		
	return true;
}

void create(Tree &t)
{
	int cnt;
	cout << "请输入你要构建的树的节点的个数: " << endl;
	cin >> cnt;
	for(int i = 0; i < cnt; i ++ )
	{
		cin >> x;
		insertNode(t, x);
	}
}

int main()
{
	Tree t;
	create(t);	
	
	return 0;
}
 
