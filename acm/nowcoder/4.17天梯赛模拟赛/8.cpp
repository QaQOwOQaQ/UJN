#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int m, n, idx;
int primes[1010];

bool check(int x)
{
	if(x < 2)	return false;
	for(int i = 2; i <= x / i; i ++ )
		if(x % i == 0)	return false;
	return true;
} 

void get_primes()
{
	for(int i = m; i <= n; i ++ )
		if(check(i))
			primes[idx ++ ] = i;
}

int main()
{
	cin >> m >> n;
	get_primes();
	
//	cout << "cnt: " << idx << endl;
//	for(int i = 0; i < idx; i ++ )
//		cout << primes[i] << ' ';
//	cout << endl;
	
	int res = 0;
	for(int i = 0; i < idx; i ++ )//p
	{
		for(int j = i + 1; j < idx; j ++ )//q
		{
			for(int k = j + 1; k < idx; k ++ )//r
			{
				if(check(primes[i] * primes[j] + primes[k]) 
				&& check(primes[j] * primes[k] + primes[i]) 
				&& check(primes[i] * primes[k] + primes[j]))
				{
//					cout << primes[i] << ' ' << primes[j] << ' ' << primes[k] << endl;
					res ++ ;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
