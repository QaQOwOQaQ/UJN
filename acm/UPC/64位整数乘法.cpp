#include<iostream>
using namespace std;
//typedef unsigned long long ull;
int main()
{
    long long  a,b,p;
    long long  ans=0;//定义一定要用ull，不然会wa
    cin>>a>>b>>p;
    while(b>0)
    {
        if(b%2==1)
        	ans = ans%p + a%p;
        b=b/2;   
		a=a*2%p;
    }
    cout<<ans<<endl;
    return 0;
}

