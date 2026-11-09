#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int f[1010];
int main()
{
	int n;
	cin >> n;
	f[0] = f[1] = 1;
	for(int i=2;i<=n;i++)
	{
		f[i] = f[i-1];
		if(i%2==0)
			f[i]+= f[i/2];
	}
	cout << f[n];
	return 0;
	
 } 
//n=0: 1 0
//n=1: 1
//n=2: 2,12
//n=3: 3,12,
//n=4: 4,14,24,124
//n=5: 5,15,25,125
//n=6: 6,16,26,126,36,136
//n=7: 7,17,27,127,37,137
//n=8: 8,18,28,128,38,138,48,148,248,1248
