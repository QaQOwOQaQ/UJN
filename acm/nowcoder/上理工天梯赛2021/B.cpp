//暴力出奇迹
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n;

inline int get(int x)
{
    return x * x;
}

bool check(int a, int b)
{
    int c = get(a) + get(b);
    int d = sqrt(c);
    if(get(d) == c && d <= n)  return true;
    return false;
}

int main()
{
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i ++ )
    {
        for(int j = i; j <= n; j ++ )
        {
            if(check(i, j)) res ++ ;
        }
    }
    cout << res << endl;
    
    return 0;
}