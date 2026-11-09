#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int a[10],tmp[10];
ll ans;
void dfs(int n)
{
	if(n == 10)
	{
		if(a[0]<min(a[1],a[2]) && 
		   a[1]<min(a[3],a[4]) && 
		   a[2]<min(a[4],a[5]) &&
		   a[3]<min(a[6],a[7]) &&
		   a[4]<min(a[7],a[8]) &&
		   a[5]<min(a[8],a[9]) )
		   	
		   ans++;	
		   return ;	
	}
	else
	{
		for(int i=0;i<=9;i++)
		{
			if(!tmp[i])
			{
				a[n] = i;
				tmp[i] = 1;
				dfs(n+1);
				tmp[i] = 0;
			}
		}
	}
	return ;
}
int main()
{

	dfs(0);
	
	cout << ans << endl;

	return 0;
	
} 
