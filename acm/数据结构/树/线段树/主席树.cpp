#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

const int maxn = 5e6 + 10;

struct zxs
{
	int l,r,v;	
}t[maxn * 20];

int a[maxn],node[maxn];//node[i]为i版本的根编号，刚开始编号为0 
int top;

int copy(int node)	//新建节点
{
	top++;
	t[top] = t[node];	//全部信息都传到新节点
	return top;
}

int build(int root,int l,int r)	//建树其实就是新建节点的过程
{
	root = ++top;
	if(l == r)
	{
		t[root].v = a[l];
		return root;
	}
	int m = (l+r)>>1;
	t[root].l = build(t[root].l,l,m);
	t[root].r = build(t[root].r,m+1,r);
	return root;
}

int update(int root,int l,int r,int loc,int val)
{
	root = copy(root);	//更新就要新建节点 
	if(l == r)
		t[root].v = val;
	else
	{
		int m = (l+r)>>1;
//如果要更新的树不是单独节点的树，逐层递归，寻找需要修改的节点以减少空间 
		if(loc <= m)
			t[root].l = update(t[root].l,l,m,loc,val); 
		else
			t[root].r = update(t[root].r,m+1,r,loc,val);
	}
	return root;
}

int query(int root,int l,int r,int loc)
{
	if(l == r)
		return t[root].v;
	int m = (l+r)>>1;
	if(loc <= m)
		return query(t[root].l,l,m,loc); 
	else
		return query(t[root].r,m+1,r,loc);
}

int main()
{
	int n,k,ver,op,loc,val,res;
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]);
		
	node[0] = build(0,1,n);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d", &ver, &op, &loc);
		if(op == 1)	//修改 
		{
			scanf("%d", &val);
			node[i] = update(node[ver],1,n,loc,val);	//修改版本 
		}
		else	//查询 
		{
			res = query(node[ver],1,n,loc);
			printf("%d\n", res);
			node[i] = node[ver];	//保存版本 
		}
	}

	return 0;
	
} 
