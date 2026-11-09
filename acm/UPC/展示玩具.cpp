#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=5e4+1;
int s[N]; 
int main()
{
	int n,k;
	int sum=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s,s+n);
	for(int i=0;i<n;i++)
	{
		int j=i+1,ans=1;
		if(s[j]>=s[i] && j<n)
			while(s[j]-s[i]<=k&&j<n)
			{
				j++;
				ans++;
			}
		sum = max(sum,ans);
	}
	printf("%d\n",sum);
	return 0;
}
