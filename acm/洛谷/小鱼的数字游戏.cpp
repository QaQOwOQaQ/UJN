#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[1100],b[1100]={0};

int main()
{
	int n,ans = 0;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+1+n);	
	for(int i=3;i<=n;i++)
	{
		for(int x=1;x<=i-2;x++)
		{
			for(int y=x+1;y<=i;y++)
			{
				if( a[x] + a[y] == a[i] )
				{
//					cout << a[i] << endl;
					b[i] = 1;				
				}

			}
		}
	}
//1 2 //3 4 5 6 //6
//3:1+2
//4:1+2 1+3 2+3
//5:1+2 1+3 1+4 2+3 2+4 3+4
//6:1+2 1+3 1+4 1+5 2+3 2+4 2+5 3+4 3+5
	for(int i=1;i<=n;i++)
	{
		if(b[i])
			ans++;
	}
	cout << ans << endl;
	return 0;
	
 } 
