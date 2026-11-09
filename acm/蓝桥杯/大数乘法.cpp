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
	if(s1=="0" || s2=="0")
	{
		cout << 0;
		return 0;
	}

	//初始化 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	int len1 = s1.length();
	int len2 = s2.length();
	for(int j=0,i=len1-1;i>=0;i--,j++)
		a[i] = s1[i] - '0';
	for(int j=0,i=len2-1;i>=0;i--,j++)
		b[i] = s2[i] - '0';
	
	//竖式相乘
	int len = len1 + len2 - 1;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<=i;j++)
			c[i] += a[j] * b[i-j];
		if(c[i]>9)
		{
			c[i+1] += c[i] / 10;
			c[i] %= 10;
		}
		
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
