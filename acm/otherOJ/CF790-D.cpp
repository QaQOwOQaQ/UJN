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

const int N = 410;

int T, n, m;
int a[N][N];
int l[N], r[N];

int main()
{
	cin >> T;
	while(T -- )
	{
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		
		cin >> n >> m;
		for(int i = 0; i < n; i ++ )
			for(int j = 0; j < m; j ++ )
			{
				cin >> a[i][j];
				l[i + j] += a[i][j];
				r[j - i + n] += a[i][j];
			}
		
		int res = -1;
		for(int i = 0; i < n; i ++ )
			for(int j = 0; j < m; j ++ )
			{
				//ע��ö�ٵ���ö�ټ�������,����Ҫ��ȥһ�� 
				res = max(res, l[i + j] + r[j - i + n] - a[i][j]);
			}

		cout << res << endl;
		
	}   
	 
    return 0;
}
