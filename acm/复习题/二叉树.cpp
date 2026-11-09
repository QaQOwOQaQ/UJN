#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

typedef struct tree
{
	int date;
	struct tree *left,*right;
}*Tree,TreeNode;

typedef struct element
{
	Tree ptr;
	bool isfirst;
}*Element,ElementNode;

void createTree(Tree &t)	//后序遍历建立树 
{
	int c;
	cin >> c;
	if(c == -1)	t = NULL;
	else
	{
		t = new TreeNode;
		t->date = c;
		createTree(t->left);
		createTree(t->right);	
	}	
} 

void midPrint(Tree t) //中序遍历 
{
	if(t == NULL)	return ;
	
	stack<Tree> s;
	Tree p = t;
	while(p || !s.empty())
	{
		while(p)
		{
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->date << " ";
			p = p->right; 
		}
	}
	
}

void prePrint(Tree t)	//先序遍历 
{
	if(t == NULL)	return ;
	
	stack<Tree> s;
	Tree p = t;
	
	while(p || !s.empty())
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

void lastPrint(Tree t)	//后序遍历 
{
	if(t == NULL)	return ;
	
	stack<ElementNode> s;
	ElementNode e;
	Tree p = t;
	while(p || !s.empty())
	{
		while(p)
		{
			e.ptr = p;
			e.isfirst = true;
			s.push(e);
			p = p->left;
		}
		if(!s.empty())
		{
			e = s.top();
			s.pop();
			p = e.ptr;
			if(e.isfirst)
			{
				e.isfirst = false;	//必须在入栈之前设置 
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

/*测试样例 
1 2 4 -1 -1 -1 3 5 7 
-1 -1 8 -1 -1 6 -1 -1
先序：1 2 4 3 5 7 8 6
中序：4 2 1 7 5 8 3 6
后序：4 2 7 8 5 6 3 1
*/
int main()
{
	Tree t;
	cout << "please " << endl;
	createTree(t);
	
	cout << "先序遍历" << endl;
	prePrint(t);	cout << endl;	
	cout << "中序遍历" << endl;
	midPrint(t);	cout << endl;
	cout << "后序遍历" << endl;
	lastPrint(t);	cout << endl;
	
	return 0;
} 
