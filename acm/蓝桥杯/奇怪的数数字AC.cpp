#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;
int main()
{
	string S;
	int n;
	cin >> S >> n;
	for(int p=1;p<=n;p++)
	{
		string st = S + "0";
		string s="";
		int len = 1;
		for(int i=0;i<st.length()-1;i++)
		{
			if(st[i] != st[i+1])
			{
				s+= to_string(len) + st[i];
				len = 1;
			}
			else
				len++;
		}
		S = s;
		
		if(p==n)
		{
			for(int i=0;i<st.length()-1;i++)
				cout << st[i];
//			cout << endl;		
		}

	}

	return 0;
	
} 
