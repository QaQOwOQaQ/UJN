#include<cstdio>
int n,m,f[40005],x,y;
char c;
int find(int x)//查找根节点
{
	if(x!=f[x]) f[x]=find(f[x]);
	return f[x];
}

int join(int x,int y)
{
	int jx = find(x);
	int jy = find(y);
	if(jx == jy)
		return 1;
	else
	{
		f[jx] = jy;
		return 0;
	}
} 
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*n;i++)//初始化
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d %c",&x,&y,&c);
		int r=(x-1)*n+y,l;//给两个要连的节点编号
		if(c=='D')
			l=x*n+y;
		else
			l=(x-1)*n+y+1;
		if(join(r,l))//判断是否源自同一棵树
		{
			printf("%d",i);
			return 0;
		}
		else join(r,l);
	}
	printf("draw");
	return 0;
}

