#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

double a,b,c,d;
double getAns(double x)
{
	return a*x*x*x + b*x*x + c*x + d;
}
int main()
{
	double m,l,r,x1,x2;
	int sum = 0;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	for(int i=-100;i<100;i++)
	{
		l = i;
		r = i + 1;
		x1 = getAns(l);
		x2 = getAns(r);

		if(!x1)
		{	
			sum++;
			printf("%.2lf ",l);
		}
		if(x1 * x2 < 0)
		{
			sum++;
			while(r-l >= 0.001)
			{
				m = l + (r - l) / 2;
				if(getAns(r) * getAns(m) < 0)
					l = m;
				else if(getAns(r) * getAns(m) > 0)
					r = m;
				else
				{
					if(!getAns(l))
						printf("%.2f ",l);
					else
						printf("%.2f ",r);

				}
			}
			  printf("%.2lf ",r); 
		}
		if(sum == 3)
			break;
		
	}
	
	
	
	
	return 0;
	
 } 
