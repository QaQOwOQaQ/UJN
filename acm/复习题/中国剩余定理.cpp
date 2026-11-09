#include<cstdio>
#define ll long long

ll n,a[16],m[16],Mi[16],mul=1,X;

void exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
	{
		x=1;y=0;return ;
	}
    exgcd(b,a%b,x,y);
    int z=x;x=y,y=z-y*(a/b);
}
int main()
{
    scanf("%d", &n);
    for(int t=1;t<=n;t++)
	{
        int M;
		scanf("%d", &M);
		m[t]=M;
        mul*=M;
        scanf("%lld", &a[t]);
    }
    for(int t=1;t<=n;++t)
	{
        Mi[t]=mul/m[t];
        ll x=0,y=0;
        exgcd(Mi[t],m[t],x,y);
        X+=a[t]*Mi[t]*x;
    }
	X = (X % mul + mul) % mul;
    printf("%lld",X);
    return 0;
}
