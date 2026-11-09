#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

string s1,s2;
const int maxn = 1010;
int a[maxn],b[maxn],c[maxn];

int main()
{
	string s1,s2;
	bool flag = 0;	//flag=1输出负号 
	int len1,len2,len;
	
	cin >> s1 >> s2;
	len1 = s1.length();
	len2 = s2.length();
	
	//判断大小
	if(len1<len2 || (len1==len2 && s1<s2)) 
	{
		flag = 1;
		swap(s1,s2);
		len1 = s1.length();
		len2 = s2.length();		
	}
	
	//初始化 
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int j=0,i=len1-1;i>=0;j++,i--)
		a[j] = s1[i] - '0';
	for(int j=0,i=len2-1;i>=0;j++,i--)
		b[j] = s2[i] - '0';
	
	//
//	cout << "测试数组1!!!" << endl;
//	for(int i=0;i<len1;i++)
//		cout << a[i];
//	cout << endl;	
//	for(int i=0;i<len2;i++)
//		cout << b[i];	
//	cout << endl << "测试数据" << endl; 
	
	//
	
	//竖式相减 
	len = max(len1,len2);
	for(int i=0;i<len;i++)
	{
		if(a[i] < b[i])
		{
			a[i+1] += 10; 
			cout << i << "小于了" << endl;
			a[i+1] --;	
			
//			cout << a[i] << " " << b[i] << "小于了！！！" << endl;
			
		}
		c[i] = a[i] - b[i];
	}
	
	//去前导零
	for(int i=len-1;i>=0;i--)
	{
		if(len>1 && c[i]==0)
			len--;
		else
			break;	
	} 

	//输出
	if(flag)
		cout << "-";
	for(int i=len-1;i>=0;i--)
		cout << c[i];
	cout << endl; 


	return 0;
	
} 
