#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[1010][1010],b[1010][1010]; 
int main()
{
	int n,m,x1,x2,y1,y2;
	cin >> n >> m;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	
	for(int i=0;i<m;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		b[x1][y1]++;
		b[x1][y2+1]--;
		b[x2+1][y1]--;
		b[x2+1][y2+1]++;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[i][j]+= b[i-1][j] + b[i][j-1] - b[i-1][j-1];
		}
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}	
	cout << endl;
	return 0;
	
 } 
