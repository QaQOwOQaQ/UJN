#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	stack <char> s;
	string str;	
	int len = str.length();
	int flag = 1;
	cin >> str;
	for(int i=0;i<len;i++)
	{
		if(s.empty())
			s.push(str[i]);
		else
		{
			if(str[i] == s.top())
			{
				flag+=1;
				s.pop();
			}
			else
				s.push(str[i]);
		}
	}
	if(flag%2 == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
