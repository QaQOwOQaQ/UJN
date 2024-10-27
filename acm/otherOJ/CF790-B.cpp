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

const int N = 100010;

int T;
int n, a[N];

int main()
{
	cin >> T;
	while(T -- )
	{
		cin >> n;
		int sum = 0, minx = 1e9;
	    for(int i = 1; i <= n; i ++ )	
	    {
	    	cin >> a[i];
	    	minx = min(minx, a[i]);
	    	sum += a[i];
	    }
	
	    cout << sum - minx * n << endl;
	    
	    
	}

    
    
    return 0;
}
