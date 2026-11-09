#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 50010;

int pre[N * 3], n, k, res;
//1-n同类，n-2n食物，2n-3n天敌 

int find(int x)
{
	if(pre[x] == x)	return x;
	return pre[x] = find(pre[x]);
}

void unite(int x, int y)
{
	int fx = find(x), fy = find(y);
	pre[fx] = fy;
}

int main()
{
	cin >> n >> k;
	/*极其不推荐这么写
	for(int i = 1; i <= n; i ++ )	 
	{
		pre[i] = i;
		pre[i + n] = i;
		pre[i + 2 * n] = i; 
	}
	*/
	for(int i = 1; i <= 3 * n; i ++ )	pre[i] = i;
	
	while(k -- )
	{
		int p, x, y;
		cin >> p >> x >> y;
		if(x > n || y > n)	res ++ ;
		else if(p == 1)
		{
			if(find(x) == find(y + n) || find(x) == find(y + 2 * n))	res ++ ;
			else
			{
				unite(x, y);
				unite(x + n, y + n);
				unite(x + 2 * n, y + 2 * n);
			}
		}
		else if(p == 2)
		{
			if(x == y || find(x) == find(y) || find(x) == find(y + n))	res ++ ;
			else	//一般把并查集划分了几个域，这里就有几个unite 
			{
				unite(x + n, y);
				unite(x, y + 2 * n);
				unite(x + n + n, y + n);
			}
		}
	}
	
	cout << res << endl;
	
	return 0;
}
