#include<iostream>
using namespace std;
#include<fstream>
#define filename "txt/booklist.txt"
#include<list>
#include<cstring>
#include<iomanip>
 
class Book	//创建Book类，存放图书信息
{
public:
	Book(string na=" ", int p=0, int n=0)
	{
		name = na;
		num = n;
		price = p;
	}
	void Show()
	{
		cout <<  "书名：" << std::left << setw(20) << name << std::right << setw(6) << "\t价格：" << price << "\t数量：" << num << endl;
	}
	void Set()
	{
		cout << "请输入书名:";
		cin >> name;
		cout << "请输入价格:";
		cin >> price;
		cout << "请输入数量:";
		cin >> num;
	}
	void Addnum()
	{
		int n;
		cout << "请输入归还的数量：";
		cin >> n;
		num += n;
	}
	void Borrownum()
	{
		int n;
		cout << "请输入借出的数量：";
		cin >> n;
		num -= n;
	}
public:
	string name;
	int price;
	int num;
};
 
void menu()
{
	cout << "--------------------------------------欢迎进入图书管理系统--------------------------------------" << endl;
	cout << endl << "0 - 退出系统；" << "1 - 显示库存；" << "2 - 查询图书；" << "3 - 借阅图书；" << "4 - 归还图书；" << "5 - 增加图书；" << "6 - 删除图书；" << endl;
}
 
class Booklist	//创建BookList类，数据成员有Book还有图书数量
{
public:
	void save()	//新建图书的话保存数据，用app方式打开文件
	{
		ofstream fout(filename, ios::app);
		list<Book>::iterator it = BList.begin();
		for (int i = 0; i < num-1; i++)	//偏移迭代器，指向新加入的Book并写入文件
		{
			it++;
		}
		for (; it != BList.end(); it++)
		{
			fout << (*it).name << ' ' << (*it).price << ' ' << (*it).num << '\n';
		}
		fout.close();
	}
	void resave()
	{
		ofstream fout(filename, ios::out);	//重新写入数据，因为删除了某个元素
		if (fout.is_open())
		{
			for (list<Book>::iterator it = BList.begin(); it != BList.end(); it++)
			{
				fout << (*it).name << ' ' << (*it).price << ' ' << (*it).num << '\n';
			}
		}
		fout.close();
	}
	void Show()
	{
		for (list<Book>::iterator it = BList.begin(); it != BList.end(); it++)
		{
			(*it).Show();
		}
	}
	void adddata()	//添加数据
	{
		Book B;
		B.Set();
		BList.push_back(B);
		num++;
	}
	void start()	//程序一开始读取文件里的数据
	{
		string na;
		int n;
		int p;
		ifstream fin(filename, ios::in);
		if (fin.is_open())
		{
			while (fin >> na >> p >> n)
			{
				Book B(na, p, n);
				BList.push_back(B);
				num++;
			}
		}
		fin.close();
	}
	void increase()
	{
		cout << "请输入书名：" << endl;
		string n;
		cin >> n;
		for (list<Book>::iterator it = BList.begin(); it != BList.end(); it++)
		{
			if ((*it).name == n)
				(*it).Addnum();
		}
		resave();
	}
	void decrease()
	{
		cout << "请输入书名：" << endl;
		string n;
		cin >> n;
		for (list<Book>::iterator it = BList.begin(); it != BList.end(); it++)
		{
			if ((*it).name == n)
				(*it).Borrownum();
		}
		resave();
	}
	void FindBook()
	{
		string name;
		cin >> name;
		for (list<Book>::iterator it = BList.begin(); it != BList.end(); it++)	//遍历整个list，所以符合关键字的都会被找到
		{
			int index = (*it).name.find(name);	//如果没找到返回值是一个很大的数
			if (index < (*it).name.length())
				(*it).Show();
		}
	}
	void DeleteBook()
	{
		string name;
		cout << "请输入书名：";
		cin >> name;
		int i = 0;
		for (list<Book>::iterator it = BList.begin(); it != BList.end();it++)
		{
			if ((*it).name == name)
				break;
			++i;
		}
		list<Book>::iterator it = BList.begin();
		advance(it, i);
		BList.erase(it);
		--num;
		resave();
	}
public:
	list<Book>BList;
	int num = 0;
};
 
int main()
{
	Booklist B1;
	B1.start();
	while (1)
	{
		menu();
		int key;
		cout << "请输入要进行的操作：";
		cin >> key;
		switch (key)
		{
		case 0:
			return 0;
			break;
		case 1:
			B1.Show();
			break;
		case 2:
			B1.FindBook();
			break;
		case 3:
			B1.decrease();
			break;
		case 4:
			B1.increase();
			break;
		case 5:
		{
			B1.adddata();
			B1.save();
			break;
		}
		case 6:
			B1.DeleteBook();
			break;
		}
 
	}
}
