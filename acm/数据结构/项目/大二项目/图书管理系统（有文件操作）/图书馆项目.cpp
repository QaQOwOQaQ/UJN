#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#define filename "BookList.txt"

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


//文件操作
void init(Link &head)	//程序一开始读取文件里的数据
{
	Link newNode, rear;
	
	head = new LinkNode;
	head->next = NULL;
	rear = head;
	
	ifstream fin(filename, ios::in);
	if (fin.is_open())
	{
		while(fin >> date >> name >> auth >> ISBN >> num >> price)
		{
			newNode = new LinkNode;
			strcpy(newNode->date, date);
			strcpy(newNode->name, name);
			strcpy(newNode->auth, auth);
			strcpy(newNode->ISBN, ISBN);
			newNode->num = num;
			newNode->price = price;
			
			newNode->next = rear->next;
			rear->next = newNode;
		}
	}
	fin.close();
}

void resave(Link L)
{
	if(L == NULL || L == NULL)	return ;

	L = L->next;
	ofstream fout(filename, ios::out);	//重新写入数据，因为改变了某个元素
	if(fout.is_open())
	{
		for(L; L; L = L->next)
			fout << L->date << ' ' << L->name << ' ' << L->auth << ' ' << L->ISBN << ' ' << L->num << ' ' << L->price << endl;
	}
	
	fout.close(); 
}


//展示功能 
void myPrint(Link L)
{
	printf("************************\n");
	printf("*     【%s】     \n",L->name);
	printf("*  1.购买日期:%s       \n",L->date); 
	printf("*  2.作者:%s           \n",L->auth); 
	printf("*  3.ISBN:%s           \n",L->ISBN); 
	printf("*  4.数量:%d           \n",L->num); 
	printf("*  5.价格:%.2f         \n",L->price); 
	printf("************************\n");
	printf("\n");
}

void ShowItem(Link L)
{
	L = L->next;
	if(L == NULL)	cout << "图书信息为空!" << endl;
	else
	{
		cout << "图书信息如下：购买日期-->书名-->作者-->书号-->数量-->价格" << endl;
		while(L)
		{
			myPrint(L);
			L = L->next;
		}
		cout << endl;	
	}
}

//查询功能 
Link IsbnQuery(Link L)
{
	Link goalNode = L->next;
	
	cout << "请输入你要查询书目的ISBN号: ";
	scanf("%s", ISBN); 

	while(goalNode && strcmp(ISBN, goalNode->ISBN))	goalNode = goalNode->next;	 
	if(goalNode == NULL)
	{
		printf("书单中不存在该书目!\n");
		return NULL; 
	} 
	else myPrint(goalNode);
	
	return goalNode;
	
}

Link NameQuery(Link L)
{
	Link goalNode = L->next;
	
	cout << "请输入你要查询书目的书名: ";
	scanf("%s", name); 

	while(goalNode && strcmp(name, goalNode->name))	goalNode = goalNode->next;	 
	if(goalNode == NULL)	printf("书单中不存在该书目!\n");
	else myPrint(goalNode);
	
	return goalNode;
	
}

Link AuthQuery(Link L)
{
	bool has_book = false;
	Link goalNode = L->next;
	
	cout << "请输入你要查询书目的作者名称: ";
	scanf("%s", auth); 

	while(goalNode)
	{
		if(!strcmp(goalNode->auth, auth))
		{
			myPrint(goalNode);
			has_book = true;		
		}
		goalNode = goalNode->next;
	}
	if(!has_book)	printf("书单中不存在该书目\n");
	
	return goalNode;
	
}

Link PriceQuery(Link L)
{
	double price1, price2;
	Link goalNode = L->next;
	bool has_book = false;
	
	cout << "请输入你要查询书目的价格区间(两个数字): ";
	cin >> price1 >> price2;
	if(price1 > price2) swap(price1, price2);
	
	while(goalNode)
	{
		if(goalNode->price >= price1 && goalNode->price <= price2)
		{
			myPrint(goalNode);
			has_book = true;		
		}
	}	 
	if(!has_book)	printf("书单中不存在该书目\n");
	
	return goalNode;
	
}

void QueryItem(Link L)
{
	int query_opt;
	bool tag = true;
	while(tag)
	{
		cout << "请输入查询代号(0--退出  1--ISBN  2--作书名  3--作者  4--价格): " << endl;
		cin >> query_opt;
		switch(query_opt)
		{
			case 0 : {
				tag = false;
				cout << "退出成功！" << endl;
				break;
			}
			case 1 : {
				IsbnQuery(L);
				break;
			}	
			case 2 : {
				NameQuery(L);
				break;
			}
			case 3 : {
				AuthQuery(L);
				break;
			}
			case 4 : {
				PriceQuery(L);
				break;
			}
			default : {
				cout << "请输入正确的指令！" << endl; 
				break;
			}
		}	
		
	}
	
} 


//插入功能 -- 默认根据ISBN号升序插入 
void InsertItem(Link L)
{
	char flag;
	int tag = true;
	while(tag)
	{
		Link newNode, preNode;
		newNode = new LinkNode;
		cout << "请请依次输入：购买日期-->书名-->作者-->IBSN编号-->数量-->价格" << endl;
		scanf("%s%s%s%s%d%lf", newNode->date, newNode->name, newNode->auth, newNode->ISBN, &newNode->num, &newNode->price);
	
		preNode = L;
		while(preNode->next && strcmp(newNode->ISBN, preNode->next->ISBN) != -1)	preNode = preNode->next;	
		
		newNode->next = preNode->next;
		preNode->next = newNode;
		
		cout << "插入成功！"  << endl;
		cout << "是否继续插入信息(Y/其他字符): ";
		cin >> flag; 
		if(flag != 'Y')	
		{
			cout << "退出成功！" << endl;
			tag = false;
		}
	}

}


//删除功能
void IsbnDelete(Link L)
{
	string delete_flag;
	Link goalNode, preNode;
	preNode = L;
	
	cout << "请输入你要删除书目的ISBN号: ";
	scanf("%s", ISBN); 

	while(preNode->next && strcmp(ISBN, preNode->next->ISBN))	preNode = preNode->next;
	goalNode = preNode->next;
	if(goalNode == NULL)	printf("书单中不存在该书目！\n");
	else
	{
		cout << "请再次确认是否删除：(Y/其他字符): ";
		cin >> delete_flag;
		if(delete_flag != "Y")	return ;
		
		preNode->next = goalNode->next;
		cout << "删除成功！" << endl; 
		free(goalNode);
	} 
}

void NameDelete(Link L)
{
	string delete_flag;
	Link goalNode, preNode;
	preNode = L;
	
	cout << "请输入你要删除书目的书名: ";
	scanf("%s", name); 

	while(preNode->next && strcmp(name, preNode->next->name))	preNode = preNode->next;
	goalNode = preNode->next;
	if(goalNode == NULL)	printf("书单中不存在该书目！\n");
	else
	{
		cout << "请再次确认是否删除(Y/其他字符): ";
		cin >> delete_flag;
		if(delete_flag == "Y")
		{
			preNode->next = goalNode->next;
			free(goalNode);
			cout << "删除成功！" << endl; 
		}
	} 
}

void AuthDelete(Link L)
{
	string delete_flag;
	Link goalNode, preNode;
	preNode = L;
	
	cout << "请输入你要删除书目的作者名: ";
	scanf("%s", auth); 

	while(preNode->next && strcmp(auth, preNode->next->auth))	preNode = preNode->next;
	
	goalNode = preNode->next;
	if(goalNode == NULL)	cout << "书单中不存在该书目！" << endl;
	else
	{
		cout << "请再次确认是否删除!(Y/N): ";
		cin >> delete_flag;
			
		if(delete_flag == "Y")
		{
			preNode->next = goalNode->next;
			free(goalNode);
			cout << "删除成功！" << endl; 
		}
	}
}

void DeleteItem(Link L)
{
	bool tag = true;
	while(tag)
	{
		cout << "请输入删除代号(0--退出  1--ISBN  2--书名  3--作者)：";
		int del_opt;
		cin >> del_opt;
		switch(del_opt)
		{
			case 0 : {
				tag = false;
				cout << "退出成功！" << endl;
				break;
			}
			case 1 : {
				IsbnDelete(L);
				break;
			}	
			case 2 : {
				NameDelete(L); 
				break;
			}
			case 3 : {
				AuthDelete(L);
				break;
			}
			default : {
				cout << "你输入了错误的指令！" << endl;
				break;
			} 
			
		}	
	} 
} 


//修改功能 
void ChangeItem(Link L)		
{
	int flag;
	bool tag = true;
	while(tag)
	{
		Link goalNode = IsbnQuery(L);
		if(goalNode == NULL)	break;
		cout << "请输入你要修改的选项(0--退出  1--日期  2--书名  3--作者  4--数量  5--价格): " << endl;
		cout << "输入代号: ";
		cin >> flag;
		switch(flag)
		{
			case 0 : {
				tag = false;
				cout << "退出成功！" << endl;
				break;
			}
			case 1 : {
				cout << "请输入你要修改的日期: ";
				scanf("%s", date);
				strcpy(goalNode->date, date);
				cout << "修改成功!" << endl; 			
				break;
			}
			case 2 : {
				cout << "请输入你要修改的书名: ";
				scanf("%s", name);
				strcpy(goalNode->name, name);
				cout << "修改成功!" << endl; 			
				break;
			}
			case 3 : {
				cout << "请输入你要修改的作者: ";
				scanf("%s", auth);
				strcpy(goalNode->auth, auth);
				cout << "修改成功!" << endl; 
				break;
			}
			case 4 : {
				cout << "请输入你要修改的数量: ";
				scanf("%d", &num);
				goalNode->num = num;
				cout << "修改成功!" << endl; 
				break;
			}
			case 5 : {
				cout << "请输入你要修改的价格: ";
				scanf("%lf", &price);
				goalNode->price = price;
				cout << "修改成功!" << endl; 
				break;
			}
			default : {
				cout << "请输入正确的指令！" << endl;
				break;
			}
		}	
	}
	
}


//排序功能 -- 插入排序 
void PriceSort(Link &head)	
{
	Link tmp, pre, cur, r;
	
	cur = head->next->next;
	head->next->next = NULL;
	
	while(cur)
	{
		pre = head;
		r = head->next;
		while(r && cur->price > r->price)
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

void NumSort(Link &head)
{
	Link tmp, pre, cur, r;
	
	cur = head->next->next;
	head->next->next = NULL;
	
	while(cur)
	{
		pre = head;
		r = head->next;
		while(r && cur->num > r->num)
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

void IsbnSort(Link &head)
{
	Link tmp, pre, cur, r;
	
	cur = head->next->next;
	head->next->next = NULL;
	
	while(cur)
	{
		pre = head;
		r = head->next;
		while(r && cur->price > r->price)
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

void SortItem(Link L)
{
	bool tag = true;
	int sort_flag;  
	
	while(tag)
	{
		cout << "请选择你要排序的方式(0--退出  1--按价格排序  2--按ISBN编号排序  3--按数量排序)：";
		cin >> sort_flag;
		switch(sort_flag)
		{
			case 0 : {
				tag = false;
				cout << "退出成功" << endl; 
				break;
			}
			case 1 : {
				PriceSort(L);
				cout << "书单已经按照价格升序排列！" << endl;
				ShowItem(L);
				break;
			}
			case 2 : {
				IsbnSort(L);
				cout << "书单已经按照ISBN编号升序排列！" << endl;
				ShowItem(L);
				break;
			}
			case 3 : {
				NumSort(L); 
				cout << "书单已经按照数量升序排列！" << endl;
				ShowItem(L);
				break;
			}
			default : {
				cout << "请输入正确的指令" << endl;
				break;
			}
		}
	}
	
}


//主界面 
void MainMenu()
{
	printf("          		个人图书管理系统菜单\n");
	printf("  -----------------------------------------------------------------------\n");
	printf("*****************************************************************************\n");
	printf("\n");
	printf("             1---信息展示                   2---插入功能\n");
	printf("\n");
	printf("             3---删除功能                   4---修改功能 \n");
	printf("\n");
	printf("             5---查询功能                   6---排序功能\n");
	printf("\n");		
	printf("             7---退出程序                   8---敬请期待\n");
	printf("\n");		
	printf("*****************************************************************************\n");
	printf("  -----------------------------------------------------------------------\n");
}

int main()
{
	Link L;
	init(L);
	bool start = true;
	while(start)
	{
		int opt;
		MainMenu();
		cin >> opt;
		system("cls");
		switch(opt)
		{
			case 1 : {
				ShowItem(L);
				break;
			}
			case 2 : {
				InsertItem(L);
				break;
			}
			case 3 : {
				DeleteItem(L);
				break;
			}
			case 4 : {
				ChangeItem(L);
				break;
			}
			case 5 : {
				QueryItem(L);
				break;
			}
			case 6 : {
				SortItem(L);
				break;
			}
			case 7 : {
				start = false;
				cout << "您已经成功退出本程序!" << endl; 
				break;
			}
			case 8 : {
				cout << "敬请期待!" << endl; 
				break;
			}
			default : {
				cout << "请输入正确的指令！" << endl;
				break;
			}
		}	
		resave(L);
	}	

	
	return 0;
}
