#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	for(int a=1;a<=49;a++)
	{
		for(int c=1;c<=49;c++)
		{
			int b=a+1,d=c+1;
			if(1225-a-b-c-d+a*b+c*d==2015 && b<c)
				cout << a << endl;
		}
	}
	
	
	

	return 0;
	
 } 
