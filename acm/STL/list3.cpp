#include<iostream>
#include<list>
using namespace std;
list<int> q;
int main()
{
	int n,op,code;
	cin >> n;
	while(n--)
	{
		cin >> op;
		if(op == 1)	//left¡ªfront 
		{
			cin >> code;
			q.push_front(code);	
		}
		if(op == 2) //right-back
		{
			cin >> code;
			q.push_back(code);
		}
		if(op == 3)
		{
			cout << q.front() << endl;
			q.pop_front();
		}
		if(op == 4)
		{
			cout << q.back() << endl;
			q.pop_back();
		}
	}
		
} 
