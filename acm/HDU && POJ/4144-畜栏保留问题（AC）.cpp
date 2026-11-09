#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define ll long long

using namespace std;

const int maxn = 50010;
struct node
{
	int l,r,pos;
	friend bool operator < (const node &x,const node &y)
	{
		return x.r > y.r;
	}
}a[maxn];

int n;
int use[maxn];
priority_queue<node> q;

bool cmp(const node a,const node b)
{
	if(a.l == b.l)
		return a.r < b.r;
	else
		return a.l < b.l;
}
int main()
{
	int ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		a[i].pos = i;	
		cin >> a[i].l >> a[i].r;
	}
	sort(a,a+n,cmp);
	
	for(int i=0;i<n;i++)
	{
		if(!q.empty() && q.top().r < a[i].l)
		{
			use[a[i].pos] = use[q.top().pos];
			q.pop();
		}
		
		q.push(a[i]);
		
		else
		{
			ans++;
			use[a[i].pos] = ans;
		}
		
	}
	
	cout << ans << endl;
	for(int i=0;i<n;i++)
		cout << use[i] << endl;
	return 0;
	
 } 
