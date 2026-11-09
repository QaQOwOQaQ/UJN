#include<iostream>
#include<map> 
using namespace std;
int main()
{
	map<long long,long long> mp;
	long long n,m;
	long long res=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		long long x;
		cin>>x;
		res+=(n-(i-mp[x]));
		mp[x]=i;
	//	cout<<"ans:"<<res<<endl;
	cout<<res<<endl;
	}
    return 0;
}

