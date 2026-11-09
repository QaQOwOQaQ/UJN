#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010, M = 200010;

int h[N], e[M], ne[M], w[M], idx; 
int color[N], n, m, l, r;

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;	
} 

bool bfs(int u, int c, int v)
{
	color[u] = c;
	for(int i = h[u]; i != -1; i = ne[i])
	{
		if(w[i] > v)
		{
			int j = e[i];
			if(!color[j])	//这里一定要加括号！！！ 
			{
				if(!bfs(j, 3 - c, v))	return false;
			}
			else if(color[j] == c)	return false;
		}
	}
	return true;
}

bool check(int v)
{
	memset(color, 0, sizeof color);
	for(int i = 1; i <= n; i ++ )
	{
		if(!color[i])
			if(!bfs(i, 1, v))
				return false;
	}
	return true;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m -- )
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
		r = max(r, c);
	}
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid))	r = mid;
		else	l = mid + 1;
	}
	
	cout << l << endl;
	
	return 0;
}
