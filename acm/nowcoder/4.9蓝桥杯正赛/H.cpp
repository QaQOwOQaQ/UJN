#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef long long LL;

const int N = 100010;

int n, m;
vector<PIII> boom, toboom;
bool st[N];

int main()
{
	cin >> n >> m;
	queue<PIII> q;
	for(int i = 1; i <= n; i ++ )
	{
		int a, b, r;
		cin >> a >> b >> r;
		boom.push_back({{a, b}, r});
	}
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, r;
		cin >> a >> b >> r;
//		toboom.push_back({{a, b}, r});
		q.push({{a, b}, r});
	}
	
	int res = 0;
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		int ll = t.first.first, rr = t.first.second;
		int r = t.second;
		for(int i = 0; i < boom.size(); i ++ )
		{
			if(st[i])	continue;
			int x = boom[i].first.first, y = boom[i].first.second;
			int z = boom[i].second;
			if(abs(x - ll) <= r && abs(y - rr) <= r)
			{
				st[i] = true;
				q.push({{x, y}, z});
				res ++ ;
			}
		}
	}

	cout << res << endl;
	
	return 0;
}
