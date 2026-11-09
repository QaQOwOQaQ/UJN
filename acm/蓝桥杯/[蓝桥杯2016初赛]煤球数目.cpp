#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;
int a[110],b[110];
int main()
{

	a[1] = 1;
	b[1] = 1;
	for(int i=2;i<=100;i++)
	{
		a[i] += a[i-1] + i;
		b[i] += a[i] + b[i-1];
	}
	
//	for(int i=1;i<=10;i++)
//		cout << b[i] << endl;
		
	cout << b[100] << endl;
	return 0;
	
} 
