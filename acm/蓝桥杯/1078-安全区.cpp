#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int a[110][110],b[110][110];
int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int n,m,l,r,d,ans = 0;
	scanf("%d%d",&n,&m);
	
	for(int k=0;k<m;k++)
	{
		scanf("%d%d%d",&l,&r,&d);
		for(int i=max(1,l-d);i<=min(l+d,n);i++)
		{
			for(int j=max(1,r-d);j<=min(r+d,n);j++)
			{
				int len = (i-l)*(i-l)+(j-r)*(j-r);
				if(len <= d*d)
					a[i][j]=1;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	

	

	return 0;
	
} 
			if(a[i][j] == 0)
				ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
	
} 
