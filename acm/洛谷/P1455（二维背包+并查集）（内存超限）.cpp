#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 10007
#define ll long long

using namespace std;

ll pre[maxn];
ll dp[10007][5007];
struct node
{
	ll p,v;
};

bool cmp(const node &a,const node &b)
{
	return a.p > b.p; 
}
struct node a[maxn],b[maxn];
void init(ll n)
{
	for(ll i=1;i<=n;i++)
		pre[i] = i;
}

ll find(ll x)
{
	if(pre[x] == x)
		return x;
	else
		return pre[x] = find(pre[x]); 
}

void unite(ll x,ll y)
{
	ll fx = find(x);
	ll fy = find(y);
	if(fx != fy)
		pre[fx] = fy;
}

int main()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(dp,0,sizeof(dp));
	ll n,m,w,x,y;
	cin >> n >> m >> w;
	init(n);
	for(ll i=1;i<=n;i++)
	{
		cin >> a[i].p >> a[i].v;
	}
	for(ll i=1;i<=m;i++)
	{
		cin >> x >> y;
		unite(x,y);
	}
	
//	for(int i=1;i<=n;i++)
//		cout << find(i) << " ";
//	cout << endl;
	
	for(int i=1;i<=n;i++)
	{
		b[find(i)].p+= a[i].p;
		b[find(i)].v+= a[i].v;				
	}
	
	sort(b+1,b+1+n,cmp);
		
	int tmp;
	for(tmp=1;tmp<=n;tmp++)
	{
		if(b[tmp].p == 0)
		{
			break;
		}
	}
	tmp--;

	for(int i=1;i<=tmp;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(j < b[i].p)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-b[i].p]+b[i].v);
		}
	}
	cout << dp[tmp][w] << endl;
	
	return 0;
	
} 
