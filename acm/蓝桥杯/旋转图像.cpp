#include<iostream>

using namespace std;

int a[110][110],b[110][110];
int main()
{
	int m,n;
	cin >> m >> n;
	
	for(int i=1;i<=m;i++)	//mÐÐnÁÐ 
	{
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
			cout << a[j][i] << " ";
		cout << endl;	
	}	
	
	return 0;
}
