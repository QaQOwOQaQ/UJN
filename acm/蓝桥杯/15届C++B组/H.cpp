// ÐþÑ§×ö·¨ ... 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <random>
#include <ctime>

#define int long long 

using namespace std;

const int N = 1e3 + 10;

int n, w[N];
int avg, res;

void dfs(int u, int n, int cur) 
{
	if(u == n + 1)
	{
		res = min(res, abs(cur));
		return ;
	}
	dfs(u + 1, n, cur + w[u]);
	dfs(u + 1, n, cur - w[u]);
}

void rand_init()
{
	res = 0;
	srand(time(nullptr));
	n = 20;
	for(int i = 1; i <= n; i ++ )	
	{
		w[i] = rand() % 100000000;
		res += w[i];
	}
	sort(w + 1, w + 1 + n);
	avg = res / 2;
}

void init()
{
	res = 0;
	cin >> n;
	for(int i = 1; i <= n; i ++ )	cin >> w[i], res += w[i];
	sort(w + 1, w + n + 1);	
	avg = res / 2;
}

int solve1() // dfs±©ËÑ 
{
	dfs(1, n, 0);
	return res;
}

int solve2()
{
	vector<int> a, b;
	int sa = 0, sb = 0;
	for(int i = 1; i <= n; i ++ )
	{
		if(sa + w[i] <= avg)	a.push_back(w[i]), sa += w[i];
		else b.push_back(w[i]), sb += w[i];
	}
	int d = sa - sb;
	while(1)
	{
		bool flag = false;
		int lena = a.size(), lenb = b.size();
		int cur = d, pa, pb;
		
		for(int i = 0; i <= lena; i ++ )
		{
			for(int j = 0; j <= lenb; j ++ )
			{
				int wa = (i == lena) ? 0 : a[i];
				int wb = (j == lenb) ? 0 : b[j];
				int newd = d - 2 * wa + 2 * wb;
				if(abs(newd) < abs(cur))
				{
					cur = newd;
					pa = i, pb = j;
					flag = true;	
				}
			}
		}
		if(flag)
		{
			if(pa == lena)
			{
				a.push_back(b[pb]);
				b[pb] = 0;
			}
			else if(pb == lenb)
			{
				b.push_back(a[pa]);
				a[pa] = 0;
			}
			else
			{
				int t = a[pa];
				a[pa] = b[pb];
				b[pb] = t;
			}
			d = cur;
			flag = false;
		}
		else	break;
	}
	
	return abs(d);
}

signed main()
{
	init();
	if(n <= 20)	cout << solve1() << endl;
	else	cout << solve2() << endl;
	
	return 0;
}
