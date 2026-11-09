#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int n,x;
ll ans[31];

void f(int n,int x)
{
	ans[0] = 1;
	for(int i=1;i<=n;i++)
		ans[i] = ans[i-1]*(x+1);

	
}
int main()
{
	cin >> n >> x;
	f(n,x);
//	for(int i=0;i<=n;i++)
//		cout << ans[i] << endl;
	cout << ans[n] << endl;
	

	return 0;
	
} 
