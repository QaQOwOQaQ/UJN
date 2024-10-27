/*
    贪心
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int T, n;
double w[N], m;

int main()
{
	cin >> T;
	while(T -- )
	{
		double sum = 0;
		bool flag = true;
		cin >> n >> m;
		for(int i = 0; i < n; i ++ )	
		{
			cin >> w[i], sum += w[i];
		}
		sort(w, w + n, greater<int>() );
		for(int i = 0; i < n; i ++ )
		{
			if(m < w[i])	
			{
				flag = false;
				break;
			}
			m = m - w[i] * 0.7;
		}
		if(flag)	puts("yes");
		elsea	puts("no");
	}
	
	
	return 0;
}