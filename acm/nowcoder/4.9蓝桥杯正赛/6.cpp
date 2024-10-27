#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long

using namespace std;

const int N = 510;

int n, m, k;
int a[N][N], s[N][N];

int get(int x1, int y1, int x2, int y2)
{
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

signed main()
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			cin >> a[i][j];
	
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
		{
			s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; 
		}
	
//	
//	for(int i = 1; i <= n; i ++ )
//	{
//		for(int j = 1; j <= m; j ++ )
//		{
//			
//		}
//	}
	
	cout << get(2, 2, 3, 3);	
			
	return 0;
}
/*n^2*logn*logn
3 4 10
1 2 3 4
5 6 7 8
9 10 11 12
*/
