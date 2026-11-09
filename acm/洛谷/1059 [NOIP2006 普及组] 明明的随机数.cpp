#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[100];

int main()
{
	int n,ans = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	a[0] = 1001;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			ans++;
	}
	cout << ans << endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			cout << a[i] << " ";
	}
	cout << endl;

	return 0;
	
 } 
