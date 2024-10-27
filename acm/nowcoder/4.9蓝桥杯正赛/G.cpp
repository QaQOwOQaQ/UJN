#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const LL mod = 1000000007, N = 1000010;

LL n, res;
bool st[2][N];

int main()
{
	cin >> n;
	if(n == 1)	res = 1;
	else if(n == 2)	res = 2;
	else if(n == 3)	res = 5;
	else if(n == 4)	res = 9;
	else
	{
		for(int i = 0; i <= 200; i ++ )//heng
		{
			for(int j = 0; j <= 200; j ++ )//shu
			{
				for(int k = 0; k <= 200; k ++ )//san_jiao
				{
					if(i * 2 + j * 2 + k * 6 == n * 2)	res ++ ;
					if(k)	res ++ ;
				}
			}
		}
	}		
	cout << res << endl;
	
	return 0;
}
