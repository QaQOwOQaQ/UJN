#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int h;
    cin >> h;
    double w = (h - 100) * 0.9 * 2;
    printf("%.1lf\n", w);
    
    return 0;
}