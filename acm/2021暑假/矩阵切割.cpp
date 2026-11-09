#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=19;
int x1[maxn],x2[maxn],y1[maxn],y2[maxn],ans=0;
void Work(int left,int right,int high,int low,int t){
 //   if(left>right||high<low)return;//将不符合要求的矩形过滤掉
    while(t>0&&(left>=x2[t]||right<=x1[t]||high<=y2[t]||low>=y1[t]))//如果当前矩形与之前的矩形无冲突就不管了
   		t--;
    if(!t)
	{
        ans+=(right-left)*(high-low);//没有冲突就累加进答案
        return ;
    }
    //下面就是切割了，变量名已经很明显了，就不再重复地解释了
    if(left<x1[t]){
        Work(left,x1[t],high,low,t-1);
        left=x1[t];
    }
    if(right>x2[t]){
        Work(x2[t],right,high,low,t-1);
        right=x2[t];
    }
    if(high>y1[t]){
        Work(left,right,high,y1[t],t-1);
        high=y1[t];
    }
    if(low<y2[t]){
        Work(left,right,y2[t],low,t-1);
        low=y2[t];
    }
    return ;
}
int main()
{
	int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
    for(int i=1;i<=n;i++)
    Work(x1[i],x2[i],y1[i],y2[i],i-1);
    printf("%d\n",ans);
    return 0;
}

