#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int main()
{
//	a,2,3,4,5,6,7,8,9,10,j,q,k
	int ans=0;
	int a,b,c,d,e,f,g,h,i,j,k,l,m;
	for(int a=0;a<=4;a++)	//1
	for(int b=0;b<=4;b++)	//2
	for(int c=0;c<=4;c++)	//3
	for(int d=0;d<=4;d++)	//4
	for(int e=0;e<=4;e++)	//5	
	for(int f=0;f<=4;f++)	//6
	for(int g=0;g<=4;g++)	//7
	for(int h=0;h<=4;h++)	//8
	for(int i=0;i<=4;i++)	//9
	for(int j=0;j<=4;j++)	//220
	for(int k=0;k<=4;k++)	//66
	for(int l=0;l<=4;l++)	//12
	for(int m=0;m<=4;m++)	//1
	if(a+b+c+d+e+f+g+h+i+j+k+l+m==13)
		ans++;

	cout << ans;
	return 0;
	
 } 
