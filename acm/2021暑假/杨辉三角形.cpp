#include <iostream>
using namespace std; 
int main() 
{
	int n;
	int i,j;
	cin>>n;
	int a[n][n] ;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			a[i][j] = 1;
		}
		
	for(i=1;i<n;i++)
		for(j=1;j<i;j++)
			a[i][j] = a[i-1][j]+a[i-1][j-1];
	
	for(i=0;i<n;i++)
	{	for(j=0;j<=i;j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}	
	return 0;
}

