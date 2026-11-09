#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <set>

using namespace std;

typedef struct link
{
	int val;
	struct link *next;
}*Link, LinkNode;

void create(Link &head)	//带头结点, 默认头结点的位置编号为0, 尾插法 
{
	Link newNode, rear;
	int val, cnt;
	
	head = new LinkNode;
	head->next = NULL;
	rear = head;
	
	cout << "你输入节点个数：";
	cin >> cnt;
	
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
	if(L == NULL)
	{
		cout << "链表为空" << endl;
		return ;	
	} 
	cout << "链表如下：" << endl;
	while(L)
	{
		cout << L->val << " ";
		L = L->next;
	}
	cout << endl;
}

void InsertSort(Link &head)
{
	Link pre, r, cur, tmp;
	
	cur = head->next->next;
	head->next->next = NULL;
	while(cur)
	{
		pre = head;
		r = head->next;
		while(r && r->val < cur->val)
		{
			pre = pre->next;
			r = r->next;
		}
		tmp = cur;
		cur = cur->next;
		pre->next = tmp;
		tmp->next = r;
	}
}

void deleteMinNode(Link &L, int &min_val)	//直接删除最小值节点 
{
	Link minPre, cur;
	int min;
	
	minPre = L;
	cur = L->next;
	if(cur == NULL)
	{
		cout << "链表为空!" << endl;
		return ;
	}
	
	min = cur->val;
	while(cur->next)
	{
		if(cur->next->val < min)
		{
			min = cur->next->val;
			minPre = cur;
		}
		cur = cur->next;
	}
	cur = minPre->next;
	minPre->next = cur->next;
	
	free(cur); 		//删除就要释放 
	min_val = min;
}

void swapMinNode(Link &L, int &min_val)	//删除最小值节点并由最后一个节点补充 
{
	//思路：将最小值节点替换为最后一个节点，然后删除最后一个节点 
	Link minPre, cur, curPre;
	int minx;
	
	minPre = L;
	curPre = L;
	cur = curPre->next;
	if(cur == NULL)	
	{
		cout << "链表为空!" << endl;	
		return ;
	}

	minx = cur->val;
	while(cur->next)
	{
		if(cur->next->val < minx)
		{
			minx = cur->next->val;
			minPre = cur;
		}
		curPre = cur;
		cur = cur->next;
	}
	minPre->next->val = cur->val; 
	curPre->next = cur->next;
	
	free(cur);
	min_val = minx;
}

void deleteByPos(Link &L, int pos)	//删除pos位置的节点 
{
	int j = 1;
	Link pre, goal;	//第k个节点的前驱节点, 目标节点 
	pre = L;
	while(pre->next && j < pos)
	{
		j ++ ;
		pre = pre->next;
	}
	goal = pre->next;
	if(pos < j || goal == NULL)
	{
		cout << "节点不存在!" << endl;
		return ;
	}
	pre->next = goal->next;
	free(goal);
}

void insertNode(Link &L, int pos)	//在pos位置之前插入节点 
{
	int j = 1, val;
	Link newNode, preNode;
	preNode = L;
	
	while(j < pos && preNode)
	{	
		j ++ ;
		preNode = preNode->next;
	} 
	
	if(pos < j || preNode == NULL)
	{
		cout << "插入位置不正确" << endl;
		return ;
	}
	
	cout << "请输入要插入的数据: ";
	cin >> val; 
	newNode = new LinkNode;
	newNode->val = val;
	newNode->next = preNode->next; 
	preNode->next = newNode;
}

void deleteNodeByNum(Link &L, int val)	//删除具有给定值val的节点 
{
	Link pre, goalNode;	 
	pre = L;
	
	if(pre->next == NULL)
	{
		cout << "链表为空!" << endl;
		return ;
	}
	
	while(pre->next)
	{
		if(pre->next->val == val)
		{
			goalNode = pre->next;
			pre->next = goalNode->next;
			free(goalNode);
		}
		else
		{
			/*
			当有连续的两个val值的时候只会删除一个
			因为在删除一个val之后pre后移一位指向了下一个val值的节点 
			所以当我们删除了一个val值节点之后不要后移pre指针 
			*/
			pre = pre->next;
		}

	}
}

int getValNum(Link &L, int val)	//查找节点值为给定值val的节点个数 
{
	L = L->next;
	int cnt = 0;
	
	if(L == NULL)
	{
		cout << "链表为空" << endl;
		return 0;
	}
	
	while(L)
	{
		if(L->val == val)	cnt ++ ;
		L = L->next;	
	} 
	return cnt;
}

void SelectSort(Link &L)//单链表上的简单选择排序算法
{
    int tmp;
    Link p, q, minp;

	for(p = L->next; p; p = p->next)	//遍历所有节点, 注意跳过头结点 
	{
        minp = p;	//默认当前节点是值最小的节点 
        for(q = p->next; q; q = q->next)	//在当前节点和后面所有节点中找到一个值最小的节点 
			if(q->val < minp->val)
				minp = q;
              
        if(minp != p)	//如果当前节点不是最小值节点就交换值 
		{
            tmp = p->val;
            p->val = minp->val;
            minp->val = tmp;
        }
	}
}


//归并排序 -- 就地归并 
Link MergeListCore(Link head1, Link head2) //两个单链表head1和head2的归并排序 
{
	//如果head1或者head2==NULL，直接返回另一个 
	if (head1 == NULL) 
		return head2;
	if (head2 == NULL)
		return head1;
	
	//如果head1和head2均不为空，让值小的作为头， 
	if (head1->val <= head2->val) 
	{
		head1->next = MergeListCore(head1->next, head2); //head1作为头 
		return head1;
	}
	if (head1->val > head2->val) 
	{
		head2->next = MergeListCore(head1, head2->next);  //head2作为头 
		return head2;
	}
}

Link MergeSortCore(Link head)
{
	if (head->next == NULL)	//只有一个节点返回 
		return head;
	
	//如果区间长度不为1，递归划分左右区间 
	//左区间长度为len/2上取整,右区间长度为len/2下取整,即左区间长度减去右区间长度等于1/0 	
	Link slow, fast;
	slow = head;
	fast = slow->next;
	while (fast != NULL) 
	{
		fast = fast->next;
		if (fast != NULL) 
		{ 
			slow = slow->next;
			fast = fast->next;
		}
	}
	
	Link righthead;
	righthead = slow->next;
	slow->next = NULL;
//	cout << "text: " << head->val << " " << righthead->val << endl;

	//继续划分 
	head = MergeSortCore(head);
	righthead = MergeSortCore(righthead);
	return MergeListCore(head, righthead);
}

void MergeSort(Link &head)
{
	if(head->next == NULL)	return ;
	head->next = MergeSortCore(head->next);
} 

bool checkLift(Link &L)	//判断一个单链表是否递增, 这里相等也算递增 
{
	Link pre = L->next;
	if(pre == NULL)
	{
		cout << "链表为空！" << endl;
		return false;
	}
	
	while(pre->next != NULL)
	{
		if(pre->next->val < pre->val)	return false;
		else	pre = pre->next;
	}
	return true;
} 

Link partition(Link head, int x) //根据x的值把单链表分割成两个区间 
{
	/*pre指针的作用：
	  pre指向可以与cur的值做交换的节点
	  如果cur的值小于x，我们需要把cur的值放到链表的前面
	  但又希望小于x的值在排序后仍然保持原来的顺序，即保持稳定性
	  例如，原本是1,2，我们希望排序后仍然是1,2而不是2,1 
	  那么我们就要记录当前已经遍历到的小于x的最后一个元素的后继，就是pre
	  那么初始时pre就要放在第一个元素的位置了 
	*/ 
    Link pre = head->next;	 
    Link cur = head->next;	//cur遍历单链表所有元素 
    while(cur)
	{
        if(cur->val < x)
		{
            int temp = pre->val;
            pre->val = cur->val;
            cur->val = temp;
            pre = pre->next;
        }
        cur = cur->next;
    }
    return head;
}

//删除链表中的重复元素  
void deleteDuplecate(Link &L)//方法一：哈希表法，时间复杂度O(n) 额外空间复杂度O(n)
{
	set<int> S;
	Link cur, pre;
	
	pre = L;
	cur = L->next;
	if(cur == NULL)
	{
		cout << "链表为空" << endl;
		return ;
	}
	while(cur != NULL)
	{
		if(S.count(cur->val))	pre->next = cur->next;
		else
		{
			S.insert(cur->val);
			pre = cur;
		}
		cur = cur->next;
	}
} 


Link reverseList(Link &head)	//反转链表 
{
	//思路：头插入创建一个新链表 
	Link newHead;
	Link tmpNode;
	
	newHead = new LinkNode;
	newHead->next = NULL;
	head = head->next;
	while(head != NULL)
	{
		tmpNode = head;
		head = head->next;
		
		tmpNode->next = newHead->next;
		newHead->next = tmpNode;
	}
	return newHead;
}

void deleteNthFromEnd(Link &head, int n)	//删除倒数第k个节点 
{
	// 设链表长度为len 
	// 双指针法，让fast先走n步，然后fast和slow一起走，
	// 当fast走到链表尾部(NULL)处，fast一共走了len步，slow走了len-n步
	// 正数len-n就是倒数第n的位置 
	if(head->next == NULL)
	{
		cout << "链表为空" << endl;
		return ;
	}
	Link slow = head, fast = head, pre;
	for(int i = 0; i < n; i ++ )	fast = fast->next;
	while(fast != NULL)
	{
		fast = fast->next;
		pre = slow;
		slow = slow->next;
	}
	pre->next = slow->next;
}

int main()
{
	int min;
	Link L;
	create(L);	show(L);
	deleteDuplecate(L);
	show(L);
	return 0;
}
