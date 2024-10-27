#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

#define x first
#define y second

#define debug2(x, y)	\
	cout << "debug: " << #x << " = " << x << "   " << #y << " = " << y << endl
#define debug1(x)	\
	cout << "debug: " << #x << " = " << x << endl
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010;

int T;
char g[30][30][30];

int main()
{
	for(int k = 0; k < 26; k ++ )
		for(int i = 0; i < 7; i ++ )
			for(int j = 0; j < 5; j ++ )
				cin >> g[k][i][j];

	getchar();
	string s;
	getline(cin, s);
	
	int len = s.length(), idx = 0;
	vector<char> v[20];
	
	for(int i = 0; i < len; i ++ )
	{
		char c = s[i];
		if(c >= 'A' && c <= 'Z')	v[idx].push_back(c);
		else idx ++ ;
	}
	
	vector<char> res[1110];
	int cnt = 0;
	
	// cout << "idx: " << idx << endl;
	
	for(int id = 0; id < idx; id ++ )
	{
		for(int i = 0; i < idx * 8; i ++ )	res[i].clear();
		
		for(int k = 0; k < v[id].size(); k ++ )
		{
			for(int i = 0; i < 7; i ++ )
			{
				for(int j = 0; j < 5; j ++ ) 
				{
					res[i].push_back(g[v[id][k] - 'A'][i][j]); 
					if(j == 4 && k != v[id].size() - 1)	res[i].push_back('*');	
				}
			}
		
		}
// 
		// cout << "debug: " << endl;
		// for(int i = 0; i < 7; i ++ )	cout << res[i].size() << ' ';
		// cout << endl;
			
		for(int i = 0; i < 7; i ++ )
		{
			for(int j = 0; j < res[i].size(); j ++ )
			{
				if(res[i][j] == '*')	cout << ' ';
				else	cout << res[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}


    return 0;
}
