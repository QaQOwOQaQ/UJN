#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 1e5;

int n;
// int w[N];
unordered_map<int,int> ass;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++ )  
    {
        int x;  cin >> x;
        // w[i] = x;
        ass[x] ++ ;
    }
    long long res = n;
    for(auto &x : ass)
        if(x.second > 1)    
            res += (long long)x.second * (x.second - 1);
    cout << res << endl;
    
    // int test = 0;
    // for(int i = 1; i <= n; i ++ )
    // {
    //     for(int j = 1; j <= n; j ++ )
    //     {
    //         if(i == j)  test ++ ;
    //         else if(w[i] == w[j])   test ++ ;
    //     }
    // }
    // cout << test << endl;
    return 0;
}