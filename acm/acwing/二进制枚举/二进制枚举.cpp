#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < (1<<n); i++) //从0～2^n-1个状态
    {
        for(int j = 0; j < n; j++) //遍历二进制的每一位
        {
            if(i & (1 << j))
//1<<j输出一个n位中只有一位（第j位）为1的二进制数字，与i进行与运算，同1为1来判断该位是否为1 
//判断二进制第j位是否存在
            {
                printf("%d ",j);//如果存在输出第j个元素
            }
            else
            	cout << "*";
        }
        printf("\n");
    }
    return 0;
}

