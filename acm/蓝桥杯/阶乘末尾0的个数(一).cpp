#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long
using namespace std;

int n;
int a[101],s[101];
void multi(int x)
{
	int jw = 0;
	for(int i=100;i>=0;i--)
	{
		a[i] = a[i]*x + jw;
		jw = a[i] / 10;
		a[i] = a[i] % 10;
	}
}

void sum()
{
	int jw = 0;
	for(int i=100;i>=0;i--)
	{
		s[i] = s[i] + a[i] + jw;
		jw = s[i] / 10;
		s[i] = s[i] % 10;
	}
}

void out()
{
	int j;
	for(j=0;j<=100;j++)
	{
		if(s[j] != 0)
			break;
	}
	for(;j<=100;j++)
		printf("%d",s[j]);
	printf("\n");
}
int main()
{	
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		a[100]=s[100] = 1;
		for(int i=2;i<=n;i++)
		{
			multi(i);
			sum();
		}
		out();
	}

	return 0;
	
} 
