#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a = 0, b = 0;
    int n;  cin >> n;
    for(int i = 0; i < n; i ++ )
    {
        int x;  cin >> x;
        if(x >= 60) a ++ ;
        if(x >= 85) b ++ ;
    }
    double r1 = 1.0 * a / n * 100, r2 = 1.0 * b / n * 100;
    printf("%.0lf%\n%.0lf%\n", r1, r2);
    return 0;
}