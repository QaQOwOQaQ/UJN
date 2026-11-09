#include<bits/stdc++.h>
using namespace std;
int main()
{
        string s;
        int x,y,n;
        cin>>n;
       getchar();
        for(int i=0;i<n;i++)
        {
            x=0;
            y=0;
            getline(cin,s);
            if(s.find("miao.")==0)
            x=1;
            if(s.rfind("lala.")==s.length()-5)
            y=1;
            if(x==0&&y==1)
         {
       printf("Freda's\n");
       }
         else if(x==1&&y==0) 
        	 printf("Rainbow's\n");
         else
    		  printf("OMG>.< I don't know!\n");
        }
    return 0;
}


