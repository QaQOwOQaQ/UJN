#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#define ll long long

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int flag = 1;
		for(int a=0;a*a<=n && flag;a++)
		{
			for(int b=a;a*a+b*b<=n && flag;b++)
			{
				for(int c=b;a*a+b*b+c*c<=n && flag;c++)
				{
					int d = floor(sqrt(n-a*a-b*b-c*c));
					if(d*d == n-a*a-b*b-c*c)
					{
						printf("%d %d %d %d\n",a,b,c,d);	
						flag = 0;
					}	
				}	
			}	
		}	
	}
	return 0;
	
} 
