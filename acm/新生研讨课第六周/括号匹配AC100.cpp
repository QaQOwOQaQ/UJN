#include<iostream>
#include<stack>
#include<string> 
using namespace std;
int main()
{
//	while(1)
//	{
		int flag=1;
		string s;
		stack<char>st;
		getline(cin,s);
		int len = s.length();
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='{'||s[i]=='['||s[i]=='(')
				st.push(s[i]);
			if(s[i]=='}'||s[i]==']'||s[i]==')')
			{
				if(st.empty())
				{
					flag = 0;
					break;
				}
				if((st.top()=='{'&&s[i]=='}')||(st.top()=='('&&s[i]==')')||(st.top()=='['&&s[i]==']'))
                    st.pop();
				else
				{
					flag = 0;
					break;
				}
			}
		}
		if(st.empty()&&flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;


//	}

}
