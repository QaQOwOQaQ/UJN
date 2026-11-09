#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

ll change(ll n)
{
	ll tmp,ans = 0;
	while(n)
	{
		tmp = n % 2;
		if(tmp==1)
			ans++;
		n /= 2;
	}
	return ans;
}
int main()
{
	ll n,ans;
	while(scanf("%lld",&n) != EOF)
	{
		ans = change(n);
		printf("%lld\n",ans);
		
	}
	return 0;
	
} 
