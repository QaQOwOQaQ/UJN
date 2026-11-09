#include<iostream>
#include<algorithm>

using namespace std;

int n,k,t;
int a[100000];	//第i个牛舍与起点的距离 

bool fun(int d)		//枚举间距 
{
	int last=0,num=1;	//第一头牛入社，共有一头牛 
	for(int i=1;i<t;i++)	//枚举所有牛舍 
	{
		if(a[i]-a[last]>=d)	//往后所有间距都得大于这个最小间距的最大值d 
		{
			num++;	//入社的牛数量加1 
			last=i;	//记录新入社牛的坐标 
		}
	}
	
	if(num>=n)		//所有牛都放入牛舍了 
		return true;
	else
		return false;
}

int main()
{
	cin>>t>>n;		//t个牛栏，n头牛 
	for(int i=0;i<t;i++)
		cin>>a[i];
	sort(a,a+t);
	int l=0,r=a[t-1],mid=(l+r)/2;
	while(l<=r)
	{
		if(fun(mid))
			l=mid+1;
		else
			r=mid-1;
				
		mid=(l+r)/2;
	
	}
	cout<<r<<endl;
	return 0;
} 
 

