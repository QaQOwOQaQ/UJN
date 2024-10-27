#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long LL;

const LL mod = 1000000007;

LL n, m, res = 0;

void dfs(LL a, LL b, LL s)
{
	if(s < 0 || a > n || b > m)	return ;
	if(s-(m-b) > 1)	return ;
	
	if(a == n && b == m)	
	{
		if(s == 1)	res = (res + 1) % mod;
	}
	
	if(a < n)	dfs(a + 1, b, s * 2);	
	
	if(b < m)	dfs(a, b + 1, s - 1);		
	
	
	return ;
}

int main()
{
	cin >> n >> m;
	m -- ;
	dfs(0, 0, 2);//Óöµ½¾Æµên¼Ò£¬»¨m¶ä£¬¾Æ2Éý 
	cout << res << endl;
	
	return 0;
}
