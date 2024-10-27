#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int n, m, w[110], res[110];
    cin >> n >> m;
    for(int i = 1; i <= m; i ++ )   cin >> w[i];
    for(int i = 1; i <= m; i ++ )   cin >> res[i];
    
    for(int i = 1; i <= n; i ++ )
    {
        int sum = 0;
        for(int j = 1; j <= m; j ++ )
        {
            int x;  cin >> x;
            if(x == res[j]) sum += w[j];
        }
        cout << sum << endl;
    }
    
    
    return 0;
}