#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

ll func(ll n)
{
	ll ans = -1;
	while(n != 1)
	{
		if(n & 1)
			n = n * 3 + 1;
		else
			n = n / 2;	
		ans = max(ans,n);
	}
	return ans;
}
int main()
{
	ll n;
	while(cin >> n)
	{
		ll res = 0;
		for(ll i=1;i<=n;i++)
		{
			res = max(res,func(i));
		}

		cout << res << endl;
	}

	return 0;
	
} 









