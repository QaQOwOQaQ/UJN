#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

const int maxn = 510;
int m,n,op=0; 
int num[maxn],a[maxn][maxn],spot[maxn];
//colspan,rowspan
struct Node		//储存三元组 
{
	int row,col;
	int v;
	Node() {}
	Node(int a,int b,int c) : row(a),col(b),v(c) {}
	
};
struct Node node[maxn],rev[maxn];
int main()
{
	cin >> m >> n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			cin >> a[i][j];
			if(a[i][j] != 0)
			{
				node[++op] = Node(i,j,a[i][j]); //原三元组 		
				num[j]++;		
			}
		}
	}
	node[0] = Node(m,n,op);
	
//	cout << "原三元组	" << endl;
//	for(int i=1;i<=op;i++)
//		cout << node[i].row << " " << node[i].col << " " << node[i].v << endl;
		
	spot[1] = 1;
	for(int i=2;i<=n;i++)
		spot[i] = spot[i-1] + num[i-1];
		
//cout << "num" << endl;		
//	for(int i=1;i<=n;i++)
//		cout << num[i] << " ";
//	cout << endl;
//cout << "spot" << endl;
//	for(int i=1;i<=n;i++)
//		cout << spot[i] << " ";
//	cout << endl;


	for(int i=1;i<=op;i++) //转置矩阵 
	{
		int tmp = node[i].col;
		rev[spot[tmp]] = Node(node[i].col,node[i].row,node[i].v);
		spot[tmp]++;
	}
	

	cout << "转置后的矩阵：" << endl; 
	for(int i=1;i<=op;i++)
		cout << rev[i].row << " " << rev[i].col << " " << rev[i].v << endl;
	return 0;
	
} 


//2400
//3008
//0640

