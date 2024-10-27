#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

const int N = 2010, M = 210 * 210, INF = 0x3f3f3f3f;

int n, m, idx;
int cnt[N], pre[N];
int dist[N], city[N], kill[N];
int g[N][N];
bool st[N];
string hh, tt;
unordered_map<string, int> si;
unordered_map<int, string> is;

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[0] = 0;
	
	for(int l = 0; l < idx; l ++ )
	{
		int t = -1;
		for(int i = 0; i < idx; i ++ )
			if(!st[i] && (t == -1 || dist[i] < dist[t]))	t = i;
		
		if(st[t])	continue;
		st[t] = true;
		
		for(int i = 0; i < idx; i ++ )
		{
			if(dist[i] > dist[t] + g[t][i])
			{
				dist[i] = dist[t] + g[t][i];
				kill[i] = kill[t] + cnt[i];
				city[i] = city[t] + 1;
				pre[i] = t;
				puts("add");
			}
			else if(dist[i] == dist[t] + g[t][i])
			{
				if(city[i] < city[t] + 1) 
				{
					kill[i] = kill[t] + cnt[i];
					city[i] = city[t] + 1;
					pre[i] = t;
					puts("add");
				}
				else if(city[i] == city[t] + 1)
				{
					if(kill[i] < kill[t] + cnt[i])
					{
						kill[i] = kill[t] + cnt[i];
						pre[i] = t;
						puts("add");
					}
				}
			}
		}
		
	}	
}

int main()
{
	for(int i = 0; i < N; i ++ )
		for(int j = 0; j < N; j ++ )
			if(i == j)	g[i][j] = 0;
			else	g[i][j] = INF;
	
	for(int i = 0; i < N; i ++ )	pre[i] = -1;
	
	cin >> n >> m >> hh >> tt;
	is[idx] = hh;
	si[hh] = idx ++ ;
	is[idx] = tt;
	si[tt] = idx ++ ;
	
	for(int i = 1; i < n; i ++ )
	{
		string name;
		int num, id;
		cin >> name >> num;
		if(si.count(name))	id = si[name];
		else
		{
			is[idx] = name;
			si[name] = idx ++ ;
			id = si[name];
		}
		cnt[id] = num;
	} 
	
	while(m -- )
	{
		string a, b;
		int c;
		cin >> a >> b >> c;
		if(!si.count(a))
		{
			is[idx] = a;
			si[a] = idx ++ ;
		}
		if(!si.count(b))
		{
			is[idx] = b;
			si[b] = idx ++ ;
		}
		int x = si[a], y = si[b];
		g[x][y] = g[y][x] = min(g[x][y], c);
	}
	
	dijkstra();
	
	vector<int> path;
	int state = 1;
	cout << "pre: " << pre[state] << endl;
//	while(pre[state] != -1)
//	{
//		path.push_back(state);
//		state = pre[state];
//	}
//	path.push_back(state);
//	
	cout << path.size() << ' '  << dist[1] << ' ' << kill[1] << endl;
	
	return 0;
}
