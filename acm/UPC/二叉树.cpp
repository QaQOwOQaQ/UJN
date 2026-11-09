#include<iostream>
#include<algorithm>
using namespace std;
 
int t1[1005];
int t2[1005];
 
void Func(int a, int b, int n, int flag)
{
	if (n == 1)
	{
		printf("%d ", t1[a]);
		return;
	}
	else if (n == 0)
		return;
 
	int i = 0;
	for (; t1[a] != t2[b + i]; i++);
	Func(a + 1, b, i, 0);
	Func(a + i + 1, b + i + 1, n - i - 1, 0);
 
	if (flag == 1)
		printf("%d", t1[a]);
	else
		printf("%d ", t1[a]);
}
 
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &t1[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &t2[i]);
 
		Func(1, 1, n, 1);
 
		printf("\n");
	}
 
	return 0;
}

