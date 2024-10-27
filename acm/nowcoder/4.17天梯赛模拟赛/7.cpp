#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int n, k, x;
int w[N][N], s[N][N];

int main()
{
	cin >> n >> k >> x;
	for(int i = 1; i <= n; i ++ )
		for(int j = 1; j <= n; j ++ )
			cin >> w[i][j];
	
	int t = 0;
	for(int i = 1; i <= n; i ++ )//枚举每一列 
	{
		if(i % 2 == 0)
		{
			t ++ ;
			if(t > k)	t = 1;
		}
		for(int j = 1; j <= n; j ++ )//枚举每一行 
		{
			if(i % 2 == 0)//如果是偶数列 
			{
				if(j - t <= 0)	s[j][i] = x;
				else	s[j][i] = w[j - t][i];	
			}	
			else	s[j][i] = w[j][i];	
		}
	}
//	
//	cout << "new: " << endl;
//	for(int i = 1; i <= n; i ++ )
//	{
//		for(int j = 1; j <= n; j ++ )
//			cout << s[i][j] << ' ';
//		cout << endl;
//	}
//	
	for(int i = 1; i <= n; i ++ )
	{
		int sum = 0;
		for(int j = 1; j <= n; j ++ )
			sum += s[i][j];
		
		cout << sum;
		if(i != n)	cout << ' ';
	}
	
	return 0;
}
