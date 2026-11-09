#include<stdio.h>
#include<math.h>
int main() 
{	int n;
	scanf("%d",&n);
	int a1[8],a3[8],a5[8],a7[8];
	int b1[8],b3[8],b5[8],b7[8];
	char b2,b4,b6;
	char a2,a4,a6;
	while(n--)
	{	
		//1,2,4,8,16,32,64,128
		for(int i=0;i<8;i++)
			scanf("%d",&a1[i]);
		scanf("%c",&a2);
		for(int i=0;i<8;i++)
			scanf("%d",&a3[i]);
		scanf("%c",&a4);
		for(int i=0;i<8;i++)
			scanf("%d",&a5[i]);
		scanf("%c",&a6);
		for(int i=0;i<8;i++)
			scanf("%d",&a7[i]);
		int s[4] = {0,0,0,0};
		//01000001
		for(int j=0;j<4;j++)
		{
			for(int i=0;i<8;i++)
			{
				s[j] = s[j] + pow(2,8-i);
			}
			printf("%d ",&s[j]);
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
