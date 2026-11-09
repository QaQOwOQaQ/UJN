#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath> 

using namespace std;

const int N = 500010;

int num[N], val[N], n;
int s[N], t[N], maxn;

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ )	//n个石子，每个石子的重量是val,数量是num 
	{
		cin >> val[i];	
		num[i] = 1;
		maxn += val[i] * num[i];
	}
	
	sort(val, val + n);
	
	for(int i = 0; i <= val[0] * num[0]; i += val[0]) s[i] = 1;
	
	for(int i = 1; i < n; i ++) 	//每一个多项式 
	{
		for(int j = 0; j <= maxn; j ++)	//当前（前面的）多项式的每一项 
		{
			for(int k = 0; k <= val[i] * num[i] && k + j <= maxn; k += val[i])	//该多项式可以取到的值 
			{
				t[k + j] += s[j]; 
			//	t[abs(k - j)] += s[j];
			} 
		}
		
		for(int j = 0; j <= maxn; j ++ )	s[j] = t[j], t[j] = 0;
	}
	
	int cnt = 0;
	for(int i = 1; i <= maxn; i ++ )
		if(s[i])
			cout << s[i]<< " ", cnt ++ ;
	
	cout << cnt << endl;
	

	
	return 0;
}
