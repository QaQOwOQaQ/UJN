#include<iostream>
using namespace std;
double sort(double x,double y)
{
	if(x>y)
		return x-y;
	else
		return y-x;
}
int main()
{
	double h,m,s,ans;
	double degh,degm;
	int n;
	cin >> n;
	while(n--)
	{
		
		cin >> h>> m>>s;
		if(h>=12)
		h=h-12;
		m=m+s*1.0/60;
		cout <<"m:"<< m << endl;
		h=h+m*1.0/60;
		cout <<"h:"<< h << endl;
		degh=h/24*360;
		cout <<"degh:"<< degh << endl;
		degm=m/60*360;
		cout <<"degm:"<< degm << endl;
		cout << (int)sort(degh,degm) << endl;

		
		
		
	 } 
	
	
	
	
	return 0;
 } 
