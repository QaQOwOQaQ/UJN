#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int b[2][5];
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int ans=0;
	do
	{
		memset(b,0,sizeof(b));
		int op=0,flag=1;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=5;j++)
			{
				b[i][j]=a[op++];
			}
		}
		for(int i=2;i<=5;i++)
		{
			if(b[1][i]<b[1][i-1] || b[2][i]<b[2][i-1])
			{
				flag=0;break;
			}
		}
		for(int i=1;i<=5;i++)
		{
			if(b[1][i]>b[2][i])
			{
				flag=0;break;
			}
		}
		if(flag)
			ans++;
	}
	while(next_permutation(a,a+10));
	
	cout << ans << endl;
	return 0;
	
 } 
