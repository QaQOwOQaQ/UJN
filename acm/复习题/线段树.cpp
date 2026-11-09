#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n, m;
int sum[N << 2], w[N], add[N];

void pushUp(int u)
{
    sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

void build(int u, int l, int r)
{
    if(l == r)  sum[u] = w[l];
    else
    {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushUp(u);
    }
}

void NodeUpdate(int u, int l, int r, int x, int c)    //w[x]+=c
{
    if(l == r)  sum[u] += c;
    else
    {
        int mid = l + r >> 1;
        if(x <= mid)  NodeUpdate(u << 1, l, mid, x, c);
        else    NodeUpdate(u << 1 | 1, mid + 1, r, x, c);
        pushUp(u);
    }
}

void pushDown(int u, int ln, int rn)
{
    if(add[u])
    {
        add[u << 1] = add[u];
        add[u << 1 | 1] = add[u];
        
        sum[u << 1] += add[u] * ln;
        sum[u << 1 | 1] += add[u] * rn;
        
        add[u] = 0;
    }
}

void EdgeUpdate(int u, int l, int r, int x, int y, int c)
{
    if(x <= l && y >= r)
    {
        sum[u] += c * (r - l + 1);
        add[u] += c;
    }
    else
    {
        int mid = l + r >> 1;
        pushDown(u, mid - l + 1, r - mid);
        if(x <= mid) EdgeUpdate(u << 1, l, mid, x, y, c);
    	if(y > mid)EdgeUpdate(u << 1 | 1, mid + 1, r, x, y, c);
        pushUp(u);
    }
}

int query(int u, int l, int r, int x, int y)
{
    int res = 0;
    if(x <= l && y >= r)    return sum[u];
    else
    {
        int mid = l + r >> 1;
        pushDown(u, mid - l + 1, r - mid);
        if(x <= mid)  res += query(u << 1, l, mid, x, y);
        if(y > mid)    res += query(u << 1 | 1, mid + 1, r, x , y);
    }
    return res;
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
