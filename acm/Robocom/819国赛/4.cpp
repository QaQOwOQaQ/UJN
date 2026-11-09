// 22-30, 一个点内存超限 ，一个点运行超时 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;

const int N = 1010;

int n, m, w[N][N];
bool done[N];
set<int> h;
unordered_map<int, vector<PII>> ass;

void init()
{
	cin >> n >> m;
	for(int i = 0; i < n; i ++ )	
		for(int j = 0; j < m; j ++ )
		{	
			int x;	cin >> x;
			w[i][j] = x;
			h.insert(x);
			ass[x].push_back({i, j});
		}
}

bool remove(int u)
{
	for(auto &t : ass[u])
		if(t.first && w[t.first - 1][t.second] != -1 && w[t.first - 1][t.second] != u)	
			return false;
	return true;
}

void solve()
{
	int len = h.size();
	for(int i = 0; i < len; i ++ )
	{
		bool has_res = false;
		for(auto &x : h)
		{
			if(!has_res && !done[x])
			{
				has_res = remove(x);
				if(has_res)	
				{
					cout << x << " \n"[i == len - 1];
					done[x] = true;	
					for(auto &t : ass[x])	w[t.first][t.second] = -1;
					break;
				}
			} 
		}
		if(!has_res)	
		{
			puts("Impossible");
			return ;	
		}
	}
}

int main()
{
	init();
	solve();
	return 0;
}


