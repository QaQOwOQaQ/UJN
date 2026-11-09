#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
	int ans=0;
	int a[17]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	do
	{
		int h1=a[1]+a[2]+a[3]+a[4];
		int h2=a[5]+a[6]+a[7]+a[8];
		int h3=a[9]+a[10]+a[11]+a[12];
		int h4=a[13]+a[14]+a[15]+a[16]; 
		
		int r1=a[1]+a[5]+a[9]+a[13];
		int r2=a[2]+a[6]+a[10]+a[14];
		int r3=a[3]+a[7]+a[11]+a[15];
		int r4=a[4]+a[8]+a[12]+a[16]; 	
		
		int d1=a[1]+a[6]+a[11]+a[16];
		int d2=a[4]+a[7]+a[10]+a[13];
		
		if(h1==h2&&h2==h3&&h3==h4&&h4==r1&&r1==r2&&r2==r3&&r3==r4&&r4==d1&&d1==d2)
			ans++;	
//		for(int i=1;i<=16;i++)
//			cout << a[i] << " ";
		cout << endl;
	}
	while(next_permutation(a+1,a+1+16)&&a[1]==1);
	
	cout << ans << endl;
	return 0;
	
 } 
