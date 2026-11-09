#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	string s;
	getline(cin,s);
//	cout << s;
	int ans = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] != ' ')
			ans++;	
	}	
	cout << ans << "\n";
	
	return 0; 
} 
