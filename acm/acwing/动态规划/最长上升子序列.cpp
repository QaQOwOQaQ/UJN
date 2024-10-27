#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int a[1010],f[1010];
int maxn = 1;
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int len = 1;
	f[1] = a[1];
	
	for(int i=2;i<=n;i++)
	{
		if(a[i] > f[len])
			f[++len] = a[i];
		else
		{
			int l = 1,r = len,mid;
			while(l <= r)
			{
				mid = (l+r)/2;
				if(f[mid] > a[i])
					r = mid - 1;
				else
					l = mid + 1;
			}
			f[l] = min(a[i],f[l]);
		}
	}
	
	for(int i=1;i<=len;i++)
		cout << f[i] << endl;
	cout << "最长上升子序列" << len << endl;
	
//	cout << len << endl;
	return 0;	
} 
/*

https://blog.csdn.net/zjwreal/article/detai
ls/91049705?ops_request_misc=%257B%2522request%
255Fid%2522%253A%2522163334774016780357284238%2522
%252C%2522scm%2522%253A%252220140713.130102334.pc%25
5Fall.%2522%257D&request_id=163334774016780357284238&
biz_id=0&utm_medium=distribute.pc_search_result.none-ta
sk-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-10-9104970
5.first_rank_v2_pc_rank_v29&utm_term=%E6%9C%80%E9%95%BF%E4%
B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97%E8%B4%AA%E5%BF%83&spm=1018.2226.3001.4187

*/

