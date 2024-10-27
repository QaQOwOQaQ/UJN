#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;  cin >> n;
    double sum = 0;
    for(int i = 1; i <= n; i ++ )
    {
        double x;   cin >> x;
        sum += 1 / x;
    }
    
    printf("%.2lf\n", 1 / (sum / n));
    
    return 0;
}