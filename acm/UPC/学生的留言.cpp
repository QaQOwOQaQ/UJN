#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	int count=0; 
	cin >> n;
	getchar();
	while(n--)
	{
		string s;
		int flag;
		getline(cin,s);
		flag=s.find("Cinger"); 
		if(flag!=-1)
			count ++;
	}
	cout << count;
	return 0;
 } 
