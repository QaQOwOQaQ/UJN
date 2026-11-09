#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
	int n1,n2,n,a;
   priority_queue<int> h;//由大到小
   priority_queue<int,vector<int>,greater<int> > l;//由小到大
   while(scanf("%d %d %d",&n1,&n2,&n)){
   	  if(n1==n2&&n2==n&&n==0)break;
   	   ll ans=0;
		 for(int i=0;i<n;i++){
   	  	   scanf("%d",&a);
   	  	   ans+=a;//先求总和
   	  	   h.push(a);
   	  	 //  if(h.size()>n2) h.pop();//求n2个小的
   	  	   l.push(a);
   	  	 //  if(l.size()>n1) l.pop();//求n1个大的
		 }
		while(h.size()>n2) h.pop();
		while(l.size()>n1) l.pop();
		 while(!h.empty()){
		 	  ans-=h.top();
		 	  h.pop();
		 }
		 while(!l.empty()){
		 	  ans-=l.top();
		 	  l.pop();
		 }
		 printf("%0.6lf\n",ans*1.0/(n-n1-n2));
   }
	return 0;
}

