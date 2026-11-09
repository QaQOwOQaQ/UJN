#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int found(int n,int x)
{
	int ans = 0;
	while(n)
	{
		int t = n % 10;
		if(t == x)
			ans++;
		n /= 10;
	}
	return ans;
}
int main()
{
	int n,x;
	cin >> n >> x;
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		ans += found(i,x);
	}
	cout << ans << endl;

	return 0;
	
 } 
