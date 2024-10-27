#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;
const int maxn = 1010;
int pre[maxn],root[maxn];

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
void join(int x,int y)
{
	int jx = find(x);
	int jy = find(y);
	if(jx != jy)
		pre[jx] = jy;	
}
int main()
{
	int n,m,a,b;
	while(~scanf("%d%d",&n,&m) && n)
	{
		memset(root,0,sizeof(root));
		init(n);
		int ans = 1;
		//
//		cout << "父亲数组" << endl;
//		for(int i=1;i<=n;i++)
//			cout << find(i) << " ";
//		cout << endl;
		//
		for(int i=1;i<=m;i++)
		{
  			scanf("%d%d",&a,&b);
  			join(a,b);
  			//
//			cout << "父亲数组" << endl;
//			for(int i=1;i<=n;i++)
//				cout << find(i) << " ";
//			cout << endl;
			//
		}
			for(int i=1;i<=n;i++)
				root[i] = find(i);
			sort(root+1,root+1+n);
			for(int i=2;i<=n;i++)
			{
				if(root[i]!=root[i-1])
					ans++;
			}
    		printf("%d\n",ans-1);		
	}
	return 0;
	
 } 
