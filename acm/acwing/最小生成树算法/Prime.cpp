#include <iostream>
#include <limits.h>
#include <cstring>
#include <algorithm>

using namespace std;

const int n = 9;

int INF = INT_MAX;	//没有边直接相连的距离设为最大值 
int vex[10];	//最小权值边的起点 
int lowcost[10]; 	//最小权值的边 
bool check[10];

int G[9][9] = 
{
	{0, 4, INF, INF, INF, INF, INF, 8, INF}, 
	{4, 0, 8, INF, INF, INF, INF, 11, INF},
	{INF, 8, 0, 7, INF, 4, INF, INF, 2},
	{INF, INF, 7, 0, 9, 4, INF, INF, INF},
	{INF, INF, INF, 9, 0, 10, INF, INF, INF},
	{INF, INF, 4, 14, 10, 0, 2, INF, INF},
	{INF, INF, INF, INF, INF, 2, 0, 1, 6},
	{8, 11, INF, INF, INF, INF, 1, 0, 7},
	{INF, INF, 2, INF, INF, INF, 6, 7, 0}	
};

int main()
{
	//初始化 
	for(int i = 0; i < n; i ++ )
	{	
//		check[i] = 1;	//初始化所有点都没有走过 
		lowcost[i] = G[0][i]; //最小权值边都是从0出发的 
		vex[i] = 0;	//0作为所有最小权值边的起点 
	}	
	memset(check, true, sizeof check);
	
	
	for(int p = 1; p < n; p ++ )	//在lowcost中找到一条权值最小的边，不需要在遍历0 
	{
		int now = INF;	//当前状态下的最小权值边 
		int k = 0;	//保存最小权值边的起点 
		for(int j = 1; j < n; j ++ )	//找到指向最小边的起点	
		{
			if(check[j] && lowcost[j] && lowcost[j] < now)	//lowcost为0是一个环 
			{
				now = lowcost[j];	
				k = j;
			}	  		
		}	
		
		cout << "当前遍历到的定点:" << k << endl;
		check[k] = false;	//相当于到定点k已经有边了，不能再遍历了 
		
		for(int i = 0; i < n; i ++ )	//用起点更新权值最小的边 
		{
			if(check[i] && lowcost[i] && lowcost[i] > G[k][i])	
			{
				lowcost[i] = min(lowcost[i], G[k][i]);
				vex[i] = k;	
			}
		}
	
	cout << "当前权值最小的边：" << endl; 
	for(int i = 0; i < n; i ++ )
		cout << lowcost[i] << " ";
	cout << endl;
	}
	


	for(int i = 0; i < n; i ++ )	printf("(%d, %d)边的权值为：%d\n",vex[i], i, lowcost[i]);
	


	return 0;
}
