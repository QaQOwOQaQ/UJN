#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char s[51];
	char m,n;
	scanf("%s %c %c",&s,&m,&n);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==m)
			printf("%c",n);
		else
			printf("%c",s[i]);
	}
	return 0;
 } 
