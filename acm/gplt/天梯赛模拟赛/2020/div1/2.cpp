#include <iostream>
using namespace std;
int main()
{
    double price;
    int rate;
    scanf("%lf %d", &price, &rate);
    printf("%.2lf\n", price * 0.1 * rate);
}