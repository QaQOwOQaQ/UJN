#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<limits.h>
#define maxn 1000007
#define ll long long

using namespace std;

int pre[510];

struct node
{
	int l,r;
}a[510*510];

struct kkk
{
	int st,ed;	
	ll len;	//记录节点st到节点ed的最近距离 
}num[510*510];

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
		return 1;		
	}
	return 0;

}

bool cmp(const kkk &a,const kkk &b)
{
	return a.len < b.len;
}
int main()
{
	int s,p,cut,ans = 0;
	scanf("%d%d",&s,&p);
	cut = p - s ; 	//还要修的路数 
	for(int i=1;i<=p;i++)
		pre[i] = i;
	for(int i=1;i<=p;i++)	
		scanf("%d%d",&a[i].l,&a[i].r);
	
	int op = 0;
	for(int i=1;i<=p;i++)
	{
		num[i].len = 10000010;
		for(int j=1;j<=p;j++)
		{
			ll tmp = pow(a[i].l-a[j].l,2) + pow(a[i].r-a[j].r,2);
			if(tmp < num[i].len && tmp)
			{
				op++;
				num[op].st = i;
				num[op].ed = j;	
				num[op].len = tmp;			
			}
		}
	}

	sort(num+1,num+op,cmp);
	
//	for(int i=1;i<=p;i++)
//		cout << num[i].st << " " << num[i].ed << " " << num[i].len << endl; 

	for(int i=1;i<=op;i++)
	{
		if(cut == 0)
			break;
		cut-= unite(num[i].st,num[i].ed);
		ans = num[i].len;
	}
		
	printf("%.2f",sqrt(ans));
	
	return 0;
	
} 
