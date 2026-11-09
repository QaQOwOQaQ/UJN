#include<iostream>
#include<algorithm>

using namespace std;

const int maxn =  100007;

int pre[maxn],depth[maxn];
int ans[maxn];	//ans用来保存离线操作下的结果 

struct node		
{
	int l,r,dis;	//视频l和视频r的相关性为dis 
	node () {}
	node(int x,int y,int v) : l(x),r(y),dis(v) {}
}a[maxn*40];

struct kkk	
{
	int v,pot;		//v，pot对应每一次询问的相关性界值和视频号 
	int pos; 	//每一次询问的编号 
}b[maxn*40];

bool cmp1(node x,node y)
{
	return x.dis > y.dis; 
}

bool cmp2(kkk x,kkk y)
{
	return x.v > y.v;
}

int find(int x)
{
	if(pre[x] == x)
		return x;
	return pre[x] = find(pre[x]);
}

void unite(int x,int y)
{
	int fx = find(x);
	int fy = find(y);
	if(fx != fy)
	{
		pre[fx] = fy;
		depth[fy]+= depth[fx];
	}
}
int main()
{
	int n,m;
	
	//输入数据初始化 
	cin >> n >> m;	
	for(int i=1;i<=n;i++)
	{
		pre[i] = i;
		depth[i] = 1;		
	} 
	for(int i=1;i<n;i++)
		cin >> a[i].l >> a[i].r >> a[i].dis;
	for(int i=1;i<=m;i++)
	{
		cin >> b[i].v >> b[i].pot;
		b[i].pos = i;
	} 
	
	/*  对结构体排序，让每一次询问都从大到小询问，这样就可以避免先询问小的，后续询问大的，
	 *  导致前面已经联合的小的视频无法去除,也保证可以按照顺序联合将相关系数大于该询问的两个视频联合
	 * （联合视频的结构体已经按相关系数排序） 
	 *  从而避免了多次查找，但因为排序会打乱顺序，所以要对查找结构体添加编号pos， 
	*/
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+m,cmp2);
	
	//
//	cout << "测试" << endl; 
//	for(int i=1;i<n;i++)
//		cout << a[i].l << " " << a[i].r << " " << a[i].dis << endl;
//	for(int i=1;i<=m;i++)
//		cout << b[i].v << " " << b[i].pot << endl;
//	cout << "测试" << endl; 
	//
			
	//由相关系数从大到小便利每一次询问 
	int cut = 1;	//便利保存相关关系的结构体	！！这里只需要便利一次！！ 
	for(int i=1;i<=m;i++)
	{
		int d = b[i].v;	//保存这次询问的相关性大小 
		int p = b[i].pot;	//保存这次询问的视频节点pot 
		int pos = b[i].pos;	//记录编号用于保存ans 
		while(a[cut].dis >= d && cut < n)
		{
			unite(a[cut].l,a[cut].r);
			cut++;	
		} 	
		ans[pos] = depth[find(p)] - 1; 
	}
	
	//输出
	for(int i=1;i<=m;i++)
		cout << ans[i] << endl; //深度要减一，减去自己 
	
	return 0;
} 
