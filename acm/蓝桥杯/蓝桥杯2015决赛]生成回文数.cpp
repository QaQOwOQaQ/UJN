#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;
int a[10010];

int pd(ll x)
{
	string s1,s2;
	s1 = to_string(x);
	s2 = s1;
	reverse(s1.begin(),s1.end());
	if(s1 == s2)
		return 1;
	else
		return 0;
}
int main()
{
	for(int i=10;i<=200;i++)
	{
		ll ans = i;
		ll tmp = 0;
		while(!pd(ans))  //不是回文数 
		{		
			tmp++;
			if(tmp > 30)
			{
				cout << i <<  endl;
				break;
			}
			
			int p = 0;
			ll add = 0;	//回文数的转置 
			ll sum = ans;	//保存原数 
			while(sum)
			{
				a[p++] = sum % 10;
				sum = sum / 10;
			} 
			for(int j=0;j<p;j++)
				add = add * 10 + a[j];
			ans = ans + add;
		}
	}

	return 0;
	
} 
