#include<iostream>
using namespace std;
int ugly(int x)
{
	while(x%2==0) 
		x=x/2;
	while(x%5==0)
		x=x/5;
	while(x%3==0)
		x=x/3;
	if(x==1)
		return 1;
	else
		return 0;
}
;
int main()
{
	int sum=0,i,q;
	for(i=1;;i++)
	{
		sum=sum+ugly(i);
		if(sum==1500)
		{
			q=i;
			break;
		}
	}
	
	cout << "The 1500'th ugly number is <" << q<< ">.";
	return 0;
 } 
