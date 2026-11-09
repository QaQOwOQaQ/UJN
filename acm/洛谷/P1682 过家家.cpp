#include<iostream>
#include<algorithm>
#include<cstring>
#include<limits.h>

using namespace std;

int pre[600];	//女生的集合 
int sum[600];	//第i个女生的朋友数 
bool maps[600][600];
int ans = INT_MAX;
struct node
{
	int from,to;
};
struct node edge1[600],edge2[600];	//女生和男生，女生和女生 

void init(int n)
{
	for(int i=1;i<=n;i++)
		pre[i] = i;
}

int find(int i)
{
	if(pre[i] == i)
		return pre[i];
	return pre[i] = find(pre[i]);
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
	int n,m,k,f;
	cin >> n >> m >> k >> f;
	init(n);
	
	for(int i=1;i<=m;i++)
	{
		cin >> edge1[i].from >> edge1[i].to;
//		unite(edge1[i].from,edge1[i].to);		
	}

		
	for(int i=1;i<=f;i++)
	{
		cin >> edge2[i].from >> edge2[i].to;		
		unite(edge2[i].from,edge2[i].to);	
	}

	for(int i=1;i<=m;i++)
	{
		if(!maps[find(edge1[i].from)][edge1[i].to])
		{
			sum[find(edge1[i].from)]++;	
			maps[find(edge1[i].from)][edge1[i].to] = true;	
		}
	}
	
//	for(int i=1;i<=n;i++)
//		cout << sum[i] << " ";
//	cout << endl;
	
	for(int i=1;i<=n;i++)
	{
		if(sum[i])		
			ans = min(ans,sum[i]);
	}
	
	ans = min(ans+k,n);
	
	cout << ans << endl;
	return 0;
}




