#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
int main()
{
	int n,flat,j;
	char s[1001];
	cin>>n;
	getchar();
    while(n--)
	{
		gets(s);
		flat=0;
		for(int i=0;s[i]!='\0';i++)
		{
		   if(s[i]==' ')
		   {
		   	for(j=i-1;j>=flat;j--)
		   	printf("%c",s[j]);
		   	flat=i+1;
		   	cout<<" ";
		   }
		   if(i==strlen(s)-1)
		   {
		   	for(j=i;j>=flat;j--)
		   	printf("%c",s[j]);
		   }
		}
		printf("\n");
	}
	

}

