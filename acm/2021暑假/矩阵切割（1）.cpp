#include<iostream>
using namespace std;
struct op
{
	long long x1;
	long long y1;
	long long x2;
	long long y2;
}a[1010];
long long ans=0;
void func(long long left,long long right,long long up,long long down,int t)
{
	while(t>0 && (left>=a[t].x2 || up<=a[t].y2 || right<=a[t].x1 || down>=a[t].y1))
		t--;
	if(!t)
	{
		ans+=(right-left)*(up-down);
//		cout<<"上下左右:"<<up<<" "<<down<<" "<<left<<" "<<right<<endl; 
//		cout<<"操作一次楼！"<<(right-left)*(up-down)<<endl;
		return;		
	}

    if(left<a[t].x1)
    {
        func(left,a[t].x1,up,down,t-1);
        left=a[t].x1;
  //      cout<<"操作1"<<endl;
    }
    if(right>a[t].x2)
    {
    	func(a[t].x2,right,up,down,t-1);
    	right=a[t].x2;
 //       cout<<"操作2"<<endl;
	}
	if(up>a[t].y1)
	{
		func(left,right,up,a[t].y1,t-1);
		up=a[t].y1;
 //       cout<<"操作3"<<endl;
	}
	if(down<a[t].y2)
	{
		func(left,right,a[t].y2,down,t-1);
		down=a[t].y2;
 //       cout<<"操作4"<<endl;
	}
	return;
}
int main()
{
	int n;	scanf("%d",&n);
	a[0].x1=0; a[0].x2=0; a[0].y1=0; a[0].y2=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(int i=1;i<=n;i++)
		func(a[i].x1,a[i].x2,a[i].y1,a[i].y2,i-1);
	printf("%lld",ans);
	
	
	return 0;
}
