#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#define ll long long

using namespace std;

int ans = 0;
int a[10]={0,1,2,3,4,5,6,7,8,9};

bool check()
{
	if(
        abs(a[0] - a[1] ) == 1 ||
        abs(a[0] - a[3] ) == 1 ||
        abs(a[0] - a[4] ) == 1 ||
        abs(a[0] - a[5] ) == 1 ||
        
        abs(a[1] - a[4] ) == 1 ||
        abs(a[1] - a[5] ) == 1 ||
        abs(a[1] - a[6] ) == 1 ||
        abs(a[1] - a[2] ) == 1 ||
        
        abs(a[2] - a[5] ) == 1 ||
        abs(a[2] - a[6] ) == 1 ||
        
        abs(a[3] - a[7] ) == 1 ||
        abs(a[3] - a[8] ) == 1 ||
        abs(a[3] - a[4] ) == 1 ||
         
        abs(a[4] - a[7] ) == 1 ||
        abs(a[4] - a[8] ) == 1 ||
        abs(a[4] - a[9] ) == 1 ||
        abs(a[4] - a[5] ) == 1 ||
        
        abs(a[5] - a[8] ) == 1 ||
        abs(a[5] - a[9] ) == 1 ||
        abs(a[5] - a[6] ) == 1 ||
        
        abs(a[6] - a[9] ) == 1 ||
        
        abs(a[7] - a[8] ) == 1 ||
        
        abs(a[8] - a[9] ) == 1
        ){
            return false;
        }
    return true;

}

int main()
{
	do{
		if(check())
			ans++;		
	}while(next_permutation(a,a+10));
	cout << ans << endl;
	

	return 0;
	
} 
