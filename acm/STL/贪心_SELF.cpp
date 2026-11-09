#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j;
	int x,y;    
	//b的最小接受惩罚次数是多少，
	//a最大惩罚对方的次数是多少。 
	char a[1000],b[1000]; 
	cin >> n;	//升序 
	cin >> a >> b;
	sort(a,a+n);
	sort(b,b+n);
	//b至少受到几次惩罚
	//a最多可以实施几次惩罚 
	for(i=0,j=0;j<n;j++)
	{
		if(b[j]>=a[i])
			i++;
		else
			x++;
	}
	//a=1459
	//b=2356
	for(i=0,j=0;j<n;j++)
	{
		if(a[i]<=b[i])
			i++;
		else
			y++;
	}
	
	cout << x << endl << y << endl;

	return 0;
}
