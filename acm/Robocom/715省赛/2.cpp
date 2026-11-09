#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<string, char> ass;

void solve(string s)
{
	if(ass[s])	cout << ass[s] << endl;
	else 
	{
		int n = s.size(), cnt = 0;
		char a, b;
		for(int len = 1; len < n; len ++ )
		{
			string l = s.substr(0, len);
			string r = s.substr(len);
			if(ass[l] && ass[r])	
			{
				a = ass[l], b = ass[r];
				cnt ++ ;
			}
		}
		if(cnt != 1)	cout << "D" << endl;
		else	cout << a << b << endl;
	}
}

void init()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++ )
	{
		string s;	char d;
		cin >> s >> d;
		ass[s] = d;
	}
	while(m -- )
	{
		string s;	cin >> s;	
		solve(s);
	}
}

int main()
{
	init();
	return 0;
}
