#include <iostream>
#include <algorithm>
#include <cstring>

using namespace  std;

int a[10];
int n;
bool st[10][10];

int main()
{
	for(int i = 1; i <= 6; i ++ )	cin >> a[i], st[i][a[i]] = true;
	
	cin >> n;
	for(int u = 1; u <= n; u ++ )
	{
		for(int i = 1; i <= 6; i ++ )
		{
			for(int k = 6; k >= 1; k -- )
			{
				if(!st[i][k])	
				{
					a[i] = k;
					st[i][k] = true;
					break;
				}
				else	continue;	
			}	
		}
	}
	
		
	for(int i = 1; i <= 6; i ++ )
	{
		cout << a[i];
		if(i != 6)	cout << ' ';
	}
		
	return 0;
}
