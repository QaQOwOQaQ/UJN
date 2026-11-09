#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int a[1010],ans[1010],b;
string s;

int main()
{
	cin >> s >> b;
	int len = s.length();
	memset(a,0,sizeof(a));
	memset(ans,0,sizeof(ans));
	
	//≥ı ºªØ 
	for(int i=0;i<len;i++)
		a[i+1] = s[i] - '0';
	
	ll tmp;
	for(int i=1;i<=len;i++)
	{
		a[i] += tmp*10;
		ans[i] = a[i] / b;
		tmp = a[i] - ans[i]*b ;
	}

	int i;
	for(i=1;i<=len;i++)
	{
		if(ans[i]!=0)
			break;
	}
	for(;i<=len;i++)
		cout << ans[i];
	cout << endl;
	return 0;
	 
} 
