#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001],b[1001];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char s[1001];
		scanf("%s",s);
		for(int i=0;i<n;i++)
		a[i]=s[i]-'0';
		scanf("%s",s);
		for(int i=0;i<n;i++)
		b[i]=s[i]-'0';
		
		sort(a,a+n);
		sort(b,b+n);
		int ans1=0,ans2=0;
		for(int i=0,j=0;i<n&&j<n;i++)
		{
			if(a[j]<=b[i])
			{
				ans1++;
				j++;
			}
		}
		ans1=n-ans1;//找到大于等于的最多数目，用n减去即是最小数目 
		for(int i=0,j=0;i<n&&j<n;i++)
		{
			if(b[i]>a[j])
			{
				j++;
				ans2++;
			}
		}
		printf("%d\n%d\n",ans1,ans2);
	}
}


