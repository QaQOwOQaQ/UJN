#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;

int n, a[N];
int res;
int st, en;

int main()
{
	cin >> n;
    for(int i = 1; i <= n; i ++ )	cin >> a[i];
	
	bool flag = false;
	for(int i = 1; i <= n; i ++ )	
		if(a[i] >= 0)	
			flag = true;
	
	if(!flag)
	{
		cout << 0 << ' ' << a[1] << ' ' << a[n] << endl;
		return 0;
	}
	
	int t = 0, hh = 0, tt = 0;
    for(int i = 1; i <= n; i ++ )	
    {
    	if(t + a[i] >= 0)
    	{
    		if(t == 0)	hh = a[i];
    		t += a[i];
    		tt = a[i];
    	}
    	else
    	{
    		t = 0;
    	}
    	
    	if(t > res)
    	{
    		res = t;
    		st = hh;
    		en = tt;
    	}
    }
    
    cout << res << ' ' << st << ' ' << en << endl;
    
    return 0;
}
