//  ±º‰∏¥‘”∂» O(N * 8), N = 1e7
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, res;

bool check(int x)
{
	bool odd = true;
	while(x)
	{
		int t = x % 10;
		x /= 10;
		if(odd && t % 2 == 0)	return false;
		if(!odd && t % 2)	return false;
		odd = odd ? false : true;
	}
	return true;
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++ )
		res += check(i);
	cout << res << endl;
	
	return 0;
}

