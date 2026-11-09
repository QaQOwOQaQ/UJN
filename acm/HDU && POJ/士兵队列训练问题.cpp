#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
#include<list>
#include<cstring>

using namespace std;

int main()
{
	int op;	cin >> op;
	for(int j=0;j<op;j++)
	{
		int n,k = 2;	
		cin >> n;
		list<int> ls;
		list<int> ::iterator it;
		for(int i=1;i<=n;i++)
			ls.push_back(i); 
		while(ls.size() > 3)
		{
			int cut1 = 1;
			for(it=ls.begin();it!=ls.end();)
			{			
				if(cut1++ % k == 0)
				{
					it = ls.erase(it);
				}
				else
					it++;
			}
			k == 2 ? k = 3 : k = 2; 		
		}
		
		for(it=ls.begin();it!=ls.end();it++)
		{	
			if(it != ls.begin())
				cout << " ";
			cout << *it ;	
		}
		cout << endl;	
	}

	

	return 0;
	
 } 
