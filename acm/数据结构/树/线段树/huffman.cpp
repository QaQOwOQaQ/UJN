#include<iostream>
#include<stdlib.h>

using namespace std;

const int M = 50,MAX = 100;

typedef struct
{
	int date;
	int pa,lc,rc;
}Tree;

void huffman(int n,int w[],Tree t[])
{
	int k,x1,x2,m1,m2;
	for(int i = 1; i < (2 * n) ;  i ++ )
	{
		t[i].pa = t[i].lc = t[i].rc = 0;
		if(i < n)
			t[i].date = w[i];
		else
			t[i].date = 0;
	}	
	
	for(int i = 1; i < n; i ++ )
	{
		m1 = m2 = MAX;
		x1 = x2 = 0;
		for(int j = 1; j < (n + 1); j ++ )
		{
			if(t[i].date < m1 && t[j].pa == 0)
			{
				m2 = m1; x2 = x1;
				m1 = t[j].date;	x1 = j;
			}
			else
			{
				if(t[j].date < m2 && t[j].pa ==0)
				{
					m2 = t[j].date;	x2 = j;
				}
			}
			k = n + i;
			t[x1].pa = t[x2].pa = k;
			t[k].date = m1 + m2;
			t[k].lc = x1;	t[k].rc = x2;
		}
	}
}

int main()
{
	
	
	
	return 0;
}
