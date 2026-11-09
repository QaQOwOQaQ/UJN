#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long

using namespace std;

ll n,a[110],b[110];
bool cmp(ll x,ll y)
{
	return x > y;
}
int main()
{
 	while(scanf("%d",&n) != EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int top,sup,op = 0;
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(a[i]!=a[i+1])
				b[op++] = a[i];
		}
		
		//*
		for(int i=0;i<op;i++)
			cout << b[i] << " ";
		cout << endl; 
		//*
		
		for(int i=b[op-1];i>=1;i--)
		{
			int flag = 1; 
			for(int j=1;j<op;j++)
			{
				if(b[j] % i != 0)
				{
					flag = 0;	break;	
				}

			}
			if(flag == 1)
			{
				sup = i;	
				top = b[op-2]/(b[op-1]/sup);	
				cout << top << "/" << sup << endl;	
				break;			
			}

		} 
	
	}  
    
    
    
    return 0;
}
