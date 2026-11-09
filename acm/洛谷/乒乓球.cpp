#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int main()
{
	string s="",str;
	while(cin>>str)
	{
		s+= str;
		if(str.find("E")!=-1)
			break;
	}

	if(s.length() == 0)
	{
		cout <<"0:0" << endl << endl << "0:0" <<endl;	
		return 0;	
	}

	int cut = 0,l = 0,r = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i] == 'E')
		{	
			cout << l << ":" << r << endl;
			break;
		}
		if(s[i] == 'W')	
			l++;
		else
			r++;
		if(abs(l-r)>=2 && (l>=11 || r>=11))
		{
			cout << l << ":" << r << endl;	
			l = 0;	cut = 0;	r = 0;;	
		}
//		if(i == s.length()-1)
//		{
//			if(l!=0 || r!=0)
//			{	
//				cout << l << ":" << r << endl;	
//				l = 0;	cut = 0;	r = 0;
//			}
//				
//		}
	}
	
	cout << endl;
	
	cut = 0,l = 0,r = 0;
	for(int i=0;i<s.length();i++)
	{
//		cout << "21Ê¤´Î:" << l << r<< endl;
		if(s[i] == 'E')
		{	
			cout << l << ":" << r << endl;
			break;
		}
		if(s[i] == 'W')
			l++;
		else
			r++;
		if(abs(l-r) >= 2 && (l>=21 || r>=21))
		{
			cout << l << ":" << r << endl;	
			l = 0;	cut = 0;	r = 0;;	
		}
//		if(i == s.length()-1)
//		{
//			if(l!=0 || r!=0) 
//			{
//				cout << l << ":" << r << endl;	
//				l = 0;	cut = 0;	r = 0;;				
//			}
//		}
	}
	return 0;
	
}

