#include <iostream>
#include <algorithm>
#include <cstring>

using namespace  std;

string get(string a)
{
	string s = "";
	int len = a.length();
	for(int i = 1; i < len; i ++ )
	{
		int l = a[i] - '0', r = a[i - 1] - '0';
		if(l % 2 == r % 2)
		{
			int maxn = max(l, r);
			s += to_string(maxn);
		} 
	}
	
	return s;
}

int main()
{
	string a, b;
	cin >> a >> b;
	
	string t1 = get(a);
	string t2 = get(b);
	
	if(t1 == t2)
		cout << t1 << endl;
	else
		cout << t1 << endl << t2 << endl;
	
	return 0;
}
