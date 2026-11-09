#include <iostream>
#include <algorithm> 
#include <cstring>

using namespace std;

typedef struct tree
{
	int val;
	struct tree *left, *right;
}*Tree, TreeNode;


//声明 
void Create(Tree &t, int key);
void Insert(Tree &t, int key);
bool Delete(Tree &t, int key);
bool DeleteNode(Tree &t);
void Print(Tree &t, int key);
Tree Query(Tree t, int key);

void Create(Tree &t)
{
	t = NULL;
	int cnt, val;
	cout << "请输入节点数:";
	cin >> cnt;
	for(int i = 0; i < cnt; i ++ )
	{
		cin >> val;
		Insert(t, val);
	}
}

void Print(Tree t)
{
	if(t == NULL)	return ;
	Print(t->left);
	cout << t->val << " ";
	Print(t->right);	
} 

void Insert(Tree &t, int key)
{
	if(t == NULL)
	{
		Tree newNode = new TreeNode;
		newNode->val = key;
		newNode->left = newNode->right = NULL;
		t = newNode;
	}
	else if(key < t->val)	Insert(t->left, key);
	else	Insert(t->right, key);
}

Tree Query(Tree t, int key)
{
	if(t == NULL)	return NULL;
	if(key == t->val)	return t;
	else if(key < t->val)	return Query(t->left, key);
	else	return Query(t->right, key);
}

bool Delete(Tree &t, int key)
{
	if(t == NULL)
	{
		cout << "要删除节点不存在" << endl;
		return false;
	}
	else
	{
		if(key == t->val) DeleteNode(t);
		else if(key < t->val)	return Delete(t->left, key);
		else return Delete(t->right, key); 
	}
	return true;
}

bool DeleteNode(Tree &p)
{
	Tree q, s;	//q是辅助指针，s指向直接前驱 
	if(p->left == NULL && p->right == NULL)	
		p = NULL;
	else if(p->left == NULL)
	{
		q = p;
		p = p->right;
		free(q);
	}
	else if(p->right == NULL)
	{
		q = p;
		p = p->left;
		free(q);
	}
	else
	{
		q = p;
		s = p->left;
		while(s->right)
		{
			q = s;
			s = s->right;
		}
		p->val = s->val;
		if(p != q)
			q->right = s->left;
		else	
			q->left = s->left;
	}
	return true;
} 

int main()
{
	Tree t;
	Create(t);
	Print(t); cout << endl;
	Insert(t, 5);
	Print(t);	cout << endl;
	Delete(t, 9);
	Print(t);	cout << endl;
	return 0;
}
