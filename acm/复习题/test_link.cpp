#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

typedef struct link
{
	int val;
	struct link *next;
}*Link, LinkNode;

void headCreate(Link &head)
{
	Link newNode;
	int val;
	
	head = new LinkNode;
	head->next = NULL;
	cout << "输入-1停止！ " << endl; 
	while(cin >> val, val != -1)
	{
		newNode = new LinkNode;
		newNode->val = val;
		newNode->next = head->next;
		head->next = newNode;
	}
}

void tailCreate(Link &head, int cnt)
{
	Link newNode, rear;
	head = new LinkNode;
	head->next = NULL;
	rear = head;
	for(int i = 0; i < cnt; i ++ )
	{
		newNode = new LinkNode;
		cin >> newNode->val;
		
		newNode->next = rear->next;
		rear->next = newNode;
		rear = newNode; 
	}
}

void show(Link L)
{
	L = L->next;
	cout << "链表遍历如下：" << endl;
	while(L)
	{
		cout << L->val << " ";
		L = L->next;
	}
	cout << endl;
}


void partition(Link &head, int val)
{
	Link pre = head->next;
	Link cur = head->next;
	while(cur)
	{
		if(cur->val < val)
		{
			int tmp = pre->val;
			pre->val = cur->val;
			cur->val = tmp;
			pre = pre->next; 
		}
		cur = cur->next; 
	}
} 

Link merge(Link L1, Link L2 )
{
    Link L, p1, p2, rear;
    
    p1 = L1->next;
    p2 = L2->next;
    L = new LinkNode;
    L->next = NULL;
    rear = L;
    
    while (p1 && p2)
	{
        if(p1->val < p2->val)
		{
            rear->next = p1;
            rear = p1;
            p1 = p1->next;
        }
        else
		{
            rear->next = p2;
            rear = p2;
            p2 = p2->next;
        }
    }
    
    rear->next = p1 ? p1 : p2;

	L1->next = NULL;
	L2->next = NULL;
	
	return L;
}


int main()
{
	Link L1, L2;
	tailCreate(L1, 5);
	tailCreate(L2, 5);
	show(L1);	show(L2);
	Link L3 = merge(L1, L2); 
	show(L3);

	return 0;	
} 
