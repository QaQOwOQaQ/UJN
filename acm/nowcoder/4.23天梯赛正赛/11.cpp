#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace  std;

const int N = 100010, M = 200020;

int n, m;
int dist[N];
int pre[N];
bool st[N];
vector<int> g[N];

void bfs(int u)
{
	queue<int> q;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	q.push(1);
	st[1] = true;
	
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		for(int i = 0; i < g[t].size(); i ++ )
		{
			int to = g[t][i];
			if(!st[to])
			{
				dist[to] = dist[t] + 1;
				q.push(to);
			}
		}
	}
}

int main()
{
	cin >> n >> m; 
	
	int root = 1;
	for(int i = 1; i <= n; i ++ )
	{
		int x;	cin >> x;
		if(x == -1)	root = x;
		else 
		{
			g[x].push_back(i);
		}
		pre[i] = x;
	}
	
	bfs(root);
	
	st[1] = true;
	long long res = 0;
	for(int i = 1; i <= m; i ++ )
	{
		int x;	cin >> x;
		if(!st[x])
		{
			st[x] = true;
			if(i == 1)	
			{
				res = dist[x];
				while(pre[x] != -1)	
				{
					st[pre[x]] = true;
					x = pre[x];	
				}
			}
			else
			{
				while(!st[pre[x]] && pre[x] != -1)
				{
					st[pre[x]] = true;
					x = pre[x];
				}
				res = res + 2 * dist[x] - 2 * dist[pre[x]];
			}
		}				
		cout << res << endl;
	}
	
	return 0;
}
