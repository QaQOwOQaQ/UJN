#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

ll n,c,l,r,mid;
ll a[1000010];

bool check(int d)
{
	int next,last = 1,k = 1;
	for(int i=2;i<=n;i++)
	{
		if(a[i] - a[last] >= d)
		{
			k++;
			last = i;
		}
	}
	if(k >= n)
		return true;
	else
		return false;
}
int main()
{
	cin >> n >> c;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);
	l = 1;
	r = a[n];
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
