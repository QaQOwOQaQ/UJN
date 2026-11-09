#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	int a[7],b[7],sum,maxn = 0,flag = 0; 
	for(int i=1;i<=7;i++)
	{
		cin >> a[i] >> b[i];
		sum = a[i] + b[i];
		{
			if(sum > maxn)
			{
				flag = i;
				maxn = sum;
			}	
		}

	}
	if(maxn <= 8)
		cout << 0;
	else
		cout << flag;
	cout << endl;
	return 0;
	
 } 
