// 25/25
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;


typedef long long LL;
typedef pair<int,int> PII;

const int N = 1e5 + 10;

int n, m, l;
int t[N], cnt[N], a[N];
PII res[N]; // <id, time>

void init()
{
	cin >> n >> m >> l;
	for(int i = 1; i <= n; i ++ )	cin >> t[i];
	for(int i = 1; i <= l; i ++ )	cin >> a[i], res[i] = {i, t[a[i]]};
//	cout << "init_done!" << endl;
}

void out_answer()
{
//	cout << "res!" << endl;
	sort(res + 1, res + 1 + l, [&](const PII &lhs, const PII &rhs){ // <id, time>
		if(lhs.second == rhs.second)	return lhs.first < rhs.first;
		return lhs.second < rhs.second;
	});
	for(int i = 1; i <= l; i ++ )	cout << res[i].first << ':' << res[i].second << " \n"[i == l];
	for(int i = 1; i <= m; i ++ )	cout << cnt[i] << " \n"[i == m];
}

void solve()
{
	typedef pair<int,pair<int,int>> PIII;
	priority_queue<PIII, vector<PIII>, greater<PIII>> q; // <time, bucket_id, obj_id>
	for(int i = 1; i <= min(m, l); i ++ )
	{
		q.push({t[a[i]], {i, i}});
		cnt[i] ++ ;
	}
	for(int i = min(m, l) + 1; i <= l; i ++ )
	{
		auto cur = q.top();	q.pop();
		int bucket_id = cur.second.first;
		int cur_time = cur.first + t[a[i]];
		q.push({cur_time, {bucket_id, i}});
		res[i].second = cur_time;
		cnt[bucket_id] ++ ;
	}
	out_answer();
}

int main()
{
	init();
	solve();
	return 0;
}
/*
3种面 5个篮子 10个订单 
3 5 8
2 1 3 3 1 1 2 1 3 2
* 如果空闲的篮子不止一个，那么先放到其中编号最小的篮子里煮
* 如果有多个篮子里的面同时到了捞取时间，师傅会同时捞起
	但要本着先到先得的原则，按下单顺序招呼送餐。
* 下面、捞面和送餐的时长是可以忽略不计的
*/
