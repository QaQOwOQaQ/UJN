#include<iostream>
#include<stdlib.h>
#include<algorithm>
#define len sizeof(link)

using namespace std;

struct link
{
	int s;
	struct link *next;
};

struct link *creat()	//尾插法 
{
	struct link *head,*p,*tail;
	head = (link *)malloc(len);
	head->next = NULL;
	tail = head;
	p = (link*)malloc(len);
	cin >> p->s;
	while(p->s != 0)
	{
		tail->next = p;
		tail = p;
		tail->next = NULL;
		p = (link *)malloc(len);
		cin >> p->s;
	}
	return head;
}

void print(struct link *head)
{
	struct link *p;
	int count = 0;	//链表长度 
	if(head == NULL)
		cout << "Nothings!";
	else
	{
		p = head->next;
		cout << "信息如下：" << endl; 
		while(p != NULL)
		{
			cout << p->s << endl;
			p = p->next;
			count++;
		}
	}
}

void insert(struct link *head,int n)	//在第n个节点后买你插入一个节点 
{
	struct link *p0,*p = head;
	p0 = (link *)malloc(len);
	cout << "你要插入的数据:" << endl;
	cin >> p0->s;
	int i = 0;
	while(i<n && p!=NULL)
	{
		p = p->next;
		i++;
	}
	if(p == NULL)
		cout << "节点不存在！" << endl;
	else
	{
		p0->next = p->next;
		p->next = p0;	//p的next指向p0 
	}
	
}

void deleteNode(struct link *head,int n)//删除第n个节点p0
{
	struct link *p = head,*p0 = head;//p0指向p 
	int i = 0;
	while(i<n && p0!=NULL)
	{
		p = p0;
		p0 = p0->next;
		i++;
	}
	if(p0 == NULL)
		cout << "节点不存在！" << endl;
	else
	{
		p->next = p0->next;
		free(p0);
	}
}
int main()
{
	struct link *head;
	int n;
	head = creat();
	print(head);
	cout << "插入节点!" << endl;
	cin >> n;
	insert(head,n);
	print(head);
	cout << "删除节点！" << endl;
	cin >> n;
	deleteNode(head,n);
	print(head);
	return 0;
}
