#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n, h, w;

int main()
{
    cin >> n;
    while(n -- )
    {
        cin >> h >> w;
        double t = (h - 100) * 0.9 * 2;
        if(fabs(w - t) < t * 0.1)   puts("You are wan mei!");
        else
        {
            if(w > t)   puts("You are tai pang le!");
            else    puts("You are tai shou le!");
        }
    }

    
    return 0;
}