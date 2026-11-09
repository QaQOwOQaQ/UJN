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
void Create(Tree &t); 
void InOderTraverse(Tree &t);
Tree Search(Tree t, int key);
void Insert(Tree &t, int key);
bool Delete(Tree &p);
bool DeleteBST(Tree &T, int key);

//实现 
void InOderTraverse(Tree &t)   //中序递归遍历二叉树
{
	if(t != NULL)
	{
		InOderTraverse(t->left);
		printf("%d ", t->val);
		InOderTraverse(t->right);
	}
}

Tree Search(Tree t, int key)	//递归查找 
{
	if(t == NULL)	return NULL;
	if(key == t->val)	return t;
	else if(key < t->val)	return Search(t->left, key);
	else Search(t->right, key); 
}

void Insert(Tree &t, int key)
{
	//如果树为空直接插入 
	if(t == NULL)
	{
		Tree newNode = new TreeNode;
		newNode->val = key;
		newNode->left = newNode->right = NULL;
		t = newNode;
	}
	
	//查找插入位置 
	else if(key < t->val)	
		Insert(t->left, key);
	else	
		Insert(t->right, key);
		
}

void Create(Tree &t)	//创建 -- 不断插入的过程 
{
	t = NULL;	//初始化树为空, 必须要有, 对应插入操作的直接插入这一种情况 
	int cnt;
	cout << "请输入节点个数: ";
	cin >> cnt;
	for(int i = 0; i < cnt; i ++ )
	{
		int val;
		cin >> val;
		Insert(t, val);
	}
}

Tree find_Father(Tree t, int key)	//查找父节点 
{
	Tree cur = t;
	while(cur != NULL && cur->val != key)
	{
		if(key > cur->val)	cur = cur->right;
		else	cur = cur->left;
	}
	if(cur == NULL)	return NULL;
	return cur;
}

bool Delete(Tree &p)	//删除该节点 
{
	/* 从二叉排序树中删除节点p， 并重接它的左或右子树 */
	Tree q, s; /* q是辅助指针，s指向直接前驱 */
	if( !p->left && !p->right )	/* p为叶子节点 */
		p = NULL;
	else if( !p->left )	/* 左子树为空，重接右子树 */
	{
		q = p;	
		p = p->right;
		free(q);
	}
	else if( !p->right )	/* 右子树为空，重接左子树 */
	{
		q = p;
		p = p->left;		
		free(q);
	}
	else						/* 左右子树均不为空 */
	{
		q = p;
		s = p->left;
		while(s->right)		/* 转左，然后向右走到尽头 */
		{
			q = s;
			s = s->right;
		}
		p->val = s->val;
		if( q != p )				/* 判断是否执行上述while循环 */
			q->right = s->left;	/* 执行上述while循环，重接右子树 */	
		else
			q->left = s->left;	/* 未执行上述while循环，重接左子树 */
		free(s);
	}
	return true;
}
 
bool DeleteBST(Tree &T, int key)	//找到要删除的节点 
{
	/* 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素节点 */
	/* 并返回TRUE；否则返回FALSE */
	if( T == NULL)
	{
		cout << "要删除节点不存在" << endl;
		return false;	/* 不存在关键字等于key的数据元素 */	
	}
	
	else
	{
		if( key == T->val )
			Delete(T);
		else if( key < T->val)
			return DeleteBST(T->left, key);
		else
			return DeleteBST(T->right, key);
	}
	return true;
}


int main()
{
	Tree t;
	Create(t);
	InOderTraverse(t);
	cout << endl;
	//
	DeleteBST(t, 30 );
	InOderTraverse(t);
	return 0;
}

