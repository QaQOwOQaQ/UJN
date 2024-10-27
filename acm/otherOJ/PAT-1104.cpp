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

#define int long long

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int N, k, m;
int cnt = 0;
vector<PII> res;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int get(int x)
{
	int sum = 0;
	while(x)
	{
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

bool check(int a, int b)
{
	int c = gcd(a, b);
	if(c <= 2)	return false;
	for(int i = 2; i <= c / i; i ++ )//i<=c/i:测试点4
		if(c % i == 0)	return false;
	return true;
}

void dfs(int c, int u)
{
	if(u == k)
	{
		int a = get(c), b = get(c + 1);
		if(a == m && check(a, b))
		{
			// cout << "u: " << u << "k: " << k << endl;
			// cout << "res: " << c << endl;
			cnt ++ ;
			res.push_back({b, c});
		}
		return ;
	}
	
	if(u && !c)	return ;
	
	if(get(c) > m || get(c) + (k - u) * 9 < m)	return ;
	
	for(int i = 0; i <= 9; i ++ )	dfs(c * 10 + i, u + 1);
	
}

bool cmp(PII a, PII b)
{
	if(a.x == b.x)	return a.y < b.y;
	return a.x < b.x;
}

signed main()
{
	cin >> N;
	for(int T = 1; T <= N; T ++ )
	{
		cnt = 0;
		printf("Case %d\n", T);
		cin >> k >> m;
		dfs(0, 0);
		sort(res.begin(), res.end(), cmp);//测试点3
		if(res.size() == 0)	puts("No Solution");
		for(auto t : res)	cout << t.x << ' ' << t.y << endl;
		res.clear();
	}


    return 0;
}
