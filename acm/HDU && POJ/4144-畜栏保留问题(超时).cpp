#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

struct node
{
	int l;
	int r;
	int node;
	int v;
}a[50010];

bool cmp1(struct node x,struct node &y)
{
	if(x.l == y.l)
		return x.node < y.node;
	else
		return x.l < y.l;
}

bool cmp2(const node &x,const node &y)
{
	return x.node < y.node;	
} 
int main()
{
	int n,ans = 0,now;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].l >> a[i].r;	
		a[i].node = i + 1;	
		a[i].v = 0;
	}
	sort(a,a+n,cmp1);

//	cout << "sort" << endl;
//	for(int i=0;i<n;i++)
//	{
//		cout << a[i].l << " " << a[i].r << " " << a[i].v << endl;	
//	}
//	cout << "sort" << endl;	
	
	ans = 0;
	for(int i=0;i<n;i++)	//便利所有出栏 
	{
		if(a[i].v)
			continue;
		else
		{
			ans++;	
			a[i].v = ans;
			now = a[i].r;
		}
			
		for(int j=i+1;j<n;j++)	//便利该出栏后面的所有出栏 
		{
			if(a[j].v)
				continue;	
			if(a[j].l > now)
			{
				now = a[j].r;	
				a[j].v = ans;		
			}		
		}
	}
	
	cout << ans << endl;
	sort(a,a+n,cmp2);
	for(int i=0;i<n;i++)
	{
		cout << a[i].v << endl;
	}
	

	return 0;
	
 } 
