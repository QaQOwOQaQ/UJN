#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	ll ans = 0;
	ll a1,a2,n,d;
	cin >> a1 >> a2 >> n;
	d = a2 - a1;
	ans = n * a1 + n * (n-1) * d / 2;
	cout << ans << endl; 
	

	return 0;
	
 } 
