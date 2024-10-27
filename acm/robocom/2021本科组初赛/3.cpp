#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1010, M = N * N, INF = 0x3f3f3f3f;

int n, m, k;
int g[N][N], v[N][N], ist[N];
int pre[N], energy[N], dist[N];
bool st[N];
vector<int> query;
int startx = -1, maxn = INF;

void dijkstra(int x)
{
	memset(st, false, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	memset(pre, -1, sizeof pre);

	dist[x] = 0;
	for(int ver = 1; ver <= n; ver ++ )
	{
		int t = -1;
		for(int i = 1; i <= n; i ++ )
			if(!st[i] && (t == -1 || dist[i] < dist[t]))
				t = i;
		st[t] = true;
		
		for(int i = 1; i <= n; i ++ )	
		{
			int c = g[t][i], d = v[t][i];
			if(dist[i] > dist[t] + c)
			{
				pre[i] = t;
				dist[i] = dist[t] + c;
				energy[i] = energy[t] + d;
			}
			else if(dist[i] == dist[t] + c)
			{
				if(energy[i] < energy[t] + d)
				{
					pre[i] = t;
					energy[i] = energy[t] + d;
				}
			}
		}
	} 
	
	int tmp = -1;
	for(int i = 1; i <= n; i ++ )	tmp = max(tmp, dist[i]);
	if(tmp < maxn)	maxn = tmp, startx = x;
}

vector<int> getPath(int x)
{
	vector<int> path;
	while(x != -1)
	{
		path.push_back(x);
		x = pre[x];
	}
	return vector<int>(path.rbegin(), path.rend());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
			if(i == j)	g[i][j] = 0;
			else	g[i][j] = INF;

	while(m -- )
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		g[a][b] = g[b][a] = c;
		v[a][b] = v[b][a] = d;
	}
	cin >> k;
	while(k -- )
	{
		int x;	cin >> x;
		query.push_back(x);
	}
	
	for(int i = 1; i <= n; i ++ )	dijkstra(i);
	
	memset(pre, -1, sizeof pre);
	memset(energy, 0, sizeof energy);
	dijkstra(startx);	
	
	// output answer
	cout << startx << endl;
	for(auto &x : query)
	{
		vector<int> res = getPath(x);
		int len = res.size();
		for(int i = 0; i < len; i ++ )
		{
			cout << res[i];
			if(i != len - 1)	cout << "->";
		}
		cout << endl << dist[x] << ' ' << energy[x] << endl;
	}
	
	
	return 0;
}