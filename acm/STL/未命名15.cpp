#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack <string> s1;  //input
stack <string> s2;	//output
int main()
{	int n,len;
	string op;	
	cin >> n;
	while(n--)
	{
		cin >> op;
		if(op == "cd")
		{
			string a,now="";
			cin >> a;
			len = a.length();
			a[len++] = '/';
			//a[len] = '\0';
			for(int i=0;i<len;i++)
			{
				now += a[i];
				if(a[i] == '/')
				{
					if(now == "/")
					{
						while(!s1.empty())
							s1.pop();
					}
					else if(now == "../")
					{
						if(!s1.empty())
							s1.pop();
					}
					else
					{
						s1.push(now);
					}
					now = "";
				}	
			}
		}
		if(op == "pwd")
		{
			cout << "/";
			while(!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
			while(!s2.empty())
			{
				cout << s2.top();
				s1.push(s2.top());
				s2.pop();
			}	
			cout << endl;		
		}
	}
	return 0;
}
