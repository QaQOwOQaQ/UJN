#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int c[5],d[5];
	char a[40],b[40];
	int t,qt=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",&a,&b);
		int indexc = 0,sum = 0;
		int lena = strlen(a);
		for(int i=0;i<lena;i++)
		{
			if(a[i] == '.' || a[i] == lena)
			{
				c[indexc++]=sum;
				sum=0 ;
			}
			else
				sum = sum*10+a[i]-'0';
		}
		int indexd=0,q=1;
		sum=0;
		int lenb=strlen(b);
		for(int i=lenb-1;i>=-1;i--)
		{
			if(b[i] == '.' || i == -1)
			{
				d[indexd++] = sum;
				sum = 0;
				q = 1;	
			}
			else
			{
				sum = sum + (b[i]-'0') * q;
				q = q*2;
			}
		}
		int i;
		for(i=0;i<4;i++)
			if(c[i] != d[3-i])
				break;
		printf("Case %d: ",qt++);
		if(i == 4)
			printf("Yes\n");
		else
			printf("No\n");
		
	}
}
