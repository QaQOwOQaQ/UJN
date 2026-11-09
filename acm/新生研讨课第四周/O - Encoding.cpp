#include<bits/stdc++.h>
using namespace std;
int main()
{	int n,len,count;
	char s[100];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(s);
		len = strlen(s);
		count = 1;
		for(int i=0;i<len;i++)
		{
			if(s[i]!=s[i+1])
			{
				if(count==1)
					printf("%c",s[i]);
				else
					printf("%d%c",count,s[i]);
					count = 1;
			}
			else
				{
				count++;
				continue;
				}
		}
		printf("\n");
	}

	return 0;	
} 
