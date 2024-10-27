#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long
#define maxn 1000007

using namespace std;

struct node
{
	int l,r,dis;
}a[maxn*10];

struct kkk
{
	int dis,v,op;
}b[maxn*10];

int pre[maxn],depth[maxn],ans[maxn];

void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		pre[i] = i;
		depth[i] = 1;
	}
}

int find(int x)
{
	if(pre[x] == x)
		return x;
	return pre[x] = find(pre[x]);
}
void unite(int x,int y)
{
	int fx = find(x),fy = find(y);
	if(fx != fy)
	{
		pre[fx] = fy;	
		depth[fy]+= depth[fx];
	}

}

bool cmp1(const node &x,const node &y)
{
	return x.dis > y.dis;
}

bool cmp2(const kkk &x,const kkk &y)
{
	return x.dis > y.dis;
}

int main()
{	
	int n,q;
	cin >> n >> q;
	
	//初始化 
	init(n);
	for(int i=1;i<=n-1;i++)
		cin >> a[i].l >> a[i].r >> a[i].dis;
	for(int i=1;i<=q;i++)
	{
		cin >> b[i].dis >> b[i].v;	
		b[i].op = i;	
	}

	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+q,cmp2);
	
	//离线操作
	int tmp = 1;
	for(int i=1;i<=q;i++)
	{
		int dis = b[i].dis;
		int v = b[i].v;
		while(tmp<n && a[tmp].dis>=dis)
		{
			unite(a[i].l,a[i].r);
			tmp++;
		}
		ans[b[i].op] = depth[find(v)] - 1;
	} 
	
	for(int i=1;i<=q;i++)
		cout << ans[i] << endl;
	cout << endl;
	
	

	return 0;
	
 } 
