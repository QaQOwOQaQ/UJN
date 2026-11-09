#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010 ,MAX = 1e6;

struct kkk
{
	char ch;
	int num;
	int pa, lc, rc;
}h[2 * N];

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++ )	cin >> h[i].ch >> h[i].num;	
	for(int i = 1; i <= 2 * n - 1; i ++ )	h[i].pa = h[i].lc = h[i].rc = 0; 
	
	for(int i = 1; i <= n - 1; i ++ )
	{
		int k;
		int num1 = MAX, num2 = MAX;	//两个最小值,规定num1 < num2 
		int idx1 = 0, idx2 = 0;	// 两个最小值的下标 
		for(int j = 1; j < n + i; j ++ )
		{
			if(h[j].num < num1 && !h[j].pa)	//如果这个数小于m1 
			{
				num2 = num1, num1 = h[j].num;
				idx2 = idx1, idx1 = j;
			} 
			else if(h[j].num < num2 && !h[j].pa)	//如果这个数小于m2 
				num2 = h[j].num, idx2 = j;
			
		} 
			k = n + i;
			h[idx1].pa = h[idx2].pa = k;
			h[k].num = num1 + num2;
			h[k].lc = idx1, h[k].rc = idx2;
	}
	
	for(int i = 1; i <= 2 * n - 1; i ++ )	
		cout << h[i].num << " " << h[i].lc << " " << h[i].rc << " " << h[i].pa << endl;	
	cout << endl;
	
	
	
	return 0;
}
