#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{	map<int,string> a,b;
	a.insert(map<int, string>::value_type(1,"Diao"));
	a.insert(map<int, string>::value_type(2,"Giao"));
	a.insert(map<int, string>::value_type(3,"Tiao"));
	b.insert(pair<int, string>(1,"hahaha"));
	b.insert(pair<int, string>(2,"lalala"));
	b.insert(pair<int, string>(3,"xixixi"));
	b[3] = "xujiayuan";
	int size = a.size();
	map<int,string>::iterator it;
	for(it=a.begin();it!=a.end();it++)
		cout<< it->first <<' '<< it->second <<endl;
	for(it=b.begin();it!=b.end();it++)
		cout<< it->first <<' '<< it->second <<endl;
	cout << size;

	
	
	
	
	
	return 0;
} 
