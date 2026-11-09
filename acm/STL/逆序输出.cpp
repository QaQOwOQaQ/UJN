#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int main()
{
	int n,a;
	while(cin>>n&&n)
	{
		while(n--)
		{
			cin>>a;
			s.push(a);
		}
		while(!s.empty())
		{
			cout << s.top() << " ";
			s.pop(); 
		}
		cout << endl; 
		
	}
	
	return 0;	
} 
