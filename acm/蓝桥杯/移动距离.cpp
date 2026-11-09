


#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	int n,l,r;
	while(cin>>n>>l>>r)
	{
		int x1,x2,y1,y2,ans;
		x1=ceil((double)l/n);	//hang
		x2=ceil((double)r/n);
		if(x1%2==1)	//ji shu lou ceng
			y1=l-n*(x1-1);			
		else
			y1=1+n-(l-n*(x1-1));
		if(x2%2==1)	//ji shu lou ceng
			y2=r-n*(x2-1);			
		else
			y2=1+n-(r-n*(x2-1));
//		cout << "зјБъ" << endl;
//		cout << x1 << " " << y1 << endl;
//		cout << x2 << " " << y2 << endl;	
//		cout << "зјБъ" << endl; 
		ans=abs(x1-x2)+abs(y1-y2);
	
		

		cout << ans << endl;
	}
	return 0;
	
 }


