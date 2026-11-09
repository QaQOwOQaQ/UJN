#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{

	for(int i=1;i<=100;i++)
	{
		int cut=0,sum=0;
		for(int j=i;j<=100;j++)
		{
			sum+=j;
			cut++;
			if(sum-(cut-1)==100 && (cut-1)>i)
			{
				cout << cut-1;
				return 0;
			}
		}
	}

	return 0;
	
} 
