#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

ll len,n,m;
ll a[50010]={0};
bool check(ll mid)
{
	ll last = 0,cut = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i] - a[last] < mid)	//需要移走石头 
			cut++;	
		else
			last = i;	
	}
	
	if(cut <= m)
		return true;
	else
		return false;	
}

int main()
{
	ll l,r,mid;
	cin >> len >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	l = 1;
	r = len;
	mid = l + (r - l) / 2;
	while(l <= r)
	{
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
		mid = l + (r - l) / 2;
	}
	cout << r << endl;
	

	return 0;
	
 } 
