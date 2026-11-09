#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

const int N = 13;

int n, m, k, g[N][N];
bool edge_vis[N][N][N][N];
bool node_vis[N][N];
bool has_res;
vector<int> path;
		//   0, 1, 2, 3, 4, 5,  6, 7
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool edge_vis_check(int x, int y, int a, int b)
{
	if(x > a)
	{
		swap(x, a);
		swap(y, b);
	}
	// (x,y)  (x,y+1)|	(x-1,y)(a,b)
	// (x+1,y)(a,b)  |	(x,y)  (x,y+1)
	if(a == x + 1 && b == y + 1)
		return !edge_vis[x+1][y][x][y+1];
	return !edge_vis[x-1][y][x][y+1];
}

void dfs(int x, int y, int ne, int cnt)
{
	if(has_res)	return ;
	if(x == n - 1 && y == n - 1 && cnt == m)
	{
		for(auto &x : path)	cout << x;	
		cout << endl;
		has_res = true;
		return ;
	}
	for(int i = 0; i < 8; i ++ )
	{
		int a = x + dx[i], b= y + dy[i];
		if(a < 0 || a >= n || b < 0 || b >= n || g[a][b] != ne)	continue;
		if(node_vis[a][b])	continue;
		if(!edge_vis_check(x, y, a, b))	continue;
		
		path.push_back(i);
		node_vis[a][b] = true;
		edge_vis[x][y][a][b] = edge_vis[a][b][x][y] = true;
		dfs(a, b, (ne + 1) % k, cnt + 1);
		edge_vis[x][y][a][b] = edge_vis[a][b][x][y] = false;
		node_vis[a][b] = false;
		path.pop_back();
	}
}

int main()
{
	cin >> n >> k;	
	m = n * n;
	for(int i = 0; i < n; i ++ )
		for(int j = 0; j < n; j ++ )	cin >> g[i][j];
	node_vis[0][0] = true;
	dfs(0, 0, 1, 1);
	if(!has_res)	cout << -1 << endl;
	return 0;
}
