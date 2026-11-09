#include<iostream>
using namespace std;
int main()
{
	
	int n;
	cin >>n;
	while(n--)
	{
		int count=0;
		int a,b,c;
		cin >> a >> b>>c;
		if(a>25)
			count ++;
		if(b>25)
			count++;
		if(c>25)
			count++;
		if(count==0)
			cout << "The Big Three People is Good!";
		if(count==1)
			cout << "The Big Three People is Better!";
		if(count==2)
			cout << "The Big Three People is Best!";
		if(count==3)
			cout << "The Big Three People is Excellent!";
		cout << endl;
	}

	return 0;
}
