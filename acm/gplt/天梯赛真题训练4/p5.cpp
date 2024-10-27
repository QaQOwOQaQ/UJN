#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    double res;
    cin >> a >> b;
    if(!b)  printf("%d/%d=Error", a, b);
    else if(b < 0)   printf("%d/(%d)=%.2f", a, b, 1.0*a/b);
    else printf("%d/%d=%.2f", a, b, 1.0*a/b);   
    
    return 0;
}