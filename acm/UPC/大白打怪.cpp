#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,ans=0;
	while(cin>>n)
	{
		ans=3*(n/4)+(n-n/4);
		cout << ans << endl;
	}
	
	return 0;
 } 
