#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 20010
#define ll long long
#include<map>

using namespace std;

int pre[maxn];
map<string,int> m;
map<string,int>:: iterator it;
 
int find(int s)
{
	if(pre[s] == s)
		return s;
	else
		return pre[s] = find(pre[s]);
} 

void unite(int a,int b)
{
	int fa = find(a);
	int fb = find(b);
	if(fa != fb)
		pre[fa] = fb;
}

int isSame(int a,int b)
{
	int fa = find(a);
	int fb = find(b);
	if(fa != fb)
		return 0;
	return 1;
}

int main()
{
	int n,op,k;
	string s,a,b;
	cin >> n >> op;
	
	for(int i=1;i<=n;i++)
		pre[i] = i;
		
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		m.insert(pair<string,int>(s,i));
	}
	for(int i=1;i<=op;i++)
	{
		cin >> a >> b;
		unite(m[a],m[b]);
	} 
	cin >> k;
	for(int i=1;i<=k;i++)
	{
		cin >> a  >> b;
		isSame(m[a],m[b])==1 ? cout << "Yes." : cout << "No.";
		cout << endl;
	}
	return 0;
	
} 
