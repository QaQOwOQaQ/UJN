#include <iostream>

using namespace std;

int main()
{
    double kg, m;
    cin >> kg >> m;
    
    double res = kg / (m * m);
    printf("%.1lf\n", res);
    
    if(res > 25)   puts("PANG");
    else    puts("Hai Xing");
    
    return 0;
}