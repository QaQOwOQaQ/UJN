//签到题

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T;

int main()
{
    cin >> T;
    while(T -- )
    {
        int n, x, y;
        cin >> n >> x >> y;
        int c1 = 0, c2 = 0, m;
        m = n;
        while(m)
        {
            int t = m % x; 
            c1 += (t == 1);
            m /= x;
        }
        m = n;
        while(m)
        {
            int t = m % y; 
            c2 += (t == 1);
            m /= y;
        }
        if(c2 == c1)    puts("=");
        else if(c1 < c2)    puts("<");
        else    puts(">");
    }
    
    return 0;
}