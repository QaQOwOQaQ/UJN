#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

bool cmp(string a,string b)
{
	return a+b > b+a;
}

string s[50];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++)
		cout << s[i];
	cout << endl;
	
	
	return 0;
	
 } 
