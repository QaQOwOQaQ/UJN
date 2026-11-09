#include<iostream>
#include<string>

using namespace std;

const int maxn = 1007;
int m,n,op;
int c[maxn][maxn],num[maxn],cpot[maxn];
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
			{
				a[++op] = node(i,j,c[i][j]);
				num[j]++;	
			}			
		}

	}
	
	cout << "原三元组：" << endl;	
	for(int i=1;i<=op;i++)
		cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
	
	cpot[1] = 1;
	for(int i=2;i<=op;i++)
		cpot[i] = cpot[i-1] + num[i-1];
	
//	for(int i=1;i<=n;i++)
//		cout << num[i] << " ";
//	cout << endl;
//	for(int i=1;i<=n;i++)
//		cout << cpot[i] << " ";

	for(int i=1;i<=op;i++)
	{
		int tmp = a[i].col;
		b[cpot[tmp]] = node(a[i].col,a[i].row,a[i].val);
		cpot[tmp]++;
	}
	
	cout << "转置后的三元组：" << endl; 
	for(int i=1;i<=op;i++)
		cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
		
	cout << endl;
	return 0;
}

//text:
//3 4
//
//2 4 0 7
//0 0 1 0
//3 5 0 0
//
//2 0 3
//4 0 5
//0 1 0
//7 0 0

