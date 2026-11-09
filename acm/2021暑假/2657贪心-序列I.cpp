#include<cstdio>
#include<algorithm>
using namespace std;

struct lx 
{
	int l, r, c;
}a[1005];

bool cmp(lx x, lx y) 
{ 
	return x.l > y.l;
} 

bool flag[1005]={0};

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) 
	{
		scanf("%d %d %d", &a[i].l, &a[i].r, &a[i].c);
	} 
	sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; i ++) 
	{
		int tot = 0;
		for(int j = a[i].l; j <= a[i].r; j ++) 
		{
			if(flag[j]) tot ++; 
		} 
	//	int val = a[i].c - tot;		//
		for(int j = a[i].l; j <= a[i].r; j ++) 
		{
			if( a[i].c <= tot) 
				break;
			if(!flag[j]) 	//²»¹» 
			{
				ans ++;
				tot++; 
				flag[j] = 1;
			} 
		}
	} printf("%d", ans);
}

