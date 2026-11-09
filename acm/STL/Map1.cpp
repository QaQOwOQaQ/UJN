#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{	int n;
	cin >> n;
	map<string,int> m;
	while(n--)
	{
		string s;
		cin >> s;
		if(m[s]!=0) //注册过了 
		{
			cout << s << m[s] << endl;
			m[s]++;
		}
		else	//没注册过 
		{
			cout << "OK" << endl;
			m[s]++;
		}
	}
	return 0;
}
