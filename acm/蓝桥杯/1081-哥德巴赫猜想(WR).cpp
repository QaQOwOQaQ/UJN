#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int n;
int su[50010],un[50010];
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
	int op1 = 0;
	for(int i=2;i<=20010;i++)
	{
		if( pd(i) )
			su[op1++] = i;
	}
	
	int op2 = 0;
	for(int i=2;i<=20010;i++)
	{
		if( pd(i)==0 )
			un[op2++] = i;
	}
	

	while(scanf("%d",&n)!=EOF)
	{
		int flag = 1;
		int a = 0,b = 0,c = 0;
		for(int i=0;i<op1&&flag;i++)
		{
			for(int j=0;j<op2&&flag;j++)
			{
				if(su[i]+un[j] == n)
				{
					a = su[i];
					b = un[j];
					flag = 0;	
				}
			}
		}
		flag = 1;
		for(int i=0;su[i]<b&&flag;i++)
		{
			for(int j=0;su[j]<b&&flag;j++)
			{
				if(su[i]+su[j]==b)
				{
					b = su[i];
					c = su[j];
					flag = 0;
				}
			}
		}
		printf("%d %d %d\n",a,b,c);
	}
	
	return 0;
	
} 
