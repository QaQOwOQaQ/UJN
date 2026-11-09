#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
//400 100 200 350 300 250
int main()
{
	int n,m,a[20001],flag,ans;
	cin >> m;
	while(m--)
	{
	cin >> n;
	ans=0;
	flag=0;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		flag++;
		if(flag==3)
		{
			flag=0;
			ans=ans+a[i];
		}
	}
	cout << ans<<endl;

	}
	return 0;
 } 
