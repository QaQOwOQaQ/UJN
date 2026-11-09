#include<iostream>
#include<vector>
using namespace std;
int main()
{	int n,x;
	vector<int> a;
	cin >> n;
	while(n--)
	{
		cin >> x;
		a.push_back(x);
	}
	for(int i=0;i<5;i++)
		cout << a[i] << " ";	
	cout << endl;

	return 0;
}
