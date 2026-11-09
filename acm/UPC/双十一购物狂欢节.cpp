#include<iostream>
#include<cmath>
using namespace std;
int main()
{//80-90-60-45
	int a,b,ans=0;
	cin >> a >> b;
	if(a>=b)
	{
		if(b>=50)
			ans=80*b+60*(a-b);
		else
			ans=90*b+60*(a-b)	;
	}
	else
	{
		if(a>=50)
			ans=80*a+45*(b-a);
		else
			ans=90*a+45*(b-a);
	}
	
	cout << ans;
	return 0;
 } 
