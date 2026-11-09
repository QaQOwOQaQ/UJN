#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int a[9]={1,2,3,4,5,6,7,8,9};

int main()
{
	int ans = 0;

	do{
		int t = a[3]*100 + a[4]*10 + a[5];
		int s = a[6]*100 + a[7]*10 + a[8];
		int x1 = a[0] * a[2] * s;
		int x2 = a[1] * s;
		int x3 = t * a[2];
		int x4 = 10 * a[2] * s;
		if(x1+x2+x3 == x4)
			ans++;
	
	}while(next_permutation(a,a+9));
	
	cout << ans << endl;
	
	return 0;
	
} 
