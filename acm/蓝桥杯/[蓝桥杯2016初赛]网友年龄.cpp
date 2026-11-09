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
	for(int a=28;a<=99;a++)
	{
		int b = a - 27;
		int c = a%10*10 + a/10;
		if(b == c)
			ans++;
	}
	cout << ans << endl;

	return 0;
	
} 
