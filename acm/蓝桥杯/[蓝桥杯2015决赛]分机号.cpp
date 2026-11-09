#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	int ans = 0;
	for(int i=2;i<=9;i++)
	{
		for(int j=1;j<i;j++)	
		{
			ans+= j;
		}
	}
	cout << ans << endl;
	return 0;
} 
//9 [8[8],7[7],6,5,4,3,2,1,0] 
//
//3 [2[1,0],1,0]
//
//4 [3[2,1,0],2[2,0],1,0] 

