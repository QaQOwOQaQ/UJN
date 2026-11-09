#include<iostream>
#include<cmath>
#define ll long long 
using namespace std;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m))
	{
	ll ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ans1+=min(i,j);
			ans2+=i*j;
		}
	}
	printf("%lld %lld\n",ans1,ans2-ans1);		
	}

	

	return 0;
	
} 
