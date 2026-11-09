#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[1010];

int main()
{
	int n;
	cin >> n;
	for(int i=n;i>=0;i--)
		cin >> a[i];
	for(int i=n;i>=0;i--)
	{
		if(a[i] == 0)
			continue;
		else if(a[i] > 0)
		{
			if((i == n) || (n == 1 && i == n) ) 
			{
				if(a[i] != 1)
					cout << a[i]; 
			}
			else
			{
				if(a[i] == 1 && i!=0)
					cout << "+";
				else
					cout << "+" << a[i]; 
			}
		}
		else	//if(a[i] < 0)
		{
			if(a[i] == -1 && i != 0)
				cout << "-";
			else
				cout << a[i]; 		
		}
		if(i == 1)
			cout << "x";
		else if(i != 0)
			cout << "x^" << i;
	}

	return 0;
	
 } 
