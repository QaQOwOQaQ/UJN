#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long
struct op
{
	int num;
	int sta;
	int end;
}a[110];
bool cmp(op p,op q)
{
	return p.end<q.end;
}
using namespace std;
int main()
{
	int n;	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i].num>>a[i].sta>>a[i].end;
	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++)
//		cout<<a[i].num<<" "<<a[i].sta<<" "<<a[i].end<<endl;	
	bool b[100]={0};	//记录n个活动是否选择 
	int pre=a[0].end;	//记录上一次活动的结束时间 
	b[a[0].num]=1;					//第一个活动必选 
	for(int i=1;i<n;i++)
	{
		if(a[i].sta>=pre)
		{
			pre=a[i].end;	//更新结束时间
			b[a[i].num]=1;	//记录该活动 
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i])
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
	
 } 
