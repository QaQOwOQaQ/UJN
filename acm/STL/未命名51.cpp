#include<iostream>
using namespace std;
int main()
{
	int a,count=0;
	while(cin>>a)
	{
		if(a==6)
			count++;	
		if(a!=6||count==3)
			break;
	} 
		if(count==0)
		cout << "0";
		if(count==1)
		cout << "10";
		if(count==2)
		cout << "100";
		if(count==3)
		cout << "1000";
	
	return 0;
 } 
