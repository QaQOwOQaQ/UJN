#include<iostream>
#include<string>
#include<cmath>
 
using namespace std;

const int maxn = 50010;

int a[maxn],b[maxn],c[maxn];
string s1,s2;
int len1,len2;
bool pd = false;

int main()
{
	cin >> s1 >> s2;
	
	//判断大小	
	len1 = s1.length();
	len2 = s2.length();
	if(len1==len2&&s1<s2 || len1<len2)	//s1<s2 有负号 	
	{
		pd = true;
		swap(s1,s2);
		len1 = s1.length();
		len2 = s2.length();
	}
	
	cout << "s1:" << s1 << endl << "s2:" << s2 << endl;
	//初始化 
	for(int j=0,i=len1-1;i>=0;i--,j++)
		a[j] = s1[i] - '0';
	for(int j=0,i=len2-1;i>=0;i--,j++)
		b[j] = s2[i] - '0';


	//
//	cout << "数组a:";
//	for(int i=0;i<len1;i++)
//		cout << a[i];
//	cout << endl;
//	cout << "数组b:";
//	for(int i=0;i<len2;i++)
//		cout << b[i];
//	cout << endl;
	//
	
	
	//竖位相减 
	for(int i=0;i<len1;i++)
	{
		if(a[i] < b[i])
		{
			a[i]+= 10;
			a[i+1]--;
		}
		c[i] = a[i] - b[i];
	}
	
	//删除前导零
	for(int i=len1-1;i>=0;i--)
	{
		if(c[i]==0 && len1>1)
			len1--;
		else
			break;	
	} 

	if(pd)
		cout << "-";
	for(int i=len1-1;i>=0;i--) 
		cout << c[i];
	cout << endl;
	
	
	
	
	
	
	return 0; 
}
