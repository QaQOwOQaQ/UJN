#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	string str;
	double num,f,s=0;
	while(cin >> str >> num >> f)
		s += num * 1.0 * f; 
	printf("%.1f\n",int(s)+round((s-int(s))*10)*1.0/10);
	
	

	return 0;
	
 } 
