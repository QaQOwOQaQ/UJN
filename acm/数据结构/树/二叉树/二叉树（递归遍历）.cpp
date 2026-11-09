#include<iostream>
#include<stdlib.h>
#include<cstring>

using namespace std;

typedef struct treeNode 
{
	char ch;
	struct treeNode *left,*right;
}treeNode,*tree;

void creatTree(tree &t)	//先序 
{
	char ch;
	cin >> ch;
	if(ch == '#')
		t = NULL;
	else
	{
		t = (tree)malloc(sizeof(treeNode));
		t->ch = ch;
		creatTree(t->left);
		creatTree(t->right);
	}
}

void preOrder(tree &t)
{
	if(t == NULL)
		return ;
	cout << " " << t->ch;
	preOrder(t->left);
	preOrder(t->right);
}

void midOrder(tree &t)
{
	if(t == NULL)
		return ;
	midOrder(t->left);
	cout << " " << t->ch;
	midOrder(t->right);
}

void lasOrder(tree &t)
{
	if(t == NULL)
		return ;
	lasOrder(t->left);
	lasOrder(t->right);
	cout << " " << t->ch;
}
int main()
{
	tree t; 
	creatTree(t);
	
	cout << "先序" << endl;
	preOrder(t);
	cout << endl;
	
	cout << "中序" << endl;
	midOrder(t);
	cout << endl;

	cout << "后序" << endl;
	lasOrder(t); 
	cout << endl;
	
	return 0;
} 






