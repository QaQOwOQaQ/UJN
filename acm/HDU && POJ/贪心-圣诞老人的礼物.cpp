#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

struct node
{
	int v;
	int w;
	double f;
}a[110];

bool cmp(const node &x,const node &y)
{
	return x.f > y.f;
}

int main()
{
	int n,weight;
	double ans = 0;
	cin >> n >> weight;
	for(int i=0;i<n;i++)
	{
		cin >> a[i].v >> a[i].w;
		a[i].f = a[i].v * 1.0 / a[i].w;
	}
	sort(a,a+n,cmp);
	
//	cout << "sort后的数据:" << endl;
//	for(int i=0;i<n;i++)
//	{
//		cout << a[i].w << " " << a[i].f << endl;
//	}	
	
	for(int i=0;i<n;i++)
	{
		if(weight >= a[i].w)
		{
			ans+= a[i].v;
			weight-= a[i].w;
		}
		else
		{
			ans+= weight * 1.0 * a[i].f ;
			break;
		}
	}		
	

	printf("%.1f",ans);
	
	return 0;
	
 } 

