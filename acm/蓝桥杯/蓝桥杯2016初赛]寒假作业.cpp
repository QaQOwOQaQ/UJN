#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long
using namespace std;

int main()
{
	ll ans = 0;
	int a[10] = {1,3,4,5,7,8,9,10,11,13};
	do{
		if(a[0]+a[1]==a[2] && a[3]-a[4]==a[5] && a[6]*a[7]==a[8])
			ans++;
		
	}while(next_permutation(a,a+10));
	
	int b[10] = {1,3,4,6,7,8,9,11,12,13};
	do{
		if(b[0]+b[1]==b[2] && b[3]-b[4]==b[5] && b[6]*b[7]==b[8])
			ans++;
		
	}while(next_permutation(b,b+10));
	
	int c[10] = {1,3,5,6,7,9,10,11,12,13};
	do{
		if(c[0]+c[1]==c[2] && c[3]-c[4]==c[5] && c[6]*c[7]==c[8])
			ans++;
		
	}while(next_permutation(c,c+10));
	
	int d[10] = {1,2,5,6,7,8,9,10,11,13};
	do{
		if(d[0]+d[1]==d[2] && d[3]-d[4]==d[5] && d[6]*d[7]==d[8])
			ans++;
		
	}while(next_permutation(d,d+10));		

	//3
	int e[10] = {1,4,5,7,8,9,10,11,12,13};
	do{
		if(e[0]+e[1]==e[2] && e[3]-e[4]==e[5] && e[6]*e[7]==e[8])
			ans++;
		
	}while(next_permutation(e,e+10));
	
	//4
	int f[10] = {1,2,5,6,7,8,9,10,11,13};
	do{
		if(f[0]+f[1]==f[2] && f[3]-f[4]==f[5] && f[6]*f[7]==f[8])
			ans++;
		
	}while(next_permutation(f,f+10));
	//5
	int g[10] = {1,4,5,7,8,9,10,11,12,13};
	do{
		if(g[0]+g[1]==g[2] && g[3]-g[4]==g[5] && g[6]*g[7]==g[8])
			ans++;
		
	}while(next_permutation(g,g+10));
	//6
	int h[10] = {1,3,5,6,7,9,10,11,12,13};
	do{
		if(h[0]+h[1]==h[2] && h[3]-h[4]==h[5] && h[6]*h[7]==h[8])
			ans++;
		
	}while(next_permutation(h,h+10));
	//7
	int p[10] = {1,3,4,6,7,8,9,11,12,13};
	do{
		if(p[0]+p[1]==p[2] && p[3]-p[4]==p[5] && p[6]*p[7]==p[8])
			ans++;
		
	}while(next_permutation(p,p+10));

	cout << ans << endl;
	return 0;
	
} 
