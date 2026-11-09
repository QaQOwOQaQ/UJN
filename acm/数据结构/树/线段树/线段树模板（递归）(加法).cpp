#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define maxn 100007
#define ll long long


using namespace std;

//x>>1表示x/2 
//x<<1表示x*2 
//x<<1|1表示x*2+1 

//定义 

ll sum[maxn<<2],add[maxn<<2];//Sum求和，Add为懒惰标记
ll a[maxn];	//原数组组 

//PushUp函数更新节点信息，这里是求和 
void PushUp(ll rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
} 

//Bulid函数建立线段树 
void Bulid(ll l,ll r,ll rt)//[l,r]表示当前节点区间，rt表示当前节点的实际存储位置 
{
	if(l == r)	//到达叶节点 
	{
		sum[rt] = a[l];//存贮数组值 
		return ;
	}
	int m = (l+r)>>1;
	//左右递归
	Bulid(l,m,rt<<1);
	Bulid(m+1,r,rt<<1|1);
	//更新信息
	PushUp(rt); 
}

//点修改，假设a[L]+=C
void UpdateNote(ll L,ll C,ll l,ll r,ll rt)//[l,r]表示当前区间，rt是当前节点编号
{
	if(l == r)
	{
		sum[rt]+= C;
		return ;
	}
	ll m = (l+r)>>1;
 	//根据条件判断往左子树调用还是往右
	if(L <= m)
		UpdateNote(L,C,l,m,rt<<1);
	else
		UpdateNote(L,C,m+1,r,rt<<1|1);
	PushUp(rt);//子节点的信息更新了，所以本节点也要更新信息
} 

//下推函数 
void PushDown(ll rt,ll ln,ll rn)
{
	//ln,rn分别为左右子树的数量 
	if(add[rt])
	{
		//下推标记 
		add[rt<<1]+= add[rt];
		add[rt<<1|1]+= add[rt];
		//修改子节点的sum使之与对应的add相对应 
		sum[rt<<1]+= add[rt]*ln;
		sum[rt<<1|1]+= add[rt]*rn;
		//清除本节点标记 
		add[rt] = 0;
	}
}

//区间修改，假设a[L,R]+=C
void Update(ll L,ll R,ll C,ll l,ll r,ll rt)
{
	if(L <= l && r <= R)//如果本区间完全在操作区间[L,R]以内
	{
		sum[rt]+= C*(r-l+1);//更新数字和，向上保持正确
		add[rt]+= C;//增加Add标记，表示本区间的Sum正确，子区间的Sum仍需要根据Add的值来调整
		return ;
	}
	ll m = (l+r)>>1;  
	PushDown(rt,m-l+1,r-m);	//下推标记
	//这里判断左右子树跟[L,R]有无交集，有交集才递归
	if(L <= m)
		Update(L,R,C,l,m,rt<<1);
	if(R > m)
		Update(L,R,C,m+1,r,rt<<1|1);
	PushUp(rt);
}
 
//区间查询
ll Query(ll L, ll R, ll l, ll r, ll rt)//[L,R]表示操作区间，[l,r]表示当前区间，rt:当前节点编号
{	
	ll ans = 0;
	if(L <= l && r <= R)
		return sum[rt];
	ll m = (l+r)>>1;
	
	//下推标记，否则Sum可能不正确
	PushDown(rt,m-l+1,r-m);
	
	//左子区间:[l,m] 右子区间：[m+1,r]  求和区间:[L,R]
	//累加答案

	if(L <= m)//左子区间与[L,R]有重叠，递归
		ans+= Query(L, R, l, m, rt<<1);
	if(R > m)
		ans+= Query(L, R, m + 1, r, rt<<1|1);//右子区间与[L,R]有重叠，递归
	return ans;
} 

int main()
{
	ll n, m, op, x, y, k, ans;
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i ++ )
		cin >> a[i];
	Bulid(1,n,1);

	for(ll i = 1; i <= m; i ++ )
	{
		cin >> op;
		if(op == 1)
		{
			cin >> x >> y >> k;
			Update(x, y, k, 1, n, 1);
		}
		if(op == 2)
		{
			cin >> x >> y;
			ans = Query(x, y, 1, n, 1);
			cout << ans << endl;
		}
	}
	return 0;
} 
