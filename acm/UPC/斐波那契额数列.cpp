#include<iostream>
using namespace std;
__int64 num[55];

void init()
{
    num[0]=0;
    num[1]=1;
    for(int i=2;i<=50;i++)
    {
        num[i]=num[i-1]+num[i-2];
    }
}

int main()
{
    init();
    int n;
    while(scanf("%d",&n))
    {
        
        if(n==-1)return 0;
        printf("%I64d\n",num[n]);
    }
}

