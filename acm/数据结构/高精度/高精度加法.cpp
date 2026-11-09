#include<iostream>
#include<string>
#include<cmath>
 
using namespace std;

const int maxn = 50010;

int a[maxn],b[maxn],c[maxn];
string s1,s2;
int len1,len2,len,jw;

int main()
{
	cin >> s1 >> s2;
	//初始化 
	len1 = s1.length();
	len2 = s2.length();
	for(int i=len1-1,j=0;i>=0;i--,j++)
		a[j] = s1[i] - '0';	
	for(int i=len2-1,j=0;i>=0;i--,j++)
		b[j] = s2[i] - '0';		
	
	//竖位相加 
	len = max(len1,len2) + 1;
	jw = 0;
	for(int i=0;i<len;i++)
	{
		c[i] = a[i] + b[i] + jw;
		jw = c[i] / 10;
		c[i] %= 10;
	}
	
	//删除前导0
	for(int i=len-1;i>=0;i--)
	{
		if(c[i]==0 && len>1)
			len--;
		else
			break;
	} 
	
	//输出数据
	for(int i=len-1;i>=0;i--)
		cout << c[i];
	cout << endl;
	return 0; 
}
