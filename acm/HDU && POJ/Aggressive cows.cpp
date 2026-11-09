#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

ll n,m;	//n个牛栏,m头牛 
ll a[1000010];	//牛栏坐标 

bool check(ll mid)
{
	ll sum = 1,last = 0;
	for(int i=1;i<n;i++)
	{
		if(a[i] - a[last] >= mid)
		{
			sum++;
			last = i;
		}
	}
	if(sum >= m)
		return true;
	else
		return false;
}
int main()
{
	ll l,r,mid;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	l = 0;
	r = a[n-1];
	mid = l + (r - l) / 2;
	while(l <= r)
	{
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
		mid = l + (r - l) / 2;
	}
	printf("%lld\n",r);	//只能是R 
	return 0;	
	
 } 
