#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,sum,count=0;
	while(cin >> n)
	{
		if(n==6)
			count++;
		else
			break;
		if(count==3)
			break;
	}
	
	sum = pow(10,count);
	if(sum==1)
		cout << "0";
	else
		cout << sum;
	return 0;
 } 
