#include<iostream>
#include<string.h>
using namespace std;
int vis[10][10];
int cnt=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
bool inside(int x,int y)
{
	if(x>=0&&x<=6&&y>=0&&y<=6)return true;
	else return false;
}
void dfs(int x,int y)
{
	if(x==0||x==6||y==0||y==6)
	{
		cnt++;
		return;
	}
	for(int i=0;i<4;i++){
		int cx=x+dx[i];
		int cy=y+dy[i];
		int rx=6-cx;//对称的点 
		int ry=6-cy;
		if(inside(cx,cy)&&!vis[cx][cy]){//对称设置vis成1的,判断一个就好 
			vis[cx][cy]=1;	
			vis[rx][ry]=1;
			dfs(cx,cy);
			vis[cx][cy]=0; 
			vis[rx][ry]=0;
		}
	}
}
int main(){
	memset(vis,0,sizeof(vis));
	vis[3][3]=1;
	dfs(3,3);
	cout<<cnt/4;
    return 0;
}
