#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	int l,r,ans = 0;
	cin >> l >> r;
	string s="";
	for(int i=l;i<=r;i++)
	{
		s+= to_string(i);
	}
//	cout << s;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='2')
			ans++;
	}
	cout << ans << endl;
	return 0;
	
 } 
