#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 100007
#define ll long long

using namespace std;
//时间复杂度优化的 
int pre[maxn];

struct node
{
	int l,r,v;
	node() {}
	node(int a,int b,int c) : l(a),r(b),v(c) {}
}a[maxn*40];

bool cmp(const node &a,const node &b)
{
	return a.v < b.v;
}

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

int unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		pre[fx] = fy;
//		cout << "1" << endl;
		return 1;		
	}
	return 0;

}

int main()
{
	int n,m,res;
	scanf("%d%d",&n,&m);
	init(n);
	res = n;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		res-= unite(a[i].l,a[i].r);
		if(res == 1)
		{
			printf("%d\n",a[i].v);			
			return 0;
		}

	}	
	printf("-1\n");
	return 0;
	
} 
