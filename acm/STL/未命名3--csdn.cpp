#include<stdio.h>
 #include<string.h>
#include<stack>
using namespace std;
char str1[1005],str2[1005];int len1,len2;
char path[2005];
 void test(int x,int y,stack<char> st,int t)
 {
      int j;
     if(y==len2)
     {
         printf("i ");
         for(j=0;j<t;j++)
             printf("%c ",path[j]);
         printf("\n");
         return ;
     }
     if(st.empty ())
     {
         st.push(str1[x+1]);
         path[t]='i';
         test(x+1,y,st,t+1);
         st.pop();
         return ;
     }
     char cur=st.top ();
     if(x==len1 && cur!=str2[y])
         return ;
     if(cur!=str2[y])
     {
         st.push(str1[x+1]);
         path[t]='i';
         test(x+1,y,st,t+1);
         st.pop();
     }
     if(cur==str2[y])
     {
         st.push(str1[x+1]);
         path[t]='i';
         test(x+1,y,st,t+1);
         st.pop();
         st.pop();
         path[t]='o';
         test(x,y+1,st,t+1);
         st.push(str1[x]);
     }
     return ;
 }
 int main()
 {
     int i,j;
     while(scanf("%s%s",str1,str2)!=EOF)
     {
         len1=strlen(str1);
         len2=strlen(str2);
         printf("[\n");
         if(len1<len2)
         {
             printf("]\n");
             continue;
         }
         stack<char> st;
         st.push(str1[0]);
         test(0,0,st,0);
         printf("]\n");
     }
     return 0;
 }
