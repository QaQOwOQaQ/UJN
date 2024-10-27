#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T -- )
	{
		bool flag = true;
		string s;
		cin >> s;
		int len = s.length();
		for(int i = 0; i < len - 1; i ++ )
		{
			if(s[i] >= 'A' && s[i] <= 'Z')//+32
			{
				if((s[i + 1] == s[i] + 32) || s[i + 1] == s[i] + 1)	continue;
				else	
				{
					flag = false;
					break;
				}
			}
			else
			{
				if((s[i + 1] == s[i] - 32) || s[i + 1] == s[i] - 1)	continue;
				else	
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)	cout << 'Y' << endl;
		else	cout << 'N' << endl;
	}
	

	
	return 0;
}
