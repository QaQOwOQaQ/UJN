#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

const int maxn = 100010;
int pre[maxn],root[maxn];

struct Bridge
{
	int x,y;
	int day;
	Bridge(){ }
	Bridge(int a,int b,int c):x(a),y(b),day(c){ }
}bridge[maxn];

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

bool join(int x,int y)
{
	int fx = find(x),fy = find(y);
	if(fx == fy)
		return false;
	pre[fx] = fy;
	return true;
}

bool cmp(const Bridge x,const Bridge y)
{
	return x.day > y.day;
}



int main()
{
	int n,m,a,b,t;	//小岛的个数和桥的数量
	cin >> n >> m;
	init(n);
	for(int i=1;i<=m;i++)
	{
		cin >> a>> b >> t;
		bridge[i] = Bridge(a,b,t);
	}
	
	sort(bridge+1,bridge+1+m,cmp);
	
	int ans = 0,lastDay = 0;
	
	for(int i=1;i<=m;i++)
	{
		bool flag = join(bridge[i].x,bridge[i].y);
		if(flag && bridge[i].day != lastDay)
		{
			ans++;
			lastDay = bridge[i].day;
		}
	}
	cout << ans << endl;

	return 0;
	
 } 
