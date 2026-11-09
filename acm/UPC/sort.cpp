#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+1;
int a[N];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
			cout <<a[i];
		else
			cout << a[i] << " ";
	}
		
	return 0;
	
}
