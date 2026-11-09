#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int func(int n)
{
	if(n==0)
		return 0;
	else if(n<=3)
		return 1;
	else
		return func(n-2)+func(n-3);
}
int main()
{
	int n;
	cin >> n >> k;
	cout << func(n);
	

	return 0;
	
 } 
