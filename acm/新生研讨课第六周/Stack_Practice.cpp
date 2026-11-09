#include<iostream>
#include<stack>
//遍历栈所有元素并输出！ 
using namespace std;
int main()
{	stack <int> st1;
	stack <int> st2;
//	if(st.empty())
//		cout << "empty" << endl;
	for(int i=1;i<=10;i++)
		st1.push(i);
	cout << "st1.size=" << st1.size() << endl;
	cout << "st1.top=" << st1.top() << endl;
	while(!st1.empty())
	{
		int a = st1.top();
		st2.push(a);
		st1.pop();
	}
	cout << "stack(st2)=";
	while(!st2.empty())
	{
		int a = st2.top();
		cout << a << " ";
		st1.push(a);
		st2.pop();
	}
	cout << endl;
	stack <int> st3;
	st3.push(1);
	st3.push(2);
	st3.push(4);
	while(!st3.empty())
	{	
		cout << "st3.top=" << st3.top() << endl;
		st3.pop();
	}

	return 0;
}
