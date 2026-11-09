#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20010, M = 100010;

int n, m, res, pre[N << 1];

struct node
{
	int l, r, w;
}g[M];

bool cmp(const node &x, const node &y)
{
	return x.w > y.w;
}

int get(int x)
{
	if(pre[x] == x)	return x;
	return pre[x] = get(pre[x]);
}

void unite(int x, int y)
{
	pre[get(x)] = get(y);
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[i] = {a, b, c};
	}
	
	for(int i = 1; i <= n * 2; i ++ )	pre[i] = i;
	
	sort(g + 1, g + 1 + m, cmp);
	
	int res;
	for(int i = 1; i <= m; i ++ )
	{
		int x = g[i].l, y = g[i].r;
		int xx = get(x), yy = get(y);
		if(xx == yy)
		{
			res = g[i].w;
			break;		
			/*wrong写法,注意答案可能是0 
			cout << g[i].w << endl;
			return 0;
			*/ 
		}			
		//x和y是仇人,那么x的仇人和y是一个集合,同样y的仇人和x在一个集合 
		pre[xx] = get(y + n);
		pre[yy] = get(x + n);
	}
	cout << res << endl;
	return 0;
} 
