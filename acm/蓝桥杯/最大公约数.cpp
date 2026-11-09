#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

ll yue(ll a,ll b)
{
	ll t;
	if(a<b)
	{
		t = a;
		a = b;
		b = t;
	}
	while(a%b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return b;
}
int main()
{
	ll a,b;
	while(~scanf("%lld%lld",&a,&b))
	{
		ll ans = a*b/yue(a,b);	
		printf("%lld\n",ans);
	} 

	return 0;
	
} 
