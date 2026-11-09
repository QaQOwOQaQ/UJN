#include<iostream>
#define ll long long

using namespace std;

const ll maxn = 100007;
ll a[maxn],sum[maxn<<2],add[maxn<<2];

void pushup(ll rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void build(ll l,ll r,ll rt)
{
	if(l == r)
	{
		sum[rt] = a[l];
		return ;
	}
	ll m = (l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}

void updateNode(ll L,ll C,ll l,ll r,ll rt)
{
	if(l == r)
	{
		sum[rt]+= C;
		return ;
	}
	ll m = (l+r)>>1;
	if(l <= m)
		updateNode(L,C,l,m,rt<<1);
	else
		updateNode(L,C,m+1,r,rt<<1|1);
	pushup(rt);
}

void pushdown(ll ln,ll rn,ll rt)
{
	if(add[rt])
	{
		ll C = add[rt];
		add[rt<<1]+= C;
		add[rt<<1|1]+= C;
		sum[rt<<1]+= ln*C;
		sum[rt<<1|1]+= rn*C;
		add[rt] = 0;
	}	
}
void update(ll L,ll R,ll C,ll l,ll r,ll rt)
{
	// L,l,r,R
	if(L <= l && r <= R)
	{
		add[rt]+= C;
		sum[rt]+= C*(r-l+1); 
		return ;
	}
	ll m = (l+r)>>1;
	pushdown(m-l+1,r-m,rt);
	if(L <= m)
		update(L,R,C,l,m,rt<<1);
	if(R > m)
		update(L,R,C,m+1,r,rt<<1|1);
	pushup(rt);
}	

ll query(ll L,ll R,ll l,ll r,ll rt)
{
	ll ans = 0;
	if(L <= l && r <= R)
		return sum[rt];
	ll m = (l+r)>>1;
	pushdown(m-l+1,r-m,rt);
	if(L <= m)
		ans+= query(L,R,l,m,rt<<1);
	if(R > m)
		ans+= query(L,R,m+1,r,rt<<1|1);
	return ans;
}
int main() 
{
	ll n,m,op,x,y,k,ans;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	build(1,n,1);
	
	//
	cout << "emam" << endl;
	for(int i=1;i<=n;i++)
		cout << sum[i] << " ";
	cout << endl << "exam" << endl;
	//
	
	for(int i=1;i<=m;i++)
	{
		cin >> op;
		if(op == 1)
		{
			cin >> x >> y >> k;
			update(x,y,k,1,n,1);
		}
		if(op == 2)
		{
			cin >> x >> y;
			ans = query(x,y,1,n,1);
			cout << ans << endl;
		}
	}
	
	
}
