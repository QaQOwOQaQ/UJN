#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	int n,a,b,c,d;
	cin >> n;
	for(a=2;a<=n;a++)
	{
		for(b=2;b<=n;b++)
		{
			for(c=b;c<=n;c++)
			{
				for(d=c;d<=n;d++)
				{
					int p=a*a*a;
					int q=b*b*b+c*c*c+d*d*d;
					if(p==q)
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
					}
				}
			}
		}
	}

	return 0;
	
} 
