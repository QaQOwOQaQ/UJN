#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int n;
	queue<int> a,b;
	while(1)
	{
		cin >> n;
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
			a.push(i);	
		cout << "Discarded cards: ";
		//a:  2 3 4 5 6 7
		//b: 1
		while(a.size()>1)
		{
			cout << a.front() << " ";	
			a.pop();
			a.push(a.front());
			a.pop();	
		}
		cout << endl << "Remaining card: " << a.front() << endl;
		a.pop();	
	}	
	return 0;
}

