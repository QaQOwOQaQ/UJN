// 24/30
// 我用的二分，应该使用dp? 
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n;
int cnt[N], p[N], cur[N];

bool checkl(int x)
{
	memcpy(cur, cnt, sizeof cnt);
	for(int i = 0; i < n - 1; i ++ )
	{
		if(cur[p[i]] < cur[p[i + 1]])	
		{
			if( -- x < 0)	return false;
			cur[p[i + 1]] = cur[p[i]];
		}
	}
	return true;
}

bool checkr(int x)
{
	memcpy(cur, cnt, sizeof cnt);
	for(int i = n - 1; i >= 1; i -- )
	{
		if(cur[p[i]] > cur[p[i - 1]])
		{
			if( -- x < 0)	return false;
			cur[p[i - 1]] = cur[p[i]];
		}
	}
	return true;
}

void solve()
{	
	int l = 0, r = n;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(checkl(mid) || checkr(mid))	r = mid;
		else	l = mid + 1;
	}
//	cout << "Res: ";
	cout << l << endl;
}

// 2 2 1 1 0 
// 2 2 1 1 0 --->  0 1 1 2 2

void init()
{
	int T;	cin >> T;
	while(T -- )
	{
		memset(cnt, 0, sizeof cnt);
		cin >> n;
		for(int i = 1; i <= n; i ++ )
		{
			int a, b;	cin >> a >> b;
			cnt[i] = a + 1 - b;
		}
		for(int i = 0; i < n; i ++ )	cin >> p[i];
		
//		cout << "<=======================>\n";
//		for(int i = 1; i <= n; i ++ )	
//			cout << "[" << i << "] " << cnt[i] << endl;
//		cout << "<=======================>\n";
//			
		solve();
	}
}

int main()
{
	init();
	return 0;
}
