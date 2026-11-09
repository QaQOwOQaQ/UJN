#include<iostream>
#include<string>

using namespace std;

const int maxn = 1007;
int m,n,op,cut;
int c[maxn][maxn],pd[maxn];//pd[i]用来标记第i个原三元组是否已经放置到转置后的三元组 
struct node
{
	int row,col,val;
	node () {};
	node (int i,int j,int v):row(i),col(j),val(v) {}
};
struct node a[maxn],b[maxn];
int main()
{
	cin >> m >> n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> c[i][j];
			if(c[i][j])
				a[++op] = node(i,j,c[i][j]);			
		}
	}
	
	cout << "原三元组：" << endl;	
	for(int i=1;i<=op;i++)
		cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
	
	for(int p=1;p<=op;p++)
	{
		int minx = n + 10;
		int tmp = n + 1;	//用来找出最小靠前的列号 
		for(int i=1;i<=op;i++)
		{
			if(a[i].col < minx && pd[i] == 0)
			{
				minx = a[i].col;
				tmp = i;
			}
		
		}
		pd[tmp] = 1;
		b[++cut] = node(a[tmp].col,a[tmp].row,a[tmp].val);
	}


	cout << "转置后的三元组：" << endl; 
	for(int i=1;i<=op;i++)
		cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
		
	cout << "pd:" << endl;
	for(int i=1;i<=n;i++)
		cout << pd[i] << " ";
	cout << endl;
	return 0;
}



