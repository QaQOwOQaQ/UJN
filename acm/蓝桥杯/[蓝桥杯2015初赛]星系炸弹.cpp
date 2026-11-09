#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int rui(int y)
{
	if(y%400==0 || (y%4==0&&y%100!=0))
		return 1;
	else
		return 0;
}
int main()
{
	int y,m,d,n;
	bool flag;
	while(scanf("%d%d%d%d",&y,&m,&d,&n) != EOF)
	{
			flag=1;
			d+=n;
			while(flag)
			{	
	
				if(m == 2)
				{
					if(rui(y))	//29
					{
						if(d>29)
						{
							d-=29;
							m++;
						}
						else
							flag=0;
					}
					else	//28
					{
						if(d>28)
						{
							d-=28;
							m++;
						}
						else
							flag=0;
					}
				}
				else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)//31
				{
					if(d>31)
					{
						d-=31;
						m++;
					}
					else
						flag=0;
				}
				else //30
				{
					if(d>30)
					{
						d-=30;
						m++;
					}
					else
						flag=0;
				}
				if(m == 13)
				{
					m = 1;
					y++;	
				} 
							
		}
		printf("%04d-%02d-%02d\n",y,m,d);
	}
		

	return 0;
	
 } 
