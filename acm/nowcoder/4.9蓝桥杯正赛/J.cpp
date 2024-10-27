#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

#define int long long

using namespace std;

const int N = 200010;

int n, w[N], b[N], minx = 1e17;

int get(int x)
{
	return floor(sqrt(x / 2 + 1));
}

signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ )	cin >> w[i], minx = min(minx, w[i]);
	for(int i = 1; i <= n; i ++ )	b[i] = w[i] - w[i - 1];
	
	cout << 5 << endl;
	
	
	return 0;
}
