#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[1010];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		int sum = 0;
		double ans = 0;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+= a[i];		
		}
		sort(a,a+n,cmp);
		if(sum-a[0] <= a[0])
			ans = sum - a[0];
		else
			ans = sum * 1.0 / 2;
		printf("%.1f\n",ans);
	}

	return 0;
	
 } 
