#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int op[1010];
int a[1010][1010];	//a[n][k]

int main()
{
	int n,m,k;	//n个人,m天有空,一共K天 
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
	{
		int cut = 1;
		for(int j=1;j<=m;j++)
		{
			int day;
			cin >> day;
			a[i][day] = cut++;
		}
	}
//	
//	cout << "日程表" << endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=k;j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}

	for(int j=1;j<=k;j++)	//每一天	 
	{
		int ans = 0;
		memset(op,0,sizeof(op));
		for(int i=1;i<=n;i++)	//遍历所有人 
		{
			op[a[i][j]] = 1;
		}
		
//		cout << "op表" << endl; 
//		for(int i=1;i<=k;i++)
//			cout << op[i] << " ";
//		cout << endl;
		
		for(int i=1;i<=k;i++)	//遍历所有人 
		{
			if( op[i] )
				ans++;
		}
		cout << ans << " ";
	}
	cout << endl;
	return 0;
	
} 
//0 1 2 3 0 0 0
//0 1 0 0 2 0 3
//0 0 1 0 2 0 3
//1 0 2 0 3 0 0
//0 0 0 0 1 2 3
//1 2 3 0 0 0 0
//ans:
//1 2 3 1 3 1 1
