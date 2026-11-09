#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int su[50010];
int pd(int n)
{
	for(int i=2;i<n;i++)
	{
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	int n;
	int op1 = 0;
	for(int i=2;i<=20010;i++)
	{
		if( pd(i) )
			su[op1++] = i;
	}	

	while(scanf("%d",&n)!=EOF)
	{
		int ans[3]={0};
		int flag = 1;
		while(!pd(n - su[ans[0]] - su[ans[1]]))
		{
			if(ans[1]<op1)
				ans[1]++;
			else
				ans[0]++;
			while(n - su[ans[0]] - su[ans[1]]<2)
				ans[1]--,ans[0]++;
		}
		ans[0] = su[ans[0]];
		ans[1] = su[ans[1]];
		ans[2] = n - ans[0] - ans[1];
		sort(ans,ans+3);
		printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		
	}


	return 0;
	
} 
