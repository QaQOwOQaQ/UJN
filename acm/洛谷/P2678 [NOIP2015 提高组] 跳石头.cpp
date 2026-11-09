#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

ll len,n,m,l,r,mid; 
ll a[50010];
bool check(ll mid)
{
	int last = 0;	//last-上一个石头节点 
	int sum = 0;	//需要移走的石头数量 
	for(int i=1;i<=n;i++)
	{
		if(a[i] - a[last] >= mid)
			last = i;
		else
			sum++;
	}
	if(sum <= m)
		return true;
	else
		return false;
}
int main()
{
	cin >> len >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a,a+n);
	l = 0;
	r = len;
	mid = l + (r - l) / 2;
	while(l <= r)
	{
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
		mid = l + (r - l) / 2;		
	}
	cout << r << endl;
	return 0;
	
 } 
