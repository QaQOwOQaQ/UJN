#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<map>
#include<stack>
#include<set>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;
int a[]={1,2,3,4,5,6,8,9,10,12};
int num=0;

bool check(int a[]) // 按照五角星的形状求和
{
    int num1=a[0]+a[2]+a[5]+a[8];
    int num2=a[1]+a[2]+a[3]+a[4];
    int num3=a[0]+a[3]+a[6]+a[9];
    int num4=a[1]+a[5]+a[7]+a[9];
    int num5=a[4]+a[6]+a[7]+a[8];
    if(num1==num2&&num2==num3&&num3==num4&&num4==num5)
        return true;
    return false;
}

void dfs(int n)
{
    if(n==9)
    {
        if(check(a))
            num++;
        return ;
    }
    for(int i=n;i<10;i++)  //填数
    {
        int t=a[i];	//交换a[i]和a[n] 
        a[i]=a[n];
        a[n]=t;

        dfs(n+1);

        t=a[i];
        a[i]=a[n];	//交换a[i]和a[n] 
        a[n]=t;

    }
}
int main()
{
    dfs(0);
    printf("%d\n",num/10);//这里注意下，除去旋转和对称的情况
    return 0;
}




