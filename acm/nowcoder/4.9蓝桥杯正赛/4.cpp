#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

const int N = 100010;

LL n;

int main()
{
	cin >> n;
	for(LL i = 1; i <= n; i ++ )
	{
		LL res = 0;
		res = 2 * max(abs(i - 1), abs(i - n));
		cout << res << endl;
	}
	
	return 0;
}
