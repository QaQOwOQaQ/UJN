// Problem: H1. Максимизация пересечений (простая версия)
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/H1
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 210;

int T, n, m;
int w[N][N], a[N][N];
int l[N], r[N];

int main()
{
	cin >> T;
	while(T -- )
	{
		memset(l, 0, sizeof 0);
		memset(r, 0, sizeof 0);
		
		cin >> n >> m;
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= m; j ++ )
			{
				cin >> w[i][j];	
				r[i + j - 1] += w[i][j];
			}
		
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= m; j ++ )
			{
				a[i][j] = w[n - i + 1][j];
				l[i + j - 1] += a[i][j];
			}
		
		cout << "test: " << endl;
		for(int i = 1; i <= n << 1 - 1; i ++ )
			cout << r[i] << ' ';
		cout << endl;
		
		for(int i = 1; i <= n << 1 - 1; i ++ )
			cout << r[i] << ' ';
		cout << endl;
		cout << "end" << endl;
		
		//枚举主教的位置	
		int res = -1;	
		for(int i = 1; i <= n; i ++ )
			for(int j = 1; j <= m; j ++ )
				res = max(res, l[n - (i + j - 1)] + r[i + j - 1]);
		
		cout << res << endl;
	
	}   
	 
    return 0;
}