#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace  std;

typedef pair<int, int> PII;

const int N = 510, M = 510 * 510, INF = 0x3f3f3f3f;

int n;
bool st[N];
int dist[N][N];
int h[N], e[M], ne[M], w[M], idx;
char sex[N];
PII res[N];
bool man[N], woman[N];

void add(int a, int b, int c)
{
	w[idx] = c;
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra(int u)
{
	memset(st, false, sizeof st);
	dist[u][u] = 0;
	priority_queue<PII, vector<PII>, greater<PII> > q;
	q.push({0, u});
	
	while(q.size())
	{
		auto t = q.top();
		q.pop();
		int ver = t.second, distance = t.first;
		if(st[ver])	continue;
		st[ver] = true;
		
		for(int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[u][j] > distance + w[i])
			{
				dist[u][j] = distance + w[i];
				q.push({dist[u][j], j});
			}
		}
			
	}
}

int main()
{
	memset(h, -1, sizeof h);
	memset(dist, 0x3f, sizeof dist);
	
	cin >> n;
	for(int i = 1; i <= n; i ++ )
	{
		int k;
		cin >> sex[i] >> k;
		while(k -- )
		{
			int p, d;
			scanf("%d:%d", &p, &d);
			add(i, p, d);
		}
	}
	
	for(int i = 1; i <= n; i ++ )	dijkstra(i);
	
	vector<int> v1, v2;
	int m1 = -1, m2 = -1;
	for(int i = 1; i <= n; i ++ )
	{
		int maxn = -1, id;
		for(int j = 1; j <= n; j ++ )
		{
			if(dist[i][j] > maxn && i != j && sex[i] != sex[j])
				maxn = dist[i][j], id = j;
		}
//		cout << maxn << endl;
		if(sex[id] == 'F')//¹éÀàÅ®v1 
		{
			if(maxn > m1)	
			{
				m1 = maxn;
				v1.clear();
				v1.push_back(i);
			}
			else if(maxn == m1)	v1.push_back(i);
		}
		else
		{
			if(maxn > m2)	
			{
				m2 = maxn;
				v2.clear();
				v2.push_back(i);
			}
			else if(maxn == m2)	v2.push_back(i);
		}
	}
	
	for(int i = 0; i < v1.size(); i ++ )
	{
		cout << v1[i];
		if(i != v1.size() - 1)	cout << ' ';
		else	cout << endl;
	}
	
	for(int i = 0; i < v2.size(); i ++ )
	{
		cout << v2[i];
		if(i != v2.size() - 1)	cout << ' ';
		else	cout << endl;
	}

	
	
	return 0;
}
