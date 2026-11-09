#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

string s1,s2;
int a[1010],b[1010],c[1010];
int main()
{
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	
	//初始化 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int j=0,i=len1-1;i>=0;j++,i--)
		a[j] = s1[i] - '0';
	for(int j=0,i=len2-1;i>=0;j++,i--)
		b[j] = s2[i] - '0';
		
	//竖式相加
	int len = max(len1,len2) + 1;
	int jw = 0;
	for(int i=0;i<len;i++)
	{
		c[i] = a[i] + b[i] + jw;
		jw = c[i] / 10;
		c[i] %= 10;
	} 
	
	//去前导零
	for(int i=len-1;i>=0;i--)
	{
		if(c[i]==0 && len>1)
			len--;
		else
			break;	
	} 
	
	//输出 
	for(int i=len-1;i>=0;i--)
		cout << c[i];
	cout << endl;
	return 0;
	
} 
