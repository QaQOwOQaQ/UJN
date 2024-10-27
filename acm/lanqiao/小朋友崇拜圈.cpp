#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, in[N], out[N], ne[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )
    {
        int x;  cin >> x;
        out[i] ++ ;
        in[x] ++ ;
        ne[i] = x;
    }
    
    int res = -1;
    for(int i = 1; i <= n; i ++ )
    {
        if(!in[i] || !out[i])   continue;
        else
        {
            int dis = i, len = 1;
            while(ne[dis] != i)
            {
                dis = ne[dis];
                len ++ ;
            }
    //        cout << i << " "  << len << "\n";
            res = max(res, len);
        }
    }
    cout << res << endl;
    
    return 0;
}