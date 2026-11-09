#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 510, M = 100010;

int h[N], e[N], ne[N], idx;
int n, m;
bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)	//depth
{
	cout << u << " ";
	st[u] = true;
	for(int i = h[u]; i != -1; i = ne[i] )
	{
		int j = e[i];
		if(!st[j])
		dfs(j);
	}
}

void bfs()
{
	queue<int> q;
	q.push(1);
	st[1] = true;
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		cout << t << " ";
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(!st[j])	q.push(j), st[j] = true;
		}
	}
	cout << endl;
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
	
	dfs(1);	 cout << endl;	
	memset(st, false, sizeof st);
	bfs();
	
	return 0;
}

/*
20 30
1 2
2 3
3 4 
4 5
5 1
1 8
8 9
9 10
4 14
11 19

2 10
10 11
11 12
12 3
9 18
18 19
19 20
17 18
17 16
7 8

7 6
7 17
6 5
6 15
14 15
14 13
13 20
13 12
15 16
16 20





*/
