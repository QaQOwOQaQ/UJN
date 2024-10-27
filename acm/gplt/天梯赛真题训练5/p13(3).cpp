#include<bits/stdc++.h>
using namespace std;
 
const int maxn=110;
int a[maxn],l[maxn],r[maxn];
int pre[maxn],deep[maxn];
map<int,int>mp;
int n,q;
int root;
 
void insert(int &Root,int fa,int dep,int id)
{
//	cout<<l[Root]<<","<<r[Root]<<endl;
	if(Root==-1)
	{
		Root=id;//这里就是给l，r数组赋值；如果是-1那么会走这个if语句，然后赋值返回 
		pre[id]=fa;
		deep[id]=dep;
		return;
	}
	if(a[id]<a[Root])insert(l[Root],Root,dep+1,id);
	else insert(r[Root],Root,dep+1,id);
}
int main()
{
	scanf("%d",&n);
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	root=-1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		insert(root,-1,1,i);
		mp[a[i]]=i;
	}
	scanf("%d",&q);getchar();
	while(q--)
	{
		string s;getline(cin,s);
		int x,y,f=0;
		if(s.find("root")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the root",&x);
			if(mp.find(x)!=mp.end() && a[root]==x)f=1;
		}
		else if(s.find("siblings")!=string::npos)
		{
			sscanf(s.c_str(),"%d and %d are siblings",&x,&y);
			if(mp.find(x)!=mp.end() && mp.find(y)!=mp.end() && pre[mp[x]]==pre[mp[y]])f=1;	
		}
		else if(s.find("parent")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the parent of %d",&x,&y);	
			if(mp.find(x)!=mp.end() && mp.find(y)!=mp.end() && pre[mp[y]]==mp[x])f=1;
		}
		else if(s.find("left")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the left child of %d",&x,&y);	
			if(mp.find(x)!=mp.end() && mp.find(y)!=mp.end() && pre[mp[x]]==mp[y] && x<y)f=1;
		}
		else if(s.find("right")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the right child of %d",&x,&y);	
			if(mp.find(x)!=mp.end() && mp.find(y)!=mp.end() && pre[mp[x]]==mp[y] && x>y)f=1;
		}else if(s.find("same")!=string::npos)
		{
			sscanf(s.c_str(),"%d and %d are on the same level",&x,&y);	
			if(mp.find(x)!=mp.end() && mp.find(y)!=mp.end() && deep[mp[x]]==deep[mp[y]])f=1;
		}
		if(f)puts("Yes");
		else puts("No");
	}
}