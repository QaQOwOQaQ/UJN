#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

#define int long long 

using namespace std;

const int N = 100010;

int n, p, q;
int w[N];
int res = 0;

signed main()
{
	cin >> n >> p >> q;
	priority_queue<int> heap;
	for(int i = 1; i <= n; i ++ )	
	{
		int x;	cin >> x;
		heap.push(x);
	}
	while(p || q)
	{
		auto t = heap.top();	heap.pop();
		int pt = sqrt(t);
		int qt = t / 2;
		if(!q)	heap.push(pt), p -- ;
		else if(!p)	heap.push(qt), q -- ;
		else 
		{
			if(pt < qt)
			{
				heap.push(pt);
				p -- ;
			}
			else 
			{
				heap.push(qt);
				q -- ;
			}
		}
	}
	while(heap.size())
	{
		res += heap.top();	
		heap.pop();
	}
	cout << res << endl;
	return 0;
}
