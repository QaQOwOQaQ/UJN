#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
	int n;
	stack <char> st;
	string s;
	cin >> n;	
	getchar();
	for(int j=0;j<n;j++)
	{
		getline(cin,s);
		//cout << "len:" << s.length() << endl;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==' ')
			{
				while(!st.empty())
				{
					cout << st.top();
					st.pop();					
				}
				cout << " ";
			}
			else
				st.push(s[i]);
		}
		while(!st.empty())
		{
			cout << st.top();
			st.pop();				
		}
		cout << endl;
	}
	return 0;
}
