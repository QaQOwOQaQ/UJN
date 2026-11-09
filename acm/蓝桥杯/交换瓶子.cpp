#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<math.h>
using namespace std;
typedef long long ll;
int n,a[10005];
int main()
{
   while( cin >> n )
   {
   	memset(a,0,sizeof(a));
     for(int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 1;i <= n; i++)
    {
        while(a[i] != i)///交换使当前的位置放相应的数
        {
            swap(a[i],a[a[i]]);
            ans++;
        }
    }
    cout << ans << endl;  	
   }

    return 0;
}
