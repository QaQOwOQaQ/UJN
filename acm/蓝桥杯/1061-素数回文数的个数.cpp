#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

bool su(int x)
{
	for(int i=2;i<=x-1;i++)
		if(x%i==0)
			return false;
	return true;
}

bool huiwen(int x)
{
	string s1,s2;
	s1 = to_string(x);
	s2 = s1;
	reverse(s1.begin(),s1.end());
	if(s1 == s2)
		return true;
	else
		return false;
}
int main()
{
	int l,r,ans = 0;
	cin >> l >> r;
	for(int i=l;i<=r;i++)
	{
		if(su(i) && huiwen(i))
			ans++;
	}
	cout << ans << endl;

	return 0;
	
} 
