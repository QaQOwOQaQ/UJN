#include<iostream>
using namespace std;
int main()
{
	int n,k;
	int ans=0;
	cin>>n>>k;
	int a[1001][11],b[1001][11];
	int t[11]; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			char ch;
			cin >> ch;
			a[i][j]=(ch=='T'?1:0);
		}
	}
	for(int i=0;i<(1<<k);i++)
	{
		for(int j=0;j<k;j++)
			t[j]=(i>>j)&1;
	
	int minx=100;
		for(int j=0;j<n;j++)
		{
			int sum=0;
			for(int i=0;i<k;i++)
			{
				b[j][i]=t[i]^a[j][i];
				sum+=b[j][i];
			}	
			if(sum<minx)
			minx=sum;
		}
		if(minx>ans)
			ans=minx;
	
	}
	cout<<ans;
	
	return 0;
}
