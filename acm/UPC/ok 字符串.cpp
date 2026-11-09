#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const int N=1e6+2;
char s[N]; 
int main()
{
	int n,t;
	int o=0,k=0,sum=0,j=0;
	scanf("%d%d",&n,&t);
//	getchar();
	scanf("%s",&s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='o')
			o++;
		else
			k++;	
		while(o>t&&k>t)
		{
			if(s[j++]=='o')
				o--;
			else
				k--;
		}
	}
	sum=o+k;		
	printf("%d",sum);
	return 0;
 } 
