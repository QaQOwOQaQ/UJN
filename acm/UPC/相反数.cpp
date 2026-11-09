#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a[501],n,count=0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >>a[i];
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
			{
				if(a[j]+a[i]==0&&a[j]!=0&&a[i]!=0)	
						{
				//		cout << "::"<<a[j] << a[i] <<endl;
						count++;	
						}
			}
	}
	cout << count/2;
	return 0;
}
