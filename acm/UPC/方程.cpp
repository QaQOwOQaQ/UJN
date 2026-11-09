#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		double a[3001]={0},c[3001]={0};
		scanf("%lf%lf",&a[0],&a[n+1]);
		c[0] = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&c[i]);
		}
		for(int i=1;i<=n;i++)
		{		
			a[i] = (a[i+1]+a[i-1]) / 2 - c[i];
		}
		printf("%.2f\n",a[1]);	
	}


	return 0;
}

