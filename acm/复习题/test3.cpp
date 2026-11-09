#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 5e6 + 10, M = 20;

struct Tree
{
	int l, r;
	int val;
}t[N * M];	

int n, m, loc, ver, top;
int node[N], w[N];

int copy(int root)
{
	t[++ top] = t[node];
	return top;
}

int build(int root, int l, int r)
{
	root = ++ top;
	if(l == r)
	{
		t[root].val = w[l];	
		return root;
	}	
	else
	{
		int mid = l + r >> 1;
		t[root].l = build()	
	}	
}

int main()
{
	scanf("%d%d", &n, &m);
	
	
	return 0;
}
