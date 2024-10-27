#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int n = 14;

struct edge	
{
	int b, e;	//一条边的起点和终点 
	int v;	//权值 
	edge() {}
	edge(int x,int y, int z) : b(x), e(y), v(z) {}
}E[n], res[n];	//边集数组,最小生成树的边集数组  


int par[n + 1];	//定义前驱数组,作用是判断是否有环 
int cut;	//记录最小生成树的边集数组的大小 

bool cmp(const edge &x, const edge &y)
{
	if(x.v == y.v)
		return x.b < y.b;
	return x.v < y.v;
}

int find(int x)
{
	while(par[x] != x)
		x = par[x];
	return x;
}

int main()
{	
	for(int i = 0; i < n; i ++ )	//初始化边集数组,代码最下方有测试数据 
	{
		char x, y;
		int t;
		cin >> x >> y >> t;
		E[i] = edge(x - 'a' + 1, y - 'a' + 1, t);	//将a换成1,b换成2,往后以此类推 
	}	

	sort(E, E + n, cmp);	//将所有边按权值升序排序
	
	for(int i = 0; i <= n; i ++ )	par[i] = i;	//初始化前驱数组的前驱为自己 	
	
	cout << "排序后边集数组如下:" << endl;
	for(int i = 0; i < n; i ++ )
	{
		char c1 = E[i].b + 'a';
		char c2 = E[i].e + 'a';
		cout << c1 << " " << c2 << " " << E[i].v << endl; 
//		cout << E[i].b << " " << E[i].e << " " << E[i].v << endl;			
	}
	cout << endl; 

	for(int i = 0; i < n; i ++ )	//遍历所有边
	{
		int l = find(E[i].b), r = find(E[i].e);	//要找到最开始的前驱节点,可以认为是父节点 
		if(l != r)	//如果不会形成环 
		{
			par[r] = l;	//修改前驱数组	
			res[cut ++] = edge(E[i].b, E[i].e, E[i].v);
		}
	} 
	
	//
	cout << "最小生成树边集数组如下:" << endl;
	for(int i = 0; i < cut; i ++ )
	{
		char c1 = res[i].b + 'a';
		char c2 = res[i].e + 'a';
		cout << c1 << " " << c2 << " " << res[i].v << endl; 
//		cout << res[i].b << " " << res[i].e << " " << res[i].v << endl;		
	}
	cout << endl; 
	//	
	
	

	return 0;	
} 


/*测试数据 
a b 4
a h 8
b h 11
h i 7
i c 2
b c 8
h g 1
g f 2
c f 4
c d 7
d f 14
d e 9
f e 10
i g 6
*/

