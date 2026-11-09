#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

void solve(int x)
{
	if(x != 0)
	{
		int p = 1,q = 0;	//2^q
		printf("2");
		while(p <= x)
		{
			q++;
			p*= 2;
		}
		q--;
		if(q==0 || q==2)
			printf("(%d)",q);
		if(q >= 3)
		{
			printf("(");
			solve(q);	
			printf(")");
		} 
		x-= p / 2;
		if(x)
		{
			printf("+");
			solve(x);
		}
	}
} 
int main()
{
	int n;
	cin >> n;
	solve(n);
	return 0;
	
 } 
