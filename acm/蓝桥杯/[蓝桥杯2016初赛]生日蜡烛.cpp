#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	for(int a=1;a<=100;a++)
	{
		int sum = 0;
		for(int b=a;b<=100;b++)
		{
			sum += b;
			if(sum==236)
			{
				cout << a << endl;
				return 0;
			}
			if(sum > 236)
				break;
		}
	}

	return 0;
	
} 
