#include<iostream>
#include<cmath>
#include<string>

using namespace std;

const int maxn = 50010;
int a[maxn],b[maxn],c[maxn];
int len1,len2,len;
string s1,s2;

int main()
{
	cin >> s1 >> s2;
	
	//特判 
	if(s1=="0" || s2=="0")
	{
		cout << 0;
		return 0;
	}
	
	//初始化 
	len1 = s1.length();
	len2 = s2.length();
	for(int j=0,i=len1-1;i>=0;i--,j++)
		a[j] = s1[i] - '0';
	for(int j=0,i=len2-1;i>=0;i--,j++)
		b[j] = s2[i] - '0';	
	
	//竖式相乘
	len = len1 + len2 - 1;
	for(int i=0;i<len;i++)
	{
		for(int j=0;j<=i;j++)
			c[i] += a[j] * b[i-j];
		//进位
		if(c[i] >= 10)
		{
			c[i+1] += c[i]/10;
			c[i] %= 10;	
		} 
	} 
	
	//去前导零，i从len开始，例如5*5=25，答案需要2个长度，但是分配时只给了1+1-1=1个长度，所以长度要加1 
	for(int i=len;i>=0;i--)	
	{
		if(c[i]==0 && len>1)
			len--;
		else
			break;	
	} 
	
	//逆序输出 
	for(int i=len;i>=0;i--)	//输出时也从len开始 
		cout << c[i];
	cout << endl;
	
	return 0;
} 

//https://blog.csdn.net/qq_47982709/article/details/119394793?ops_requ
//est_misc=%257B%2522request%255Fid%2522%253A%2522163292991416780262536
//487%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257
//D&request_id=163292991416780262536487&biz_id=0&utm_medium=distribute.pc_se
//arch_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-12-1193947
//93.pc_search_result_control_group&utm_term=%E9%AB%98%E7%B2%BE%E5%BA%A6%E4%B9
//%98%E6%B3%95&spm=1018.2226.3001.4187
