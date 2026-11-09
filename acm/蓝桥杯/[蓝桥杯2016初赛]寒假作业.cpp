#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#define ll long long

using namespace std;

int a[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};
int ans = 0;
int pd[13];

int check()
{
	if(a[0]+a[1]==a[2] && a[3]-a[4]==a[5] && a[6]*a[7]==a[8] && a[9]==a[11]*a[10])
		return 1;
	else
		return 0;
}

void dfs(int n)
{
	if(n == 13)
	{
		if(check())
			ans++;
		return ;
	}
	
	for(int i=1;i<=13;i++)
	{
		if(pd[i])
		{
			pd[i] = 1;
			a[i] = i;
			dfs(n+1);
			pd[i] = 0;
		}
	}
	return ;
}
int main()
{
	int op = 0;
	do{
		cout << op++ << endl;
		if(check())
			ans++;
	}while(next_permutation(a,a+13));
	
	cout << ans << endl;
	cout << clock() << "ms:" << endl;

	return 0;
	
} 
