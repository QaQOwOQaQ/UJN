#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;
int a[10];
int main()
{
	string str;
	int n;
	cin >> str >> n;
	for(int op=0;op<n;op++)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<str.length();i++)
			a[str[i]-'0']++;	
		
		//
		cout << "²âÊÔÊý×é:" << op+1 << endl;
		for(int i=0;i<=9;i++)
			cout << a[i] << " ";
		cout << endl;
		//
		
		string num="";
		for(int i=0;i<=9;i++)
		{
			if(a[i]!=0)
			{
				num += to_string(a[i]) + to_string(i);
				str = num;				
			}

		}	
		cout << "ans:" << str << endl; 
	}

	return 0;
	
} 
