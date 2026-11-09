#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{	
	stack <int> s;
	string str;
	cin >> str;
	int len=str.length();
	int flag=1;
	for(int i=0;i<len;i++)
	{
		if(s.empty())
			s.push(str[i]);
		else
		{
			if(s.top()==str[i])
			{
				flag++;
				s.pop();
			}
			else
			s.push(str[i]);
		}
		
	}
	if(flag%2==0)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
