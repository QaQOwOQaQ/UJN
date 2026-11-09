#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<set> 
#include<cstring>
#define ll long long

using namespace std;


int main()
{
	int n;
	while(cin >> n)
	{
		if(!n)
			break;
		set<string> a,b;
		string s1,s2;
		for(int i=0;i<n;i++)
		{
			cin >> s1 >> s2;
			a.insert(s1);	a.insert(s2);
			b.insert(s2);
		}			
		if(a.size()-b.size()==1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}	
	return 0;
	
 } 

