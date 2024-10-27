#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[1010][1010],b[1010][1010];	//a为原数组，b为差分数组
 
void operate(int x1,int y1,int x2,int y2,int d)	//将原数组[x1,y1],[x2,y2]之间的元素加上d 
{
	b[x1][y1]+= d;
	b[x1][y2+1]-= d;
	b[x2+1][y1]-= d;
	b[x2+1][y2+1]+= d; 
} 
int main()
{
	int p,q,m,x1,x2,y1,y2,d;
	cin >> p >> q >> m;
	
	for(int i=1;i<=p;i++)	//原数组初始化 
	{
		for(int j=1;j<=q;j++)
			cin >> a[i][j];
	}
	
	for(int i=1;i<=p;i++)	//差分数组初始化 
	{
		for(int j=1;j<=q;j++)
			b[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1]; 
	}

	for(int i=1;i<=m;i++)	//差分数组修改 
	{
		cin >> x1 >> y1 >> x2 >> y2 >> d;
		operate(x1,y1,x2,y2,d);
	}
	
	for(int i=1;i<=p;i++)	//差分数组的前i,j项和等于原数组a[i][j] 
	{
		for(int j=1;j<=q;j++)
			b[i][j]+= b[i-1][j] + b[i][j-1] - b[i-1][j-1]; 
	}
	
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=q;j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
	return 0;
	
 } 
