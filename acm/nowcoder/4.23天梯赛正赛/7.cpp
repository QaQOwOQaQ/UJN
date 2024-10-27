#include <iostream>
#include <algorithm>
#include <cstring>

using namespace  std;

const int N = 100010;

bool col[N], row[N];
int  p1, p2;

int main()
{
	int n, m, q;

	cin >> n >> m >> q;
	long long res = n * m;
	
	while(q -- )
	{
		int op, x;
		cin >> op >> x;
		if(op == 0)//hang
		{

			if(!row[x])
			{			p1 ++ ;
				row[x] = 1;
				res -= m;
			}
		}
		else//lie
		{

			if(!col[x])
			{			p2 ++ ;
				col[x] = 1;
				res -= n;
			}

		}
		
	}
	
	res += (p1 * p2);
	cout << res << endl;
	
	return 0;
}
