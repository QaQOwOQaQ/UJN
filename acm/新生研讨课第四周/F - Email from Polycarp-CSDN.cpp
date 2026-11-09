#include<bits/stdc++.h>
using namespace std;
int main()
{	int n,flag,a,b,count;
	string s,t;
	cin >> n;
	getchar();
	while(n--)
	{	
		count = 0; 
		getline(cin,s);
		getline(cin,t);
		a=s.length();
		b=t.length();
		if( a>b || s[0]!=t[0] || s[a-1]!=t[b-1] )
		{
            cout << "No" << endl ;
			  continue;
		}	
		int i=0,j=0;
         for (i=0;i<a;i++)
         {
             while (j<b)
             {
                 if (s[i] == t[j]) 
                 {
                     count++;
                     j++;
                     break;
                 }
                 else if (s[i-1]!=t[j]) 
                 {
                     flag = 1;
                     break;
                 }
                 j++;
             }
           if (flag==1)
                break;
            if (j>=b)
                break;
       }
       if (flag==1) 
        {
            cout << "No" << endl ;
            continue;
        }
      if (flag==0 && count!=a)  
       {
            cout << "No" << endl ;
           continue;
         }
        if (count == b)
        {
            while (j<b) 
           {
                if (s[a-1] != t[j])
                {
                flag = 1;
                break;
                }
                j++;
           }
        }
         if (flag==1)
            cout << "No" << endl ;
       else
            cout << "Yes" << endl;
		}
	return 0;
} 
