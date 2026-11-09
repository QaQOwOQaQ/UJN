#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#define filename "txt/test.txt"

using namespace std;

typedef struct link
{
	char name[30];
	char num[30];
	int score;
	struct link *next;	
}*Link, LinkNode;
 
void start(Link &head)	//程序一开始读取文件里的数据
{
	char name[30], num[30];
	int score;
	Link newNode;
	head = new LinkNode;
	head->next = NULL;
	ifstream fin(filename, ios::in);
	if (fin.is_open())
	{
		while(fin >> name >> num >> score)
		{
			newNode = new LinkNode;
			strcpy(newNode->name, name);
			strcpy(newNode->num, num);
			newNode->score = score;
			newNode->next = head->next;
			head->next = newNode;
		}
	}
	fin.close();
}

void show(Link L)
{
	L = L->next;
	cout << "单链表信息如下:"  << endl;
	while(L)
	{
		printf("姓名：%s\t学号：%s\t成绩: %d\n", L->name, L->num, L->score);
		L = L->next; 
	}
	cout << endl;
}



int main()
{
	Link L;
	start(L);	
	show(L);

}
