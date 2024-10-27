// Problem: G. Чёрно-белые сбалансированные поддеревья
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

int T;
int n, m;
string s[N];

int work(string a, string b)
{
	int res = 0;
	for(int i = 0; i < m; i ++ )
	{
		int x = a[i] - '0', y = b[i] - '0';
		res += abs(x - y);
	}
	
	return res;
}

int main()
{
	cin >> T;
	while(T -- )
	{
		cin >> n >> m;
		for(int i = 0; i < n; i ++ )	cin >> s[i];
		
		int res = 1e9;
		for(int i = 0; i < n; i ++ )
			for(int j = i + 1; j < n; j ++ )
				res = min(res, work(s[i], s[j]));
		
		cout << res << endl;
		
	}	
    
    return 0;
}
