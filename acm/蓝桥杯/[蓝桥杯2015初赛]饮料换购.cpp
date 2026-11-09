#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	int n,ans,ping;
	while(scanf("%d",&n) != EOF)
	{
		ans=n;
		ping=n;
		while(ping>=3)
		{
			int tmp=ping/3;
			ans+=tmp;
	//		cout<<"ans:"<<ans<<endl;
			ping=ping%3+tmp;
//			cout<<"ping:"<<ping<<endl;	
		}
	cout << ans << endl;
	}
	
	

	return 0;
	
 } 
