#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long __gcd(long long x,long long y)
{
	long long aa=x,bb=y;//将这两个数先存下来
	while(aa!=bb)//他们两个不等的时候就继续减下去
	{
		if(aa>bb)//判断大小
		{
			aa=aa-bb;//辗转相减
		}
		else 
		{
			bb=bb-aa;//辗转相减
		}
	}
	return x*y/aa;//这里返回x,y的最小公倍数
}
ll a,b,c,d;
int main()
{
    cin>>a>>b>>c>>d;//输入
    //通过容斥原理进行计算
    ll k=__gcd(c,d);
    ll a1=b/c-(a-1)/c,a2=b/d-(a-1)/d,a3=b/k-(a-1)/k,a4=b-a+1;
    ll ans=a4-a1-a2+a3;
    cout<<ans<<endl;//输出
}


