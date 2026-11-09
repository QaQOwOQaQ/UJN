#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;
ll ksm(ll a,ll b,ll p)
{
	ll ans = 1;
	while(b)
	{
		if(b & 1)
			ans = ans * a % p;
		b>>= 1;
		a = a * a % p;
	} 
	return ans;
}
int main()
{
	ll a,b,p,ans;
	cin >> a >> b >> p;
	ans = ksm(a,b,p);
	cout << a << "^" << b << " mod " << p << "=" << ksm(a,b,p) << endl;
//	cout << (3&1) << endl;
	return 0;
	
 } 
