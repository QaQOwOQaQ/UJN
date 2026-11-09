#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int a[100],b[100];
int func(int n)
{
	int ans = 0;
	int op = 0;
	while(n)
	{
		b[op++] = n % 10;
		n /= 10;
	}
	for(int i=0;i<op;i++)
		ans+= b[i] * b[i];
	return ans;
}

int main()
{
//	int n,ans;
//	cin >> n;
//	for(int i=0;i<20;i++)
//	{
//		ans = func(n);
//		cout << ans << endl;
//		n = ans;
//	}

	cout << 145 << endl;
	return 0;
	
} 

