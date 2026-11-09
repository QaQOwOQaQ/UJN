#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int statistic(int num)
{
	int ans = 0;
	while(num)
	{
		if(num%10==2)
			ans++;
		num/= 10;
	}
	return ans;
}
int main()
{
	int l,r,ans = 0; 
	cin >> l >> r;
	for(int i=l;i<=r;i++)
		ans+= statistic(i);
	cout << ans << endl;

	return 0;
	
 } 
