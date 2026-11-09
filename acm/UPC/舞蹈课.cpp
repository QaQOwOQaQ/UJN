#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
	int flag=5;
	flag=(flag+2*(n-1))%7;
	cout << flag<<endl;
	}
	
	//5 0 2 4 6 1 3 5
	
	return 0;
}
