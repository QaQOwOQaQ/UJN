#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue> 

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

void create(Tree &t)
{
	int c;
	cin >> c;
	
	if(c == -1) t = NULL;
	else
	{
		t = new TreeNode;
		t->date = c;
		create(t->left);
		create(t->right);
	}
}


void midPrint(Tree t)
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

void levelPrint(Tree t) 
{
	Tree p = t;
	queue<Tree> q;
	if(t == NULL)	return;
	q.push(p);
	while(q.size())
	{
		p = q.front();
		q.pop();
		cout << p->date << " ";
		if(p->left)	q.push(p->left);
		if(p->right)	q.push(p->right); 
	}
	cout << endl;
}


bool checkOrder(Tree t, int &cur)
{
	if(t == NULL)	return true;

	checkOrder(t->left, cur);
	cout << t->date << " "; 
	if(t->date < cur)	return false;
	else 	cur =  t->date;
	checkOrder(t->right, cur);
	return true;
}

bool chekcComplete(Tree t)
{
	if(t == NULL)	return false;
	
	Tree p = t;
	queue<Tree> q;
	q.push(t);
	while(q.size())
	{
		p = q.front();
		if(p->left && p->right)
		{
			q.pop();
			q.push(p->left);
			q.push(p->right);
		}
		if(p->left == NULL && p->right)	return false;
		if(p->right == NULL)
		{
			q.pop();
			if(p->left)	q.push(p->left);
			while(q.size())
			{
				p = q.front();
				if(p->left == NULL && t->right == NULL)	q.pop();
				else	return false;
			}	
			return true;
		}
	
	}
	
	return true;
	
	
}

int main()
{
	Tree t;
	create(t);
	midPrint(t);
	cout << endl;

	cout << chekcComplete(t) << endl;
	
	return 0;
}
