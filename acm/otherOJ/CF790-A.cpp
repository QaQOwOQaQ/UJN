// Problem: A. Счастливый?
// Contest: Codeforces - Codeforces Round #790 (Div. 4)
// URL: https://codeforces.com/contest/1676/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1;

int t;

int main()
{
	cin >> t;
	while(t -- )
	{
		string s;
		cin >> s;
		int l = s[0] - '0' + s[1] - '0' + s[2] - '0';
		int r = s[3] - '0' + s[4] - '0' + s[5] - '0';
		if(l == r)	cout << "YES" << endl;
		else	cout << "NO" << endl;
	}
	
    
    return 0;
}
