#include<iostream>
#include<vector>
#include<queue>
#include<cmath> 
typedef long long ll;
using namespace std;
int main()
{
	priority_queue<int> h; //头大尾小 
	priority_queue<int,vector<int>,greater<int> > q;//头小尾大 
	long long sum,average;
	int n1,n2,n,t;//去掉最大的n1个和最小的n2个
	while(scanf("%d %d %d",&n1,&n2,&n))
	{
	sum = 0;
	t = 0;
	t = n - n1 - n2;
//	printf("n-n1-n2 = %d\n",t);
	if(n1==n2&&n2==n&&n==0)break;
	while(n--)
	{
		int x;
		scanf("%d",&x);
		h.push(x);
	}
	while(n1--) //去掉n1个大的 
	{
		if(!h.empty())	
			h.pop();
	}
	while(!h.empty())
	{
		q.push(h.top());
		h.pop();
	}
	while(n2--)//去掉最小的n2个
	{
		if(!q.empty())
			q.pop();
	}
	while(!q.empty())
	{
		sum+=q.top();
		q.pop();
	}
	printf("%0.6lf\n",sum*1.0/t);
	}
	return 0;
}
