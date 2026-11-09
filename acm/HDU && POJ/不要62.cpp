#include<iostream>
#include<cmath>
#include<cstring>
#include<string>

int a[1000010];
int func(int n)
{
	while(n)
	{
		if(n%10==4 || n%100==62)	//找到了 
			return 0;
		n/=10;
	}
	return 1;	//没找到 
}

using namespace std;

int main()
{
	int n,m;
	for(int i=1;i<=1000010;i++)
		a[i] = a[i-1]+func(i);
	while(scanf("%d%d",&n,&m) != EOF)	
	{
		if(n==0 && m==0)
			break;	
		printf("%d\n",a[m]-a[n-1]);
	}


	return 0;
}

