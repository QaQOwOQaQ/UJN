#include <iostream>
#include <cstdio>

using namespace std;

int mi(int x,int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
    if(n==2){
        return x*x;
    }
    if(n==3){
        return x*x*x;
    }
    if(n%2==0){
        return mi(x,n/2)*mi(x,n/2);
    }
    if(n%2!=0){
        return mi(x,(n-1)/2)*mi(x,(n-1)/2)*x;
    }
}

int main()
{
    int x;
    int n;
    int jieguo;
  //  while(scanf("%d %d",&x,&n)!=EOF)
  
  {
  		cin>>x>>n;
        jieguo=mi(x,n);
        printf("%d\n",jieguo);
    }
    return 0;
}

