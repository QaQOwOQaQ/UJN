#include<cstdio>
int n,m,L;
int sz[50001];
int main(){
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++) 
	scanf("%d",&sz[i]);
    int l=0,r=L;
    sz[n+1]=L;
    while(l<=r)
	{
        int mid=(l+r)/2;
		int k=0,st=0;		//k:去掉石头数，当前石头 
        for(int i=1;i<=n+1;i++)
		{
            if(sz[i]-sz[st]<mid) k++;        //统计石头间距小于mid的点的个数； 
            else st=i;
        }
        if(k>m) r=mid-1;                     //小于mid的点多了，减小二分的答案； 
        else l=mid+1;                          //少了就增大二分的答案； 
    }
    printf("%d",r);
    return 0;
}
