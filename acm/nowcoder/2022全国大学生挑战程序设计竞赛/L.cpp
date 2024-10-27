/*
    妈的，披着线段树的皮，吓唬人
    其实非常非常非常简单！
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL n, m;
LL sum;

LL get(LL x)
{
    LL res = 0;
    while(x)
    {
        res += x;
        x /= 2;
    }
    return res;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    LL t = get(n);
    for(int i = 0; i < n; i ++ )
    {
        LL x;   
        scanf("%lld", &x);
        sum += x;
    }
    while(m -- )
    {
        LL a, b, k, res;
        scanf("%lld%lld%lld", &a, &b, &k);
        sum += k * (b - a + 1);

        res = sum * t;
        printf("%lld\n", res);
    }
    
    return 0;
}
*/

/*
//但我感觉线段树没毛病啊，为啥会错呢？？？
这我就不理解了
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 1000007
#define ll long long
 
using namespace std;

ll n,m;
ll op,x,y,k,ans;
ll sum[maxn<<2],add[maxn<<2];
ll a[maxn];
 
void PushUp(ll rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
} 
 
void Bulid(ll l,ll r,ll rt)
{
	if(l == r)	
	{
		sum[rt] = a[l];
		return ;
	}
	int m = (l+r)>>1;
	Bulid(l,m,rt<<1);
	Bulid(m+1,r,rt<<1|1);
	PushUp(rt); 
}

void PushDown(ll rt,ll ln,ll rn)
{
	if(add[rt])
    {
		add[rt<<1]+= add[rt];
		add[rt<<1|1]+= add[rt];
		sum[rt<<1]+= add[rt]*ln;
		sum[rt<<1|1]+= add[rt]*rn;
		add[rt] = 0;
	}
}

void Update(ll L,ll R,ll C,ll l,ll r,ll rt)
{
	if(L <= l && r <= R)
	{
		sum[rt]+= C*(r-l+1);
		add[rt]+= C;
		return ;
	}
	ll m = (l+r)>>1;  
	PushDown(rt,m-l+1,r-m);	
	if(L <= m)
		Update(L,R,C,l,m,rt<<1);
	if(R > m)
		Update(L,R,C,m+1,r,rt<<1|1);
	PushUp(rt);
}

ll Query(ll L,ll R,ll l,ll r,ll rt)
{
	if(L <= l && r <= R)    return sum[rt];
	ll m = (l+r)>>1;
	PushDown(rt,m-l+1,r-m);
	ll ans = 0;
	if(L <= m)  ans+= Query(L,R,l,m,rt<<1);
	if(R > m)   ans+= Query(L,R,m+1,r,rt<<1|1);
	return ans;
} 

ll get(ll x)
{
    ll res = 0;
    while(x)
    {
        res += x;
        x /= 2;
    }
    return res;
}

int main()
{
    cout << get(16) << endl;
	cin >> n >> m;
	for(ll i=1;i<=n;i++)    cin >> a[i];
	Bulid(1,n,1);
	ll ttt = get(n);
	for(ll i=1;i<=m;i++)
	{
		cin >> x >> y >> k;
		Update(x,y,k,1,n,1);
		ll res = ttt * Query(1, n, 1, n, 1);
	    cout << res << endl;
	}
	
	return 0;
} 
*/
