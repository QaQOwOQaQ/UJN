#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
/*bool comp(int a,int b)
{
	return a>b;
}*/
int main()
{
	int n,x;
	vector<int> a;
//	a.push_back(111);
	cin >> n;
	while(n--)
	{
		cin >> x;
		a.push_back(x);
	}
	sort( a.begin(),a.end() );
	for(int i=0;i<a.size();i++)
		cout << a[i] << " ";
	cout << endl;
//	sort( a.rbegin(),a.rend() );
//	for(int i=0;i<a.size();i++)
//		cout << a[i] << " ";
//	cout << endl;
	return 0;
}
