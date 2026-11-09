#include<iostream>
#include<set>
using namespace std;
int main()
{	multiset<int>a;
	multiset<int>::iterator it;
	int n,count=0,q;
	cin >> n;
	while(n--)
	{
		int t;
		cin >> t;
		a.insert(t);
	}
	for(it=a.begin();it!=a.end();it++)
	{
		if(a.count(*it)>count)
		{
			count = a.count(*it);
			q = *it;
		}	
	}
	cout << q;
	return 0;
} 
