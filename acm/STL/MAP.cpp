
#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string str;
	map<string,int> ma;
	while(n--)
	{
		
		cin>>str;
		cout << "ma[str]:" << ma[str] << endl;
		if( ma[str]!= 0) {
			cout<<str<<ma[str]<<endl;
			ma[str]++;
		}else{
			cout<<"OK"<<endl;
			ma[str]=0;
			ma[str]++;
		}
	}
	return 0;
}



