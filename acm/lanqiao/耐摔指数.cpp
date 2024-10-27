/* approach 1
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

inline int get(int x)
{
    return (x * x * x + 5 * x) / 6;
}

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 1; ; i ++ )
        {
            if(get(i) >= n)
            {
                cout << i << endl;
                break;
            }
        }
    }
    
    
    
    return 0;
}
*/

//approach2
#include <iostream>
#include <cstring>
#include <string> 
#include <algorithm>
using namespace std;
int dp[10005][10];
int main()
{
	int n, m = 3;
	while(cin >> n)
	{
	    memset(dp, 0, sizeof dp);
    	for(int i = 1; i <= n; i++){
    		dp[i][1] = i;
    	}
    	for(int j = 2; j <= m; j++){
    		for(int i = 1; i <= n; i++){
    				dp[i][j] = 2e9;
    				for(int k = 1; k <= i; k++)//开始从第二层放置第一个手机
    						dp[i][j] = min(dp[i][j],1 + max(dp[k-1][j-1],dp[i-k][j]));
    		} 
    	}
    	cout << dp[n][m] << endl;
	}

	return 0;
} 

/*  approach3
#include <iostream>
#include <cstring>
#include <string> 
#include <algorithm>
using namespace std;
int dp[10005][10];
int main()
{
	int n, m = 3;
	while(cin >> n)
	{
	    memset(dp, 0x3f, sizeof dp);
    	for(int i = 1; i <= n; i++) 
    	    dp[i][1] = i;
    	
    	for(int i = 0; i <= n; i ++ )
    	    dp[i][0] = 0;
    	for(int i = 1; i <= m; i ++ )
    	    dp[0][i] = 0;
    	
    	for(int i = 1; i <= n; i++)
    		for(int j = 2; j <= m; j++)
    			for(int k = 1; k <= i; k++)//开始从第二层放置第一个手机
    			    dp[i][j] = min(dp[i][j],1 + max(dp[k-1][j-1],dp[i-k][j]));
    		
    
     	cout << dp[n][m] << endl;
    // 	for(int i = 1; i <= 1000; i ++ )
    // 	{
    // 	    for(int j = 1; j <= 3; j ++ )   cout << dp[i][j] << " ";
    // 	    cout << endl;
    // 	}
	}

	return 0;
} 
*/