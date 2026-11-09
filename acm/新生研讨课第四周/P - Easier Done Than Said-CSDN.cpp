#include<stdio.h>
#include<string.h> 
char s[100]; 
int main()
{
	while(scanf("%s",s)!=EOF)
{
	if(s[0]=='e' && s[1]=='n' && s[2]=='d')
			break;    //end 结束
  	int len=strlen(s);
  	int flag1=0,flag=0;               //flag1 表示是否出现过元音,flag 表示是否有不符合条件2、3的情况
  	int a=0,b=0;                       // a 表示连续的元音, b 表示连续的辅音
  	for(int i=0;i<len;i++){
  	if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' ||s[i]=='u')
    	{
  	  	flag1 = 1;
  	  	a++;
  	  	b=0;
  	    }
	else b++,a=0;
  	  if(a==3 || b==3)
	  {
  	  	flag = 1;
  	  	break;
  	  }
  	  if(i!=0 && s[i]!='e'&&s[i]!='o' && s[i]==s[i-1])
	{
  	  	flag = 1;
  	  	break;
  	}
  	}
  	if(flag || !flag1)
	  	printf("<%s> is not acceptable.\n",s);
  	else 
	  	printf("<%s> is acceptable.\n",s);
}
  return 0;
} 
