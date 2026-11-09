#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	char a[10];
	cin >> a;
	sort(a,a+5);
//	cout << a;
	for(int i=0;i<5;i++)
	{
		cout << a[i];
		if(a[i] > '3')
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

}
