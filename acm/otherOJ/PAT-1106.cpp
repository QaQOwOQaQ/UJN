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

const int N = 100010;

int T;
int a[N];

int get(int u)
{
	return (a[u] + a[u - 1] + a[u - 2] + a[u - 3]) % 10;
}

int main()
{
	a[0] = 2, a[1] = 0, a[2] = 1, a[3] = 9;
	int n;	cin >> n;
	for(int i = 4; i < n; i ++ )
	{
		a[i] = get(i - 1);
	}
	for(int i = 0; i < n; i ++ )	cout << a[i];


    return 0;
}
