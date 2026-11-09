#include<iostream>

using namespace std;

#define maxn 50
#define OK 1
#define ERROR 0
typedef struct
{
	int date[maxn];
	int top;
}Stack;

int init(Stack *s)	//³õÊ¼»¯ 
{
	s->top = -1;
	return OK;
}

int empty(Stack *s)	//ÅÐ¶ÏÕ»¿Õ 
{
	if(s->top == -1)
		return OK;
	else
		return ERROR;
}
int length(Stack *s)
{
	return s->top + 1;
}

int push(Stack *s,int e)
{
	if(s->top == maxn-1)	//Õ»Âú 
		return ERROR;
	s->top++;
	s->date[s->top] = e;
	return OK;
}

int pop(Stack *s)
{
	if(empty(s))
		return ERROR;
	s->top--;
	return OK;
}

int top(Stack *s,int *e)
{
	if(empty(s))
		return ERROR;
	*e = s->date[s->top];
	return OK;
}

int main()
{
	Stack s;
	int e,i;
	init(&s);
	for(i=1;i<10;i++)
	{
		push(&s,i);	
	}	

	cout << "len:" << length(&s) << endl;
	while(!empty(&s))
	{
		top(&s,&e);
		cout << "top:" << e << endl;
		pop(&s);	
	}
	if(empty(&s))
		cout << "empty!" << endl;
	
	
	return 0;
}
