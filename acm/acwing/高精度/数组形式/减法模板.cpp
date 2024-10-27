#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

const int maxn = 50010; 
int a[maxn],b[maxn],c[maxn];
string s1,s2;
bool pd = false; //s1<s2为false 
int len1,len2,len;
//高精度减法 s1 - s2 
int main()
{
	cin >> s1 >> s2;
	len1 = s1.length();
	len2 = s2.length();
	//s1-s2,判断s1和s2的大小,如果s1<s2,交换s1,s2,并标记pd=true,最后输出负号 
	if(len1 < len2 || (len1 == len2 && s1 < s2))//字符串比较大小从索引0开始逐位比较 
	{
		swap(s1,s2);
		pd = true;
		len1 = s1.length();
		len2 = s2.length(); 
	}


	//将字符串信息录入数组 
	for(int i=len1-1,j=0;i>=0;i--,j++)
		a[j] = s1[i] - '0'; 
	for(int i=len2-1,j=0;i>=0;i--,j++)
		b[j] = s2[i] - '0'; 
	
	//
//	cout << "/数组/" << endl;
//	for(int i=0;i<len1;i++)
//		cout << a[i];
//	cout << endl;
//	for(int i=0;i<len2;i++)
//		cout << b[i];
//	cout << endl;
//	cout << "/数组/" << endl;
	//
	
	//模拟竖式减法	
	len = max(len1,len2);
	for(int i=0;i<len;i++)
	{
		if(a[i] < b[i])	// 向高出借位
		{
			a[i+1] --;	//不能写成a[i++]--，这样会修改自变量i的值！！！！ 
			a[i] += 10;	
		} 
		c[i] = a[i] - b[i];
	}	
	
	//删除前导零 
	for(int i=len-1;i>=0;i--)
	{
		if(c[i] == 0 && len > 1)
			len--;
		else
			break;	
	}	
	
	//输出，有负号先输出负号
	if(pd)	
		cout << "-";
	for(int i=len-1;i>=0;i--)
		cout << c[i];
	cout << endl;	
	 
	return 0;
	
 } 
