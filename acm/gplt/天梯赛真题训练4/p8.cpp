#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n -- )
    {
        char ch;
        double h;
        cin >> ch >> h;
        if(ch == 'M')   printf("%.2f\n", 1.0*h/1.09);
        else    printf("%.2f\n", 1.0*h*1.09);
    }
    
    
    return 0;
}