#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 1000007
#define ll long long

using namespace std;

int pre[maxn],book[maxn];
 
void init(int n)
{
	for(int i=1;i<=n;i++)	//init要从0开始,不然 
		pre[i] = i;
}

int find(int x)
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

struct node
{
	int l,r,v;
}a[maxn];

bool cmp(const node &a,const node &b)
{
	return a.v > b.v;
}
int main()
{
	int t,n,cut,tmp,flag;
	scanf("%d",&t);
	while(t--)
	{	
		//初始化 
		scanf("%d",&n);
		cut = 0;
		flag = 1;
		memset(a,0,sizeof(a));
		memset(book,0,sizeof(book));
		init(maxn);
		
		//离散化 
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
			book[++cut] = a[i].l;
			book[++cut] = a[i].r;
		}
		sort(book+1,book+cut+1);
		tmp = unique(book+1,book+cut+1) - book - 1;
		for(int i=1;i<=n;i++)
		{
			a[i].l = lower_bound(book+1,book+tmp+1,a[i].l) - book;
			a[i].r = lower_bound(book+1,book+tmp+1,a[i].r) - book;
		}
		
		//排序，先联合，后判断 
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[i].v)
				unite(a[i].l,a[i].r);
			else
			{
				if(find(a[i].l) == find(a[i].r))
				{
					flag = 0;	
					printf("NO\n");	
					break;	
				}	
			}	
		}	
		if(flag)
			printf("YES\n");

	}

	return 0;
	
} 
