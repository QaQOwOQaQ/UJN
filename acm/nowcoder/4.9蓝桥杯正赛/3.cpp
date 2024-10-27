#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

LL a, b, n, res;

int main()
{
	cin >> a >> b >> n;
	LL w[10] = {a, a, a, a, a, b, b};
	LL week = a * 5 + b * 2;
	LL s = n / week;
	n = n - week * s;
	res = res + 7 * s;
//	cout << n << endl;
	if(n)
	{
		for(int i = 0; i < 7; i ++ )
		{
			n -= w[i];
			res ++ ;
			if(n <= 0)	break;
		}
	}

	cout << res << endl;
	return 0;
}
/*
10
10
70000000100
*/
