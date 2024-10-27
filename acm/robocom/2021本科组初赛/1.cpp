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

const int N = 512, M = 110;

int n, k;
bool st[N], vis[M];
int a[M];

void dfs(int u, int s)
{
	if(u > 4)	
	{	
		if(s % 4 == 0)
			st[s / 4] = true;
		return ;
	}	
	
	for(int i = 0; i < n; i ++ )
	{
		if(!vis[i])
		{
			vis[i] = true;
			dfs(u + 1, s + a[i]);
			vis[i] = false;
		}
	}
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i ++ )	cin >> a[i];
	
	dfs(1, 0);

	while(k -- )
	{
		int x;	
		cin >> x;
		bool has_res = true;
		for(int i = 0; i < x; i ++ )
		{
			int t;	cin >> t;
			if(!st[t])	
				has_res = false;
		}
		if(has_res)	puts("Yes");
		else	puts("No");
	}

    return 0;
}