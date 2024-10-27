//前缀和 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[1010],b[1010];	//a为原始数组，b为前n项和 

int main()
{
	memset(a,0,sizeof(a));	//cstring
	memset(b,0,sizeof(b));	//cstring
	int n,m,l,r;
	cin >> n >> m;	//n个数，遍历m次 
	for(int i=1;i<=n;i++)
		cin >>a[i];
	for(int i=1;i<=n;i++)
		b[i] = b[i-1] + a[i]; 
	for(int i=1;i<=m;i++)//每次遍历 求区间[l,r]的和	
	{
		cin >> l >> r;	
		cout << "ans:" << (b[r] - b[l-1]) << endl; 
	}	
	return 0;
	
 } 
