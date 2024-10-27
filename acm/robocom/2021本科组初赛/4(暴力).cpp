#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 500010, M = N;

int h[N], e[M], ne[M], idx;
int n, m, d;
bool st[N], vis[N];
bool flag;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int startx, int endx)
{
	st[startx] = true;
	if(startx == endx)
	{
		flag = 1;
		return ;
	}
	for(int i = h[startx]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!st[j] && !vis[j])	dfs(j, endx);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	memset(h, -1, sizeof h);
	
	cin >> n >> m >> d;
	while(m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);	add(b, a);
	}
	
	while(d -- )
	{
		int c, q;
		cin >> c >> q;
		vis[c] = true;
		int ans = q;
		while(q -- )
		{
			memset(st, false, sizeof st);
			flag = false;
			int a, b;
			cin >> a >> b;
			if(!vis[a] && !vis[b])	dfs(a, b);
			ans -= flag; //flag为真表示可以通行
		}
		cout << ans << endl;
	}

	return 0;
}
/*
1 2
1 3
1 5
2 5
3 4

4 3
1 3
1 4
2 3

5 3
3 4
2 3
3 5

1 3
2 3
2 5
3 4
*/