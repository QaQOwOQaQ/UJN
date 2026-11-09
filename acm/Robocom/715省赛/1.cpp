#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[10][10];

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ )
	{
		int p, c;
		cin >> p >> c;
		a[p][c] ++ ;
	}
	for(int i = 0; i <= 1; i ++ )
	{
		for(int j = 1; j <= 3; j ++ )
			cout << a[i][j] << " \n"[j == 3];
	}
	bool win = 0;
	if(a[0][1] > a[1][1])	win = 0;
	else if(a[0][1] == a[1][1])
	{
		if(a[0][2] > a[1][2])	win = 0;
		else if(a[0][2] == a[1][2])	
		{
			if(a[0][3] > a[1][3])	win = 0;
			else	win = 1;
		}
		else	win = 1;
	}
	else win = 1;
	if(!win)	puts("The first win!");
	else	puts("The second win!");
	return 0;
}
