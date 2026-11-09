#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue> 
#include <vector>
#include <limits.h>

using namespace std;

const int MINX = INT_MIN; 

typedef struct tree
{
	int date;
	struct tree *left, *right;
}*Tree, TreeNode; 

typedef struct element
{
	Tree ptr;
	bool is_first;
}*Ele, EleNode;

int path[100], pathLength;
bool has_father;

void create(Tree &t)	//先序遍历创建树 
{
	int c;
	cin >> c;
	
	if(c == -1) t = NULL;
	else
	{
		t = new TreeNode;
		t->date = c;
		create(t->left);
		create(t->right);
	}
}

void DGmidPrint(Tree &t)
{
	if(t == NULL)	return ;
	
	DGmidPrint(t->left);
	cout << t->date;
	DGmidPrint(t->right);
}

void prePrint(Tree t)
{
	if(t == NULL)	return ;
	
	stack<Tree> s;	//stack<TreeNode> s是不对的,因为我们的p=t,是Tree类型 
	Tree p = t;
	while(p || !s.empty())
	{
		while(p)
		{
			cout << p->date << " "; 
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->right; 
		}
	}
}

void midPrint(Tree t)
{
	if(t == NULL)	return ;
	
	stack<Tree> s;
	Tree p = t;
	while(p || !s.empty())
	{
		while(p)
		{
			s.push(p);
			p = p->left;
		}
		if(!s.empty())
		{
			p = s.top();
			s.pop();
			cout << p->date << " ";
			p = p->right;
		}
	}
	
}

void lastPrint(Tree t)
{
	if(t == NULL)	return ;
	
	stack<EleNode> s;
	Tree p = t;
	EleNode e;
	while(p || !s.empty())
	{
		while(p)
		{
			e.ptr = p;
			e.is_first = true;
			s.push(e);	
			p = p->left;
		}
		if(!s.empty())
		{
			e = s.top();
			s.pop();
			p = e.ptr;
			if(e.is_first)
			{
				e.is_first = false;			
				s.push(e);
				p = p->right;
			}
			else
			{
				cout << p->date << " "; 
				p = NULL;
			}
		}
	}
}
 
void DGprePrint(Tree t)
{
	if(t == NULL)	return ;
	
	cout << t->date << " ";
	prePrint(t->left);
	prePrint(t->right);
} 

void levelPrint(Tree t)	//层次遍历 
{
	if(t == NULL)	return ;
	queue<Tree> q;
	q.push(t);
	while(q.size())
	{
		Tree s = q.front();
		q.pop();	
		cout << s->date << " ";
		if(s->left)	q.push(s->left);
		if(s->right)	q.push(s->right);
	} 
}	

void DGSwapBitree(Tree t)	//交换左右子树递归 
{
	if(t == NULL)	return ;
	
	Tree p = t->left;
	t->left = t->right;
	t->right = p;
	DGSwapBitree(t->left);
	DGSwapBitree(t->right);
}

void SwapBitree(Tree t)	//交换左右子树递归 
{
	queue<Tree> q;
	q.push(t);
	while(q.size())
	{
		Tree p = q.front();
		q.pop();
		Tree tmp = p->left;
		p->left = p->right;
		p->right = tmp;
		if(p->left)	q.push(p->left);
		if(p->right) q.push(p->right);
	}
}

void Find_Father(Tree t, int date)
{
	if(t == NULL)	return ;
	if(t->left && t->left->date == date)	//先判断是否存在左孩子 
	{
		cout << "该节点的父节点是：" << t->date << endl;
		has_father = true;
		return ;
	}
	if(t->right && t->right->date == date)
	{
		cout << "该节点的父节点是：" << t->date << endl;
		has_father = true;
		return ;
	}
	
	Find_Father(t->left, date);
	Find_Father(t->right, date);
	
}

void findFather(Tree t, int date)
{
	has_father = false;
	Find_Father(t, date);
	if(!has_father)	cout << "你搜索的结点为根节点或你搜索的结点在该二叉树中不存在";
}

int nodeNum(Tree t)	//二叉树节点总数 
{
	//节点数=左孩子节点数+右孩子节点数+根节点 
	if(t == NULL)	return 0;
	
	int lnum = 0, rnum = 0;
	lnum = nodeNum(t->left);
	rnum = nodeNum(t->right);
	return lnum + rnum + 1;	
}

int leafNum(Tree t)	//二叉树叶子节点数 
{
	//叶子节点数=左孩子叶子节点数+右孩子叶子节点数 
	if(t == NULL)	return 0;
	
	int lnum = 0, rnum = 0;
	if(t->left == NULL && t->right == NULL)	return 1;
	lnum = leafNum(t->left);
	rnum = leafNum(t->right);
	return lnum + rnum;
}

int doubleBranchNodeNum(Tree t)	//具有两个孩子的节点数 
{
	if(t == NULL)	return 0;
	
	int lnum = 0, rnum = 0;
	lnum = doubleBranchNodeNum(t->left);
	rnum = doubleBranchNodeNum(t->right);
	
	if(t->left != NULL && t->right != NULL)
	return lnum + rnum + 1;
}

//默认根节点的高度为1
int BFS_Height(Tree t)	//递归计算二叉树的高度,DFS 
{
	if(t == NULL)	return 0;
	
	int lh = 0, rh = 0;
	lh = BFS_Height(t->left);
	rh = BFS_Height(t->right);
	return max(lh, rh) + 1;
} 

int DFS_Height(Tree t)	//非递归层次遍历求树的高度,BFS
{
	if(t == NULL)	return 0;
	
	//思路：通过for循环把整层的节点pop掉 	
	int height = 0;
	Tree node;
	queue<Tree> q;
	q.push(t);
	while(q.size())
	{
		int que_len = q.size();	//该长度就是当前层的所有节点数 
		for(int i = 0; i < que_len; i ++ )	//这里不可以写成q.size(),因为后面有push操作会改变size的大小 
		{
			t = q.front();
			q.pop();	
			if(t->left)	q.push(t->left);
			if(t->right)	q.push(t->right);
		}
		height ++ ;
	} 
	return height;
}

bool IsComplete(Tree t)	//判断一棵树是不是完全二叉树 
{
	//1.树为空，返回错误
	if(t == NULL)	return false;
   
    //2.树不为空
	queue<Tree> q;
	q.push(t);
	while(!q.empty())
	{
		t = q.front();
		
        //2.1如果该节点两个孩子都有，则直接pop
		if(t->left && t->right)
		{
			q.pop();
			q.push(t->left);
			q.push(t->right);
		}
		//2.2如果该节点左孩子为空，右孩子不为空，则一定不是完全二叉树
		if(t->left == NULL && t->right)	return false;
		
		//2.3如果该节点左孩子不为空，右孩子为空或者该节点为叶子节点，则该节点之后的所有结点都是叶子节点
		if(t->right == NULL)
		{
			if(t->left)	q.push(t->left);	//如果有左孩子节点需要把左孩子节点加上    
            q.pop();	//该节点后面所有节点都是叶子节点 
            while(q.size())
            {
            	t = q.front();
                if (t->left == NULL && t->right == NULL)	q.pop();
                else	return false;
			}
			return true;	//完全二叉树 
		}
	}

	return true;	//满二叉树 
} 

void FindAllPath(Tree t, vector<int> path)	//输出所有根节点到叶子节点的路径 
{
	if (t != NULL)
	{
		path.push_back(t->date);
		if (t->left == NULL && t->right == NULL)
		{
//			输出叶子节点到根节点只需要反转vector 
//			reverse(path.begin(), path.end()); 
			for(auto &x : path)	cout << x << " ";
			cout << endl;
			return;
		}
		else
		{
			FindAllPath(t->left, path);
			FindAllPath(t->right, path);
		}
	}
}

int predt = INT_MIN;
int CheckBiTree(Tree &t)	//判断二叉树是不是二叉排序树  
{
	//利用二叉排序树的中序遍历是单调序列(这里是递增)来判断 
	int b1, b2;
	if(t == NULL)	return 1; 
	else
	{
		b1 = CheckBiTree(t->left);
		if(b1 == 0 || t->date < predt) return 0; //如果左子树不是二叉排序树或者当前节点不满足递增 
		cout << t->date << " ";	//中序遍历输出 
		predt = t->date;	//如果符合递增就把当前节点的值赋给predt 
		b2 = CheckBiTree(t->right);
		return b2;
	}
	cout << endl;
}

void IsBiTree(Tree &t)
{
	if(CheckBiTree(t))	cout << "这是一棵二叉排序树!" << endl;
	else	cout << "这不是一棵二叉排序树!" << endl;
}

/*测试样例 
1、普通树： 
1 2 4 -1 -1 -1 3 5 7 
-1 -1 8 -1 -1 6 -1 -1
先序：1 2 4 3 5 7 8 6
中序：4 2 1 7 5 8 3 6 
后序：4 2 7 8 5 6 3 1

2、完全二叉树：
1 2 4 -1 -1 5 -1 
-1 3 6 -1 -1 -1

3、不是二叉排序树(典型错误) 
5 4 2 -1 -1 10 -1 21 
-1 -1 8 -1 16 -1 -1

4、是二叉排序树 
6 3 1 -1 2 -1 -1 4 -1 5
-1 -1 9 7 -1 -1 10 -1 -1
*/

 

int main()
{
	Tree t;
	create(t);
//	vector<int> path;
//	FindAllPath(t, path);

	midPrint(t); cout << endl; 
	IsBiTree(t);
	return 0;
}

