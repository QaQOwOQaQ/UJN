#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m, k, a[N][N], b[N][N];	//原矩阵，新矩阵 
int num[N], spot[N];

struct node
{
	int row, col, val;
}s[N], d[N];	//原三元表，新三元表 

bool cmp(const node &x, const node &y)
{
	return x.row < y.row;
}

int main()
{
	cin >> n >> m >> k;	//n行 m列 k个数据 
	
	for(int i = 1; i <= k; i ++ )
	{
		int x, y, z;
		cin >> x >> y >> z; 
		s[i] = {x, y, z}; 
		a[x][y] = z;
		num[y] ++ ;
	}
	
	spot[1] = 1;
	for(int i = 2; i <= m; i ++ )
		spot[i] = spot[i - 1] + num[i - 1];
	
	cout << "num: ";
	for(int i = 1; i <= m; i ++ )
		cout << num[i] << " ";
	cout << endl << "spot: ";
	for(int i = 1; i <= m; i ++ )
		cout << spot[i] << " ";
	cout << endl << "old:" << endl;
	for(int i = 1; i <= n; i ++ )
	{
		for(int j = 1; j <= m; j ++ )
			cout << a[i][j] << " ";
		cout << endl;	
	}		
	
	for(int i = 1; i <= k; i ++ )
	{
		int x = s[i].row, y = s[i].col, z = s[i].val;
		int pos = spot[y] ++ ;
		d[pos] = {y, x, z};	
		b[y][x] = z;
	}	
	
	sort(s + 1, s + k + 1, cmp);
	cout << "old three link: " << endl;
	for(int i = 1; i <= k; i ++ )
		cout << s[i].row << " " << s[i].col << " " << s[i].val << endl;
	
	sort(d + 1, d + 1 + k, cmp);	
	cout << "new three link: " << endl;
	for(int i = 1; i <= k; i ++ )
		cout << d[i].row << " " << d[i].col << " " << d[i].val << endl;
	

			
	
	
	return 0;
} 


/*测试数据1
4 5 8
1 2 5
1 3 5
1 4 5
1 5 8
2 1 1
2 3 3
3 2 -2
4 1 6

**测试数据2
10 9 24
1 5 1
2 4 2
2 6 2
3 3 3
3 7 3
4 2 4
4 3 4
4 4 4
4 6 4
4 7 4
4 8 4 
5 4 5
5 6 5
6 4 5
6 6 5
7 4 5
7 6 5
8 4 5
8 6 5
9 4 5
9 6 5
10 4 6
10 5 6
10 6 6
*/
