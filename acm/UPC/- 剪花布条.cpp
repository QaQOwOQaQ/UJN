#include<iostream>
#include<string>
#include<map> 
using namespace std;
int main()
{
	map<int,string> ms;
	string a[6]={"A","B","C","D","E","F"};
	int n,op,num;
	cin >> n;
	for(int i=0;i<n;i++) 
	{
		cin >> op;
		while(op--)
		{
			cin >> num;
			ms.insert(pair<int,string>(num,a[i]));
		}
	}
	map<int,string>::iterator it;
	for(it=ms.begin();it!=ms.end();it++)
	{
		cout << it->second; 
	}
	
	return 0;
}
