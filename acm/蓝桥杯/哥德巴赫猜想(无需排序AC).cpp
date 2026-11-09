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
		int p = 0,q = 0,flag = 1;
		while(!pd(n - su[p] - su[q]))
		{
			if(flag)
				p++,flag=0;
			else
				q++,flag=1;
			while(n - su[p] - su[q]<2)
				q--;
		}
		printf("%d %d %d\n",su[p],su[q],n - su[p] - su[q]);
	}


	return 0;
	
} 
