#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map> 
#define ll long long

using namespace std;

int main()
{
	map<string,int> shop;
	map<string,int> ::iterator it;
	int n,m,p;
	string s;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
			cin >> s;
		cin >> m;
		for(int j=0;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
				cin >> p >> s;
				shop[s] += p;
			}
			int rank = 1;
			for(it=shop.begin();it!=shop.end();it++)
			{
				if(it->second > shop["memory"])
					rank++;
			}
			cout << rank << endl;
		}	
		shop.clear();	
	}


	return 0;
	
 } 
