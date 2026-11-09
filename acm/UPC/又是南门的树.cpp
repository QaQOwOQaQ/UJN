#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	m = n/2+1;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==j||i==(2*m-j))	
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;		
	}
	for(int j=m+1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
			{
				if(i==j||i==(2*m-j))
					cout << "X";
				else
					cout << ".";
			}
			cout << endl;
	}	
	return 0;
}
