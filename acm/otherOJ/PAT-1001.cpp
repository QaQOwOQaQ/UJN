#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1;

int main()
{
	int a, b, c;
	cin >> a >> b;
	c = a + b;
	bool flag = false;
	if(c < 0)	flag = true, c = -c;
    
    string s = to_string(c);
    int len = s.length();
    if(flag)	cout << '-';
    
    string res = "";
    
    for(int i = len - 1, j = 1; i >= 0; i -- , j ++ )
	{
		res += s[i];
		if(j == 3 && i)
		{
			res += ",";
			j = 0;
		}
	}
	reverse(res.begin(), res.end());
    cout << res << endl;
    
    return 0;
}
