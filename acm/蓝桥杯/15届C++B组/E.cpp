// 暴力做法 
#include <iostream>
#include <cstring>
#include <algorithm>

#define int long long 

using namespace std;

const int N = 1e5 + 10;

int n, w[N];
double s;
int a, b, c;

int gcd(int _a, int _b)
{
	return _b ? gcd(_b, _a % _b) : _a;
}

int lcm(int _a, int _b)
{
	return _a * _b / gcd(_a, _b);	// a * b 爆 int 
}

void solve1()	// 暴力 O(N^3) 
{
	n = min(n, (long long)2010);
	for(int i = 0; i < n; i ++ )
	{
		for(int j = i + 1; j < n; j ++ )
		{
			for(int k = j + 1; k < n; k ++ )
			{
				int _a = w[i], _b = w[j], _c = w[k];
				int down = lcm(_a, _b) * lcm(_a, _c) * lcm(_b, _c);
				int up = lcm(lcm(_a, _b), _c);
				double cur = _a * _b * _c * up * 1.0 / down;
				if(cur > s)
				{
					s = cur;
					a = _a, b = _b, c = _c;
				}
			}
		}
	}
	cout << a << ' ' << b << ' ' << c << endl;
}

void init()
{
	cin >> n;
	for(int i = 0; i < n; i ++ )	cin >> w[i];
	sort(w, w + n);	
}

signed main()
{
	init();
	solve1();
	return 0;
}
