#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,int> m;
	int num[10001];
	int n,a;
	cin>>n; 
//Stl解决 
//	for(int i=1;i<=n;i++)
//	{
//		cin >> a;
//		m[a]++;
//		if(i==n)
//		cout << m[a];
//		else
//		cout << m[a] << " ";
//	}
//数组解决 
	for(int i=1;i<=n;i++)
	{
		cin >> a;
		num[a]++;
		if(i==n)
		cout << num[a];
		else
		cout << num[a] << " ";
	}
	return 0;
}
