#include<iostream>
#include<stack>
using namespace std;
int main()
{	
	stack<int> q;
	int op;
	long long n;
	scanf("%lld",&n);
	while(n--)
	{
		cin >> op;
		if(op==1)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		if(op==2)
			q.pop();	
		if(op==3)
		{
			if(q.empty())
				printf("Empty!\n");
			else
				printf("%d\n",q.top());
		}			
	}	
	return 0;
}
