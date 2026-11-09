#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

typedef struct tree
{
	int date;
	struct tree *left, *right;	
}*Tree, TreeNode;

typedef struct element
{
	Tree ptr;
	bool is_first;
}*Ele, EleNode;

bool has_father;

void create(Tree &t)
{
	int date;
	cin >> date;
	if(date == -1)	t = NULL;
	else	//必须加else 
	{
		t = new TreeNode;	//创建树的时候要开空间 
		t->date = date;
		create(t->left);
		create(t->right);
	}
}

void DGprePrint(Tree t)
{
	if(t == NULL)	return;
	
	cout << t->date << " ";
	DGprePrint(t->left);
	DGprePrint(t->right);
}

void prePrint(Tree t)
{
	if(t == NULL)	return ;
	
	stack<Tree> s;
	Tree p = t;
	while(p || s.size())
	{
		while(p)
		{
			cout << p->date << " ";
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
}

void midPrint(Tree t)
{
	if(t == NULL)	return ;
	
	stack<Tree> s;
	Tree p = t;
	while(p || s.size())
	{
		while(p)
		{
			s.push(p);
			p = p->left;
		}
		if(s.size())
		{
			p = s.top();
			s.pop();
			cout << p->date << " ";
			p = p->right;
		}
	}
}

void lastPrint(Tree t)
{
	if(t == NULL)	return ;
	
	stack<EleNode> s;
	Tree p = t;
	EleNode e;
	while(p || s.size())
	{
		while(p)
		{
			e.ptr = p;
			e.is_first = true;
			s.push(e);	
			p = p->left;
		}	
		if(s.size())
		{
			e = s.top();
			s.pop();
			p = e.ptr;
			if(e.is_first)
			{
				e.is_first = false;
				s.push(e);
				p = p->right;
			}
			else
			{
				cout << p->date << " ";
				p = NULL;
			}
		}
	} 
	
}

void levelPrint(Tree t)
{
	if(t == NULL)	return ;
	
	queue<Tree> q;
	q.push(t);
	while(q.size())
	{
		t = q.front();
		q.pop();
		cout << t->date << " ";
		if(t->left)  q.push(t->left);
		if(t->right) q.push(t->right);
	}
}

void DGswapTree(Tree t)
{
	if(t == NULL)	return ;
	
	DGswapTree(t->left);
	DGswapTree(t->right);
	
	Tree tmp = t->right;
	t->right = t->left;
	t->left = tmp;	
}

void swapTree(Tree t)
{
	if(t == NULL)	return ;	
	queue<Tree> q;
	q.push(t);
	while(q.size())
	{
		t = q.front();
		q.pop();
		Tree tmp = t->right;
		t->right = t->left;
		t->left = tmp;
		if(t->left)	 q.push(t->left);	//对于非递归操作在添加节点的时候一定要判断是否为空 
		if(t->right) q.push(t->right); 	
	}
}

void findFather(Tree t, int u)
{
	if(t == NULL)	return ;
	
	if(t->left && t->left->date == u)
	{
		cout << "My Father is: " << t->date << endl;
		has_father = true;	
	} 
	if(t->right && t->right->date == u)
	{
		cout << "My Father is: " << t->date << endl;
		has_father = true;	
	} 
	
	if(t->left)		findFather(t->left, u);
	if(t->right)	findFather(t->right, u); 
}

void Find_Father(Tree t)
{
	int child;
	cout << "请输入你要查找的节点的编号" << endl;
	cin >> child; 
	has_father = false;
	findFather(t, child);
	if(!has_father)	cout << "No Father or NULL" << endl;;
}

int nodeNum(Tree t)
{
	if(t == NULL)	return 0;
	
	int lnum = 0, rnum = 0;
	lnum = nodeNum(t->left);
	rnum = nodeNum(t->right);
	return lnum + rnum + 1;
}

int leafNum(Tree t)
{
	if(t == NULL)	return 0;

	int lnum = 0, rnum = 0;
	lnum = leafNum(t->left);
	rnum = leafNum(t->right);
	if(t->left == NULL && t->right == NULL)	return 1;
	return lnum + rnum;
}

int doubleChild(Tree t)
{
	if(t == NULL)	return 0;
	
	int lnum = 0, rnum = 0;
	lnum = doubleChild(t->left);
	rnum = doubleChild(t->right);
	if(t->left && t->right)	return lnum + rnum + 1;
	return 0;
}

bool isComplete(Tree t)
{
	if(t == NULL)	return false;
	
	queue<Tree> q;
	q.push(t);
	while(q.size())
	{
		t = q.front();
		q.pop();
		if(t->left && t->right)
		{
			q.push(t->left);
			q.push(t->right);
		}
		if(t->left == NULL && t->right)	return false;
		if(t->right == NULL)
		{
			if(t->left)	q.push(t->left);
			while(q.size())
			{
				t = q.front();
				if(t->left == NULL && t->right == NULL)	q.pop();
				else	return false;
			}
			return true;
		}
	}
	return true;
}

void pathPrint(Tree t, vector<int> path)
{
	if(t == NULL)	return ;
	
	path.push_back(t->date);	
	if(t->left == NULL && t->right == NULL)
	{
		for(auto &x : path)	cout << x << " ";
		cout << endl;
		return ;
	}
	pathPrint(t->left, path);
	pathPrint(t->right, path);
}

/*测试样例 
1、普通树： 
1 2 4 -1 -1 -1 3 5 7 
-1 -1 8 -1 -1 6 -1 -1
先序：1 2 4 3 5 7 8 6
中序：4 2 1 7 5 8 3 6 
后序：4 2 7 8 5 6 3 1

2、完全二叉树：
1 2 4 -1 -1 5 -1 
-1 3 6 -1 -1 -1
*/

int main()
{
	Tree t;
	create(t);
	
//	prePrint(t);    cout << endl;
//	midPrint(t);	cout << endl;
//	lastPrint(t);   cout << endl;
//	levelPrint(t);   cout << endl;

//	swapTree(t);	 
//	levelPrint(t);   cout << endl;	

//	Find_Father(t); 

//	cout << leafNum(t) << endl;
//	cout << nodeNum(t) << endl;
//	cout << doubleChild(t) << endl;
	
//	cout << isComplete(t) << endl;
	
	vector<int> path;
	pathPrint(t, path);	cout << endl;
	
	return 0;
}
