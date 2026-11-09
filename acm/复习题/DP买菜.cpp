#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, M = 10010;

int f[N][M], n, m, w[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )	cin >> w[i];
	
	f[0][0] = 1; 
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 0; j <= m; j ++ )
		{
			if(j >= w[i])	f[i][j] = f[i - 1][j] + f[i - 1][j - w[i]];
			else f[i][j] = f[i - 1][j];
		}
	}
	
	cout << f[n][m] << endl;
	
}
