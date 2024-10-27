#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

int n;
string s;
set<char> S;

int main()
{
	cin >> n;
	S.insert('a');
	S.insert('e');
	S.insert('i');
	S.insert('o');
	S.insert('u');
	while(n -- )
	{
		cin >> s;
		int len = s.size();
		int res = 0, t = 0;
		for(int i = 0; i < len; i ++ )
		{
			if(S.count(s[i])) t ++;
			else
			{
				res = max(res, t);
				t = 0;
			}
		}
		res = max(res, t);//在结尾一定要再判断一下
		cout << res << endl;
	}
	
	
	return 0;
}