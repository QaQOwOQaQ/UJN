#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

int a[50010],b[50010];	//公司甲，公司乙 
using namespace std;

void init(int n,int m)
{
	for(int i=1;i<=n;i++)
		a[i] = i;
	for(int i=1;i<=m;i++)
		b[i] = i;
}

int find1(int x)
{
	if(a[x] == x)
		return x;
	else
		return a[x] = find1(a[x]);
}

void unite1(int x,int y)
{
	int fx = find1(x);
	int fy = find1(y);
	if(fx != fy)
		a[fx] = fy;
}

int find2(int x)
{
	if(b[x] == x)
		return x;
	else
		return b[x] = find2(b[x]);
}

void unite2(int x,int y)
{
	int fx = find2(x);
	int fy = find2(y);
	if(fx != fy)
		b[fx] = fy;
}
int main()
{
	int n,m,p,q,x,y;
	cin >> n >> m >> p >> q;
	
	//初始化 
	init(n,m);
		
	//联合 
	for(int i=0;i<p;i++)
	{
		cin >> x >> y;
		unite1(x,y);
	}
	for(int i=0;i<q;i++)
	{
		cin >> x >> y;
		unite2(abs(x),abs(y));
	} 
	
	//测试 
//	cout << "-----------" << endl;
//	for(int i=1;i<=n;i++)
//		cout << a[i] << " ";
//	cout << endl;
//	cout << "-----------" << endl;
//	for(int i=1;i<=m;i++)
//		cout << b[i] << " ";
//	cout << endl;
//	cout << "-----------" << endl;
	//测试 
	
	//输出 

	int ans1 = 0,ans2 = 0;
	int tmp1 = find1(1),tmp2 = find2(1);
	for(int i=1;i<=n;i++)
	{
		if(find1(i) == tmp1)
			ans1++;
	}
	for(int i=1;i<=m;i++)
	{
		if(find2(i) == tmp2)
			ans2++;
	}
	
	cout << min(ans1,ans2) << endl;

	return 0;
	
} 
