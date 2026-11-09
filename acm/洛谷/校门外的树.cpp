#include<stack>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	stack <string> v;
	string s;
	while(cin >> s && s!="0")
	{
		v.push(s);
	}
	while(!v.empty())
	{
		cout << v.top() << " ";
		v.pop();
	}
	cout << endl;
	return 0;	
}
