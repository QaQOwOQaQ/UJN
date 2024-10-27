#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int N = 10000;

typedef struct tree{
	int val;
	struct tree *left, *right;
}*Tree, TreeNode;

int n, w[N], depth;
int Mid[N], Last[N];
vector<int> g[N], l, r;
unordered_map<Tree, int> mp;

Tree Build(int mid[], int last[], int len)
{
	if(len <= 0)	return NULL;
	
	int root = last[len - 1], k = 0;
	for(int i = 0; i < len; i ++ )
		if(mid[i] == root)
			k = i;
	
	Tree t = new TreeNode;
	t->val = root;
	t->left = Build(mid, last, k);
	t->right = Build(mid + k + 1, last + k, len - k - 1);
	
	return t;//我真是个傻卵,这里没返回*Tree,SE了十分钟,幸亏提交系统会显示哪里出错了,G！ 
}

void levelPrint(Tree t)
{
	if(t == NULL)	return ;//这里不加上也会SE,恶心！ 
	queue<Tree> q;
	q.push(t);
	mp[t] = 0;
	while(q.size())
	{
		Tree s = q.front();
		q.pop();
		depth = max(depth, mp[s]);
		
		g[mp[s]].push_back(s->val);
		if(s->left)	
		{	
			q.push(s->left);
			mp[s->left] = mp[s] + 1;
		}
		if(s->right)	
		{
			q.push(s->right);
			mp[s->right] = mp[s] + 1;
		}
	}
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i ++ )	cin >> Mid[i];
	for(int i = 0; i < n; i ++ )	cin >> Last[i];
	
	Tree t = NULL;
	t = Build(Mid, Last, n);
	levelPrint(t);
		
	cout << "R: ";
	for(int i = 0; i <= depth; i ++ )
	{
		int len = g[i].size();
		cout << g[i][len - 1];
		if(i != depth)	cout << ' ';
	}
	cout << endl << "L: ";
	for(int i = 0; i <= depth; i ++ )
	{
		cout << g[i][0];
		if(i != depth)	cout << ' ';
	}
	cout << endl;
	
	return 0;
}
