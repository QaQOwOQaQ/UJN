#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

const int maxn = 10010;
//int ans[maxn][maxn];
int a[maxn][5];
int main()
{
//	³¬Ê± 
//	int n,a,b,g,k,x,y,cut=0;
//	cin >> n;
//	memset(ans,-1,sizeof(ans));
//	for(int i=1;i<=n;i++)
//	{
//		cin >> a >> b >> g >> k;
//		cut++;
//		ans[a][b]=	
//	}
//	cin >> x >> y;
//	cout << ans[x][y] << endl;
//	return 0;
	
	int n,x,y;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
			a[i][3]+= a[i][1];
			a[i][4]+= a[i][2];
	}
	cin >> x >> y;
	for(int i=n;i>=1;i--)
	{
		if(x>=a[i][1] && x<=a[i][3] && y>=a[i][2] && y<=a[i][4])
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	
 } 
