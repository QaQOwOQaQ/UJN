#include<stdio.h>
#include<algorithm>
using namespace std;
int n;int qw[2000];int tj[2000];
int* headqw;int* tailqw;int* headtj;int* tailtj;
int res;
int main()
{
    while( scanf("%d",&n) )
    {
   		if(n==0)
    		return 0;
    	res=0; 
	   for(int i=0;i<n;i++)
	    {
	        scanf("%d",&tj[i]);
	    }
	    for(int i=0;i<n;i++)
	    {
	        scanf("%d",&qw[i]);
	    }
	    sort(tj,tj+n);sort(qw,qw+n);//排序
	    tailqw=qw;tailtj=tj;headqw=qw+n-1;headtj=tj+n-1;//头尾指针，方便代码
	    for(int i=0;i<n;i++)
	    {
	        if(*headtj>*headqw)//头是否能赢
	        {
	            res+=200;headtj--;headqw--;
	            continue;
	        }
	        if(*tailtj>*tailqw)//尾是否能赢
	        {
	            res+=200;tailtj++;tailqw++;
	            continue;
	        }
	        if(*tailtj<*headqw)//硬怼
	        {
	            res-=200;
	            tailtj++;headqw--;
	        }
	        else if(*tailtj==*headqw)//特判！！！（敲黑板）不加就是10分！
	        {
	            tailtj++;headqw--;
	        }
	    }
	    printf("%d\n",res);   	
	}
  
    return 0;
}
