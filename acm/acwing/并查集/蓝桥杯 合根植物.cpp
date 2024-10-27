#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

const int maxn = 1000010;
int pre[maxn],root[maxn];

void init(int n)
{
	for(int i=1;i<=n;i++)
		pre[i] = i;
}

int find(int x)
{
	if(pre[x] == x)
		return x;
	return pre[x] = find(pre[x]);
}

void join(int x,int y)
{
	int fx = find(x),fy = find(y);
	if(fx != fy)
		pre[fx] = fy;
}


int main()
{
	int m,n,k,a,b;
	cin >> m >> n;
	init(m*n);
	cin >> k;
	
	for(int i=0;i<k;i++)
	{
		cin >> a >> b;
		join(a,b);
	}
	int ans = 0;
	for(int i=1;i<=m*n;i++)
		root[find(i)] = 1;
	for(int i=1;i<=m*n;i++)
		if(root[i])
			ans++;
	cout << ans << endl;
	

	return 0;
 } 

