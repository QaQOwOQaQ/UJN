#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=5e4+1;
char a[N]; 
int main()
{
	int n,k,a[100005],s=0;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	 } 
	 sort(a,a+n);
	 int maxx=0;
     for(int i=0;i<n;i++)
     {
      int s=1;
      for(int j=i+1;j<n;j++)
      {
      if(a[j]-a[i]<=k&&j<n)
      {
      		s++;
	  }
}
		maxx=max(maxx,s);
}
	cout<<maxx<<endl;
	return 0;
}


