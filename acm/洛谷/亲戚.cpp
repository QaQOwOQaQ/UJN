#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int pre[10010];

void init(int n)
{
	for(int i=1;i<=n;i++)
		pre[i] = i;
}

int find(int x)
{
	if(x == pre[x])	
		return pre[x];
	else
		return pre[x]=find(pre[x]);
}

void unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		pre[fx] = fy;
}

string isSame(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx == fy)
		return "Yes";
	else
		return "No";		
} 
int main()
{
	int n,m,x,y,z,p;
	cin >> n >> m >> p;
	init(n);
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		unite(x,y);
	}
	
	for(int i=0;i<p;i++)
	{
		cin >> x >> y;
		cout << isSame(x,y) << endl;
	}
	return 0;
	
} 
