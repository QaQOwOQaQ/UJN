#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

#define x first
#define y second

#define debug2(x, y)	\
	cout << "debug: " << #x << " = " << x << "   " << #y << " = " << y << endl
#define debug1(x)	\
	cout << "debug: " << #x << " = " << x << endl
#define endl '\n'

#define int long long

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 50010;

int n, m;

int check(int a)//枚举a
{
	int c = pow(a, 3) - pow(a - 1, 3);
	int t = sqrt(c);
	if(t * t != c)	return 0;
	return sqrt(c);	
}

/*
为什么1 1 不是合法解呢？
读题!
因为题目要求的是正整数,而1的小弟0不是正整数！
*/

signed main()
{
	int cnt = 0;
	cin >> n >> m;
	for(int i = n; i <= m; i ++ )
	{
		if(check(i))
		{
			for(int j = 1; j * j <= 25000 * 25000; j ++ )
			{
				int s = j * j + (j - 1) * (j - 1); //1 1 不是合法解
				if(s == check(i))
				{
					if(i == 1 && j == 1)	continue;
					cout << i << ' ' << j << endl, cnt ++ ;
				}
			}
		}
	}
	
	if(!cnt)	cout << "No Solution" << endl;
	
    return 0;
}
