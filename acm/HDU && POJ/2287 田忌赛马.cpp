#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[1010],b[1010]; 
bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	int n,ans;
//	while(cin >> n)
	{
		if(!n)
			return 0;
		ans = 0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));		
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		int l1=1,l2=1,r1=n,r2=n;	
		while(r1 >= l1)
		{
			if(a[l1] > b[l2])
			{
				l1++,l2++;
				ans+= 200;
			}
			else if(a[l1] < b[l2])
			{
				r1--,l2++;
				ans-= 200;
			}
			else
			{
				if(a[r1] > b[r2])
				{
					r1--,r2--;
					ans+= 200;
				}
				else
				{
					if(a[l1] < b[r2])
						ans-= 200;
					l1--,r2++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
	
 } 
