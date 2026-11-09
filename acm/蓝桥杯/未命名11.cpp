#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a,m;
    scanf("%lf",&a);
    printf("%.6f\n",cbrt(a));
    m = pow(a,3);
    printf("%0.6f",m);
    return 0;
}
