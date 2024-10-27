#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

const int maxn = 50010;
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
	else
		return pre[x] = find(pre[x]);
}

void join(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		pre[fx] = fy;
}
int main()
{
	int n,m,a,b,c,d,q;
	cin >> n >> m;
	init(n);
	for(int i=1;i<=m;i++)
	{
		cin >> a >> b;
		join(a,b);
	}
	cin >> q;
	for(int i=1;i<=q;i++)
	{
		cin >> c >> d;
		if(find(c) == find(d))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}

	return 0;
	
 } 
