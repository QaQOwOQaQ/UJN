#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack<char> q;
	string s;
	int flag==1; //∆•≈‰ 
		getline(cin,s);
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='{'||s[i]=='['||s[i]=='(')
				q.push(s[i]);
			else
			{
				if(q.empty())
					{
						flag == 0;
						break;
					}				
				else if((q.top()=='{'&&s[i]=='}')||(q.top()=='('&&s[i]==')')||(q.top()=='['&&s[i]==']'))
					q.pop();
				else
					{
						flag == 0;
						break;
					}
			}	
		}
		if(q.empty()&&flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	

	return 0;
} 
