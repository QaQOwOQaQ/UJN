#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	stack<char> q;
	string s;
	getline(cin,s);
	int len = s.length();
	int flat=1;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='['||s[i]=='{'||s[i]=='(')
			q.push(s[i]);
		if(s[i]==']'||s[i]=='}'||s[i]==')')
		{
			if(q.empty())
			{
				flat = 0;
				break;
			}	
			if((q.top()=='{'&&s[i]=='}')||(q.top()=='('&&s[i]==')')||(q.top()=='['&&s[i]==']'))	
				q.pop();
			else
			{
				flat = 0;
				break;
			}
		}
	}
		if(q.empty()&&flat)
			cout << "yes";
		else
			cout << "no" ;
	return 0;
}

