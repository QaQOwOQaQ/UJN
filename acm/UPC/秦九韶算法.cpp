#include<iostream>
#include<cmath>
double algorithm(float a1,float q,float x)
{
	float ans=0;
	float xn=pow(x,6);
	float an=1;
	for(int i=0;i<=5;i++)
	{
		xn=xn/x;
		an=an*q;
		ans=ans+an*xn;
	}
	return ans;	
};
using namespace std;
int main()
{
	float a,b,c;
	while(scanf("%f%f%f",&a,&b,&c) !=EOF)
	{
	float ans;
	ans=algorithm(a,b,c);
	if(ans<100000000.0)
	printf("%.0f\n",ans);	
	}

	return 0;
}
