#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;


int main()
{
	ll n,op;
	string s;
	for(ll i=1;;i++)
	{
		int flag=1;
		int num[10]={1,1,1,1,1,1,1,1,1,1};
		ll a=i*i;
		ll b=i*i*i;
		while(a)
		{
			int op = a%10;
			num[op]--;
			a=a/10;
		}
		while(b)
		{
			int op = b%10;
			num[op]--;
			b=b/10;
		}
		for(int i=0;i<=9;i++)
		{
			if(num[i]!=0)
				flag=0;	
		}		
		if(flag==1)
		{
			cout << i;
			return 0;
		}
	}

	return 0;
	
 } 
