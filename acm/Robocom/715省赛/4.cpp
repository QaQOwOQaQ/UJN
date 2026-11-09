#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <cmath>
#include <vector>

using namespace std;

const int N = 2020, M = N, INF = 0x3f3f3f3f;

int n, id = 1;
unordered_map<string, int> ass;
unordered_map<int, string> mp;
int h[N], e[M], ne[M], w[M], idx;
int pre[N], dist[N];
bool st[N];

// idx[0] = ass[s]
// idx[1] = ass[s] + 1

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void check(string s)
{
	if(!ass[s])
	{	
		ass[s] = id;
		mp[id] = s;
		id += 2;
	}	
}

int bfs(int s, int rear)
{
	memset(pre, -1, sizeof pre);
	memset(st, false, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	
	dist[s] = 0;
	q.push(s);
	st[s] = true;
	
	while(q.size())
	{
		auto t = q.front();	q.pop();
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(!st[j])
			{
				pre[j] = t;
				q.push(j);
				dist[j] = dist[t] + 1; 
				if(j == rear)	return dist[rear];
			}
		}
	}
	
	return INF;
}

string get_name(int x)
{
	if(x & 1)	return mp[x];
	return mp[x - 1];
}

string getres(int u)
{
	vector<int> path;
	while(u != -1)
	{
		path.push_back(u);
		u = pre[u];
	}
	reverse(path.begin(), path.end());
#ifdef DEBUG	
	cout << "<---------------------------->\n";
	cout << "path: ";
	for(auto &x : path)	cout << x << ' ';	cout << endl;
	for(auto &x : path)	
	{
		if(x & 1)	cout << get_name(x) << "0 ";
		else cout << get_name(x) << "1 ";
	}
	cout << endl;
	cout << "<---------------------------->\n";
#endif	
	string res = "";
	// yu, yuci, rou, yu
	// yu yuci, yuci, rou, rou yu
	for(int i = 0; i < path.size() - 1; i ++ )
	{
		int x = path[i], y = path[i + 1];
		res += get_name(x) + " " + to_string(x % 2 == 0) + " " + get_name(y) + " " + to_string(y % 2 == 0) + " ";
	}
	int l = *path.begin(), r = *(path.end() - 1);
	res += "= " + get_name(l) + " " + to_string(l % 2 == 0) + " " + get_name(r) + " " + to_string(r % 2 == 0);
	return res;
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for(int i = 0; i < n; i ++ )
	{
		string s1, s2;	bool b1, b2;
		cin >> s1 >> b1 >> s2 >> b2;
		check(s1);	check(s2);
		add(ass[s1] + b1, ass[s2] + b2);
	}
#ifdef DEBUG	
	cout << "<---------------------------->\n";
	cout << "idx: " << id << endl;
	for(int i = 1; i <= id - 1; i += 2)
		cout << i << ' ' << mp[i] << endl;
	for(auto &x : ass)	cout << x.first << ' ' << x.second << endl;
	cout << "<---------------------------->\n";
#endif
	int minx = INF;
	string res = "";
	for(int i = 1; i <= id - 2; i += 2)
	{
		int d = bfs(i, i + 1);
//		cout << "D: " << d << endl;
		if(d < minx)
		{
			minx = d;
			res = getres(i + 1);
		}
		
		d = bfs(i + 1, i);
//		cout << "D: " << d << endl;
		if(d < minx)
		{
			minx = d;
			res = getres(i);
		}
	}
	
	cout << res << endl;
}


int main()
{
	solve();
	return 0;
}


