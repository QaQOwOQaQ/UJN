#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 1000007
#define ll long long

using namespace std;

int pre[maxn];

struct node
{
	int l,r,v;
	node() {}
	node(int a,int b,int c) : l(a),r(b),v(c) {}
}a[maxn];

bool cmp(const node &a,const node &b)
{
	return a.v > b.v;
}

void init(int n)
{
	for(int i=1;i<=n;i++)
		pre[i] = i;
}

int find(ll x)
{
	if(pre[x] == x)
		return x;
	else
		return pre[x] = find(pre[x]);
}

void unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		pre[fx] = fy;			
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init(maxn);
		int n;
		scanf("%d",&n);
		for(ll p=1;p<=n;p++)
		{
			cin >> a[p].l >> a[p].r >> a[p].v;	
			if(a[p].v == 1)
				unite(a[p].l,a[p].r);		
		}
		
		//
//		cout << "op" << endl;
//		for(ll i=1;i<=n;i++)
//			cout << find(i) << " ";
//		cout << endl << "op" << endl;
		//
		int flag = 1;
		for(int i=1;i<=n;i++)
		{
			if(find(a[i].l)==find(a[i].r) && !a[i].v)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	

	return 0;
	
} 
