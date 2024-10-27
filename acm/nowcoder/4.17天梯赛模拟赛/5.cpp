#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int T, n, t;
	cin >> T;
	while(T -- )
	{
		cin >> n;
		int sum = 0;
		t = n * 2;
		bool flag = true;
		while(t)
		{
			sum += t % 10;
			t /= 10;
		}
		for(int i = 3; i <= 9; i ++ )
		{
			int tsum = 0;
			t = n * i;
			while(t)
			{
				tsum += t % 10;
				t /= 10;
			}
			if(tsum != sum)
			{
				flag = false;
			}
		}
	
		if(flag)	cout << sum << endl;
		else	cout << "NO" << endl;
	}
	
	
	
	return 0;
}
