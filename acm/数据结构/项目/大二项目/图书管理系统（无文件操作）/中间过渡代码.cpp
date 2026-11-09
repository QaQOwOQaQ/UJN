#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cstring>

using namespace std;

char date[30], name[30], auth[30], ISBN[30];	
int num;
double price;

typedef struct link
{
	char date[30];	//购买日期 
	char name[30];	//书名 
	char auth[30];	//作者 
	char ISBN[30];	//书号 
	int num;		//数量 
	double price;	//价格 
	struct link *next;
}*Link, LinkNode;

void CreateLink(Link &head, int cnt)
{
	Link rear, newNode;
	head = new LinkNode;
	head->next = NULL;
	rear = head;
	cout << "请依次输入：购买日期->书名->作者->书号->数量->价格" << endl;
	for(int i = 0; i < cnt; i ++ )
	{
		newNode = new LinkNode;
		scanf("%s%s%s%s%d%lf", newNode->date, newNode->name, newNode->auth, newNode->ISBN, &newNode->num, &newNode->price);
	
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode;
	}
}

void InsertItem(Link L)
{
	Link newNode, preNode = L;
	cout << "请请依次输入：购买日期->书名->作者->书号->数量->价格" << endl;
	scanf("%s%s%s%s%d%lf", newNode->date, newNode->name, newNode->auth, newNode->ISBN, &newNode->num, &newNode->price);
	
	preNode = preNode->next;
	while(strcmp(newNode->ISBN, L->ISBN))
	{
		preNode = preNode->next;
	}
	if(preNode->ISBN == newNode->ISBN)
	{
		strcpy(preNode->auth, newNode->auth);
		strcpy(preNode->name, newNode->name);
		strcpy(preNode->date, newNode->date);
		preNode->num = newNode->num;
		preNode->price = newNode->price;
	}
	else
	{
		newNode->next = preNode->next;
		preNode->next = newNode;
	}
}

void DeleteItem(Link L, char c[30])
{
	Link preNode, goalNode;
	preNode = L;
	while(strcmp(c, L->next->ISBN))
	{
		preNode = preNode->next;
	}
	goalNode = preNode->next;
	if(goalNode == NULL)
	{
		cout << "书单中不存在该书目!" << endl;
		return ; 
	}	 
	free(goalNode);
}

//不带头结点的单链表的排序
//合并两个有序链表
Link merge(Link left, Link right)
{
    Link out;        
    if(left->date<right->date)
	{
        out = left;
        left = left->next;
    }
    else
	{
        out = right;
        right = right->next;
    }
    Link  p = out;
    p->next = NULL;
    while(left&&right)
	{
        if(left->date<right->date)
		{
            p->next = left;
            left = left->next;
            p = p->next;
            p->next = NULL;
        }
        else
		{
            p->next = right;
            right = right->next;
            p = p->next;
            p->next = NULL;
        }
    }
    if(left!=NULL)p->next = left;
    if(right!=NULL)p->next = right;
    return out;        
}

Link sortList(Link head) 
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    Link slow = head;                  //设置一个慢指针
    Link fast = head->next;            //设置一个快指针
    while(fast!=NULL)	//找出链表的中间节点
	{                   
        fast = fast->next;
        if(fast==NULL)
            break;
        fast = fast->next;
        slow = slow->next;            
    }
    Link list1 = head;
    Link list2 = slow->next;
    slow->next = NULL;
    Link left = sortList(list1);       //递归左归并
    Link right = sortList(list2);      //递归右归并
    Link output = merge(left,right);   //合并两个有序链表
    return output;
}
 



int main()
{
	
	
	return 0;	
} 
