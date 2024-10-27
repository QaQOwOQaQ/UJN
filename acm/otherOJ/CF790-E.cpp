// Problem: B. Равенство конфет
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 150010;

int T, n, q;
long long a[N];

int main()
{
	cin >> T;
	while(T -- )
	{
		cin >> n >> q;
		for(int i = 1; i <= n; i ++ )	cin >> a[i];
		sort(a + 1, a + n + 1, greater<int>());
// 		
		// for(int i = 1; i <= n; i ++ )	
			// cout << a[i] << ' ';
		// cout << endl;
// 		
		for(int i = 1; i <= n; i ++ )	a[i] += a[i - 1];
// 		
		// for(int i = 1; i <= n; i ++ )	
			// cout << a[i] << ' ';
		// cout << endl;
		
		while(q -- )
		{
			int x;
			cin >> x;
			int l = 1, r = n;
			while(l < r)
			{
				int mid = l + r >> 1;
				if(a[mid] >= x)	r = mid;
				else	l = mid + 1;
			}
			if(a[r] < x)	r = -1;
			cout << r << endl;		
		}

			
	}

    
    return 0;
}
