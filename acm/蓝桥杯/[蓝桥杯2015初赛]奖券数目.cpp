#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	for(int a=0;a<=9;a++)
		for(int b=0;b<=9;b++)
			for(int c=0;c<=9;c++)
				for(int d=0;d<=9;d++)
					for(int e=0;e<=9;e++)
						for(int f=0;f<=9;f++)
							for(int g=0;g<=9;g++)
								for(int h=0;h<=9;h++)
							{
								int sum1=h*1000+d*100+e*10+f;
								int sum2=a*1000+b*100+c*10+d;
								int sum3=a*10000+b*1000+e*100+d*10+g;
								if(sum1+sum2==sum3
								&& a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h
								&& b!=c && b!=d && b!=e && b!=f && b!=g && b!=h
								&& c!=d && c!=e && c!=f && c!=g && c!=h
								&& d!=e && d!=f && d!=g && d!=h
								&& e!=f && e!=g && e!=h
								&& f!=g && f!=h
								&& g!=h
								)
									cout<<a<<b<<c<<d<<" "<<e<<f<<g<<endl;
							}
	



	return 0;
	
 } 
