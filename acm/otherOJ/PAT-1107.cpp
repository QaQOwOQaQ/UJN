#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

#define x first
#define y second

#define debug2(x, y)	\
	cout << "debug: " << #x << " = " << x << "   " << #y << " = " << y << endl
#define debug1(x)	\
	cout << "debug: " << #x << " = " << x << endl
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010;

int T;
int n, m;
int res[N];

int main()
{
	int maxn = -1;
	
	memset(res, -1, sizeof res);
	cin >> n >> m;
	for(int i = 0; i < n; i ++ )
	{
		for(int j = 0; j < m; j ++ )
		{
			int x;	cin >> x;
			res[i] = max(res[i], x);
		}
		maxn = max(maxn, res[i]);
		cout << res[i];
		if(i != n - 1)	cout << ' ';
	}
	
	cout << endl << maxn << endl;
	


    return 0;
}
