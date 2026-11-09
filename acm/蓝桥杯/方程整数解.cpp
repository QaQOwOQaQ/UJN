#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

const int maxn = 50010;
int x1[50010],x2[50010];

int main()
{
	int a,b,c,d,sum,op;
	bool flag;
	while(scanf("%d",&d)!=EOF)
	{
		op = 0;
		flag = 0;
		memset(x1,0,sizeof(x1));
		memset(x2,0,sizeof(x2));
		for(int i=1;i*i<d;i++)
		{
			for(int j=i;j<d;j++)
			{
				sum = i*i + j; 
				if(sum == d)
				{
					x1[++op] = i;
					x2[op] = j;
				}
			}
		}
		
//		cout << "²âÊÔ" << endl;
//		for(int i=1;i<=op;i++)
//			cout << x1[i] << " " << x2[i] << endl;
//		cout << "²âÊÔ" << endl;
		
		for(int k=1;k<=op;k++)
		{
			for(int i=1;i*i<x2[k];i++)
			{
				for(int j=i;j*j<x2[k];j++)
				{
					sum = i*i + j*j;
					if(sum == x2[k])
					{
						if(x1[k]<=i && i<=j)
						{
//							cout << x1[k] << " " << i << " " << j << endl;
							printf("%d %d %d\n",x1[k],i,j);
							flag = 1;
													
						}
					
					}
	
				}
			}
		}
		if(!flag)
		printf("No Solution\n"); 
	}


	return 0;
	
 } 
