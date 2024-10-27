#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 30;

int n, a[N];

void add(int i, int val)
{
    if(a[i] == -1)
    {
        a[i] = val;
        return ;
    }
    if(val > a[i])  add(i * 2, val);
    else    add(i * 2 + 1, val);
}

int main()
{
    memset(a, -1, sizeof a);
    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int e;
        cin >> e;
        add(1, e);
    }

    int c = 0, i = 1;
    while(c < n)
    {
        while(a[i] == -1)   i ++ ;
        if(c)   cout << " " << a[i];
        else    cout << a[i];
        i ++ , c ++ ;
    }
    //编号c的作用是遍历整个二叉树
    //i是找到二叉树最后一个节点的编号
    //因为二叉完全树是一层一层，每层从左到右排列的
    //所以数组最后一个节点下标一定是n
    //这里我们遍历到n+1时结束
    cout << endl << (i == n + 1 ? "YES" : "NO");
    return 0;
}