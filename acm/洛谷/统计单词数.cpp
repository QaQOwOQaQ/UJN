#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]>='A' && s1[i]<='Z')
			s1[i]+= 32;
	}
	
	s1+= " ";
	s1.insert(0," ");
	s2+= " ";
	s2.insert(0," ");
	
	for(int i=0;i<s2.length();i++)
	{
		if(s2[i]>='A' && s2[i]<='Z')
			s2[i]+= 32;
	}
	
	int f,pre,ans = 0;	
	
	f = s2.find(s1);
	
	if(f == -1)
	{
		cout << f << endl;
		return 0;
	}
	
	pre = f;
	while(f != -1)
	{
		ans++;	
		s2 = s2.substr(f+s1.length()-1);	
//		cout << "f:" << f << endl;
//		cout << "É¾¸Äºó:" << s2 << endl;
		f = s2.find(s1);
	}

	cout << ans << " " << pre << endl;

	
	return 0;
	
 } 
