// 14/15
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <unordered_set>

//typedef pair<int,int> PII;
typedef long long LL;

using namespace std;

string swap_one(string s)
{
	for(auto &c : s)
	{
		if(c >= '0' && c <= '9')	continue;
		else if(isupper(c))	c = (c == 'Z') ? 'A' : c + 1;
		else	c = (c == 'a') ? 'z' : c - 1;
	}
	return s;
}

void reverse_one(char &c)
{
	if(c >= '0' && c <= '9')	return ;
	c = (isupper(c)) ? c + 32 : c - 32;
}

string swap_three(string s)
{
	int n = s.size();
	int i, j;
	int pre = -1;	// 0->lower; 1->upper
	for(i = 0, j = 0; i < n; i ++ )
	{
		if(isupper(s[i]) && pre == 1 || islower(s[i]) && pre == 0)	
		{}
		else // not match
		{
			// j, i - 1 i
			if(i - j >= 3)
			{
				for(int u = j; u <= i - 1; u ++ )	
					reverse_one(s[u]);
			}
			pre = (isupper(s[i])) ? 1 : 0; 
			if(s[i] >= '0' && s[i] <= '9')	j = i + 1, pre = -1;
			else	j = i;
		}
	}
	if(i - j >= 3)
		for(int u = j; u <= i - 1; u ++ )
			reverse_one(s[u]);
	return s;
}

string solve(string id, int n)
{
	string pw = id;
	while(n -- )
	{
		pw = swap_one(pw);
		pw = swap_three(pw);
	}
	return pw;
}

int main()
{
	int n;	cin >> n;
	string id;	cin >> id;
	cout << id << endl << solve(id, n) << endl;
	return 0;
}

