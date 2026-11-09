#include<bits\stdc++.h>
#include<stack>
using namespace std;
int main()
{	int n;
	char ch;
	cin >> n;
	getchar();	
	while(n--)
	{	
		stack <char> s;
		while(1)
		{
		ch = getchar();
		if(ch == ' ' || ch == '\n')
		{
			while(!s.empty())
			{
				cout << s.top();
				s.pop();
			}	
			cout << " ";
			if(ch == '\n')
				break;	
		}	
		else
			s.push(ch); 
		}	

		cout << endl;
	}


	return 0;
}
