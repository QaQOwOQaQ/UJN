#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
     return a>b;
}
int main()
{
     int n;
     char a[1005];	//Sherlock
     char b[1005];	//Moriarty 
     while(scanf("%d",&n)!=EOF)
     {
         scanf("%s%s",a,b);
         sort(a,a+n);
         sort(b,b+n);
         int x=0;
         int y=0;
         //1569
         //2694    j
        //Moriarty的最小接受惩罚次数是多少
         for(int i=0,j=0;j<n;j++)
         {
             if(b[j]>=a[i]) i++;
             else x++;
         } 
		//后者大于前者最多的情况 
		//1477		
		//3378	j
         for(int i=0,j=0;j<n;j++)
         {
         	if(b[j]>a[i])
         	{
         		i++;
				y++;	
			}
		 }
         printf("%d\n%d\n",x,y); 
     }
return 0;
 }


