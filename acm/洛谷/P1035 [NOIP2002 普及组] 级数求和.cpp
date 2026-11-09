#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	int k,i;
	cin >> k;
	double sum = 0;
	for(i=1;;i++)
	{
		sum += 1.0/i;
//		cout << "sum:" << sum << endl;
		if(sum > k)
			break;
	}
	cout << i << endl;
	
	return 0;
	
 } 
