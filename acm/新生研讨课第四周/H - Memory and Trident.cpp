#include<bits/stdc++.h>
using namespace std;
int main()
{	string S;
	int s=0,x=0,z=0,y=0;
	getline(cin,S);
	int len,n;
	len=S.length();
	if(len%2!=0)
		cout << -1;
	else
	{
		for(int i=0;i<len;i++)
			if(S[i]=='U')
				s++;
			if(S[i]=='D')
				x++;
			if(S[i]=='L')
				z++;
			if(S[i]=='R')
				y++;
		}
		int sum1=0,sum2=0;
		if(s>=x)
			sum1=s-x;
		else
			sum1=x-s;
		if(z>=y)
			sum2=z-y;
		else
			sum2=y-z;
		n = (sum1+sum2) / 2;
		cout << n;
		
	}
	return 0;
}
