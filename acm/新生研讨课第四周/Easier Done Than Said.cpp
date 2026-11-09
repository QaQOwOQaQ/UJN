#include<stdio.h>
#include<string.h> 
int fun(char ch)    	//判断一个字符是否是元音 
{
	if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
		return 1;
	else
		return 0;
}
; 

int main()
{	char s[20];
	int len;
	int flag1; 	//判断是否含有元音
	int flag2,t1,t2;  //判断是否含有连续三个元音或者辅音;连续元音个数；连续辅音个数 
	int flag3;	//判断是否含有两个相同的字符（ee，oo除外） 
	while(scanf("%s",s)!=EOF)
	{	if(s[0]=='e' && s[1]=='n' && s[2]=='d')
			break;
		//初始化定义 
		t1 = 0;
		t2 = 0;
		flag1 = 0;
		flag2 = 1;
		flag3 = 1; 
		len = strlen(s);
//		printf("%d",len);
		//判断是否含有元音
		for(int i=0;i<len;i++)
		{
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
			{
			flag1 = 1;
			break;
			}
		}
		//判断是否含有两个相同的字符（ee，oo除外）
		for(int i=0;i<len-1;i++)
		{
			if( s[i]==s[i+1] && s[i]!='e' && s[i]!='o')
			{
				flag3 = 0;
				break;
			}
		}
		 //判断是否含有连续三个元音
		for(int i=0;i<=len;i++)				
		{	if(t1 == 3)
			{
				flag2 = 0;
				break;
			}
			else
			{
				if( fun(s[i]) == 1 )
					t1 = t1 + 1;
				else
					t1 = 0;
			}
		}
		//判断是否含有连续三个辅音 
		for(int i=0;i<=len;i++)				
		{	if(t2 == 3)
			{
				flag2 = 0;
				break;
			}
			else
			{
				if( fun(s[i]) == 0 )
					t2 = t2 + 1;
				else
					t2 = 0;
			}
		}

		//结论 
		if(flag1==1 && flag2==1 && flag3==1)
		{
		//	for(int i=0;i<len;i++)
				printf("<%s> is acceptable.\n",s);
		}
		else
		{
		//	for(int i=0;i<len;i++)
				printf("<%s> is not acceptable.\n",s);
		}
	}
	return 0;
}
