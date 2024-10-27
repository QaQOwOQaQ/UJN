//AC
#include<bits/stdc++.h>
using namespace std;
 
typedef struct node{
	struct node *lchild,*rchild;
	int val;
}node,*tree;
const int maxn=1e7+10;
int lv[maxn];
map<int,int>dep;
int n,cnt,cur,max_deep;
 
void insert(tree &T,int x,int deep)
{
	if(T==NULL)
	{
		T=new node();
		T->val=x;
		dep[x]=deep;
		max_deep=max(max_deep,deep);
		T->lchild=T->rchild=NULL;
		return;
	}
	if(x<T->val)insert(T->lchild,x,deep+1);
	else if(x>T->val)insert(T->rchild,x,deep+1);
}
void getLevel(tree &T)
{
	if(T==NULL)return;
	queue<tree>q;
	q.push(T);
	while(!q.empty())
	{
		tree t=q.front();
		q.pop();
		lv[cur++]=t->val;
		if(t->lchild!=NULL)q.push(t->lchild);
		else {t->lchild=new node();t->lchild->val=-1;q.push(t->lchild);}
		if(t->rchild!=NULL)q.push(t->rchild);
		else {t->rchild=new node();t->rchild->val=-1;q.push(t->rchild);}
		if(cur>pow(2,max_deep+1))break;
	}
}
int main()
{
	tree T=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		int x;scanf("%d",&x);
		insert(T,x,0);
	}
	//cout<<"max_deep="<<max_deep<<endl;
	memset(lv,-1,sizeof(lv));
	getLevel(T);
	int q;scanf("%d",&q);
	getchar();
	while(q--)
	{
		string s;getline(cin,s);
		int x,y,f=0;
		if(s.find("root")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the root",&x);
			if(dep.count(x) && x==lv[0])puts("Yes");
			else puts("No");
		}
		if(s.find("siblings")!=string::npos)
		{
			sscanf(s.c_str(),"%d and %d are siblings",&x,&y);
			if(dep.count(x) && dep.count(y))
			{
				for(int i=0;i<cur;++i)
					if((lv[i]==x && lv[i+1]==y)||(lv[i]==y && lv[i+1]==x))
					{
						puts("Yes");f=1;
						break;
					}
			}
			if(!f) puts("No");
		}
		if(s.find("parent")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the parent of %d",&x,&y);
			if(dep.count(x) && dep.count(y))
			{	
				for(int i=0;i<cur;++i)
					if(lv[i]==x && (lv[i*2+1]==y || lv[2*i+2]==y))
					{
						f=1;puts("Yes");
						break;
					}
			}
			if(!f) puts("No");
		}
		if(s.find("left")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the left child of %d",&x,&y);
			if(dep.count(x) && dep.count(y))
			{	
				for(int i=0;i<cur;++i)
					if(lv[i]==y && lv[i*2+1]==x)
					{
						f=1;puts("Yes");
						break;
					}
			}
			if(!f) puts("No");
		}
		if(s.find("right")!=string::npos)
		{
			sscanf(s.c_str(),"%d is the right child of %d",&x,&y);
			if(dep.count(x) && dep.count(y))
			{	
				for(int i=0;i<cur;++i)
					if(lv[i]==y && lv[i*2+2]==x )
					{
						f=1;puts("Yes");
						break;
					}
			}
			if(!f) puts("No");
		}
		if(s.find("same")!=string::npos)
		{
			sscanf(s.c_str(),"%d and %d are on the same level",&x,&y);
			if(dep.count(x) && dep.count(y))
			{	
				if(dep[x]==dep[y])puts("Yes");
				else puts("No");
			}
			else puts("No");
		}
	}
	return 0;
}