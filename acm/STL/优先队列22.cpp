#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
	int n1,n2,n,a;
	long long ans;
	priority_queue<int> h;//由大到小
	priority_queue<int,vector<int>,greater<int> > l;//由小到大
	while(scanf("%d %d %d",&n1,&n2,&n)!=EOF)
	{
		ans=0;
		if(n1==0&&n2==0&&n==0)	
			break;
		while(n--)
		{
			scanf("%d",&a);
			ans+=a;
			h.push(a);
			l.push(a);
		}
			if(h.size()>0)
				h.pop();
			if(l.size()>0)
				l.pop();
			while(!h.empty())
			{
				ans-=h.top();
				h.pop();	
			}		
			while(!l.empty())
			{
				ans-=l.top();
				l.pop();
			}
		printf("%0.6lf\n",ans*1.0/(n-n1-n2));
	}
	return 0;
}


