#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

const int mod = 11;

int main()
{
	string s;
	getline(cin,s);
	int ans,cut = 1;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			ans+= (s[i]-'0') * cut++;
		}
	}
	ans = ans % mod;
	char ch;
	if(ans == 10)
		ch = 'X';
	else
		ch = ans + '0';
//	cout << ans;
	if(ch == s[12])
		cout << "Right";
	else
	{
		s[12] = ch;
		cout << s;
	}
	cout << endl;
	return 0;
	
 } 
