#include<iostream>
using namespace std;
int fib(int n)
{
	int p=1,q=1;
	if(n>2)
	{
		for(int i=3;i<=n;i++)
		{
			int t=q;
			q=q+p;
			p=t;	
		}	
	}
	return q;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<fib(n)<<endl;
	 } 
	return 0;
 } 
