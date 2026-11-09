#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    long long sum1=0;
    for(int i=1;i<=min(n,m);i++)
	{
        sum1+=(n-i+1)*(m-i+1);
    }
    printf("%lld ",sum1);
    long long sum2=1LL*n*(n+1)/2*1LL*m*(m+1)/2;//1
    printf("%lld",sum2-sum1);
    return 0;
} 

