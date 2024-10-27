#include<stdio.h>
#include<malloc.h>

int N = 0;
int PreOrder[33];
int PostOrder[33];
typedef struct node {
	int num;
	struct node* left;
	struct node* right;
}node;
struct node *create(int pos[], int pre[], int n);
void sequence(node *T);//层序排序输出

/*
算法步骤
1.后续序列last的最后一个元素即是根节点
2.遍历中序序列mid,找到根节点,确定左子树的长度left_size
3.左子树的中序序列为mid[0，left_size )，右子树的中序序列为mid[left_size+1, mid.size)
4.左子树的前序序列为pre[1，left_size )，右子树的前序序列为pre[left_size+1, pre.size)
*/
struct node *create(int pos[], int pre[], int n) {  //先，中
	int k = 0, root = 0;
	if (n <= 0)  return NULL;
	struct node *T;
	T = (struct node *)malloc(sizeof(struct node));
	root = pos[0];//根节点就是先序遍历的
	T->num = root;
	for (int i = 0; i<n; i++){  
		if (pre[i] == root){ //通过中序遍历，确定左右子树的长度
			k = i;
			break;
		}
	}
	T->left = create(pos + 1, pre, k);//递归左右子树
	T->right = create(pos + k + 1, pre + k + 1, n - k - 1);
	return T;
}
int main()
{	
	node *T = NULL;//构建二叉树
	scanf("%d", &N);
	int i = 0;
	for (i = 0; i < N; i++)
		scanf("%d", &PostOrder[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &PreOrder[i]);
	T = create(PostOrder, PreOrder, N);
	sequence(T);
	return 0;
}
void sequence(node *T)
{
	struct node *p[33], *q;
	int f = 0, r = 0;
	int num = 0;
	if (T) {
		p[r++] = T;//根节点入队列
		while (f != r) {//队头不等于队尾时
			q = p[f++];//出队
			printf("%d", q->num);
			num++;//计数输出空格
			if (num < N)
				printf(" ");
			if (q->left)//左树不为空，入队
				p[r++] = q->left;
			if (q->right)//右树不为空，入队
				p[r++] = q->right;
		}
	}
}

