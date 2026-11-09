#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 30010;

int pre[N], size[N], d[N], n;

inline int get(int x)
{
	if(pre[x] == x)	return x;
	
	int root = get(pre[x]);
	d[x] += d[pre[x]];	//
		
	return pre[x] = root;
	
}

void unite(int x, int y)
{
	int fx = get(x), fy = get(y);
	pre[fx] = fy;
	
	d[fx] += size[fy];	//
	size[fy] += size[fx];	//
	size[fx] = 0;	//
}

int main()
{
	for(int i = 1; i <= N; i ++ )	pre[i] = i, size[i] = 1;	
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		char ch;
		int a, b;
		cin >> ch >> a >> b;
		if(ch == 'M')	unite(a, b);
		else	
		{
			if(get(a) != get(b))	cout << -1 << endl;
			else	cout << abs(d[a] - d[b]) - 1 << endl;
		}
	}
	for(int i = 1; i <= n; i ++ )	cout << d[i] << " ";
	cout << endl;
	return 0;
}
