#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long

using namespace std;

const int N = 510;

int n, m, K;
int a[N][N], s[N][N];

int get(int x1, int y1, int x2, int y2)
{
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

signed main()
{
	cin >> n >> m >> K;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
			cin >> a[i][j];
	
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= m; j ++ )
		{
			s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; 
		}
	
	
	int res = 0;
	for(int x = 1; x <= n; x ++ )//top
	{
		for(int y = x; y <= n; y ++ )//buttom
		{
			for(int k = 1; k <= m; k ++ )
			{
				int l = k, r = m;
				while(l < r)
				{
					int mid = l + r + 1 >> 1;
					if(get(x, K, y, mid) <= K) l = mid;
					else	r = mid - 1;
				}
				if(get(x, k, y, r) <= K)	res += r - k + 1;
			}
		}
	}
	cout << res << endl;
		
	return 0;
}

