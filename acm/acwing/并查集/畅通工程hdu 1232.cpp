#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;
const int maxn = 1010;
int pre[maxn];

void init(int n)
{
	for(int i=1;i<=n;i++)
		pre[i] = i;
}

int find(int x)
{
	if(pre[x] == x)
		return x;
	else
		return pre[x] = find(pre[x]);
}
int join(int x,int y)
{
	int jx = find(x);
	int jy = find(y);
	if(jx != jy)
	{
		pre[jy] = jx;	
		return 1;
	}
	return 0;

}
int main()
{
	int n,m,a,b;
	while(~scanf("%d%d",&n,&m) && n)
	{
		init(n);
		int ans = n-1;
		for(int i=1;i<=m;i++)
		{
  			scanf("%d%d",&a,&b);
  			if(join(a,b))
  				ans--;
			join(a,b);
		}
    		printf("%d\n",ans);		
	}
	return 0;
	
 } 
