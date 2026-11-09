#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#define ll long long

using namespace std;

int a[500010],c[500010];
int ans = 0;
void msort(int b,int e)
{
	if(b ==e)
		return ;
	int mid = (b + e) / 2,i = b,j = mid + 1,k = b;
	msort(b,mid);
	msort(mid+1,e);
	while(i<=mid && j<=e)
	{
		if(a[i] <= a[j])
			c[k++] = a[i++];
		else		//有逆序对 
			{
				c[k++] = a[j++];
				ans+= mid - i + 1;
			}
	}
	while(i <= mid)
		c[k++] = a[i++];
	while(j <= e)
		c[k++] = a[j++];
		
	for(int l=b;l<=e;l++)	//不可缺少1 
		a[l] = c[l];
		
}
int main()
{
	int n;	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	msort(1,n);
	cout << ans << endl;
//	for(int i=1;i<=n;i++)
//		cout << a[i] << " ";	
	return 0;
	
 } 
