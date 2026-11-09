#include<iostream>
using namespace std;
int main()
{
	long long a,b;
	int n;
	cin >> n;
	while(n--)
	{

		cin >> a>> b;
		if(a%b==0)
			cout << "YES";
		else
			cout << "NO";
		cout<<endl; 
	}
	return 0;
 } 
