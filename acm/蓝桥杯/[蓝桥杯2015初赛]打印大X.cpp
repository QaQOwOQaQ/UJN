#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	int m,n;	//表示笔的宽度，X的高度
	while(cin >> m >> n)
	{
		int col=m + n - 1;
		for(int i=1;i<=n/2+1;i++)
		{
			for(int j=1;j<=col;j++)
			{
				int d = m - 1;
				if( (j>=i&&j<=i+d) || (j>=col-i+1-d&&j<=col-i+1) )
					cout << "*";
				else
					cout << "."; 
			}
			cout << endl;
		}
		for(int i=n/2;i>=1;i--)
		{
			for(int j=1;j<=col;j++)
			{
				int d = m - 1;
				if( (j>=i&&j<=i+d) || (j>=col-i+1-d&&j<=col-i+1) )
					cout << "*";
				else
					cout << "."; 				
			}
			cout << endl;			
		}
	}
	return 0;
 } 
