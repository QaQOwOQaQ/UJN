/*
	归纳题意就是给出一张图，支持两种操作：
	1） 删除一个点。
	2） 询问两个点是否连通。
	观察到无法简单地维护“删除”这个操作，考虑将所有操作离线，逆序处理。
	即，先删除要删除的所有点，再倒着往里加点，顺便把询问处理掉，用并查集维护即可。
	时间复杂度为：O(n+mlogn+qlogn)。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
const int N = 500010, Q = 300010;

int n, m, d;
vector<PII> query[Q];
vector<int> v[N];
int pre[N], ans[N], violate[N];

int find(int x)
{
	if(pre[x] == x)	return x;
	return pre[x] = find(pre[x]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	for(int i = 0; i < N; i ++ )	pre[i] = i;
	
	cin >> n >> m >> d;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= d; i ++ )
	{
		int q;
		cin >> violate[i] >> q;
		pre[violate[i]] = 0;
		while(q -- )
		{
			int a, b;
			cin >> a >> b;
			query[i].push_back({a, b});
		}
	}
	
	// 从始至终都没有被隔离的城市先预处理
	for(int i = 1; i <= n; i ++ )
	{
		if(pre[i])
		{
			for(auto &x : v[i])
				if(pre[x])	pre[find(i)] = find(x);
		}
	}
	
	// 倒着执行查询，查询完成之后，再把这次操作中隔离的城市恢复
	for(int i = d; i >= 1; i -- )
	{
		for(int j = 0; j < query[i].size(); j ++ )
		{
			int fa = find(query[i][j].first);
			int fb = find(query[i][j].second);
			if(fa != fb || fa == 0 || fb == 0)	ans[i] ++ ;		
		} 
		
		// 恢复隔离的城市
		int city = violate[i];
		pre[city] = city;
		for(auto &x : v[city])
			if(pre[x])
				pre[find(city)] = find(x);
	}
	
	for(int i = 1; i <= d; i ++ )	cout << ans[i] << endl;
	
	return 0;
}