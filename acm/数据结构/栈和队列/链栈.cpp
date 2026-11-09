#include<iostream>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define maxn 50
#define len sizeof(StackNode)
using namespace std;

typedef struct StackNode 
{
	int date;
	struct StackNode *next;
}StackNode,*LinkStack;

int init(LinkStack &s)
{
	s = NULL;
	return OK;
}

int push(LinkStack &s,int e)
{
	LinkStack p;
	p = (LinkStack )malloc(sizeof(len));
	p->date = e;
	p->next = s;
	s = p;
	return OK;
}

int pop(LinkStack &s)
{
	LinkStack p;
	if(s == NULL)
		return ERROR;
	p = s;
	s = s->next;
	free(p);
	return OK;
}

int top(LinkStack &s)
{
	if(s == NULL)
		return ERROR;
	return s->date;
}

int main()
{
	LinkStack s;
	init(s);
	for(int i=1;i<10;i++)
		push(s,i);
	while(s != NULL)
	{
		cout << "top:" << top(s) << endl;
		pop(s);
	}
	
	
	
	return 0;
}
