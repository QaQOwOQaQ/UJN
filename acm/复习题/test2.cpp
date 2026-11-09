#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e6 + 10;

struct Node
{
	int l, r;
	int v;
}t[N * 20];	//Ö÷Ï¯Ê÷¿ª20±¶ 

int top, n, m;
int w[N], node[N];

int copy(int node)
{
	t[++ top] = t[node];
	return top;
}

int build(int root, int l, int r)
{
	root = ++ top;
	if(l == r)	
	{
		t[root].v = w[l];
		return root;
	}
	int mid = l + r >> 1;
	t[root].l = build(t[root].l, l, mid);
	t[root].r = build(t[root].r, mid + 1, r);
	return root;
}

int update(int root, int l, int r, int loc, int val)
{
	root = copy(root);
	if(l == r)	t[root].v = val;
	else
	{
		int mid = l + r >> 1;
		if(loc <= mid)	t[root].l = update(t[root].l, l, mid, loc, val);
		else	t[root].r = update(t[root].r, mid + 1, r, loc, val);
	}
	return root;
}

int query(int root, int l, int r, int loc)
{
	if(l == r)	return t[root].v;
	
	int mid = l + r >> 1;
	if(loc <= mid)	return query(t[root].l, l, mid, loc);
	else	return query(t[root].r, mid + 1, r, loc);
}

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i ++ )	cin >> w[i];
	node[0] = build(0, 1, n);
	for(int i = 1; i <= m; i ++ )
	{
		int op, loc, ver, val;
		cin >> ver >> op >> loc;
		if(op == 1)	
		{
			cin >> val;
			node[i] = update(node[ver], 1, n, loc, val);
		}
		else
		{
			node[i] = node[ver];
			int res = query(node[ver], 1, n, loc);
			cout << res << endl;
		}
	}
	
	
	return 0;
}
