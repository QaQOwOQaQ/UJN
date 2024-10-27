#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;
double m;

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++ )
    {
        double t;   cin >> t;
        if(t < m)
            printf("On Sale! %.1lf\n", t);
    }
    
    return 0;
}