#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int y, n;

bool check(int x, int m)
{
    set<int> s;
    if(x < 1000)    s.insert(0);
    while(x)
    {
        s.insert(x % 10);
        x /= 10;
    }
    return s.size() == m;
}

int main()
{
    cin >> y >> n;
    for(int i = y; ; i ++ )
    {
        if(check(i, n))
        {
            printf("%d %04d", i - y, i);
            return 0;
        }
    }
    

    return 0;
}