#include<bits/stdc++.h>

using namespace std;

const int N=2e4+5,M=1e5+5;

int n,m,cnt,first[N],col[N],l,r;
struct Edge{
	int u,v,w,nxt;
}e[M<<1];

inline void add(int u,int v,int w){
	e[++cnt]=(Edge){u,v,w,first[u]};
	first[u]=cnt;
}
bool color(int u,int k){
	int f=0;
	for(re int i=first[u];i;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(w>k){
			if(col[v]==1)col[v]=col[u]^1,f|=color(v,k);
			else if(col[v]==col[u])return 1;
		}
		if(f)break;
	}
	return f;
}
inline bool check(int w){
	int f=0;
	for(re int i=1;i<=n;++i)col[i]=1;
	for(re int i=1;i<=n;++i){
		if(col[i]!=1)continue;
		col[i]=2;
		f|=color(i,w);
		if(f)break;
	}
	return !f;
}

int main()
{
	cin >> n >> m;
	for(re int i=1;i<=m;++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a,b,c);
		add(b,a,c);
		r=max(r,c);
	}
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
