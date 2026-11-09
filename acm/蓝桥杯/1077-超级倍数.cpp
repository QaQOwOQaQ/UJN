#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int n;
int pd(int x)
{
	int a = (x - x % 100) / 100;
	int b = x % 10000 / 10;
	int c = x % 1000;
	if(x%n==0 && a%n==0 && b%n==0 && c%n==0)
		return 1;
	else
		return 0;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		bool flag = false;
		for(int i=10000;i<=99999;i++)
		{
			if(pd(i))
			{
				flag = true;
				printf("%d\n",i);
			}		
		}
		if(!flag)
			printf("No\n");
		printf("\n");		
	}
	return 0;
	
} 
