#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010, M = 200010;

int h[N], e[M], ne[M], idx;
int n, m, res, color[N], l, r;

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool check(int u, int c)
{
	color[u] = c;
	if(c == 1)	 l ++ ;
	else	r ++ ;
	for(int i = h[u]; i != -1; i = ne[i]) 
	{
		int j = e[i];
		if(!color[j])
		{
			if(!check(j, 3 - c))	return false;
		}
		else if(color[j] == c)	return false;
	}
	return true;
}

int main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a); 
	}
	
	bool flag = true;	
	for(int i = 1; i <= n; i ++ )
	{
		if(!color[i])
		{
			l = r = 0;
			if(!check(i, 1))
			{
				cout << "Impossible" << endl;
				return 0;
			}
			else	res += min(l, r);
		}
	}

	cout << res << endl;
	
	return 0;	
} 
