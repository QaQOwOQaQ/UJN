#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 2000007
#define ll long long

using namespace std;

int pre[maxn];

int main()
{
	int n,cut = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> pre[i];	
	for(int i=1;i<=n;i++)
	{
		cut++;
		pre[i] = pre[pre[i]];
		if(pre[i] == i)
		{
			cout << cut << endl;
			return 0;
		}
	}
	

	return 0;
	
} 
