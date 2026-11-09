#include<iostream>
#include<set>
using namespace std;
int main()
{
	
	multiset<int,greater<int> > s;
	set<int>::iterator it;
	s.insert(1);
	s.insert(5);
	s.insert(7);
	s.insert(3);
	s.insert(3);
	for(it=s.begin();it!=s.end();it++)
	{
		cout << *it;
	}
	return 0;
}
