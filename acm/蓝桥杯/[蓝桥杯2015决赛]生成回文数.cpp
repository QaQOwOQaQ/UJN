#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#define ll long long
using namespace std;
int a[1000];
string s;
bool judge(ll sum)//判断是不是回文数 
{
	stringstream s1;
	s1<<sum;
	s1>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-1-i])
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	int i;
	for(i=10;i<=200;i++)
	{
		ll temp=i;
		ll m=i;//保存原数 
		bool flag=true;
		int number=0;	//记录次数 
		while(flag==true)
		{
			int j=0;
			while(temp)//求其相反数 
			{
				a[j++]=temp%10;
				temp/=10;
			}
			ll sum=0;
			for(int i=0;i<j;i++)
			{
				sum=sum*10+a[i];
			}
			sum=sum+m;//两数的和 
			if(judge(sum))	//是回文数 
			{
				flag=false;
				break;
			} 
			temp=sum; 
			m=sum;
			number++;//运算的次数 
			if(number>20)//运算次数超过30 说明找到了 
			{
				printf("%d\n",i);
				break;
		//		return 0;
			}
		}
	}
	return 0;
}

