#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int N = 100010;

int n, idx;
unordered_map<int, string> name;

struct people{
	int id;
	int cnt;
	int sum;
}w[N];

bool cmp(const people &x, const people & y)
{
	if(x.cnt == y.cnt)		return x.sum < y.sum;
	return x.cnt > y.cnt;	
}

int main()
{
	cin >> n;
	for(int u = 0; u < n; u ++ )
	{
		string s;
		int k;
		cin >> s >> k;
		name[u] = s;
		unordered_set<int> S;
		for(int i = 0; i < k; i ++ )
		{
			int x;	cin >> x;
			S.insert(x);
		}
		w[u].id = u;
		w[u].cnt = S.size();
		w[u].sum = k;
	}
	
//	for(int i = 0; i < n; i ++ )
//		cout << name[w[i].id] << ' ' << w[i].cnt << ' ' << w[i].sum << endl;
//	
	sort(w, w + n, cmp);
	
//	cout << "new: " << endl;
//	for(int i = 0; i < n; i ++ )
//		cout << name[w[i].id] << ' ' << w[i].cnt << ' ' << w[i].sum << endl;
	
	if(n >= 3)
	{
		for(int i = 0; i < 3; i ++ )
		{
			cout << name[w[i].id];
			if(i != 2)	cout << ' ';
		}
		cout << endl;
	}
	if(!n)	puts("- - -");
	if(n == 1)
	{
		cout << name[w[0].id];
		puts(" - -");
	}
	if(n == 2)
	{
		cout << name[w[0].id] << ' ' << name[w[1].id];
		puts(" -");
	}
	
	
	return 0;
}



