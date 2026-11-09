#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int>::iterator it;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int m,op;
	cin >> m;
	while(m--)
	{
		cin >> op;
		it = lower_bound(a.begin(),a.end(),op);
//		cout << "POSITION:" << (it-a.begin())+1 << endl;
//		cout << "val:" << a[(it-a.begin())] << endl;
/*		if(a[(it-a.begin())]==op)
		cout << "Yes " <<  (it-a.begin())+1  << endl;
		else
		cout << "No " <<   (it-a.begin())+1  << endl;
*/
	cout << it-a.begin();
	}
	return 0;
}
