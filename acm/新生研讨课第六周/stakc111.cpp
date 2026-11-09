#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack<char> q;
	string s;
	getline(cin,s);
	int flat=0;
	//abacaba
	for(int i=0;i<s.length();i++)
	{
		if(q.empty())
			q.push(s[i]);
		else
		{
			if(s[i]==q.top())
			{
				q.pop();
				flat++;
			}
			else
			q.push(s[i]);
		}
	}
	if(flat%2==0)
		cout << "No";
	else
		cout << "Yes";
	return 0;
} 
