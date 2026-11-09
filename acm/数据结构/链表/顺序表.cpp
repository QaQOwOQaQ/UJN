#include<iostream>
#include<stdlib.h>    
#include<string>    
#include<algorithm>

using namespace std;

int len = 10;

struct stu
{
    string num;    //学号
    string name;    //姓名
    string cls;    //作班级
    int age;
}p[100];

void creat()            
{
    cout << "请输入10个学生信息:" << endl;
    for(int i=0;i<len;i++)
        cin >> p[i].num >> p[i].name >> p[i].cls >> p[i].age;
}

void print()
{
    cout << "学生信息如下:" << endl;
     for(int i=0;i<len;i++)
        cout << p[i].num << " " << p[i].name << " " << p[i].cls << " " << p[i].age << endl;    
}    

void insert()    
{
    int j = len++;
    cin >> p[j].num >> p[j].name >> p[j].cls >> p[j].age; 
	print();   
}

void deleteNode(string s)    
{
    for(int i=0;i<10;i++)
    {
        if(s == p[i].num)    //找到要删除的同学了
        {
            len--;
            cout << "找到要删除的同学了" << endl;
            for(int j=i;j<10;j++)
            {
                p[j].num = p[j+1].num;
                p[j].name = p[j+1].name;
                p[j].cls = p[j+1].cls;
                p[j].age = p[j+1].age;                    
            }
            return ;
        }
    }    
    cout << "要删除的信息不存在!" << endl;
}

void find(string s)
{
    for(int i=0;i<10;i++)
    {
        if(s == p[i].num)
        {
            cout << "找到了,学生信息如下:" << endl;
            cout << p[i].num << " " << p[i].name << " " << p[i].cls << " " << p[i].age;    
            cout << endl;
            return ;
        }
    }
    cout << "没找到！" << endl;
}


int main()
{
	string s;
//    creat();
    for(int i=0;i<10;i++)
    {
    	p[i].num = to_string(i);
    	p[i].age = 18;
    	p[i].cls = "计数20H3";
		p[i].name = "小" + to_string(i); 
	}
	print();
    cout << "请输入要插入同学的信息" << endl;
	insert();
    cout << "请输入要退学同学的学号" << endl;
    cin >> s;
    deleteNode(s);
    print();
    cout << "请输入要查找同学的学号" << endl;
    cin >> s;
    find(s); 
    return 0;
}
