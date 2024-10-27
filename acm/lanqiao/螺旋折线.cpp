#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int x,y;
   scanf("%d%d",&x,&y);
   ll m=max(abs(x),abs(y));
   ll d;
   if(y==-m)
   {
      d=m-x;
   }else if(x==m)
   {
       d=-(y+m);
   }else if(y==m)
   {
      d=-(m-x+2*m);
   }else if(x==-m)
   {
       d=-(m-y+4*m);
   }
   cout<<4*m*m+2*m + d<<endl;

}

