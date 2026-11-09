#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ch[1100];
int main()
{
	int n;
	while(scanf("%s%d",ch,&n)!=EOF)
	{
		int len,i,sum=0;
		len=strlen(ch);
		for(i=0;i<len;i++)    //Ä£°å 
			sum=(sum*10+(ch[i]-'0'))%n;
		cout<<sum<<endl;
	}
	return 0;
}
