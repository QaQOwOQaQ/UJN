#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#define ll long long

using namespace std;

int a[9]={1,2,3,4,5,6,7,8,9};
int main()
{
	int i,j,k;
	while(scanf("%d%d%d",&i,&j,&k) != EOF)
	{
		int ans = 0;
		int flag = 0;
		do{
			int d = (a[0]*100+a[1]*10+a[2]);
			int b = (a[3]*100+a[4]*10+a[5]);
			int c = (a[6]*100+a[7]*10+a[8]);
			if(d*j==b*i && b*k==c*j)
				ans++;			

		}while(next_permutation(a,a+9));
		printf("%d\n",ans);
//		cout << clock() << "ms" << endl;
			
	}


	return 0;
	
} 
