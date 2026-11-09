#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int M = 100010;

int e[M], h[M], ne[M], idx;
int n, m, f[M];
bool st[M];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int val, int u)
{
    st[u] = true;
    for(int i = h[u]; i != -1; i = ne[i])
    {
    	int j = e[i];
    	if(!st[j])	
    	{
    	    f[j] = val;	dfs(val, j);
    	}
	}
}

int main()
{
    scanf("%d%d", &n, &m);
  	
  	for(int i = 1; i <= n; i ++ )	f[i] = i;
    memset(h, -1, sizeof h);
    
    while(m -- )
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(b, a);
    }
    
    for(int i = n; i >= 1; i -- )
    {
    	if(st[i])	continue;
    	dfs(f[i], i);
	}
    
    for(int i = 1; i <= n; i ++ )	printf("%d ",f[i]);

    return 0;
}
