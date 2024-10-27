#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int N = 100010;

int n, s, m, q;
int id[N], w[110];
unordered_set<int> S;
unordered_map<int, int> mp;

int main()
{
	cin >> n >> s;
	for(int i = 0; i < n; i ++ )	
	{
		int x;	cin >> x;
		id[i] = x;
		S.insert(x);	
	}
	
	m = n / s;
	int now = 0;
	for(int i = 0; i < m; i ++ )//这里不可以开stk[N],否则内存超限 
	{
		for(int j = 1; j <= s; j ++ )	cin >> w[j];
		for(int j = s; j >= 1; j -- )
			mp[id[now ++ ]] = w[j];
	}
	
//	cout << "array: " << endl;
//	for(auto &x : mp)
//		cout << x.first << ' ' << x.second << endl;
//	
	cin >> q;
	while(q -- )
	{
		int x;	cin >> x;
		if(!S.count(x))	puts("Wrong Number");
		else	cout << mp[x] << endl;
	}
	
	return 0;
}
