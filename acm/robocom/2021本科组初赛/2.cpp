#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

#define int long long
#define endl "\n"

using namespace std;

typedef pair<int, int> PII;

int n, ans, cnt;
map<PII, vector<PII> > mp;//斜率映射到对应的距离加分数

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

signed main()
{
	cin >> n;
    for (int i = 0; i < n; i ++ )
    {
		int x, y, w; 
        cin >> x >> y >> w;
		ans += w;
		int d = gcd(abs(x), abs(y)); // 必须加绝对值
        PII k = {x / d, y / d}, v = {x * x + y * y, w};
        mp[k].push_back(v); //注意: 距离必须是x*x+y*y 单独的x是不行的因为还有y轴上的点
	}
	
	for(auto &p : mp)
	{
	    vector<PII> v = p.second;
	    sort(v.begin(), v.end());
	    int len = v.size();
	    for(int i = 0; i < len; i ++ )
	    {
	        if(v[i].second != 1) 
	        {
	            cnt ++ ;
	            if(i - 1 >= 0 && v[i - 1].second == 1)  cnt ++ ;
	        }
	    }
	    if(v[len - 1].second == 1)  cnt ++ ;
	}
	
	cout << ans << " " << cnt << endl;
	
	return 0;
}
