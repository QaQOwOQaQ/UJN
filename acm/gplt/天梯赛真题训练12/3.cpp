#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    double per3, per;
    int attr;
    
    double res = 0;
    cin >> per3 >> attr >> per;
    if(attr)//1.26
    {
        res = per3 * 1.26;
    }
    else//2.455
    {
        res = per3 * 2.455 ;
    }
    
    printf("%.2lf ", res);
    if(res > per)    puts("T_T");
    else    puts("^_^");
    
    return 0;
}