#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 100000
#define ll long long

using namespace std;
bool cmp(int x,int y)
{
	return x > y;
}
int pre[maxn],tmp[maxn],pd[maxn],ans[maxn];

int find(int x)
{
	if(tmp[x] == x)
		return tmp[x];
	return tmp[x] = find(tmp[x]);
}

void unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
		tmp[fx] = fy;
}

int main()
{
	int a,b,p,res=0;
	cin >> a >> b >> p;
	for(int i=a;i<=b;i++)
		tmp[i] = i;
	
	for(int i=p;i<=min(a,b);i++)
	{
		for(int j=a;j<=b;j++)
		{
			if(j%p == 0 && pd[j])
			{
				pd[j] = 1;
				unite(j%p,j);
			}
		}
	}
	
	for(int i=a;i<=b;i++)
		ans[find(i)]++;
	
	sort(ans,ans+b,cmp);
	for(int i=0;i<=b;i++)
	{
		if(ans[i] == 0)
			break;
		else
			res++;
	}
	cout << res << endl;
	return 0;
	
} 

