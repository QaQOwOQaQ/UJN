#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

double f(double x,int n)
{
	if(n == 2)
		return sqrt(2 + sqrt(1+x));
	else
		return sqrt(n + f(x,n-1));
}

int main()
{
	int n;
	double x,ans;
	scanf("%lf%d",&x,&n);
	ans = f(x,n);
	printf("%.2f",ans);
	

	return 0;
	
} 
