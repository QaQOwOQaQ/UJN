#include<iostream>
#include<set>
#include<string>
#include<sstream>
using namespace std;
int main()
{
	//Adventures in Disneyland Two blondes were going to Disneyland when they came to a fork in the road. The sign read: "Disneyland Left." So they went home.
	set<string> q;
	set<string>::iterator it;
	string s;
	while(cin>>s)
{	
	if(s=="EOF")
		break;
/*	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]+32;
		if(s[i]>='a'&&s[i]<='z')
			s[i]=s[i];
		else
			s[i]=' '; 
	}
*/
	for(int i=0;i<s.length();i++)
	{
		if(isalpha(s[i]))
			s[i]=tolower(s[i]);
		else
			s[i]=' ';
	}
	stringstream ss(s);
	string t;
	while(ss >> t)
	q.insert(t);
	for(it=q.begin();it!=q.end();it++)
		cout << (*it) << endl;
	q.clear();
}
	return 0;
}
