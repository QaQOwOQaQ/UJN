#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1000010, M = 2000100;

int n, m;
int pos[N];
vector<int> g[N];

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )
	{
		int k;	cin >> k;
		g[i].push_back(0);
		while(k -- )
		{
			int x; cin >> x;
			g[i].push_back(x);
		}
	}
	
	int now = 1;
	while(m -- )
	{
		int op, j;
		cin >> op >> j;
		if(op == 1)//´æµµ 
		{
			pos[j] = now;
			cout << now << endl;
		}
		else if(op == 2)//¶ÁÈ¡´æµµ 
		{
			now = pos[j];
		}
		else//op == 0ÒÆ¶¯ 
		{
			now = g[now][j];
		}
	}
	
	
	cout << now << endl;
	
	return 0;
}
