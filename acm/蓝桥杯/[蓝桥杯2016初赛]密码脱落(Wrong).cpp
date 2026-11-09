#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<limits.h>
#define ll long long

using namespace std;

int ans = INT_MAX;
string s;

void func(int i,int j,int sum)
{
	if(i == j)
	{
		ans = min(ans,sum);	
		cout << ans << endl;	
		return ;		
	}
	if(i > j)
		return ;
	else
	{
		if(s[i]!=s[j])
		{
			return func(i,j--,sum++);	//在左边加 
			return func(i++,j,sum++);		//在右边加 
		}
		else
			return func(i++,j--,sum);
	}
	return ;
}

int main()
{
	while(cin >> s)
	{
		int len = s.length()-1;
		func(0,len,0);
		cout << ans << endl;
	}

	return 0;
	
} 


