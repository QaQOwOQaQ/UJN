#include<iostream>
#include<list>
using namespace std;
int main()
{
	list<int> a,b;
	list<int>::iterator it;
	int n,t;
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
			a.push_back(i);
		//a:       6
		//b: 135742
		while(a.size()>1)
		{
			b.push_back(a.front());	
			a.pop_front();
			t = a.front();
			a.pop_front();
			a.push_back(t);
		}
		cout << "Discarded cards: ";
		while(b.size()>1)
		{
			cout << b.front() << ", ";
			b.pop_front();
		}
		cout << b.front();
		b.pop_front();
		cout << endl; 
		cout << "Remaining card: " << a.front() << endl;
		a.pop_front();	
	}
	return 0;
}
