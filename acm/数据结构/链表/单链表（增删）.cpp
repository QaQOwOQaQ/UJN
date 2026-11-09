#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct link
{
	int date;
	struct link *next;
}*Link, LinkNode;

void HeadCreate(Link &head)
{
	int c;
	Link newNode;
	
	head = new LinkNode;
	head->next = NULL;
	cout << "输入-1结束: ";
	while(cin >> c, c != -1)
	{
		newNode = new LinkNode;
		newNode->date = c;
		newNode->next = head->next;
		head->next = newNode;
	}	
}

void TailCreate(Link &head)
{
	int c;
	Link newNode, rear;
	
	head = new LinkNode;
	head->next = NULL;
	rear = head;	//比头插入多出的 
	cout << "输入-1结束: ";
	while(cin >> c, c != -1)
	{
		newNode = new LinkNode;
		newNode->date = c;
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode;	//比头插入多出的 
	}
}

void show(Link L)
{
	cout << "链表如下：";
	L = L->next;
	while(L)
	{
		cout << L->date << " ";
		L = L->next;
	}
	cout << endl;
}

void insertNode(Link &head)
{
	int n, val, i = 1;
	Link pre = head, newNode;
	
	cout << "请输入你要插入的位置：";
	cin >> n;
	
	while(i < n && pre->next != NULL)
	{
		i ++ ;
		pre = pre->next;
	}
	if(pre == NULL || n < i)
		cout << "插入位置不合法！" << endl;
	else
	{
		cout << "请输入你要插入的数据：";
		cin >> val;
		newNode = new LinkNode;
		newNode->date = val;
		newNode->next = pre->next;
		pre->next = newNode; 
	}
	
}

void deleteNode(Link &head)
{
	int n, i = 1;
	Link pre = head, goal;	//pre指向要删除节点的前一个节点 
	
	cout << "请输入你要删除的位置：";
	cin >> n;
	
	while(i < n && pre->next != NULL)
	{
		i ++ ;
		pre = pre->next;
	}
	
	goal = pre->next;
	if(goal == NULL || n < i)
		cout << "节点不存在!" << endl;
	else
	{
		pre->next = goal->next;
		free(goal);	//删除就要free 
	}
}

int main()
{
	Link L1, L2;
//	HeadCreate(L1);
//	show(L1);
	TailCreate(L2);
	show(L2);
	deleteNode(L2);
	show(L2);
	insertNode(L2);
	show(L2);
	return 0;
} 
