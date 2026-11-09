#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e6;

int n, m;
int sum[N << 2], w[N], lazy[N];

void pushUp(int u)
{
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

void build(int root, int l, int r)
{
	if(l == r)	sum[root] = w[l];
	else
	{
		int mid = l + r >> 1;
		build(root << 1, l, mid);
		build(root << 1 | 1, mid + 1, r);
		pushUp(root);
	}
}

void NodeUpdate(int root, int l, int r, int x, int c)
{
	if(l == r)	sum[root] += c;
	else
	{
		int mid = l + r >> 1;
		if(x <= mid)	NodeUpdate(root << 1, l, mid, x, c);
		else	NodeUpdate(root << 1 | 1, mid + 1, r, x, c);
		pushUp(root);
	}
}

void pushDown(int u, int ln, int rn)
{
	if(lazy[u])
	{
		int c = lazy[u];
		lazy[u << 1] = c;
		lazy[u << 1 | 1] = c;
		
		sum[u << 1] += c * ln;
		sum[u << 1 | 1] += c * rn;
		
		lazy[u] = 0;
	}
}

void EdgeUpdate(int root, int l, int r, int x, int y, int c)
{
	if(x <= l && y >= r)	
	{
		sum[root] += (r - l + 1) * c;
		lazy[root] = c;
	}
	else
	{
		int mid = l + r >> 1;
		pushDown(root, mid - l + 1, r - mid);
		if(x <= mid)	EdgeUpdate(root << 1, l, mid, x, y, c);
		if(y > mid)	EdgeUpdate(root << 1 | 1, mid + 1, r, x, y, c);
		pushUp(root);
	}
}

int query(int root, int l, int r, int x, int y)
{
	if(x <= l && y >= r)	return sum[root];
	else
	{
		int mid = l + r >> 1;
		pushDown(root, mid - l + 1, r - mid);
		int sum = 0;	
		if(x <= mid)	sum += query(root << 1, l, mid, x, y);
		if(y > mid)		sum += query(root << 1 | 1, mid + 1, r, x, y);
		return sum;
	}
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )   cin >> w[i];
    build(1, 1, n);
    
    //some test
   	cout << query(1, 1, n, 1, n) << endl;
   	
   	NodeUpdate(1, 1, n, 1, 5);	NodeUpdate(1, 1, n, 5, 5);
   	for(int i = 1; i <= n; i ++ )	cout << query(1, 1, n, i, i) << " ";
   	cout << endl;
	    
    EdgeUpdate(1, 1, n, 2, 4, 1);
   	for(int i = 1; i <= n; i ++ )	cout << query(1, 1, n, i, i) << " ";
   	cout << endl;
   	
    EdgeUpdate(1, 1, n, 1, 1, 2);
   	for(int i = 1; i <= n; i ++ )	cout << query(1, 1, n, i, i) << " ";
   	cout << endl;	
   	
    EdgeUpdate(1, 1, n, n, n, 2);
   	for(int i = 1; i <= n; i ++ )	cout << query(1, 1, n, i, i) << " ";
   	cout << endl;
}
