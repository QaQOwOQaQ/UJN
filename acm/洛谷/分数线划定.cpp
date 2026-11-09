#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

struct op
{
	int num;
	int s;
}a[5010];

bool cmp(const op &x,const op &y)
{
	if(x.s == y.s)
		return x.num < y.num;
	else
		return x.s > y.s;
}
int main()
{
	int n,m,score,ans = 0;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i].num >> a[i].s;
		
	sort(a,a+n,cmp);
	
	int op = floor(m * 1.5);
	score = a[op-1].s;
	for(int i=0;i<n;i++)	
	{
		if(a[i].s >= score)
			ans++;
	}
	
	cout << score <<  " " << ans << endl;
	for(int i=0;i<n;i++)
	{
		if(a[i].s >= score)
			cout << a[i].num << " " << a[i].s << endl;		
	}


	return 0;
	
 } 

