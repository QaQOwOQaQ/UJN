#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath> 

using namespace std;

const int N = 110;

int num[N], val[N], s[N], t[N];
int m, n, maxn;

int main()
{
	cin >> n;	//n个物品 
	for(int i = 1; i <= n; i ++ )	
	{
		cin >> val[i] >> num[i];
		maxn += val[i] * num[i]; 	//maxn表示最大价值
	}
	
	sort(val + 1, val + n + 1);	//可有可无 
	
	for(int i = 0; i <= num[1] * val[1]; i += val[1])//用最小的那个val初始化 	
		s[i] = 1;	
	
	for(int i = 2; i <= n; i ++ )	//遍历后面所有的多项式b,用b的每一项和当前多项式a相乘 
	{
		for(int j = 0; j <= maxn; j ++ )	//遍历当前多项式a的每一项 
		{
			for(int k = 0; k + j <= maxn && k <= num[i] * val[i]; k += val[i])	//遍历多项式b的每一项 
				t[k + j] += s[j];	//系数是由当前多项式a的系数决定的,b的每一项的系数肯定都是1 
		}
		
		for(int j = 0; j <= maxn; j ++ )	//注意不要写成i的循环,i变量此时还在使用 
		{
			s[j] = t[j];	
			t[j] = 0;
		}
	}
	cout << s[maxn] << endl;

	return 0;
} 

