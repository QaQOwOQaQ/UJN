#include <iostream>
#include <algorithm>
#include <cstring>

#define x first
#define y second

using namespace  std;

const int N = 100010;

typedef pair<int, int> PII;

int n, k, s, idx;
int res;
PII w[N];

bool cmp(PII a, PII b)
{
	if(a.x == b.x)	return a.y < b.y;
	return a.x > b.x;
}

int cnt[1010];

int main()
{
	cin >> n >> k >> s;
	for(int i = 1; i <= n; i ++ )
	{
		int a, b;
		cin >> a >> b;
		if(a >= 175)	w[idx ++ ] = {a, b};
	}
	
	sort(w, w + idx, cmp);
	
//	cout << "array:" << endl;
//	for(int i = 0; i < idx; i ++ )
//		cout << w[i].x << ' ' << w[i].y << endl;
	
	int last = -1;
	for(int i = 1; i <= idx; i ++ )
	{
		int a = w[i].x, b = w[i].y;
		if(a != last)
		{
			res ++ ;
			cnt[a] ++ ;
			last = a;
		}
		else if(a == last)
		{
			if(b >= s)	res ++ ;
			else 
			{
				if(cnt[a] < k)	cnt[a] ++ , res ++ ;
			}
		}
//		cout << "res: " << res << endl;
	}
	
	cout << res << endl;
	
	
	return 0;
}

/*
256 100
203 0
189 0
189 95
175 0
175 90

189 89
175 88

189 0



*/
