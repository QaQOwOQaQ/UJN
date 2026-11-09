#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int a[10010],n;

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		int t,ans = 0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			if(i != a[i])
			{
				swap(a[i],a[a[i]]);
				ans++;
			}
		}	
			
		printf("%d\n",ans);
	}
	return 0;
	
} 
