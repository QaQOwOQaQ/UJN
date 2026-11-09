#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

struct node
{
	double l;
	double r;
}a[1010];

bool cmp(const node &x,const node &y)
{
	return x.l < y.l;
}
int main()
{
	int n,d,ans,x,y,op = 1;
	double now;
	bool flag;
	while(cin >> n >> d)
	{
		if(!n && !d)
			return 0;
		flag = true;
		for(int i=0;i<n;i++)
		{
			cin >> x >> y;
			if(y > d)
				flag = false;	
			else
			{
				a[i].l = x - sqrt(d*d - y*y);
				a[i].r = x + sqrt(d*d - y*y);	
			}	
		}
		sort(a,a+n,cmp); 
		ans = 1;
		now = a[0].r;
		for(int i=1;i<n;i++)
		{
			if(a[i].l <= now)
				now = min(now,a[i].r);
			else
			{
				ans++;
				now = a[i].r;
			}
		}
		if(flag)	
			printf("Case %d: %d\n",op++,ans);
		else
			printf("Case %d: -1\n",op++);
	}

	return 0;
	
 } 
