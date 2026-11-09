#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int n,a[10010]={0},s[10010]={0};
const int mod = 998244353;

//每一次的阶乘都是在上一次阶乘的基础上乘x，可以减少运算，提高效率
void multi(int x)
{
	int g=0;
	for(int i=10000;i>=0;i--)
	{
		a[i]=a[i]*x+g;
		g=a[i]/10;
		a[i]=a[i]%10;
	}
}
void sum()
{
	int g=0;
	for(int i=10000;i>=0;i--)
	{
		s[i]=s[i]+a[i]+g;
		g=s[i]/10;
		s[i]=s[i]%10;
	}
}
ll out()
{
	int w;
	ll sum=0;
	for(int i=0;i<=10000;i++)
	{
		if(s[i]!=0)
		{
			w=i;
			break;
		}
	}
	for(int i=w;i<=10000;i++)
		sum = (sum*10+s[i]) % mod;
	
	return sum;

}
int main()
{
	scanf("%d",&n);
	s[10000]=a[10000]=1;
	for(int i=2;i<=n;i++)
	{
		multi(i);    //求i的阶乘和
		sum();    //将i的阶乘和加到结果数组s
	}
	ll ans = out();
	printf("%lld\n",ans);
	return 0;
}


