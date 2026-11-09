#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[50010],b[50010];
int f[7],e[7],ans[7];

int main()
{
	int n,x,y;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		b[i] = (a[i] + b[i-1]) % 7;
		
//	cout << "sum[i]:" << endl;
//	for(int i=1;i<=n;i++)
//		cout << b[i] << " ";
//	cout << endl; 
	
	for(int j=0;j<7;j++)
	{
		for(int i=0;i<=n;i++)
		{
			if(b[i] == j)
			{
				f[j] = i;
				continue;
			}
		}
	}
	
	for(int j=0;j<7;j++)
	{
		for(int i=n;i>=0;i--)
		{
			if(b[i] == j)
			{
				e[j] = i;
				continue;
			}
		}
	}
	
	for(int i=0;i<7;i++)
		ans[i] = abs(e[i] - f[i]);
	sort(ans,ans+7);
	
//	for(int i=0;i<7;i++)
//		cout << ans[i] << " ";
//	cout << endl;
	
	cout << ans[6] << endl;
	return 0;
	
 } 
