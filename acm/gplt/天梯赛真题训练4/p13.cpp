#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const double g = 9.8, INF = 1e-9;

int main()
{
    double w, p, j = 1000;
    cin >> w >> p;
    w = 1.0 * w / 100; //kg
    p = 1.0 * p / 100;  //percent
    
    double distance = 0;
    while(j > 1e-9)
    {
        double v2 = 2 * j / w;  //v2=v*v
        double t = v2 / g;
        distance += t;
        j -= j * p;
    }
    
    printf("%.3f\n", distance);
    return 0;
}