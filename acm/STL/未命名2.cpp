#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{	
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int>::iterator it;
	for(int i=0;i<n;i++)
/*	{
		int t;
		cin >> t;
		a.push_back(t); 	
	}
*/
		cin >> a[i];
	int ex1,ex2,ex3;
	cin >> ex1;
	a.erase(a.begin()+ex1-1);
	cin >> ex2 >> ex3;
	a.erase(a.begin()+ex2-1,a.begin()+ex3-1);
	cout << a.size() << endl;
	for(it=a.begin();it!=a.end();it++)
		cout << *it << " ";
//	cout << a[a.size()-1] << endl;
	return 0;
}
