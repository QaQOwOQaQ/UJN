#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

const int maxn = 210;

struct point
{
	int x,y;
}pre[maxn][maxn],n1,n2;

void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			pre[i][j].x = i;
			pre[i][j].y = j;
		}
	}
}
point find(point k)
{
	if(k.x==pre[k.x][k.y].x && k.y==pre[k.x][k.y].y)
		return k;
	else
		return pre[k.x][k.y] = find(pre[k.x][k.y]);
}

int main()
{
	int n,m,x,y;
	cin >> n >> m;	
	init(n);
	char ch;
	for(int i=1;i<=m;i++)
	{
		cin >> x >> y; 
		cin >> ch;
		if(ch == 'D')	//向下连一条线 
		{
			n1 = find(pre[x][y]);
			n2 = find(pre[x+1][y]);
		}
		if(ch == 'R')	//向右连一条线 
		{
			n1 = find(pre[x][y]);
			n2 = find(pre[x][y+1]);		
		}
		if(n1.x==n2.x && n1.y==n2.y)
		{
			cout << i << endl;
			return 0;
		}
		else
			pre[n1.x][n1.y] = n2;		
	}
	cout << "draw" << endl;
	return 0;
	
 } 
