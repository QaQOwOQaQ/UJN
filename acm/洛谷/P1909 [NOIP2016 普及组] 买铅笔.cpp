#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
#include<limits.h>
const int maxn = INT_MAX;
using namespace std;
int main()
{
	int n,num[3],p[3],ans,t=maxn;
	cin >> n;
	for(int i=0;i<3;i++)
	{
		cin >> num[i] >> p[i];
		if(n % num[i] == 0)
			ans = n / num[i] * p[i];
		else
			ans = (n / num[i] + 1) * p[i]; 
		t = min(t,ans);	
	}
	cout << t << endl;
	
	
	return 0;
	
 } 
