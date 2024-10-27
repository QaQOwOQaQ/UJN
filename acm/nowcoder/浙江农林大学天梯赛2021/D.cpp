#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
const int maxn=12;
int n,m,k;
bool vis[maxn][maxn];
ll dp[maxn][1<<maxn];
void dfs(int x, int y, int now, int Last) {
	if (y>m) {
		dp[x][now]+=dp[x-1][Last];
		return;
	}
	if (vis[x][y]) {
		dfs(x,y+1,now|(1<<(y-1)),Last|(1<<(y-1)));
	} else {
		dfs(x,y+1,now,Last|(1<<(y-1))); //空着 
		dfs(x,y+1,now|(1<<(y-1)),Last); //2x1和上一行拼凑 
		if (y!=m&&!vis[x][y+1]) { //可以1x2 
			dfs(x,y+2,now|(1<<(y-1))|(1<<y),Last|(1<<(y-1))|(1<<y));
		}
	} 
}
int main() {
	while (~scanf("%d%d%d",&n,&m,&k)&&n+m+k) {
		memset(vis,false,sizeof(vis));
		memset(dp,0,sizeof(dp));
		while (k--) {
			int x,y;
			scanf("%d%d",&x,&y);
			vis[x][y]=true;
		}
		dp[0][(1<<m)-1]=1;
		for (int i=1; i<=n; i++) {
			dfs(i,1,0,0);
		}
		printf("%lld\n",dp[n][(1<<m)-1]);
	}
	return 0;
}